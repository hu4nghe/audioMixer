/*! VideomasterHD_Ip_ST2110_20.h

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


#ifndef _VIDEOMASTERHD_IP_ST2110_20_H_
#define _VIDEOMASTERHD_IP_ST2110_20_H_

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_ST2110_20
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_ST2110_20
*/

/*_ VHD_ST2110_20_STREAMPROPERTY _____________________________________*/
/*!
   Summary
   VideoMaster ST2110 20 streams properties
   Description
   The VHD_ST2110_20_STREAMPROPERTY enumeration lists all the
   ST2110 stream properties available on IP board.
   
   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_ST2110_20_STREAMPROPERTY
{
   VHD_ST2110_20_SP_VIDEO_STANDARD=ENUMBASE_ST2110_20,      /*!_VHD_ST2110_20_STREAMPROPERTY::VHD_ST2110_20_SP_VIDEO_STANDARD
                                                               Logical stream video standard selection (see VHD_ST2110_20_VIDEO_STANDARD)
                                                            */
   VHD_ST2110_20_SP_SAMPLING,                               /*!_VHD_ST2110_20_STREAMPROPERTY::VHD_ST2110_20_SP_SAMPLING
                                                               Color difference signal sub-sampling structure for the network stream reception or transmission (see VHD_ST2110_20_SAMPLING)
                                                            */ 
   VHD_ST2110_20_SP_DEPTH,                                  /*!_VHD_ST2110_20_STREAMPROPERTY::VHD_ST2110_20_SP_DEPTH
                                                                Number of bits per sample for the network stream reception or transmission (see VHD_ST2110_20_DEPTH)
                                                            */ 
   VHD_ST2110_20_SP_TRAFFIC_SHAPING_MODE,                   /*!_VHD_ST2110_20_STREAMPROPERTY::VHD_ST2110_20_SP_TRAFFIC_SHAPING_MODE
                                                               Traffic Shaping Mode (see VHD_ST2110_20_TRAFFIC_SHAPING_MODE)
                                                            */
   VHD_ST2110_20_SP_TR_OFFSET,                              /*!_VHD_ST2110_20_STREAMPROPERTY::VHD_ST2110_20_SP_TR_OFFSET
                                                               TR Offset value (in µs)
                                                            */
   NB_VHD_ST2110_20_STREAMPROPERTY
} VHD_ST2110_20_STREAMPROPERTY;

/*_ VHD_ST2110_20_VIDEO_STANDARD ______________________________________*/
/*!
   Summary
   VideoMaster supported ST2110 video standards
   Description
   The VHD_ST2110_20_VIDEO_STANDARD enumeration lists all the supported
   video standards for ST2110 IP streams.

   These values are used in VHD_ST2110_BRD_SP_20_VIDEO_STANDARD stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_BRD_SP_20_VIDEO_STANDARD>
*/
typedef enum _VHD_ST2110_20_VIDEO_STANDARD
{
   VHD_ST2110_20_VIDEOSTD_720x480i59,     /*! 720x480i @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_720x576i50,     /*! 720x576i @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_1280x720p50,    /*! 1280x720p @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_1280x720p59,    /*! 1280x720p @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_1280x720p60,    /*! 1280x720p @ 60Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080i50,   /*! 1920x1080i @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080i59,   /*! 1920x1080i @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080i60,   /*! 1920x1080i @ 60Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p23,   /*! 1920x1080p @ 23Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p24,   /*! 1920x1080p @ 24Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p25,   /*! 1920x1080p @ 25Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p29,   /*! 1920x1080p @ 29Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p30,   /*! 1920x1080p @ 30Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p50,   /*! 1920x1080p @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p59,   /*! 1920x1080p @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_1920x1080p60,   /*! 1920x1080p @ 60Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p23,   /*! 2048x1080p @ 23Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p24,   /*! 2048x1080p @ 24Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p25,   /*! 2048x1080p @ 25Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p29,   /*! 2048x1080p @ 29Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p30,   /*! 2048x1080p @ 30Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p47,   /*! 2048x1080p @ 47Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p48,   /*! 2048x1080p @ 48Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p50,   /*! 2048x1080p @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p59,   /*! 2048x1080p @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_2048x1080p60,   /*! 2048x1080p @ 60Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p25,   /*! 3840x2160p @ 25Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p29,   /*! 3840x2160p @ 29Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p30,   /*! 3840x2160p @ 30Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p50,   /*! 3840x2160p @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p59,   /*! 3840x2160p @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p60,   /*! 3840x2160p @ 60Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p25,   /*! 4096x2160p @ 25Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p29,   /*! 4096x2160p @ 29Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p30,   /*! 4096x2160p @ 30Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p50,   /*! 4096x2160p @ 50Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p59,   /*! 4096x2160p @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p60,   /*! 4096x2160p @ 60Hz */
   VHD_ST2110_20_VIDEOSTD_720x487i59,     /*! 720x487i @ 59Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p23,   /*! 3840x2160p @ 23Hz */
   VHD_ST2110_20_VIDEOSTD_3840x2160p24,   /*! 3840x2160p @ 24Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p23,   /*! 4096x2160p @ 23Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p24,   /*! 4096x2160p @ 24Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p47,   /*! 4096x2160p @ 47Hz */
   VHD_ST2110_20_VIDEOSTD_4096x2160p48,   /*! 4096x2160p @ 48Hz */
   NB_VHD_ST2110_20_VIDEO_STANDARD
} VHD_ST2110_20_VIDEO_STANDARD;

/*_ _VHD_ST2110_20_SAMPLING ___________________________________________*/
/*!
   Summary
   VideoMaster supported ST2110 sampling types
   Description
   The VHD_ST2110_20_SAMPLING enumeration lists all the supported
   sampling types for ST2110 IP streams.
   These values are used in VHD_ST2110_BRD_SP_20_SAMPLING stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_BRD_SP_20_SAMPLING>
*/
typedef enum _VHD_ST2110_20_SAMPLING
{
   VHD_ST2110_20_SAMPLING_YUV_422,     /*! YUV 4:2:2 sampling */
   NB_VHD_ST2110_20_SAMPLING
} VHD_ST2110_20_SAMPLING;

/*_ VHD_ST2110_20_DEPTH ______________________________________*/
/*!
   Summary
   VideoMaster supported ST2110 sample depths
   Description
   The VHD_ST2110_20_DEPTH enumeration lists all the supported
   sample depths for ST2110 IP streams.
   These values are used in VHD_ST2110_BRD_SP_20_DEPTH stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_BRD_SP_20_DEPTH>
*/
typedef enum _VHD_ST2110_20_DEPTH
{
   VHD_ST2110_20_DEPTH_8BIT,     /*! 8-bit sample depth */
   VHD_ST2110_20_DEPTH_10BIT,    /*! 10-bit sample depth */
   NB_VHD_ST2110_20_DEPTH
} VHD_ST2110_20_DEPTH;

/*_ _VHD_ST2110_20_TRAFFIC_SHAPING_MODE __________________________*/
/*!
   Summary
   VideoMaster supported ST2110 traffic shaping modes
   Description
   The VHD_ST2110_20_TRAFFIC_SHAPING_MODE enumeration lists all the supported
   traffic shaping modes for ST2110 IP streams.

   These values are used in VHD_ST2110_20_TRAFFIC_SHAPING_MODE stream
   property.
   See Also
   <link _VHD_ST2110_BRD_STREAMPROPERTY, VHD_ST2110_20_SP_TRAFFIC_SHAPING_MODE>
*/
typedef enum _VHD_ST2110_20_TRAFFIC_SHAPING_MODE
{
   VHD_ST2110_20_TRAFFIC_SHAPING_MODE_LINEAR,   /*! Linear traffic shaping mode */
   VHD_ST2110_20_TRAFFIC_SHAPING_MODE_GAPPED,   /*! Gapped traffic shaping mode */
   NB_VHD_ST2110_20_TRAFFIC_SHAPING_MODE
} VHD_ST2110_20_TRAFFIC_SHAPING_MODE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Ip_ST2110_20
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif
   
/*** VHD_ST2110_20_AutoDetect ****************************************************/
/*!
   Summary
   Get auto-detected stream property
   Description
   This function gets the auto-detected value of the given property.
   In this case, auto-detected means that based on the analysis of
   the incoming traffic which matches the configuration of the given
   reception stream some properties can be deducted.

   Parameters
   StrmHandle :   Handle of the stream to work with
   Property :     Property to auto-detect
   pValue :       Pointer to a caller\-allocated variable 
                     where the value of the property is returned

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
*/
ULONG VIDEOMASTER_HD_API VHD_ST2110_20_AutoDetect(HANDLE StrmHandle, VHD_ST2110_20_STREAMPROPERTY Property, ULONG* pValue);

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_IP_ST2110_20_H_