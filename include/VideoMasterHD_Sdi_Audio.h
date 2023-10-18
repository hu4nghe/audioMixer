/*! VideomasterHD_Sdi_Audio.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : gt                             Date: 2009/06/26

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_SDI_AUDIO_H_
#define _VIDEOMASTERHD_SDI_AUDIO_H_

#ifdef __cplusplus
extern "C" {
#endif


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Audio
*/

#define VHD_NBOFGROUP         4  /*!VHD_NBOFGROUP
                                    Number of audio groups in a stream */
#define VHD_NBOFCHNPERGROUP   4  /*!VHD_NBOFCHNPERGROUP
                                    Number of audio channels in an audio group */
#define VHD_NBOFPAIRPERGROUP  2  /*!VHD_NBOFPAIRPERGROUP
                                    Number of audio pairs in an audio group */







/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Audio
*/



/*_ VHD_AUDIOFORMAT  _________________________________________________________*/
/*!
   Summary
   SDI audio formats
   Description
   The VHD_AUDIOFORMAT enumeration lists all the available SDI
   audio sample formats
   
   These values are used in the VHD_AUDIOCHANNEL structure.
   See Also
   VHD_AUDIOCHANNEL                                            */
typedef enum _VHD_AUDIOFORMAT {
   VHD_AF_RAW,                  /*! Raw AES sample (32 bits) */
   VHD_AF_16,                   /*! PCM sample (16 bits) */
   VHD_AF_20,                   /*! PCM sample (20 bits) */
   VHD_AF_24,                   /*! PCM sample (24 bits) */
   NB_VHD_AUDIOFORMAT
} VHD_AUDIOFORMAT;


/*_ VHD_AUDIOMODE ____________________________________________________*/
/*!
   Summary
   SDI audio channel modes
   Description
   The VHD_AUDIOCHANNELMODE enumeration lists all the available
   SDI audio channel modes
   
   These values are used in the VHD_AUDIOCHANNEL structure.
   See Also
   VHD_AUDIOCHANNEL                                             */
typedef enum _VHD_AUDIOMODE {
   VHD_AM_OFF,           /*! No reception/transmission */
   VHD_AM_MONO,          /*! Single channel mode */
   VHD_AM_STEREO,        /*! Stereo channel mode. Channel samples of the same AES pair are interleaved 
                         in the same buffer (the buffer of the left (i.e. the first) channel of the audio pair).
                         If the stereo channel mode is used for one channel of an audio pair, the
                         ChannelMode and ChannelFormat fields of the two channels of this pair should be the same.
                         */
                         NB_VHD_AUDIOMODE
} VHD_AUDIOMODE;



/*_ VHD_AUDIOSAMPLINGRATE ____________________________________________________*/
/*!
   Summary
   SDI audio sampling rates
   Description
   The VHD_AUDIOSAMPLINGRATE enumeration lists all the available
   SDI audio sampling rates
   
   These values are used in the VHD_AUDIOGROUPCTRL structure.
   See Also
   VHD_AUDIOGROUPCTRL                                            */
typedef enum _VHD_AUDIOSAMPLINGRATE {
   VHD_ASR_48000,                   /*! 48 kHz sampling rate */
   VHD_ASR_44100,                   /*! 44.1 kHz sampling rate */ 
   VHD_ASR_32000,                   /*! 32 kHz sampling rate */ 
   VHD_ASR_FREERUN,                 /*! Free running */ 
   NB_VHD_AUDIOSAMPLINGRATE
} VHD_AUDIOSAMPLINGRATE;








/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Audio
*/



/*_ VHD_AUDIOGROUPCTRL ________________________________________________________*/
/*!
   Summary
   SDI audio group control
   Description
   The VHD_AUDIOGROUPCTRL structure contains information
   embedded in an Audio Control Packet. It is part of the
   VHD_AUDIOGROUP structure.
   See Also
   VHD_AUDIOGROUP VHD_AUDIOSAMPLINGRATE                   */
typedef struct _VHD_AUDIOGROUPCTRL {
   ULONG ActiveChannels;                                				/*! Active channels mask */
   union{
      ULONG AudioFrameNb;                               				/*! Audio frame number data (HD/3G) */
      ULONG pAudioFrameNb[VHD_NBOFPAIRPERGROUP];        				/*! Audio frame number data (SD) */
   };                                                					/*!*/
   union{
      VHD_AUDIOSAMPLINGRATE SamplingRate;                         /*! Sampling rate (HD/3G) */
      VHD_AUDIOSAMPLINGRATE pSamplingRate[VHD_NBOFPAIRPERGROUP];  /*! Sampling rate (SD) */          
   };                                                 				/*!*/
   union{
      BOOL32 Asynchronous;                              				/*! TRUE if asynchronous audio (HD/3G) */
      BOOL32 pAsynchronous[VHD_NBOFPAIRPERGROUP];       				/*! TRUE if asynchronous audio (SD) */       
   };                                                 				/*!*/
   union{
      BOOL32 Delay12Valid;                              				/*! Audio pair 1-2 delay is valid (HD/3G) */
      BOOL32 pDelay12Valid[VHD_NBOFPAIRPERGROUP];       				/*! Audio pair 1-2 delay is valid (SD) */      
   };                                                 				/*!*/
   union{
      ULONG Delay12;                                    				/*! Audio pair 1-2 delay (HD/3G) */  
      ULONG pDelay12[VHD_NBOFPAIRPERGROUP];             				/*! Audio pair 1-2 delay (SD) */ 
   };                                                          	/*!*/
   union{
      BOOL32 Delay34Valid;                              				/*! Audio pair 3-4 delay is valid (HD/3G) */
      BOOL32 pDelay34Valid[VHD_NBOFPAIRPERGROUP];       				/*! Audio pair 3-4 delay is valid (SD) */      
   };                                                 				/*!*/
   union{
      ULONG Delay34;                                    				/*! Audio pair 3-4 delay (HD/3G) */  
      ULONG pDelay34[VHD_NBOFPAIRPERGROUP];             				/*! Audio pair 3-4 delay (SD) */
   };                                                 				/*!*/          

} VHD_AUDIOGROUPCTRL;




#pragma pack (push,1)

/*_ VHD_AESCHANNELSTATUSBLOCK ____________________________________________________*/
/*!
   Summary
   SDI audio channel status block
   Description
   This structure contains the received/transmitted audio
   channel status block corresponding to a single AES channel.
   It is part of the VHD_AUDIOCHANNEL structure.
   See Also
   VHD_AUDIOCHANNEL                                            */
typedef union _VHD_AESCHANNELSTATUSBLOCK
{
   struct
   {
      //byte 0
      unsigned char  Pro : 1;									/*!*/
      unsigned char  NotAudio : 1;							/*!*/
      unsigned char  EncodedAudioSignalEmphasis : 3;	/*!*/
      unsigned char  NotLocked : 1;							/*!*/
      unsigned char  SampleFrequency : 2;					/*!*/

      //byte 1
      unsigned char   ChannelMode : 4;						/*!*/
      unsigned char   UserBitMngmt : 4;					/*!*/

      //byte 2
      unsigned char   Aux : 3;								/*!*/
      unsigned char   SrcWordLen : 3;						/*!*/
      unsigned char   Reserved1 : 2;						/*!*/

      //byte 3
      unsigned char   Reserved2 : 8;						/*!*/

      //byte 4
      unsigned char   Reference : 2;						/*!*/
      unsigned char   Reserved3 : 6;						/*!*/

      //byte 5
      unsigned char   Reserved4 : 8;						/*!*/

      //byte 6-9
      ULONG          OrigData : 32;							/*!*/

      //byte 10-13
      ULONG          DestData : 32;							/*!*/

      //byte 14-17
      ULONG          LocalSampleAddressCode : 32;		/*!*/

      //byte 18-21
      ULONG          TimeOfDaySampleAddressCode : 32;	/*!*/

      //byte 22
      unsigned char   Reserved5 : 4;						/*!*/
      unsigned char   CSB0to5Unrel : 1;					/*!*/
      unsigned char   CSB6to13Unrel : 1;					/*!*/
      unsigned char   CSB14to17Unrel : 1;					/*!*/
      unsigned char   CSB18to21Unrel : 1;					/*!*/

      //byte 23
      unsigned char   CRC : 8;								/*!*/
   };
   BYTE pByte_UB[24];											/*!*/
}VHD_AESCHANNELSTATUSBLOCK;
#pragma pack (pop)

/*_ VHD_AESCHANNELUSERBLOCK ____________________________________________________*/
/*!
   Summary
   SDI audio channel status block
   Description
   This structure contains the received/transmitted audio
   channel status block corresponding to a single AES channel.
   It is part of the VHD_AUDIOCHANNEL structure.
   See Also
   VHD_AUDIOCHANNEL                                            */
typedef union _VHD_AESCHANNELUSERBLOCK
{
   BYTE pByte_UB[24];											/*!*/
}VHD_AESCHANNELUSERBLOCK;

/*_ VHD_AUDIOCHANNEL ________________________________________________________*/
/*!
   Summary
   SDI audio channel
   Description
   The VHD_AUDIOCHANNEL structure contains information about a
   SDI embedded audio channel. It is part of the VHD_AUDIOGROUP
   structure.
   See Also
   VHD_AUDIOGROUP VHD_AUDIOFORMAT VHD_AESCHANNELUSERBLOCK
   VHD_AESCHANNELSTATUSBLOCK                                    */
typedef struct _VHD_AUDIOCHANNEL { 
   VHD_AUDIOMODE   Mode;                              /*! 
                                                      (IN) Audio channel mode. Following fields are relevant if this field is not VHD_AM_OFF. */
   VHD_AUDIOFORMAT BufferFormat;                      /*!
                                                      RX: (IN) Wanted buffer format. 

                                                      TX: (IN) Provided buffer format. 
                                                      */
   BOOL32 ExtendedData_B;                               /*! 
                                                      This field is only relevant in SD.

                                                      RX: (OUT) TRUE if Extended Data Packet are embedded. FALSE otherwise.

                                                      TX: (IN) Set to TRUE to embed Extended Data Packet. FALSE otherwise. 
                                                      */
   BOOL32 AesChannelStatusBlockValid;                   /*! 
                                                      Not relevant if BufferFormat is VHD_AF_RAW

                                                      RX : (OUT) TRUE if the following AesChannelStatusBlock field contains a valid 
                                                      Channel Status Block, i.e. there is 192 samples between the two last AES 
                                                      Z preamble and the Channel Status Block CRC is correct. FALSE, otherwise 

                                                      TX : (IN) TRUE to embed the following AesChannelStatusBlock field.
                                                      FALSE to let the API build and embed a default AesChannelStatusBlock field
                                                      based on the given configuration.
                                                      */
   VHD_AESCHANNELSTATUSBLOCK AesChannelStatusBlock;   /*! 
                                                      Not relevant if BufferFormat is VHD_AF_RAW

                                                      RX : (OUT) The last received AES Channel Status Block. 

                                                      TX : (IN if AesChannelStatusBlockValid is TRUE) AES Channel Status Block 
                                                      to embed. (OUT if AesChannelStatusBlockValid is FALSE) AES Channel Status Block 
                                                      build and embedded by the API. 
                                                      */
   BOOL32 AesChannelUserBlockValid;                     /*! 
                                                      Not relevant if BufferFormat is VHD_AF_RAW

                                                      RX : (OUT) TRUE if the following AesChannelUserBlock field  contains a valid
                                                      Channel User Block, i.e. there is 192 samples between the two last AES Z 
                                                      preamble. FALSE, otherwise 

                                                      TX : (IN) TRUE to embed the following AesChannelStatusBlock field.
                                                      FALSE, otherwise. 
                                                      */
   VHD_AESCHANNELUSERBLOCK AesChannelUserBlock;       /*! 
                                                      Not relevant if BufferFormat is VHD_AF_RAW

                                                      RX : (OUT) The last received AES Channel User Block. 

                                                      TX : (IN) Relevant if preceding AesChannelUserBlockValid field is TRUE.
                                                      AES Channel User Block to embed.
                                                      */
   ULONG DataSize;                                    /*!_VHD_AUDIOCHANNEL::DataSize
                                                         RX : (IN/OUT) Size of the user allocated buffer pointed by
                                                         following pData field. If the buffer is too small to receive
                                                         every audio samples, VHD_SlotExtractAudio/VHD_SlotExtractAudioEx returns the needed
                                                         buffer size in this field and doesn't extract audio. If the
                                                         buffer is big enough to receive every audio samples,
                                                         VHD_SlotExtractAudio/VHD_SlotExtractAudioEx returns the used buffer size in this
                                                         field and extracts audio in the buffer.
                                                         
                                                         TX : (IN/OUT) Size of the user provided buffer pointed by
                                                         following pData field. If the buffer is too small to embed
                                                         the entire slot, VHD_SlotEmbedAudio/VHD_SlotEmbedAudioEx returns the needed buffer
                                                         size in this field and doesn't embed audio. If the buffer is
                                                         big enough to embed the entire slot, VHD_SlotEmbedAudio/VHD_SlotEmbedAudioEx
                                                         returns the used buffer size in this field and embed audio
                                                         in the slot.                                                  */
   BYTE *pData;                                       /*!_VHD_AUDIOCHANNEL::pData
                                                         RX : (IN) Pointer to a caller-allocated buffer receiving the
                                                         samples.
                                                         
                                                         TX : (IN) Pointer to the caller-allocated buffer containing
                                                         the samples to embed.                                        */
} VHD_AUDIOCHANNEL;

/*_ VHD_AUDIOGROUP ________________________________________________________*/
/*!
   Summary
   SDI audio group
   Description
   The VHD_AUDIOGROUP structure contains information about an
   audio group. It is part of the VHD_AUDIOINFO structure.
   See Also
   VHD_AUDIOINFO VHD_AUDIOGROUPCTRL VHD_AUDIOCHANNEL          */
typedef struct _VHD_AUDIOGROUP { 
   BOOL32 GroupCtrlValid;                /*! 
                                       RX : (IN) TRUE if the GroupCtrl field contains the received audio control packet. FALSE if there
                                       is no embedded audio control packet for this audio group in the received stream. 

                                       TX : (IN) TRUE to embed the following GroupCtrl field. FALSE to let the API build and embed 
                                       a default GroupCtrl field based on the given configuration. In this case the default 48kHz
                                       sampling rate is assume.
                                       */
   VHD_AUDIOGROUPCTRL GroupCtrl;       /*! 
                                       RX : (OUT) Relevant if preceding AesChannelUserBlockValid field is TRUE. 
                                       Embedded audio control packet.

                                       TX : (IN if GroupCtrlValid is TRUE) Audio control packet to embed. 
                                       (OUT if GroupCtrlValid is FALSE) Audio control packet build and embedded by the API. 
                                       */

   VHD_AUDIOCHANNEL pAudioChannels[VHD_NBOFCHNPERGROUP];     /*! Array of 4 VHD_AUDIOCHANNEL structures representing the 4 audio channels of this group. */
   ULONG Reserved1;                      /*! Reserved for future use */
   ULONG Reserved2;                      /*! Reserved for future use */
   ULONG Reserved3;                      /*! Reserved for future use */
   ULONG Reserved4;                      /*! Reserved for future use */
} VHD_AUDIOGROUP;



/*_ VHD_AUDIOINFO ________________________________________________________*/
/*!
   Summary
   SDI slot audio information
   Description
   The VHD_AUDIOINFO structure contains information about
   embedded audio data of a SDI slot.
   
   It is used by the VHD_SlotExtractAudio and VHD_SlotEmbedAudio
   API functions.
   See Also
   VHD_SlotExtractAudio VHD_SlotEmbedAudio VHD_AUDIOGROUP        */
typedef struct _VHD_AUDIOINFO {
   VHD_AUDIOGROUP pAudioGroups[VHD_NBOFGROUP];     /*! Array of 4 VHD_AUDIOGROUP structures representing the 4 audio groups of the stream */
} VHD_AUDIOINFO;


#ifndef EXCLUDE_API_FUNCTIONS

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Audio
*/



/*** VHD_SlotExtractAudio ****************************************************/
/*!VHD_SlotExtractAudio@HANDLE@VHD_AUDIOINFO *
   Summary
   Audio data extraction
   Description
   This function extracts audio data from a SDI slot, 
   up to 16 audio channels.
   
   The concerned stream must be of processing mode including
   ancillary data handling

   Parameters
   SlotHandle :  Handle of the slot to work on
   pAudioInfo :  Pointer to a VHD_AUDIOINFO structure which
                 contains extraction audio configuration on call,
                 and extracted audio data on return.
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   Remarks
   A caller-allocated buffer is needed for each channel to
   capture. In stereo channel mode, audio samples of the same
   AES pair are interleaved in the same buffer (the buffer of
   the left (i.e. the first) channel of the audio pair). If the
   stereo channel mode is used for one channel of an audio pair,
   the ChannelMode and ChannelFormat fields of the two channels
   of this pair should be the same.
   
   
   
   The API computes the required size of this buffer based on
   the audio frame number of the embedded group control packet
   and the programmed video standard and clock divisor. If the
   buffer is smaller that this computed size,
   VHD_SlotExtractAudio doesn't extract audio and returns the
   required buffer size. Otherwise, VHD_SlotExtractAudio
   extracts audio in the buffer and returns the used buffer
   size.
   
   
   
   If the API cannot compute the required size because there is
   no group control packet or because of a "free run sampling
   rate", VHD_SlotExtractAudio extracts audio until the buffer
   is full.
   
   
   
   If the computed required buffer size is too small to extract
   all embedded samples, VHD_SlotExtractAudio extracts audio
   until the buffer is full and returns <link VHD_ERRORCODE, VHDERR_BUFFERTOOSMALL>.
   This could happen if the programmed clock divisor doesn't
   match the incoming one, or if the incoming stream is not
   standard.
   See Also
   VHD_LockSlotHandle VHD_AUDIOINFO VHD_SlotExtractAudioEx                      */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractAudio (HANDLE SlotHandle, VHD_AUDIOINFO *pAudioInfo);


/*** VHD_SlotExtractAudioEx ****************************************************/
/*!VHD_SlotExtractAudioEx
   Summary
   Audio data extraction extension
   Description
   This function extracts audio data from a SDI slot,
   up to 32 audio channels.

   The concerned stream must be of processing mode including
   ancillary data handling

   Parameters
   SlotHandle :   Handle of the slot to work on
   pAudioGroup :  Pointer to a vector of VHD_AUDIOGROUP structure which
                  contains extraction audio configuration on call,
                  and extracted audio data on return.
   AudioGroupNb : Audio group number to extract

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   Remarks
   A caller-allocated buffer is needed for each channel to
   capture. In stereo channel mode, audio samples of the same
   AES pair are interleaved in the same buffer (the buffer of
   the left (i.e. the first) channel of the audio pair). If the
   stereo channel mode is used for one channel of an audio pair,
   the ChannelMode and ChannelFormat fields of the two channels
   of this pair should be the same.
   
   
   
   The API computes the required size of this buffer based on
   the audio frame number of the embedded group control packet
   and the programmed video standard and clock divisor. If the
   buffer is smaller that this computed size,
   VHD_SlotExtractAudioEx doesn't extract audio and returns the
   required buffer size. Otherwise, VHD_SlotExtractAudioEx
   extracts audio in the buffer and returns the used buffer
   size.
   
   
   
   If the API cannot compute the required size because there is
   no group control packet or because of a "free run sampling
   rate", VHD_SlotExtractAudioEx extracts audio until the buffer
   is full.
   
   
   
   If the computed required buffer size is too small to extract
   all embedded samples, VHD_SlotExtractAudioEx extracts audio
   until the buffer is full and returns <link VHD_ERRORCODE, VHDERR_BUFFERTOOSMALL>.
   This could happen if the programmed clock divisor doesn't
   match the incoming one, or if the incoming stream is not
   standard.
   See Also
   VHD_LockSlotHandle VHD_AUDIOGROUP  VHD_SlotExtractAudio                          */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractAudioEx (HANDLE SlotHandle, VHD_AUDIOGROUP pAudioGroup[], ULONG AudioGroupNb);


/*** VHD_SlotEmbedAudio ******************************************************/
/*!VHD_SlotEmbedAudio@HANDLE@VHD_AUDIOINFO *
   Summary
   Audio data embedding
   Description
   This function embeds audio data in a SDI slot,
   up to 16 audio channels.

   The concerned stream must be of processing mode including
   ancillary data handling

   Parameters
   SlotHandle :  Handle of the slot to work on
   pAudioInfo :  Pointer to a VHD_AUDIOINFO structure which
                 contains embedding audio configuration and audio
                 data.

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   Remarks
   In stereo channel mode, audio samples of the same AES pair
   have to be interleaved in the same buffer (the buffer of the
   left (i.e. the first) channel of the audio pair). If the
   stereo channel mode is used for one channel of an audio pair,
   the ChannelMode and ChannelFormat fields of the two channels
   of this pair should be the same.
   
   
   
   If the audio sample rate of an audio group (SD: audio pair)
   is not an entire multiple of the video frame rate (ex: 48kHz
   audio sampling rate with 29.97Hz video frame rate), the API
   sets automatically the AudioFrameNb (SD: pAudioFrameNb) value
   of this group (SD: pair) on return for the next
   VHD_SlotEmbedAudio call. So, the caller should pay attention
   if it uses an other VHD_AUDIOINFO structure on the next
   VHD_SlotEmbedAudio call.
   
   
   
   48kHz, 44.1kHz and 32kHz are valid sampling rate for HD
   embedding. Only 48kHz is valid for SD embedding.
   
   Freerun is invalid for both HD and SD
   See Also
   VHD_LockSlotHandle VHD_AUDIOINFO VHD_SlotEmbedAudioEx                */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedAudio (HANDLE SlotHandle, VHD_AUDIOINFO *pAudioInfo);


/*** VHD_SlotEmbedAudioEx ******************************************************/
/*!VHD_SlotEmbedAudioEx
   Summary
   Audio data embedding extension
   Description
   This function embeds audio data in a SDI slot,
   up to 32 audio channels.

   The concerned stream must be of processing mode including
   ancillary data handling

   Parameters
   SlotHandle :   Handle of the slot to work on
   pAudioGroup :  Pointer to a vector of VHD_AUDIOGROUP structure which
                  contains embedding audio configuration and audio
                  data.
   AudioGroupNb : Audio group number to embed

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   Remarks
   In stereo channel mode, audio samples of the same AES pair
   have to be interleaved in the same buffer (the buffer of the
   left (i.e. the first) channel of the audio pair). If the
   stereo channel mode is used for one channel of an audio pair,
   the ChannelMode and ChannelFormat fields of the two channels
   of this pair should be the same.
   
   
   
   If the audio sample rate of an audio group (SD: audio pair)
   is not an entire multiple of the video frame rate (ex: 48kHz
   audio sampling rate with 29.97Hz video frame rate), the API
   sets automatically the AudioFrameNb (SD: pAudioFrameNb) value
   of this group (SD: pair) on return for the next
   VHD_SlotEmbedAudioEx call. So, the caller should pay attention
   if it uses an other vector of VHD_AUDIOGROUP structure on the next
   VHD_SlotEmbedAudioEx call.
   
   
   
   48kHz, 44.1kHz and 32kHz are valid sampling rate for HD
   embedding. Only 48kHz is valid for SD embedding.
   
   Freerun is invalid for both HD and SD
   See Also
   VHD_LockSlotHandle VHD_AUDIOGROUP VHD_SlotEmbedAudio           */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedAudioEx (HANDLE SlotHandle, VHD_AUDIOGROUP pAudioGroup[], ULONG AudioGroupNb);


/*** VHD_GetNbSamples ********************************************************/
/*!VHD_GetNbSamples@VHD_VIDEOSTANDARD@VHD_CLOCKDIVISOR@VHD_AUDIOSAMPLINGRATE@ULONG
   Summary
   Number of samples in a frame
   Description
   This helper function returns the number of samples in a
   frame, depending on the video standard, audio sampling rate
   and audio frame number
   Parameters
   VideoStd :      Video Standard
   ClockDivisor :  Clock divisor
   SamplingRate :  Audio sampling rate
   AudioFrameNb :  Audio frame number. Not relevant if the audio
                   \sample rate is an entire multiple of the
                   video frame rate.
   Returns
   The function returns the number of audio samples in the frame
   
   Remarks
   The audio frame number argument is only useful in video standards where the 
   number of embedded audio samples varies from frames to frames (NTSC for instance). 
   In all other cases or if you prefer to get the maximum number of samples 
   according to the given video standard, set the AudioFrameNb parameter to zero
   
   See Also
   VHD_VIDEOSTANDARD VHD_CLOCKDIVISOR VHD_AUDIOSAMPLINGRATE      */
VIDEOMASTER_HD_API ULONG VHD_GetNbSamples (VHD_VIDEOSTANDARD VideoStd, VHD_CLOCKDIVISOR ClockDivisor, VHD_AUDIOSAMPLINGRATE SamplingRate, ULONG AudioFrameNb);

/*** VHD_GetNbSamples ********************************************************/
/*!VHD_GetNbSamplesEx
   Summary
   Number of samples in a frame or a field
   Description
   This helper function returns the number of samples in a
   frame, depending on the video standard, audio sampling rate
   and audio frame number
   Parameters
   VideoStd :      Video Standard
   ClockDivisor :  Clock divisor
   SamplingRate :  Audio sampling rate
   AudioFrameNb :  Audio frame number. Not relevant if the audio
                   \sample rate is an entire multiple of the
                   video frame rate.
   FieldMode : TRUE if field mode
   EvenField : TRUE if even field, FALSE if odd field

   Returns
   The function returns the number of audio samples in the frame
   
   Remarks
   The audio frame number argument is only useful in video standards where the 
   number of embedded audio samples varies from frames to frames (NTSC for instance). 
   In all other cases or if you prefer to get the maximum number of samples 
   according to the given video standard, set the AudioFrameNb parameter to zero
   
   See Also
   VHD_VIDEOSTANDARD VHD_CLOCKDIVISOR VHD_AUDIOSAMPLINGRATE      */
VIDEOMASTER_HD_API ULONG VHD_GetNbSamplesEx (VHD_VIDEOSTANDARD VideoStd, VHD_CLOCKDIVISOR ClockDivisor, VHD_AUDIOSAMPLINGRATE SamplingRate, ULONG AudioFrameNb, BOOL32 FieldMode, BOOL32 EvenField);


/*** VHD_GetBlockSize ********************************************************/
/*!
   Summary
   \Sample block size information

   Description
   This helper function returns the block size of a sample for a
   given format and mode

   Parameters
   Format :  Audio sample format
   Mode :    Audio mode

   Returns
   The function returns the block size

   See Also
   VHD_AUDIOFORMAT VHD_AUDIOMODE                                
*/
VIDEOMASTER_HD_API ULONG VHD_GetBlockSize (VHD_AUDIOFORMAT Format, VHD_AUDIOMODE Mode);

#endif

#ifdef __cplusplus
}
#endif

#endif // _VIDEOMASTERHD_SDI_AUDIO_H_
