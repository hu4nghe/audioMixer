/*! VideomasterHD_Ip_S2022_Board.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : ja                             Date: 2016/06/16

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_IP_S2022_BOARD_H_
#define _VIDEOMASTERHD_IP_S2022_BOARD_H_

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_S2022_Board
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_S2022_Board
*/

/*_ VHD_S2022_BRD_STREAMPROPERTY ______________________________________________*/
/*!
   Summary
   VideoMaster S2022 streams properties
   Description
   The VHD_S2022_BRD_STREAMPROPERTY enumeration lists all the
   S2022 stream properties available on IP board.
   
   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_S2022_BRD_STREAMPROPERTY
{
	VHD_S2022_BRD_SP_5_FEC=ENUMBASE_S2022_BRD,	                     /*! If FALSE, Forward Error Correction is disabled (default is TRUE) */ 
	VHD_S2022_BRD_SP_5_FEC_BLOC_ALIGNMENT,	                           /*! If TRUE, Forward Error Correction Arrangement will be Block-Aligned (default is TRUE) */ 
	VHD_S2022_BRD_SP_5_FEC_LEVEL_B,			                           /*! If TRUE, Forward Error Correction Level B (two FEC streams) is enabled (default is TRUE) */
	VHD_S2022_BRD_SP_5_FEC_COLUMN_SIZE,		                           /*! Column size for the Forward Error Correction (default is 77) */ 
   VHD_S2022_BRD_SP_5_FEC_ROW_SIZE,			                           /*! Row size for the Forward Error Correction (default is 77) */  
   VHD_S2022_BRD_SP_6_MAP,						                           /*! High Bit Rate Media Payload Header MAP field */  
   VHD_S2022_BRD_SP_6_FRAME,					                           /*! High Bit Rate Media Payload Header FRAME field */
   VHD_S2022_BRD_SP_6_FRATE,					                           /*! High Bit Rate Media Payload Header FRATE field */ 
   VHD_S2022_BRD_SP_6_SAMPLE,					                           /*! High Bit Rate Media Payload Header SAMPLE field */ 
   VHD_S2022_BRD_SP_7_RTP_TIMESTAMP_DIFF,	                           /*! RTP Timestamp difference between the master and Seamless Protection Switching stream */
	NB_VHD_S2022_BRD_STREAMPROPERTY
}VHD_S2022_BRD_STREAMPROPERTY ;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Ip_S2022_Board
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_IP_S2022_BOARD_H_