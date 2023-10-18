/*! VideomasterHD_Ip_ST2110_Board.h

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


#ifndef _VIDEOMASTERHD_IP_ST2110_BOARD_H_
#define _VIDEOMASTERHD_IP_ST2110_BOARD_H_

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_ST2110_Board
*/
#define VHD_IP_2110_DATA_VIDEO        0x00000001  /*! Video data */
#define VHD_IP_2110_DATA_AUDIO        0x00000002  /*! Audio data */
#define VHD_IP_2110_DATA_ANC          0x00000004  /*! ANC data */

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_ST2110_Board
*/

/*_ VHD_ST2110_STREAMPROCMODE _________________________________________*/
/*!
   Summary
   VideoMaster ST2110 IP streams processing modes

   Description
   The VHD_ST2110_STREAMPROCMODE enumeration lists all the ST2110 IP
   stream processing modes.

   These values are used during VHD_OpenStreamHandle function calls.

   See Also
   VHD_OpenStreamHandle
*/
typedef enum _VHD_ST2110_STREAMPROCMODE
{
   VHD_ST2110_STPROC_DISJOINED_VIDEO=ENUMBASE_ST2110_BRD,   /*!_VHD_ST2110_STREAMPROCMODE::VHD_ST2110_STPROC_DISJOINED_VIDEO
                                                               Single Video processing (default)
                                                            */
   VHD_ST2110_STPROC_DISJOINED_AUDIO,                       /*!_VHD_ST2110_STREAMPROCMODE::VHD_ST2110_STPROC_DISJOINED_AUDIO
                                                               Single Audio processing (default)
                                                            */
   VHD_ST2110_STPROC_DISJOINED_ANC,                         /*!_VHD_ST2110_STREAMPROCMODE::VHD_ST2110_STPROC_DISJOINED_ANC
                                                               Single Anc processing (default)
                                                            */
   VHD_ST2110_STPROC_JOINED,                                /*!_VHD_ST2110_STREAMPROCMODE::VHD_ST2110_STPROC_JOINED
                                                               Coupled processing (video, audio and ANC)
                                                            */
   NB_VHD_ST2110_STREAMPROCMODE
} VHD_ST2110_STREAMPROCMODE;

/*_ VHD_ST2110_BUFFERTYPE _____________________________________________*/
/*!
   Summary
   VideoMaster ST2110 IP buffer type
   Description
   The VHD_ST2110_BUFFERTYPE enumeration lists all the ST2110 IP buffer
   types.

   These values are used during VHD_GetSlotBuffer function calls
   See Also
   VHD_GetSlotBuffer, VHD_STREAMTYPE
*/
typedef enum _VHD_ST2110_BUFFERTYPE
{
   VHD_ST2110_BT_VIDEO=0,     /*!_VHD_ST2110_BUFFERTYPE::VHD_ST2110_BT_VIDEO
                                 ST2110 Video frames buffer type
                              */
   VHD_ST2110_BT_AUDIO,       /*!_VHD_ST2110_BUFFERTYPE::VHD_ST2110_BT_AUDIO
                                 ST2110 Audio frames buffer type
                              */
   VHD_ST2110_BT_ANC_C,       /*!_VHD_ST2110_BUFFERTYPE::VHD_ST2110_BT_ANC_C
                                 ST2110 ANC-C buffer type
                              */
   VHD_ST2110_BT_ANC_Y,       /*!_VHD_ST2110_BUFFERTYPE::VHD_ST2110_BT_ANC_Y
                                 ST2110 ANC-Y buffer type
                              */
   NB_VHD_ST2110_BUFFERTYPE
} VHD_ST2110_BUFFERTYPE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Ip_ST2110_Board
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif
   /*** VHD_GetSlotRTPTimeStamp ***************************************************/
   /*!VHD_GetSlotRTPTimeStamp
   Summary
      Gets the slot RTP timestamp
   Description
      Retrieves the RTP timestamp associated to the given slot.
   Parameters
      SlotHandle :      Handle of the slot to operate on
      pSlotTimestamp :  Pointer to a caller\-allocated variable
                           receiving the RTP timestamp
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
   ULONG VIDEOMASTER_HD_API VHD_GetSlotRTPTimeStamp(HANDLE SlotHandle, ULONG *pSlotTimestamp);

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_IP_ST2110_BOARD_H_