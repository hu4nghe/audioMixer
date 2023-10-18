/*! VideomasterHD_Ip_ST2110_30_Board.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : lr                             Date: 2018/01/19

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_IP_ST2110_30_H_
#define _VIDEOMASTERHD_IP_ST2110_30_H_

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_ST2110_30
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_ST2110_30
*/

/*_ VHD_ST2110_30_STREAMPROPERTY _____________________________________*/
/*!
   Summary
   VideoMaster ST2110 30 streams properties
   Description
   The VHD_ST2110_30_STREAMPROPERTY enumeration lists all the
   ST2110 stream properties available on IP board.
   
   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_ST2110_30_STREAMPROPERTY
{
   VHD_ST2110_30_SP_FORMAT=ENUMBASE_ST2110_30,        /*!_VHD_ST2110_30_STREAMPROPERTY::VHD_ST2110_30_SP_FORMAT
                                                         Audio sample encoding (see VHD_ST2110_30_FORMAT)
                                                      */
   VHD_ST2110_30_SP_SAMPLING_RATE,                    /*!_VHD_ST2110_30_STREAMPROPERTY::VHD_ST2110_30_SP_SAMPLING_RATE
                                                         Audio sampling rate (see VHD_ST2110_30_SAMPLING_RATE)
                                                      */
   VHD_ST2110_30_SP_NB_CHANNELS,                      /*!_VHD_ST2110_30_STREAMPROPERTY::VHD_ST2110_30_SP_CHANNELS_NB
                                                         Number of audio channels
                                                      */
   VHD_ST2110_30_SP_PACKET_TIME,                      /*!_VHD_ST2110_30_STREAMPROPERTY::VHD_ST2110_30_SP_PACKET_TIME
                                                         Packet Time (see VHD_ST2110_30_SAMPLING_RATE)
                                                      */
   VHD_ST2110_30_SP_SAMPLES_NUMBER_PER_CHANNEL,       /*!_VHD_ST2110_30_STREAMPROPERTY::VHD_ST2110_30_SP_SAMPLES_NUMBER_PER_CHANNEL
                                                         Audio samples number per channel,
                                                         default is 48 (minimum is the packet time size, maximum is 1000000)
                                                      */
   VHD_ST2110_30_SP_ONBOARDBUFFER_SAMPLE_FILLING,     /*!_VHD_ST2110_30_STREAMPROPERTY::VHD_ST2110_30_SP_ONBOARDBUFFER_SAMPLE_FILLING
                                                         Number of bytes that could not have been transfered yet and waiting to be transfered next,
                                                         read-only.
                                                      */
   NB_VHD_ST2110_30_STREAMPROPERTY
} VHD_ST2110_30_STREAMPROPERTY;

/*_ VHD_ST2110_30_FORMAT ______________________________________*/
/*!
   Summary
   VideoMaster supported 2110 Audio sample encoding formats
   Description
   The VHD_ST2110_30_FORMAT enumeration lists all the supported
   audio sample encoding formats for ST2110 IP streams.

   These values are used in VHD_ST2110_BRD_SP_30_FORMAT stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_BRD_SP_30_FORMAT>
*/
typedef enum _VHD_ST2110_30_FORMAT
{
   VHD_ST2110_30_FORMAT_L16,     /*! 16-bit sample */
   VHD_ST2110_30_FORMAT_L24,     /*! 24-bit sample */
   NB_VHD_ST2110_30_FORMAT
} VHD_ST2110_30_FORMAT;

/*_ VHD_ST2110_30_SAMPLING_RATE ______________________________________*/
/*!
   Summary
   VideoMaster supported 2110 Audio Sampling Rates
   Description
   The VHD_ST2110_30_SAMPLING_RATE enumeration lists all the supported
   Audio Sampling Rates for ST2110 IP streams.

   These values are used in VHD_ST2110_BRD_SP_30_SAMPLING_RATE stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_BRD_SP_30_SAMPLING_RATE>
*/
typedef enum _VHD_ST2110_30_SAMPLING_RATE
{
   VHD_ST2110_30_SAMPLINGRATE_48KHZ,      /*! 48kHz sampling rate */
   VHD_ST2110_30_SAMPLINGRATE_96KHZ,      /*! 96kHz sampling rate */
   NB_VHD_ST2110_30_SAMPLING_RATE
} VHD_ST2110_30_SAMPLING_RATE;

/*_ VHD_ST2110_30_PACKET_TIME ______________________________________*/
/*!
   Summary
   VideoMaster supported 2110 Audio Packet Times
   Description
   The VHD_ST2110_30_PACKET_TIME enumeration lists all the supported
   Audio Packet Times for ST2110 IP streams.

   These values are used in VHD_ST2110_BRD_SP_30_PACKET_TIME stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_BRD_SP_30_PACKET_TIME>
*/
typedef enum _VHD_ST2110_30_PACKET_TIME
{
   VHD_ST2110_30_PACKETTIME_1MS,       /*! 1ms packet time */
   VHD_ST2110_30_PACKETTIME_125US,     /*! 125us packet time */
   NB_VHD_ST2110_30_PACKET_TIME
} VHD_ST2110_30_PACKET_TIME;

/*_ VHD_ST2110_30_CHANNEL_TYPE ________________________________________________*/
/*!
   Summary
   VideoMaster supported ST2110-30 channel types
   Description
   The VHD_ST2110_30_CHANNEL_TYPE enumeration lists all the supported ST2110-30
   channel types

   These values are used in VHD_SetChannelsType and VHD_GetChannelsType functions.
   See Also
   <link VHD_SetChannelsType, VHD_GetChannelsType>      */
typedef enum _VHD_ST2110_30_CHANNEL_TYPE
{
   VHD_ST2110_30_CHANNELTYPE_MONO,        /*! Mono channel type */
   VHD_ST2110_30_CHANNELTYPE_STEREO,      /*! Stereo channel type */
   NB_VHD_ST2110_30_CHANNELTYPE
}VHD_ST2110_30_CHANNEL_TYPE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Ip_ST2110_30
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*** VHD_GetSlotRTPAudioTimeStamp ****************************************************/
/*!
   Summary
   Get slot RTP audio timestamp
   Description
   This function gets the RTP audio timestamp of a given slot handle.

   Parameters
   SlotHandle :         Handle of the slot to work with
   pSlotTimestamp :     Pointer to a caller\-allocated variable 
                           where the timestamp is returned

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_GetSlotRTPAudioTimeStamp(HANDLE SlotHandle, ULONG *pSlotTimestamp);

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_IP_ST2110_30_H_