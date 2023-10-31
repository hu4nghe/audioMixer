#include <print>
#include <functional>

#include "audioQueue.h"
#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Dv.h"
#include "VideoMasterHD_Dv_Audio.h"
#include "sndfile.h"
#include "DeltaCastModule.h"


std::vector<int32_t> combineBYTETo24Bit(const std::uint8_t* sourceAudio, 
                                        const std:: size_t  sourceSize)
{
    std::vector<int32_t> combined24bit;
    if (sourceSize % 3)
    {
        std::print("HDMI Audio Error : Invalid buffer size for 24 bit audio data.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (auto i = 0, j = 0; i < sourceSize; i += 3, ++j)
        {
            std::uint32_t sample24 = static_cast<std::uint32_t>(sourceAudio[i    ] << 16) |
                                     static_cast<std::uint32_t>(sourceAudio[i + 1] << 8 ) |
                                     static_cast<std::uint32_t>(sourceAudio[i + 2]);
            combined24bit.push_back(sample24);
        }
    }
    return combined24bit;
}

std::vector<float> decodeAndConvertToFloat( const std::vector<std::int32_t>& pcmData)
{
    auto read = [](void* data, sf_count_t count,void* user_data ) -> sf_count_t
    {
        std::int32_t* pcmData = static_cast<std::int32_t*>(user_data);
        std::memcpy(data, pcmData, count);
        return count;
    };
    std::function<sf_count_t(void*, sf_count_t, void*)> readFunction = read;

    SNDFILE*    sndFile;
    SF_INFO     sfInfo;

    std::memset(&sfInfo, 0, sizeof(sfInfo));

    sfInfo.format       = SF_FORMAT_RAW | SF_FORMAT_PCM_24;
    sfInfo.channels     = 2;
    sfInfo.samplerate   = 44100;

    SF_VIRTUAL_IO virtualIO;
    
    virtualIO.read = reinterpret_cast<sf_vio_read>(readFunction.target<void(void*, sf_count_t, void*)>());
    virtualIO.get_filelen   = nullptr;
    virtualIO.seek          = nullptr;
    virtualIO.write         = nullptr; 
    virtualIO.tell          = nullptr;
     

    float* floatData = new float[pcmData.size()];

    sndFile = sf_open_virtual(&virtualIO, SFM_READ, &sfInfo, (void*)pcmData.data());

    sf_readf_float(sndFile, floatData, pcmData.size()/2);

    sf_close(sndFile);

    std::vector<float> res(floatData, floatData + pcmData.size());
    delete[] floatData;
    for (auto& i : res)
    {
        std::print("{}\n", i);
    }
    return res;
}

std::vector<float> mapToFloatVector(const std::vector<std::int32_t>& inputVector)
{
    std::vector<float> outputVector(inputVector.size());

    float inputMin = -8388608.0f;
    float inputMax = 8388607.0f;
    float outputMin = -1.0f;
    float outputMax = 1.0f;

    for (const int& value : inputVector)
    {
        float mappedValue = ((value - inputMin) / (inputMax - inputMin)) * (outputMax - outputMin) + outputMin;
        outputVector.push_back(mappedValue);
    }

    return outputVector;
}

void DeltaCastRecv(                     audioQueue<float>&     queue,
                    const	std::               uint32_t	    PA_SAMPLE_RATE,
                    const   std::               uint32_t	    PA_OUTPUT_CHANNELS,
                    const   std::               uint32_t	    BUFFER_MAX,
                    const	std::               uint32_t	    BUFFER_MIN)
{
    unsigned long   errorCode = 0;
    
    unsigned long   PxlClk = 0;
    void*           BoardHandle = nullptr;
    void*           StreamHandle = nullptr;
    void*           SlotHandle = nullptr;
    unsigned char*  pBuffer = nullptr;
    unsigned char*  pAudioBuffer = nullptr;
    
    VHD_DV_MODE                DvMode = NB_VHD_DV_MODES;
    VHD_DV_CS                  InputCS;
    VHD_DV_AUDIO_TYPE          HDMIAudioType;
    VHD_DV_AUDIO_INFOFRAME     HDMIAudioInfoFrame;
    VHD_DV_AUDIO_AES_STS       HDMIAudioAESSts;

    //debug info
    //unsigned long NbFramesRecv = 0;
    //unsigned long NbFramesDropped = 0;

    /* Query VideoMaster information */
    unsigned long nbBoards = 0;
    errorCode = VHD_GetApiInfo(nullptr, &nbBoards);//We do not care about dll versio
    if (errorCode == VHDERR_NOERROR)
    {
        if (nbBoards > 0)
        {
            unsigned long BrdId = 0;
            /* Open a handle on selected DELTA board */
            errorCode = VHD_OpenBoardHandle(BrdId, &BoardHandle, nullptr, 0);
            if (errorCode == VHDERR_NOERROR)
            {
                unsigned long BoardType = 0;
                bool IsHdmiBoard = false;
                VHD_GetBoardProperty(BoardHandle, VHD_CORE_BP_BOARD_TYPE, &BoardType);
                IsHdmiBoard = ((BoardType == VHD_BOARDTYPE_HDMI) || (BoardType == VHD_BOARDTYPE_HDMI20) || (BoardType == VHD_BOARDTYPE_FLEX_HMI) || (BoardType == VHD_BOARDTYPE_MIXEDINTERFACE));

                /* Check the board type of the selected board */
                if (IsHdmiBoard)
                {
                    /* Create a logical stream to receive from RX0 connector */
                    errorCode = VHD_OpenStreamHandle(BoardHandle, VHD_ST_RX0, IsHdmiBoard ? VHD_DV_STPROC_JOINED : VHD_DV_STPROC_DEFAULT, nullptr, &StreamHandle, nullptr);
                    if (errorCode == VHDERR_NOERROR)
                    {
                        /* Set the primary mode of this channel to HDMI */
                        errorCode = VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_MODE, VHD_DV_MODE_HDMI);
                        if (errorCode == VHDERR_NOERROR)
                        {
                            printf("Waiting for incoming HDMI signal... Press any key to stop...\n");
                            do
                            {
                                /* Auto-detect Dv mode */
                                errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_MODE, (ULONG*)&DvMode);
                            } while (DvMode != VHD_DV_MODE_HDMI || errorCode != VHDERR_NOERROR);

                            if (errorCode == VHDERR_NOERROR && DvMode == VHD_DV_MODE_HDMI)
                            {
                                /* Configure RGBA reception (no color-space conversion) */
                                VHD_SetStreamProperty(StreamHandle, VHD_CORE_SP_BUFFER_PACKING, VHD_BUFPACK_VIDEO_RGB_32);
                                VHD_SetStreamProperty(StreamHandle, VHD_CORE_SP_TRANSFER_SCHEME, VHD_TRANSFER_SLAVED);

                                unsigned long height = 0;
                                unsigned long width = 0;
                                unsigned long refreshRate = 0;
                                bool Interlaced = false;

                                /* Get auto-detected resolution */
                                errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_WIDTH, &width);
                                if (errorCode == VHDERR_NOERROR)
                                {
                                    errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_HEIGHT, &height);
                                    if (errorCode == VHDERR_NOERROR)
                                    {
                                        errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_INTERLACED, (ULONG*)&Interlaced);
                                        if (errorCode == VHDERR_NOERROR)
                                        {
                                            errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_REFRESH_RATE, &refreshRate);
                                            if (errorCode == VHDERR_NOERROR)
                                            {
                                                if (IsHdmiBoard)
                                                    errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_INPUT_CS, (ULONG*)&InputCS);

                                                if (errorCode == VHDERR_NOERROR)
                                                {
                                                    if (IsHdmiBoard)
                                                        errorCode = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_PIXEL_CLOCK, &PxlClk);
                                                    std::print("4 reached.\n");
                                                    if (errorCode == VHDERR_NOERROR)
                                                    {
                                                        printf("\nIncoming graphic resolution : %ux%u (%s)\n", width, height, Interlaced ? "Interlaced" : "Progressive");

                                                        /* Configure stream. Only VHD_DV_SP_ACTIVE_WIDTH, VHD_DV_SP_ACTIVE_HEIGHT,
                                                        VHD_DV_SP_INTERLACED and VHD_DV_SP_REFRESH_RATE properties are required for HDMI */

                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_WIDTH, width);
                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_HEIGHT, height);
                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_INTERLACED, Interlaced);
                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_REFRESH_RATE, refreshRate);

                                                        /* VHD_DV_SP_INPUT_CS and VHD_DV_SP_PIXEL_CLOCK are required for DELTA-h4k only */
                                                        if (BoardType == VHD_BOARDTYPE_HDMI)
                                                        {
                                                            VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_INPUT_CS, InputCS);
                                                            VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_PIXEL_CLOCK, PxlClk);
                                                        }

                                                        /* Start stream */
                                                        errorCode = VHD_StartStream(StreamHandle);
                                                        if (errorCode == VHDERR_NOERROR)
                                                        {
                                                            printf("\nReception started\n");

                                                            /* Reception loop */
                                                            while (1)
                                                            {
                                                                /* Try to lock next slot */
                                                                errorCode = VHD_LockSlotHandle(StreamHandle, &SlotHandle);

                                                                if (errorCode == VHDERR_NOERROR)
                                                                {   
                                                                    unsigned long bufferSize = 0;
                                                                    errorCode = VHD_GetSlotBuffer(SlotHandle, VHD_DV_BT_VIDEO, &pBuffer, &bufferSize);
                                                                    if (errorCode == VHDERR_NOERROR)
                                                                    {
                                                                        /* Do RX data processing here on pBuffer */
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("\nERROR : Cannot get video slot buffer.");
                                                                        break;
                                                                    }
                                                                    if (IsHdmiBoard)
                                                                    {
                                                                        /* Do RX data processing here on pBuffer */
                                                                        errorCode = VHD_GetSlotDvAudioInfo(SlotHandle, &HDMIAudioType, &HDMIAudioInfoFrame, &HDMIAudioAESSts);
                                                                        if (errorCode == VHDERR_NOERROR)
                                                                        {
                                                                            if (HDMIAudioType != VHD_DV_AUDIO_TYPE_NONE)
                                                                            {
                                                                                
                                                                                bufferSize = 0;
                                                                                if (HDMIAudioAESSts.LinearPCM == VHD_DV_AUDIO_AES_SAMPLE_STS_LINEAR_PCM_SAMPLE)
                                                                                {
                                                                                    VHD_SlotExtractDvPCMAudio(SlotHandle, VHD_DVAUDIOFORMAT_24, 0x3, nullptr, &bufferSize);
                                                                                    pAudioBuffer = new UBYTE[bufferSize];
                                                                                    errorCode = VHD_SlotExtractDvPCMAudio(SlotHandle, VHD_DVAUDIOFORMAT_24, 0x3, pAudioBuffer, &bufferSize);
                                                                                    if (errorCode == VHDERR_NOERROR)
                                                                                    {
                                                                                        std::vector<int32_t> combined24bit = combineBYTETo24Bit (pAudioBuffer, bufferSize);
                                                                                        std::vector<float> float32bit = mapToFloatVector(combined24bit);
                                                                                        queue.push(float32bit.data(), float32bit.size() / 2, 44100, 2);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        printf("\nERROR : Cannot get PCM audio slot buffer.");
                                                                                    }
                                                                                }
                                                                                if (pAudioBuffer)
                                                                                {
                                                                                    delete[] pAudioBuffer;
                                                                                    pAudioBuffer = nullptr;
                                                                                }
                                                                            }
                                                                        }
                                                                        else
                                                                        {
                                                                            printf("\nERROR : Cannot get HDMI audio info.");
                                                                            break;
                                                                        }
                                                                    }

                                                                    /* Unlock slot */
                                                                    VHD_UnlockSlotHandle(SlotHandle);

                                                                    /* Print some statistics */
                                                                    
                                                                    //VHD_GetStreamProperty(StreamHandle, VHD_CORE_SP_SLOTS_COUNT, &NbFramesRecv);
                                                                    //VHD_GetStreamProperty(StreamHandle, VHD_CORE_SP_SLOTS_DROPPED, &NbFramesDropped);
                                                                    //printf("%u frames received (%u dropped)            \r", NbFramesRecv, NbFramesDropped);
                                                                    //fflush(stdout);
                                                                }
                                                                else if (errorCode != VHDERR_TIMEOUT)
                                                                {
                                                                    printf("\nERROR : Cannot lock slot on RX0 stream.");
                                                                    break;
                                                                }
                                                            }

                                                            printf("\n");

                                                            /* Stop stream */
                                                            VHD_StopStream(StreamHandle);
                                                        }
                                                        else
                                                            printf("ERROR : Cannot start RX0 stream on DV board handle.");
                                                    }
                                                    else
                                                        printf("ERROR : Cannot detect incoming pixel clock from RX0.");
                                                }
                                                else
                                                    printf("ERROR : Cannot detect incoming color space from RX0.");
                                            }
                                            else
                                                printf("ERROR : Cannot detect incoming refresh rate from RX0.");
                                        }
                                        else
                                            printf("ERROR : Cannot detect if incoming stream from RX0 is interlaced or progressive.");
                                    }
                                    else
                                        printf("ERROR : Cannot detect incoming active height from RX0.");
                                }
                                else
                                    printf("ERROR : Cannot detect incoming active width from RX0.");
                            }
                            else
                                printf("ERROR : Cannot detect if incoming mode is HDMI.");
                        }
                        else
                            printf("ERROR : Cannot configure RX0 stream primary mode.");

                        /* Close stream handle */
                        VHD_CloseStreamHandle(StreamHandle);
                    }
                    else
                        printf("ERROR : Cannot open RX0 stream on HDMI / DVI board handle.");
                }
                else
                    printf("ERROR : The selected board is not a HDMI or DVI board\n");

                /* Close board handle */
                VHD_CloseBoardHandle(BoardHandle);
            }
            else
                printf("ERROR : Cannot open DELTA board handle.");
        }
        else
            printf("No DELTA board detected, exiting...\n");
    }
    else
        printf("ERROR : Cannot query VideoMaster information.");
}