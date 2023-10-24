#include <print>
#include "audioQueue.h"
#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Dv.h"
#include "VideoMasterHD_Dv_Audio.h"
#include "DeltaCastModule.h"
/*
HDMIAudioStream::HDMIAudioStream()
{
					boardHandle		= nullptr;
					streamHandle	= nullptr;
					slotHandle		= nullptr;
	unsigned long	result = 0;
	unsigned long	DllVersion		= 0;
	unsigned long	nbBoards		= 0;
	unsigned long	boardType		= 0;
	bool			isHdmiBoard		= false;

	result = VHD_GetApiInfo(&DllVersion, &nbBoards);
	if (result == VHDERR_NOERROR && nbBoards > 0)
	{
		if (VHD_OpenBoardHandle(0, &boardHandle, nullptr, 0) == VHDERR_NOERROR)
		{
			VHD_GetBoardProperty(boardHandle, VHD_CORE_BP_BOARD_TYPE, &boardType);
			isHdmiBoard = ((boardType == VHD_BOARDTYPE_HDMI) ||
				(boardType == VHD_BOARDTYPE_HDMI20) ||
				(boardType == VHD_BOARDTYPE_FLEX_HMI) ||
				(boardType == VHD_BOARDTYPE_MIXEDINTERFACE));
		}
	}
	else
	{
		std::print("Error : Cannot query VideoMaster information.\n");
	}
	
}

HDMIAudioStream::~HDMIAudioStream()
{
	VHD_CloseStreamHandle(streamHandle);
	VHD_CloseBoardHandle(boardHandle);
}

bool HDMIAudioStream::hardwareInfoCheck()
{
	unsigned long result		= 0;
	unsigned long DllVersion	= 0;
	unsigned long nbBoards		= 0;
	unsigned long boardType		= 0;
	bool          isHdmiBoard	= false;

	result = VHD_GetApiInfo(&DllVersion, &nbBoards);
	if (result == VHDERR_NOERROR && nbBoards > 0)
	{
		if (VHD_OpenBoardHandle(0, &boardHandle, nullptr, 0) == VHDERR_NOERROR)
		{
			VHD_GetBoardProperty(boardHandle, VHD_CORE_BP_BOARD_TYPE, &boardType);
			isHdmiBoard = (	(boardType == VHD_BOARDTYPE_HDMI)		|| 
							(boardType == VHD_BOARDTYPE_HDMI20)		|| 
							(boardType == VHD_BOARDTYPE_FLEX_HMI)	|| 
							(boardType == VHD_BOARDTYPE_MIXEDINTERFACE));
			if (isHdmiBoard)
			{
				result = VHD_SetStreamProperty(streamHandle, VHD_DV_SP_MODE, VHD_DV_MODE_HDMI);
			}
			
			return isHdmiBoard;
		}
	}
	else
	{
		std::print("Error : Cannot query VideoMaster information.\n");
		return false;
	}
}

bool HDMIAudioStream::videoStreamInfoCheck()
{
	unsigned long	result = 0;
	


	return false;
}

void HDMIAudioStream::getAudioData(const int PA_SAMPLE_RATE, const int PA_OUTPUT_CHANNELS)
{
}
*/

void Convert24bitTo32Bit(const uint8_t* sourceAudio, size_t sourceSize, float* destinationAudio, size_t destinationSize)
{
        const float scale = 1.0 / static_cast<float>(1 << 23); // 2^23 for 24-bit

        for (size_t i = 0; i < sourceSize; i += 3)
        {
            uint32_t sample24 = static_cast<uint32_t>(sourceAudio[i    ] << 16) | 
                                static_cast<uint32_t>(sourceAudio[i + 1] << 8 ) | 
                                static_cast<uint32_t>(sourceAudio[i + 2]);

            float sample32 = static_cast<float>(sample24) * scale *100;
            if (i / 3 < destinationSize)
                destinationAudio[i / 3] = sample32;
        }
}

void DeltaCastRecv(         std::vector<audioQueue<float>>& queue,
                    const	std::uint32_t	                PA_SAMPLE_RATE,
                    const   std::uint32_t	                PA_OUTPUT_CHANNELS,
                    const   std::uint32_t	                BUFFER_MAX,
                    const	std::uint32_t	                BUFFER_MIN)
{
    ULONG                      Result, DllVersion, NbBoards, BoardType;
    ULONG                      NbFramesRecv = 0, NbFramesDropped = 0, BufferSize = 0, AudioBufferSize = 0, PxlClk = 0;
    HANDLE                     BoardHandle = nullptr, StreamHandle = nullptr, SlotHandle = nullptr;
    ULONG                      Height = 0, Width = 0, RefreshRate = 0;
    VHD_DV_MODE                DvMode = NB_VHD_DV_MODES;
    ULONG                      BrdId = 0;
    BOOL32                     Interlaced = FALSE;
    BOOL32                     IsHdmiBoard = FALSE;
    BYTE*                      pBuffer = nullptr, * pAudioBuffer = nullptr;
    VHD_DV_CS                  InputCS;
    VHD_DV_AUDIO_TYPE          HDMIAudioType;
    VHD_DV_AUDIO_INFOFRAME     HDMIAudioInfoFrame;
    VHD_DV_AUDIO_AES_STS       HDMIAudioAESSts;

    /* Query VideoMaster information */
    Result = VHD_GetApiInfo(&DllVersion, &NbBoards);
    if (Result == VHDERR_NOERROR)
    {
        if (NbBoards > 0)
        {
            /* Open a handle on selected DELTA board */
            Result = VHD_OpenBoardHandle(BrdId, &BoardHandle, nullptr, 0);
            if (Result == VHDERR_NOERROR)
            {
                VHD_GetBoardProperty(BoardHandle, VHD_CORE_BP_BOARD_TYPE, &BoardType);
                IsHdmiBoard = ((BoardType == VHD_BOARDTYPE_HDMI) || (BoardType == VHD_BOARDTYPE_HDMI20) || (BoardType == VHD_BOARDTYPE_FLEX_HMI) || (BoardType == VHD_BOARDTYPE_MIXEDINTERFACE));

                /* Check the board type of the selected board */
                if (IsHdmiBoard)
                {
                    /* Create a logical stream to receive from RX0 connector */
                    Result = VHD_OpenStreamHandle(BoardHandle, VHD_ST_RX0, IsHdmiBoard ? VHD_DV_STPROC_JOINED : VHD_DV_STPROC_DEFAULT, nullptr, &StreamHandle, nullptr);
                    if (Result == VHDERR_NOERROR)
                    {
                        /* Set the primary mode of this channel to HDMI */
                        Result = VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_MODE, VHD_DV_MODE_HDMI);
                        if (Result == VHDERR_NOERROR)
                        {
                            printf("Waiting for incoming HDMI signal... Press any key to stop...\n");
                            do
                            {
                                /* Auto-detect Dv mode */
                                Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_MODE, (ULONG*)&DvMode);
                            } while (DvMode != VHD_DV_MODE_HDMI || Result != VHDERR_NOERROR);

                            if (Result == VHDERR_NOERROR && DvMode == VHD_DV_MODE_HDMI)
                            {
                                /* Configure RGBA reception (no color-space conversion) */
                                VHD_SetStreamProperty(StreamHandle, VHD_CORE_SP_BUFFER_PACKING, VHD_BUFPACK_VIDEO_RGB_32);
                                VHD_SetStreamProperty(StreamHandle, VHD_CORE_SP_TRANSFER_SCHEME, VHD_TRANSFER_SLAVED);

                                /* Get auto-detected resolution */
                                Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_WIDTH, &Width);
                                if (Result == VHDERR_NOERROR)
                                {
                                    std::print("2 reached.\n");
                                    Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_HEIGHT, &Height);
                                    if (Result == VHDERR_NOERROR)
                                    {
                                        std::print("3 reached.\n");
                                        Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_INTERLACED, (ULONG*)&Interlaced);
                                        if (Result == VHDERR_NOERROR)
                                        {
                                            Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_REFRESH_RATE, &RefreshRate);
                                            if (Result == VHDERR_NOERROR)
                                            {
                                                if (IsHdmiBoard)
                                                    Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_INPUT_CS, (ULONG*)&InputCS);

                                                if (Result == VHDERR_NOERROR)
                                                {
                                                    if (IsHdmiBoard)
                                                        Result = VHD_GetStreamProperty(StreamHandle, VHD_DV_SP_PIXEL_CLOCK, &PxlClk);
                                                    std::print("4 reached.\n");
                                                    if (Result == VHDERR_NOERROR)
                                                    {
                                                        printf("\nIncoming graphic resolution : %ux%u (%s)\n", Width, Height, Interlaced ? "Interlaced" : "Progressive");

                                                        /* Configure stream. Only VHD_DV_SP_ACTIVE_WIDTH, VHD_DV_SP_ACTIVE_HEIGHT,
                                                        VHD_DV_SP_INTERLACED and VHD_DV_SP_REFRESH_RATE properties are required for HDMI */

                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_WIDTH, Width);
                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_ACTIVE_HEIGHT, Height);
                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_INTERLACED, Interlaced);
                                                        VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_REFRESH_RATE, RefreshRate);

                                                        /* VHD_DV_SP_INPUT_CS and VHD_DV_SP_PIXEL_CLOCK are required for DELTA-h4k only */
                                                        if (BoardType == VHD_BOARDTYPE_HDMI)
                                                        {
                                                            VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_INPUT_CS, InputCS);
                                                            VHD_SetStreamProperty(StreamHandle, VHD_DV_SP_PIXEL_CLOCK, PxlClk);
                                                        }

                                                        /* Start stream */
                                                        Result = VHD_StartStream(StreamHandle);
                                                        if (Result == VHDERR_NOERROR)
                                                        {
                                                            printf("\nReception started\n");

                                                            /* Reception loop */
                                                            while (1)
                                                            {
                                                                /* Try to lock next slot */
                                                                Result = VHD_LockSlotHandle(StreamHandle, &SlotHandle);

                                                                if (Result == VHDERR_NOERROR)
                                                                {
                                                                    Result = VHD_GetSlotBuffer(SlotHandle, VHD_DV_BT_VIDEO, &pBuffer, &BufferSize);
                                                                    if (Result == VHDERR_NOERROR)
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
                                                                        Result = VHD_GetSlotDvAudioInfo(SlotHandle, &HDMIAudioType, &HDMIAudioInfoFrame, &HDMIAudioAESSts);
                                                                        if (Result == VHDERR_NOERROR)
                                                                        {
                                                                            if (HDMIAudioType != VHD_DV_AUDIO_TYPE_NONE)
                                                                            {
                                                                                BufferSize = 0;
                                                                                if (HDMIAudioAESSts.LinearPCM == VHD_DV_AUDIO_AES_SAMPLE_STS_LINEAR_PCM_SAMPLE)
                                                                                {
                                                                                    VHD_SlotExtractDvPCMAudio(SlotHandle, VHD_DVAUDIOFORMAT_24, 0x3, nullptr, &BufferSize);
                                                                                    pAudioBuffer = new UBYTE[BufferSize];
                                                                                    size_t floatBufferSize = BufferSize / 3; // Assuming 3 bytes per 24-bit sample
                                                                                    float* destinationAudio = new float[floatBufferSize];
                                                                                    Result = VHD_SlotExtractDvPCMAudio(SlotHandle, VHD_DVAUDIOFORMAT_24, 0x3, pAudioBuffer, &BufferSize);
                                                                                    if (Result == VHDERR_NOERROR)
                                                                                    {
                                                                                        Convert24bitTo32Bit(pAudioBuffer, BufferSize, destinationAudio, floatBufferSize);
                                                                                        audioQueue<float> HDMIAudio(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, BUFFER_MAX, BUFFER_MIN);
                                                                                        
                                                                                        HDMIAudio.push(destinationAudio, floatBufferSize / PA_OUTPUT_CHANNELS, 44100);

                                                                                        queue.push_back(HDMIAudio);
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
                                                                else if (Result != VHDERR_TIMEOUT)
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