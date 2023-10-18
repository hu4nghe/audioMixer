/*! VideomasterHD_Dv_Audio.h

Copyright (c) 2009, DELTACAST. All rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
PURPOSE.

Project : Videomaster

Package :

Company : DELTACAST

Author  : ac                             Date: 2018/02/28

Purpose : DV stands for « Digital Video » and regroups the following technologies: DVI, HDMI, DisplayPort.

*/

#ifndef _VIDEOMASTERHD_DV_AUDIO_H_
#define _VIDEOMASTERHD_DV_AUDIO_H_

#ifdef __cplusplus
extern "C" {
#endif
#ifndef VIDEOMASTER_HD_API
#if defined WIN32 || defined __CYGWIN__
#ifdef BUILDING_API
#ifdef __GNUC__
#define VIDEOMASTER_HD_API __attribute__ ((dllexport))
#else
#define VIDEOMASTER_HD_API __declspec(dllexport)
#endif
#else
#ifdef __GNUC__
#define VIDEOMASTER_HD_API __attribute__ ((dllimport))
#else
#define VIDEOMASTER_HD_API __declspec(dllimport)
#endif
#endif
#else
#include <stdint.h>
#if __GNUC__ >= 4
#define VIDEOMASTER_HD_API __attribute__ ((visibility ("default")))
#else
#define VIDEOMASTER_HD_API
#endif
#endif
#endif

   /*_ CONSTANTS ________________________________________________________________
   //
   // This section defines the different constants used by VideomasterHD_Dv_Audio
   */

#define VHD_DV_AUDIO_MAXNBCHANNELS     8


   /*_ ENUMERATIONS _____________________________________________________________
   //
   // This section defines the different enumerations used by VideomasterHD_Dv_Audio
   */



   /*_ VHD_DVAUDIOFORMAT  _________________________________________________________*/
   /*!
   Summary
   DV audio formats
   Description
   The VHD_DVAUDIOFORMAT enumeration lists all the available DV
   audio sample formats                                         */
   typedef enum _VHD_DVAUDIOFORMAT {
      VHD_DVAUDIOFORMAT_16,                     /*! PCM sample (16 bits) */
      VHD_DVAUDIOFORMAT_20,                     /*! PCM sample (20 bits) */
      VHD_DVAUDIOFORMAT_24,                     /*! PCM sample (24 bits) */
      NB_VHD_DVAUDIOFORMAT
   } VHD_DVAUDIOFORMAT;

   /*_ VHD_DVAUDIOMODE  _________________________________________________________*/
   /*!
   Summary
   DV audio formats
   Description
   The VHD_DVAUDIOMODE enumeration lists all the available DV
   audio channel modes                                         */
   typedef enum _VHD_DV_AUDIO_MODE {
      VHD_DV_AUDIO_MODE_OFF,                    /*! No channel information */
      VHD_DV_AUDIO_MODE_MONO,                   /*! Mono channel mode */
      VHD_DV_AUDIO_MODE_STEREO,                 /*! Stereo channel mode */
      NB_VHD_DV_AUDIO_MODE
   }VHD_DV_AUDIO_MODE;

#ifndef EXCLUDE_API_FUNCTIONS

   /*_ API FUNCTIONS ____________________________________________________________
   //
   // This section defines the different API functions exported by VideomasterHD_Dv_Audio
   */

   /*** VHD_SlotExtractDvPCMAudio ****************************************************/
   /*!
   Summary
   DV Audio data extraction
   Description
   This function extracts PCM audio data from an DV slot.

   The concerned stream must be of processing mode including
   audio data handling
   Parameters
   SlotHandle :  Handle of the slot to work on
   AudioFormat:  audio data bit depth (16, 20 or 24-bit)
   ChannelMask:  mask of the channels that must be extracted
   pData :       Pointer to a caller\-allocated array of byte
   receiving the audio data
   pBufferSize : Pointer to a caller\-allocated variable
   receiving the buffer size
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)

   Remarks
   The required size of this buffer can be calculated based on
   the audio format, the audio channel mask,
   the incoming audio sampling rate and the video frame rate.
   If the buffer is smaller than the required size,
   VHD_SlotExtractDvPCMAudio doesn't extract audio and returns the
   required buffer size. Otherwise, VHD_SlotExtractDvPCMAudio
   extracts audio in the buffer and returns the used buffer
   size.

   See Also
   VHD_LockSlotHandle VHD_DVAUDIOFORMAT                                                  */
   VIDEOMASTER_HD_API ULONG VHD_SlotExtractDvPCMAudio(HANDLE SlotHandle, VHD_DVAUDIOFORMAT AudioFormat, UBYTE ChannelMask, UBYTE *pData, ULONG *pBufferSize);

   /*** VHD_SlotExtractDvNonPCMAudio ****************************************************/
   /*!
   Summary
   DV Audio data extraction
   Description
   This function extracts non-PCM audio data from an DV slot.

   The concerned stream must be of processing mode including
   audio data handling
   Parameters
   SlotHandle :  Handle of the slot to work on
   pData :       Pointer to a caller\-allocated array of byte
   receiving the audio data
   pBufferSize : Pointer to a caller\-allocated variable
   receiving the buffer size
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)

   Remarks
   The required size of this buffer can be calculated based on
   the audio format, the audio channel mask,
   the incoming audio sampling rate and the video frame rate.
   If the buffer is smaller than the required size,
   VHD_SlotExtractDvNonPCMAudio doesn't extract audio and returns the
   required buffer size. Otherwise, VHD_SlotExtractDvNonPCMAudio
   extracts audio in the buffer and returns the used buffer
   size.

   See Also
   VHD_LockSlotHandle                                                  */
   VIDEOMASTER_HD_API ULONG VHD_SlotExtractDvNonPCMAudio(HANDLE SlotHandle, UBYTE *pData, ULONG *pBufferSize);
      
   /*** VHD_SlotEmbedDvPCMAudio ****************************************************/
   /*!
   Summary
   DV Audio data embedding (PCM)
   Description
   This function embeds PCM audio data into an DV slot.

   The concerned stream must be of processing mode including
   audio data handling.
   Parameters
   SlotHandle :  Handle of the slot to work on
   pAudioModes : Array of audio modes for each audio channel (see VHD_DV_AUDIO_MODE).
   pData :       Pointer to a caller\-allocated array of byte
                  containing the audio data.
   BufferSize : Size of the data buffer.
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)

   See Also
   VHD_LockSlotHandle VHD_DVAUDIOFORMAT
   */
   VIDEOMASTER_HD_API ULONG VHD_SlotEmbedDvPCMAudio(HANDLE SlotHandle, VHD_DV_AUDIO_MODE pAudioModes[VHD_DV_AUDIO_MAXNBCHANNELS], UBYTE *pData, ULONG BufferSize);
   
   /*** VHD_SlotEmbedDvNonPCMAudio ****************************************************/
   /*!
   Summary
   DV Audio data embedding (non-PCM)
   Description
   This function embeds non-PCM audio data into an DV slot.

   The concerned stream must be of processing mode including
   audio data handling.
   Parameters
   SlotHandle :  Handle of the slot to work on
   pData :       Pointer to a caller\-allocated array of byte
                  containing the audio data.
   BufferSize : Size of the data buffer.
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)

   See Also
   VHD_LockSlotHandle VHD_DVAUDIOFORMAT
   */
   VIDEOMASTER_HD_API ULONG VHD_SlotEmbedDvNonPCMAudio(HANDLE SlotHandle, UBYTE *pData, ULONG BufferSize);

#endif

#ifdef __cplusplus
}
#endif

#endif //_VIDEOMASTERHD_DV_AUDIO_H_