/*! VideomasterHD_Dv.h

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


#ifndef _VIDEOMASTERHD_DV_H_
#define _VIDEOMASTERHD_DV_H_


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Dv
*/

/*_ VideomasterHD_Dv DATA TYPE __________________________________________________*/
/*! Data types bit masks. These constants define data type bit masks for the VHD_CORE_SP_MUTED_DATA_MASK stream property */
#define VHD_DV_DATA_VIDEO          0x00000001  /*! Video data */
#define VHD_DV_DATA_AUDIO          0x00000002  /*! Audio data */
#define VHD_DV_DATA_THUMBNAIL      0x00000004  /*! Thumbnail data */

#define VHD_DV_STPROC_DEFAULT      VHD_DV_STPROC_DISJOINED_VIDEO /*! For compatibility */

/*_ DV audio InfoFrame definition __________________________________________________*/
/*! Define VHD_DV_AUDIO_INFOFRAME fields */
/*! ChannelCount */
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_REF_STREAM_HEADER              0
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_2                              1
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_3                              2
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_4                              3
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_5                              4
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_6                              5
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_7                              6
#define VHD_DV_AUDIO_INFOFRAME_CHANNEL_COUNT_8                              7

/*! CodingType */
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_REF_STREAM_HEADER                0
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_PCM                              1
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_AC3                              2
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_MPEG1                            3
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_MP3                              4
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_MPEG2                            5
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_AACLC                            6
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_DTS                              7
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_ATRAC                            8
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_DSD                              9
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_EAC3                             10
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_DTSHD                            11
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_MLP                              12
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_DST                              13
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_WMAPRO                           14
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_REF_AUDIO_CXT                    15

/*! SampleSize */
#define VHD_DV_AUDIO_INFOFRAME_SAMPLE_SIZE_REF_STREAM_HEADER                0
#define VHD_DV_AUDIO_INFOFRAME_SAMPLE_SIZE_16_BITS                          1
#define VHD_DV_AUDIO_INFOFRAME_SAMPLE_SIZE_20_BITS                          2
#define VHD_DV_AUDIO_INFOFRAME_SAMPLE_SIZE_24_BITS                          3

/*! SamplingFrequency */
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_REF_STREAM_HEADER              0
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_32000HZ                        1
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_44100HZ                        2
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_48000HZ                        3
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_88200HZ                        4
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_96000HZ                        5
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_176400HZ                       6
#define VHD_DV_AUDIO_INFOFRAME_SAMPLING_FREQ_192000HZ                       7

/*! CodingTypeExt */
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_EXT_REF_CT                       0
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_EXT_HEAAC                        1
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_EXT_HEAACV2                      2
#define VHD_DV_AUDIO_INFOFRAME_CODING_TYPE_EXT_MPEGSURROUND                 3

/*! SpeakerPlacement */
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR                      0
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE                  1
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC                   2
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC               3
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RC                   4
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RC               5
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RC                6
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RC            7
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RL_RR                8
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RL_RR            9
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR             10
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR         11
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RL_RR_RC             12
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RL_RR_RC         13
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_RC          14
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_RC      15
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RL_RR_RLC_RRC        16
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RL_RR_RLC_RRC    17
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_RLC_RRC     18
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_RLC_RRC 19
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FLC_FRC              20
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FLC_FRC          21
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_FLC_FRC           22
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_FLC_FRC       23
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RC_FLC_FRC           24
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RC_FLC_FRC       25
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RC_FLC_FRC        26
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RC_FLC_FRC    27
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RL_RR_FLC_FRC        28
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RL_RR_FLC_FRC    29
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_FLC_FRC     30
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_FLC_FRC 31
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_FCH         32
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_FCH     33
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_TC          34
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_TC      35
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RL_RR_FLH_FRH        36
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RL_RR_FLH_FRH    37
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_RL_RR_FLW_FRW        38
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_RL_RR_FLW_FRW    39
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_RC_TC       40
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_RC_TC   41
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_RC_FCH      42
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_RC_FCH  43
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_FCH_TC      44
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_FCH_TC  45
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_FLH_FRH     46
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_FLH_FRH 47
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_FC_RL_RR_FLW_FRW     48
#define VHD_DV_AUDIO_INFOFRAME_SPEAKER_PLACEMENT_FL_FR_LFE_FC_RL_RR_FLW_FRW 49

/*! LFEPlaybackLevel */
#define VHD_DV_AUDIO_INFOFRAME_LFE_PLAYBACK_LEVEL_UNDEFINED                 0
#define VHD_DV_AUDIO_INFOFRAME_LFE_PLAYBACK_LEVEL_0DB                       1
#define VHD_DV_AUDIO_INFOFRAME_LFE_PLAYBACK_LEVEL_10DB                      2

/*! DownMixedInhibit */
#define VHD_DV_AUDIO_INFOFRAME_DOWNMIX_PERMITTED                            0
#define VHD_DV_AUDIO_INFOFRAME_DOWNMIX_PROHIBITED                           1

/*_ DV audio AES channel status definition __________________________________________________*/
/*! Define _VHD_DV_AUDIO_AES_STS fields */
/*! Professional */
#define VHD_DV_AUDIO_AES_STS_CONSUMER                                       0
#define VHD_DV_AUDIO_AES_STS_PROFESSIONAL                                   1

/*! LinearPCM */
#define VHD_DV_AUDIO_AES_SAMPLE_STS_LINEAR_PCM_SAMPLE                       0
#define VHD_DV_AUDIO_AES_SAMPLE_STS_OTHER_SAMPLE                            1

/*! Copyright */
#define VHD_DV_AUDIO_AES_STS_COPYRIGHT_ASSERTED                             0
#define VHD_DV_AUDIO_AES_STS_COPYRIGHT_NONE                                 1

/*! Emphasis */
#define VHD_DV_AUDIO_AES_STS_EMPHASIS_NONE                                  0
#define VHD_DV_AUDIO_AES_STS_EMPHASIS_50_15                                 1

/*! SamplingFrequency */
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_44100HZ                          0
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_48000HZ                          2
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_32000HZ                          3
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_88200HZ                          8
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_768000HZ                         9
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_96000HZ                          10
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_176000HZ                         12
#define VHD_DV_AUDIO_AES_STS_SAMPLING_FREQ_192000HZ                         14

/*! ClockAccuracy */
#define VHD_DV_AUDIO_AES_STS_CLOCK_ACCURACY_LEVEL2_1000PPM                  0
#define VHD_DV_AUDIO_AES_STS_CLOCK_ACCURACY_LEVEL1_50PPM                    1
#define VHD_DV_AUDIO_AES_STS_CLOCK_ACCURACY_LEVEL3_VARIABLE                 2

/*! MaxWordLengthSize */
#define VHD_DV_AUDIO_AES_STS_MAX_WORD_LENGTH_20BITS                         0
#define VHD_DV_AUDIO_AES_STS_MAX_WORD_LENGTH_24BITS                         1

/*! SampleWordLength */
#define VHD_DV_AUDIO_AES_STS_SAMPLE_WORD_LENGTH_UNDEFINED                   0
#define VHD_DV_AUDIO_AES_STS_SAMPLE_WORD_LENGTH_20_OR_16_BITS               1
#define VHD_DV_AUDIO_AES_STS_SAMPLE_WORD_LENGTH_22_OR_18_BITS               2
#define VHD_DV_AUDIO_AES_STS_SAMPLE_WORD_LENGTH_23_OR_19_BITS               4
#define VHD_DV_AUDIO_AES_STS_SAMPLE_WORD_LENGTH_24_OR_20_BITS               5
#define VHD_DV_AUDIO_AES_STS_SAMPLE_WORD_LENGTH_21_BITS                     6

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Dv
*/


/*_ VHD_DV_STREAMPROPERTY______________________________________________*/
/*!
   Summary
   VideoMaster DV streams properties
   Description
   The VHD_DV_STREAMPROPERTY enumeration lists all the
   available DV stream properties.

   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                */
typedef enum _VHD_DV_STREAMPROPERTY
{
   VHD_DV_SP_MODE = ENUMBASE_DV,                /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_MODE
                                                   DV mode (see VHD_DV_MODE), default is VHD_DV_MODE_DVI_D      */
   VHD_DV_SP_ACTIVE_WIDTH,                      /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_ACTIVE_WIDTH
                                                   Active picture width, in pixels. Must be a multiple of 8
                                                   (default is 0)                                               */
   VHD_DV_SP_ACTIVE_HEIGHT,                     /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_ACTIVE_HEIGHT
                                                    Active picture height, in lines (default is 0)              */
   VHD_DV_SP_INTERLACED,                        /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_INTERLACED
                                                    TRUE if interlaced, FALSE if progressive
                                                    (default is FALSE)                                          */
   VHD_DV_SP_REFRESH_RATE,                      /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_REFRESH_RATE
                                                    Refresh rate, in frame per second (default is 0)            */
   VHD_DV_SP_PIXEL_CLOCK,                       /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_PIXEL_CLOCK
                                                    Pixel clock (kHz), default is 0                             */
   VHD_DV_SP_TOTAL_WIDTH,                       /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_TOTAL_WIDTH
                                                    Total picture width, in pixels (default is 0)               */
   VHD_DV_SP_TOTAL_HEIGHT,                      /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_TOTAL_HEIGHT
                                                    Total picture height, in lines (default is 0)               */
   VHD_DV_SP_H_SYNC,                            /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_H_SYNC
                                                    Horizontal sync pulse size, in pixels (default is 0)        */
   VHD_DV_SP_H_FRONT_PORCH,                     /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_H_FRONT_PORCH
                                                    Horizontal front porch size, in pixels (default is 0)       */
   VHD_DV_SP_V_SYNC,                            /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_V_SYNC
                                                    Vertical sync pulse size, in lines (default is 0)           */
   VHD_DV_SP_V_FRONT_PORCH,                     /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_V_FRONT_PORCH
                                                    Vertical front porch size, in lines (default is 0)          */
   VHD_DV_SP_H_SHIFT,                           /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_H_SHIFT
                                                    Picture horizontal shift, in pixels. Must be comprised between -512 and 511.
                                                    (default is 0)                                              */
   VHD_DV_SP_V_SHIFT,                           /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_V_SHIFT
                                                    Picture vertical shift, in lines. Must be comprised between -8 and 7.
                                                    (default is 0)                                              */
   VHD_DV_SP_MEASURED_H_POL_DEPRECATED,         /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_MEASURED_H_POL_DEPRECATED
                                                    Horizontal polarity. '1' = positive, '0' = negative         */
   VHD_DV_SP_MEASURED_V_POL_DEPRECATED,         /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_MEASURED_V_POL_DEPRECATED
                                                    Vertical polarity. '1' = positive, '0' = negative           */
   VHD_DV_SP_MEASURED_LINE_DUR_DEPRECATED,      /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_MEASURED_LINE_DUR_DEPRECATED
                                                    Duration of a line in ns                                    */
   VHD_DV_SP_MEASURED_TOTAL_HEIGHT_DEPRECATED,  /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_MEASURED_TOTAL_HEIGHT_DEPRECATED
                                                    Total picture height, in lines                              */
   VHD_DV_SP_MEASURED_V_SYNC_DEPRECATED,        /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_MEASURED_V_SYNC_DEPRECATED
                                                    Vertical sync pulse size, in lines                          */
   VHD_DV_SP_DUAL_LINK_DEPRECATED,              /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_DUAL_LINK_DEPRECATED
                                                    TRUE if dual link, FALSE if single link (default is FALSE)  */
   VHD_DV_SP_DISABLE_EDID_AUTO_LOAD,            /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_DISABLE_EDID_AUTO_LOAD
                                                    TRUE to disable automatic EDID loading while setting DV mode.
                                                    (default is FALSE)                                          */
   VHD_DV_SP_CS,                                /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_INPUT_CS
                                                    DV input color space (see VHD_DV_CS) */
   VHD_DV_SP_3D_MODE,                           /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_3D_MODE
                                                    HDMI 3D mode */
   VHD_DV_SP_HDR_MODE,                          /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_HDR_MODE
                                                    HDMI HDR mode */
   VHD_DV_SP_CABLE_BIT_SAMPLING,                /*!_VHD_DV_STREAMPROPERTY::VHD_DV_SP_CABLE_BIT_SAMPLING
                                                    DV cable bit sampling (see VHD_DV_SAMPLING) */
   NB_VHD_DV_STREAMPROPERTIES
} VHD_DV_STREAMPROPERTY;

#define VHD_DV_SP_INPUT_CS             VHD_DV_SP_CS


/*_ VHD_DV_STREAMPROCMODE ________________________________________*/
/*!
Summary
VideoMaster DV streams processing modes

Description
The VHD_DV_STREAMPROCMODE enumeration lists all the DV stream
processing modes.

These values are used during VHD_OpenStreamHandle function calls.

See Also
VHD_OpenStreamHandle
*/
typedef enum _VHD_DV_STREAMPROCMODE
{
   VHD_DV_STPROC_DISJOINED_VIDEO=ENUMBASE_DV,            /*! Single Video processing (default) */
   VHD_DV_STPROC_DISJOINED_AUDIO,                        /*! Single audio processing */
   VHD_DV_STPROC_JOINED,                                 /*! Coupled processing (video and audio) */
   VHD_DV_STPROC_DISJOINED_THUMBNAIL,                    /*! Single thumbnail processing */
   NB_VHD_DV_STREAMPROCMODE
} VHD_DV_STREAMPROCMODE;

/*_ VHD_DV_BUFFERTYPE ________________________________________*/
/*!
   Summary
   VideoMaster DV buffer type
   Description
   The VHD_DV_BUFFERTYPE enumeration lists all the DV buffer
   types.

   These values are used during VHD_GetSlotBuffer function
   calls.
   See Also
   VHD_GetSlotBuffer
*/

typedef enum _VHD_DV_BUFFERTYPE
{
   VHD_DV_BT_VIDEO = 0,             /*!_VHD_DV_BUFFERTYPE::VHD_DV_BT_VIDEO
                                        DVI/HDMI/DisplayPort frames buffer type */
   VHD_DV_BT_AUDIO,                 /*!_VHD_DV_BUFFERTYPE::VHD_DV_BT_AUDIO
                                        Audio frames buffer type */
   VHD_DV_BT_THUMBNAIL,             /*!_VHD_DV_BUFFERTYPE::VHD_DV_BT_THUMBNAIL
                                        Thumbnail frames buffer type */
   VHD_DV_BT_PLANAR_Y,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_Y
                                       Y-plan buffer type (planar-only scenarios) */
   VHD_DV_BT_PLANAR_U,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_U
                                       U-plan buffer type (planar-only scenarios)  */
   VHD_DV_BT_PLANAR_V,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_V
                                       V-plan buffer type (planar-only scenarios)  */
   NB_VHD_DV_BUFFERTYPE
} VHD_DV_BUFFERTYPE;


/*_ VHD_DV_MODE ____________________________________________________*/
/*!
   Summary
   DV modes
   Description
   The VHD_DV_MODE enumeration lists all supported DV modes
   used in VHD_DV_SP_MODE stream property.
   See Also
   <link VHD_DV_STREAMPROPERTY, VHD_DV_SP_MODE>             */
typedef enum _VHD_DV_MODE
{
   VHD_DV_MODE_DVI_D=0,                               /*! DV-D mode */
   VHD_DV_MODE_DVI_A_DEPRECATED,                      /*! DV-A mode */
   VHD_DV_MODE_HDMI,                                  /*! HDMI mode */
   VHD_DV_MODE_ANALOG_COMPONENT_VIDEO_DEPRECATED,     /*! Analog component video mode */
   VHD_DV_MODE_DISPLAYPORT,                           /*! DisplayPort mode */
   NB_VHD_DV_MODES
}VHD_DV_MODE;


/*_ VHD_DV_STANDARD ____________________________________________________*/
/*!
Summary
DV standards

Description
The VHD_DV_STANDARD enumeration lists all supported DV
standard used by the VHD_PresetTimingStreamProperties function.

See Also
VHD_PresetTimingStreamProperties
*/
typedef enum _VHD_DV_STANDARD
{
   VHD_DV_STD_CVT = 0,           /*! CVT standard */
   VHD_DV_STD_CVTRB,             /*! CVT-RB standard */
   VHD_DV_STD_DMT,               /*! DMT standard */
   VHD_DV_STD_SMPTE,             /*! SMPTE standard (CEA-861) */
   VHD_DV_STD_GTF,               /*! GTF standard */
   VHD_DV_STD_CVTRB_V2,          /*! CVT-RB v2 standard */
   NB_VHD_DV_STANDARD
} VHD_DV_STANDARD;

/*_ VHD_DV_EEDID_PRESET ____________________________________________________*/
/*!
Summary
E-EDID presets

Description
The VHD_DV_EEDID_PRESET enumeration lists all predefined E-EDID
used by the VHD_PresetEEDID function.

See Also
VHD_PresetEEDID
*/
typedef enum _VHD_DV_EEDID_PRESET
{
   VHD_DV_EEDID_EMPTY=0,               /*! Empty E-EDID. The host should force its output regardless of the DELTA-dvi E-EDID. Size=0 byte. */
   VHD_DV_EEDID_DVIA_DEPRECATED,       /*! DVI-A E-EDID (EDID version 1, revision 3). Size=128 bytes. */
   VHD_DV_EEDID_DVID,                  /*! DVI-D E-EDID (EDID version 1, revision 3). Size=128 bytes. */
   VHD_DV_EEDID_HDMI,                  /*! HDMI E-EDID (EDID version 1, revision 3). Size=256 bytes. */
   VHD_DV_EEDID_DVID_DUAL,             /*! DVI-D E-EDID with dual-link formats (EDID version 1, revision3). Size=256 bytes. */
   VHD_DV_EEDID_HDMI_H4K,              /*! HDMI H4K E-EDID (EDID version 1, revision 4). Size=256 bytes. */
   VHD_DV_EEDID_DVID_H4K,              /*! DVI-D H4K E-EDID (EDID version 1). Size=256 bytes. */
   VHD_DV_EEDID_HDMI_H4K2,             /*! HDMI H4K2 E-EDID (EDID version 1, revision 4). Size=256 bytes. */
   VHD_DV_EEDID_DVID_H4K2,             /*! DVI-D H4K2 E-EDID (EDID version 1). Size=256 bytes. */
   VHD_DV_EEDID_DISPLAYPORT_1_2,       /*! DisplayPort 1.2 E-EDID (EDID version 1). Size=256 bytes. */
   VHD_DV_EEDID_HDMI_FLEX_HMI,         /*! HDMI FLEX-HMI E-EDID (EDID version 1, revision 4). Size=256 bytes. */
   VHD_DV_EEDID_DVID_FLEX_HMI,         /*! DVI-D FLEX-HMI E-EDID (EDID version 1). Size=256 bytes. */
   NB_VHD_DV_EEDID_PRESET
} VHD_DV_EEDID_PRESET;


/*_ VHD_DV_CS ____________________________________________________*/
/*!
Summary
DELTA-h4k, DELTA-h4k2 and FLEX-dp color spaces

Description
The VHD_DV_CS enumeration lists all supported DV color space.
*/
typedef enum _VHD_DV_CS
{
   VHD_DV_CS_RGB_FULL=0,            /*! RGB full color space */
   VHD_DV_CS_RGB_LIMITED,           /*! RGB limited color space */
   VHD_DV_CS_YUV601,                /*! YUV 601 (SD) color space */
   VHD_DV_CS_YUV709,                /*! YUV 709 (HD) color space */
   VHD_DV_CS_XVYCC_601,             /*! CVYCC 601 (SD) color space */
   VHD_DV_CS_XVYCC_709,             /*! CVYCC 709 (HD) color space */
   VHD_DV_CS_YUV_601_FULL,          /*! YUV 601 (SD) full color space */
   VHD_DV_CS_YUV_709_FULL,          /*! YUV 709 (HD) full color space */
   VHD_DV_CS_SYCC_601,              /*! SYCC 601 color space */
   VHD_DV_CS_ADOBE_YCC_601,         /*! Adobe YCC 601 color space */
   VHD_DV_CS_ADOBE_RGB,             /*! Adobe RGB color space */
   VHD_DV_CS_BT2020_YCCBCCRC,       /*! ITU-R BT.2020 Y'cC'bcC'rc color space*/
   VHD_DV_CS_BT2020_RGB_LIMITED,    /*! ITU-R BT.2020 R’G’B’ LIMITED color space*/
   VHD_DV_CS_BT2020_RGB_FULL,       /*! ITU-R BT.2020 R’G’B’ FULL color space*/
   VHD_DV_CS_BT2020_YCBCR,          /*! ITU-R BT.2020 Y'C'bC'r color space*/
   VHD_DV_CS_DCI_P3_RGB_D65,        /*! DCI-P3 R’G’B’(D65) color space*/
   VHD_DV_CS_DCI_P3_RGB_THEATER,    /*! DCI-P3 R’G’B’ (theater) color space*/
   NB_VHD_DV_CS
} VHD_DV_CS;


/*_ VHD_DV_HDMI_VIDEOSTANDARD ________________________________________________*/
/*!
   Summary
   VideoMaster supported HDMI video standards
   Description
   The VHD_DV_HDMI_VIDEOSTANDARD enumeration lists all the supported HDMI
   video standards
*/
typedef enum _VHD_DV_HDMI_VIDEOSTANDARD
{
   VHD_DV_HDMI_VIDEOSTD_640x480p_60Hz=0,       /*! 640x480p @ 60Hz VIC=1*/
   VHD_DV_HDMI_VIDEOSTD_720x480p_60Hz,         /*! 720x480p @ 60Hz VIC=3*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_60Hz,        /*! 1280x720p @ 60 VIC=4*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080i_30Hz,       /*! 1920x1080i @ 30Hz VIC=5*/
   VHD_DV_HDMI_VIDEOSTD_720x480i_30Hz,         /*! 720x480i @ 30Hz VIC=7*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_60Hz,       /*! 1920x1080p60Hz VIC=16*/
   VHD_DV_HDMI_VIDEOSTD_720x576p_50Hz,         /*! 720x576p @ 50Hz VIC=18*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_50Hz,        /*! 280x720p @ 50Hz VIC=19*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080i_25Hz,       /*! 1920x1080i @ 25Hz VIC=20*/
   VHD_DV_HDMI_VIDEOSTD_720x576i_25Hz,         /*! 720x576i @ 25Hz VIC=22*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_50Hz,       /*! 1920x1080p @ 50Hz VIC=31*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_24Hz,       /*! 1920x1080p @ 24Hz VIC=32*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_25Hz,       /*! 1920x1080p @ 25Hz VIC=33*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_30Hz,       /*! 1920x1080p @ 30Hz VIC=34*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080i_50Hz,       /*! 1920x1080i @ 50Hz VIC=40*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_100Hz,       /*! 1280x720p @ 100Hz VIC=41*/
   VHD_DV_HDMI_VIDEOSTD_720x576p_100Hz,        /*! 720x576p @ 100Hz VIC=43*/
   VHD_DV_HDMI_VIDEOSTD_720x576i_50Hz,         /*! 720x576i @ 50Hz VIC=45*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080i_60Hz,       /*! 1920x1080i @ 60Hz VIC=46*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_120Hz,       /*! 1280x720p @ 120Hz VIC=47*/
   VHD_DV_HDMI_VIDEOSTD_720x480p_120Hz,        /*! 720x480p @ 120Hz VIC=49*/
   VHD_DV_HDMI_VIDEOSTD_720x480i_60Hz,         /*! 720x480i @ 60Hz VIC=51*/
   VHD_DV_HDMI_VIDEOSTD_720x576p_200Hz,        /*! 720x576p @ 200Hz VIC=53*/
   VHD_DV_HDMI_VIDEOSTD_720x576i_100Hz,        /*! 720x576i @ 100Hz VIC=55*/
   VHD_DV_HDMI_VIDEOSTD_720x480p_240Hz,        /*! 720x480p @ 240Hz VIC=57*/
   VHD_DV_HDMI_VIDEOSTD_720x480i_120Hz,        /*! 720x480i @ 120Hz VIC=59*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_24Hz,        /*! 1280x720p @ 24Hz VIC=60*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_25Hz,        /*! 1280x720p @ 25Hz VIC=61*/
   VHD_DV_HDMI_VIDEOSTD_1280x720p_30Hz,        /*! 1280x720p @ 30Hz VIC=62*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_120Hz,      /*! 1920x1080p @ 120Hz VIC=63*/
   VHD_DV_HDMI_VIDEOSTD_1920x1080p_100Hz,      /*! 1920x1080p @ 100Hz VIC=64*/
   VHD_DV_HDMI_VIDEOSTD_3840x2160p_30Hz,       /*! 3840x2160p @ 30Hz VIC=95*/
   VHD_DV_HDMI_VIDEOSTD_3840x2160p_25Hz,       /*! 3840x2160p @ 25Hz VIC=94*/
   VHD_DV_HDMI_VIDEOSTD_3840x2160p_24Hz,       /*! 3840x2160p @ 24Hz VIC=93*/
   VHD_DV_HDMI_VIDEOSTD_4096x2160p_24Hz,       /*! 4096x2160p @ 24Hz VIC=98*/
   VHD_DV_HDMI_VIDEOSTD_3840x2160p_50Hz,       /*! 3840x2160p @ 50Hz VIC=96*/
   VHD_DV_HDMI_VIDEOSTD_3840x2160p_60Hz,       /*! 3840x2160p @ 60Hz VIC=97*/
   VHD_DV_HDMI_VIDEOSTD_4096x2160p_25Hz,       /*! 4096x2160p @ 25Hz VIC=99*/
   VHD_DV_HDMI_VIDEOSTD_4096x2160p_30Hz,       /*! 4096x2160p @ 30Hz VIC=100*/
   VHD_DV_HDMI_VIDEOSTD_4096x2160p_50Hz,       /*! 4096x2160p @ 50Hz VIC=101*/
   VHD_DV_HDMI_VIDEOSTD_4096x2160p_60Hz,       /*! 4096x2160p @ 60Hz VIC=102*/
   NB_VHD_DV_HDMI_VIDEOSTD
} VHD_DV_HDMI_VIDEOSTANDARD;

/*_ VHD_DV_HDMI_3D_MODE ________________________________________________*/
/*!
   Summary
   VideoMaster supported HDMI 3D modes
   Description
   The VHD_DV_HDMI_3D_MODE enumeration lists all the supported HDMI
   3D modes
*/
typedef enum _VHD_DV_HDMI_3D_MODE
{
   VHD_DV_HDMI_3D_MODE_NONE,           /*! 2D mode */
   VHD_DV_HDMI_3D_MODE_FRAME,          /*! 3D frame mode */
   VHD_DV_HDMI_3D_MODE_TOP_BOTTOM,     /*! 3D top-bottom mode */
   VHD_DV_HDMI_3D_MODE_SIDE_BY_SIDE,   /*! 3D side-by-side mode */
   NB_VHD_DV_HDMI_3D_MODE
} VHD_DV_HDMI_3D_MODE;

/*_ VHD_DV_AUDIO_TYPE ________________________________________________*/
/*!
   Summary
   VideoMaster supported DV audio types
   Description
   The VHD_DV_AUDIO_TYPE enumeration lists all the supported DV
   audio types
*/
typedef enum _VHD_DV_AUDIO_TYPE
{
   VHD_DV_AUDIO_TYPE_NONE,                /*! No audio */
   VHD_DV_AUDIO_TYPE_AUDIO_SAMPLES,       /*! Audio samples packets */
   VHD_DV_AUDIO_TYPE_HDMI_HBR_PACKETS,    /*! High-Bitrate packets */
   VHD_DV_AUDIO_TYPE_HDMI_DSD_PACKETS,    /*! DSD packets */
   VHD_DV_AUDIO_TYPE_HDMI_DST_PACKETS,    /*! DST packets */
   NB_VHD_DV_AUDIO_TYPE
} VHD_DV_AUDIO_TYPE;

/*_ VHD_DV_BOARD_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster DV board capability
  Description
  The VHD_DV_BOARD_CAPABILITY enumeration lists all the available DV board capabilities

  These values are used in VHD_GetBoardCapability function
  See Also
  <link VHD_GetBoardCapability>
*/
typedef enum _VHD_DV_BOARD_CAPABILITY
{
   VHD_DV_BOARD_CAP_DVI_D = ENUMBASE_DV,     /*! Return true if the board supports DVI-D handling feature*/
   VHD_DV_BOARD_CAP_DVI_A,                   /*! Return true if the board supports DVI-A handling feature*/
   VHD_DV_BOARD_CAP_DVI_D_DUAL,              /*! Return true if the board supports DVI-D dual handling feature*/
   VHD_DV_BOARD_CAP_HDMI,                    /*! Return true if the board supports video HDMI handling feature*/
   VHD_DV_BOARD_CAP_AUDIO,                   /*! Return true if the board supports audio HDMI handling feature*/
   VHD_DV_BOARD_CAP_HDMI_TMDS600,            /*! Return true if the board supports HDMI 2.0 protocol handling feature*/
   VHD_DV_BOARD_CAP_HPD_CONTROL,             /*! Return true if the board supports hot plug detect control feature*/
   VHD_DV_BOARD_CAP_HDR_SIGNALING,           /*! Return true if the board supports HDR signaling inside payload identifier*/
   NB_VHD_DV_BOARD_CAPABILITY
}VHD_DV_BOARD_CAPABILITY;

#define  VHD_DV_BOARD_CAP_HDMI_AUDIO         VHD_DV_BOARD_CAP_AUDIO     /*! Backward compatibility */

/*_ VHD_DV_DPLINKRATE _____________________________________________*/
/*!
Summary
VideoMaster digital video DisplayPort link rate
Description
The VHD_DV_DPLINKRATE enumeration lists all the available DV DisplayPort link rates

These values are used in VHD_GetDPLinkStatus function
See Also
<link VHD_GetDPLinkStatus>
*/
typedef enum _VHD_DV_DPLINKRATE
{
   VHD_DV_DPLINKRATE_1_62_GBPS,  /*! 1.62 Gbps Displayport link rate */
   VHD_DV_DPLINKRATE_2_7_GBPS,   /*! 2.7 Gbps Displayport link rate */
   VHD_DV_DPLINKRATE_5_4_GBPS,   /*! 5.4 Gbps Displayport link rate */
   NB_VHD_DV_DPLINKRATE
}VHD_DV_DPLINKRATE;

/*_ VHD_DV_HPDSTATE _____________________________________________*/
/*!
Summary
VideoMaster digital video hot plug detect state
Description
The VHD_DV_HPDSTATE enumeration lists all the available DV hot plug detect states

These values are used in VHD_SetHPDState function
See Also
<link VHD_SetHPDState>
*/
typedef enum _VHD_DV_HPDSTATE
{
   VHD_DV_HPDSTATE_ENABLE,                  /*! Enable the Hot Plug Detect signal */
   VHD_DV_HPDSTATE_DISABLE                  /*! Disable the Hot Plug Detect signal */
} VHD_DV_HPDSTATE;

/*_ VHD_DV_SAMPLING _____________________________________________*/
/*!
Summary
VideoMaster DV cable bit sampling
Description
The VHD_DV_SAMPLING enumeration lists all the available DV cable bit samplings

See Also
<link VHD_DV_SP_CABLE_BIT_SAMPLING>
*/
typedef enum _VHD_DV_SAMPLING
{
   VHD_DV_SAMPLING_4_2_0_8BITS,              /*! 4-2-0 8-bit sampling */
   VHD_DV_SAMPLING_4_2_0_10BITS,             /*! 4-2-0 10-bit sampling */
   VHD_DV_SAMPLING_4_2_0_12BITS,             /*! 4-2-0 12-bit sampling */
   VHD_DV_SAMPLING_4_2_0_16BITS,             /*! 4-2-0 16-bit sampling */
   VHD_DV_SAMPLING_4_2_2_8BITS,              /*! 4-2-2 8-bit sampling */
   VHD_DV_SAMPLING_4_2_2_10BITS,             /*! 4-2-2 10-bit sampling */
   VHD_DV_SAMPLING_4_2_2_12BITS,             /*! 4-2-2 12-bit sampling */
   VHD_DV_SAMPLING_4_2_2_16BITS,             /*! 4-2-2 16-bit sampling */
   VHD_DV_SAMPLING_4_4_4_6BITS,              /*! 4-4-4 6-bit sampling */
   VHD_DV_SAMPLING_4_4_4_8BITS,              /*! 4-4-4 8-bit sampling */
   VHD_DV_SAMPLING_4_4_4_10BITS,             /*! 4-4-4 10-bit sampling */
   VHD_DV_SAMPLING_4_4_4_12BITS,             /*! 4-4-4 12-bit sampling */
   VHD_DV_SAMPLING_4_4_4_16BITS,             /*! 4-4-4 16-bit sampling */
   NB_VHD_DV_SAMPLING,
} VHD_DV_SAMPLING;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Dv
*/

#pragma pack (push,1)
/*_ VHD_DV_AUDIO_INFOFRAME ____________________________________________________*/
/*!
   Summary
   DV audio InfoFrame
   Description
   This structure contains the audio
   InfoFrame block.  */
typedef union _VHD_DV_AUDIO_INFOFRAME
{
   struct
   {
      //Byte 0
      UBYTE ChannelCount   : 3;     /*!*/
      UBYTE Reserved1      : 1;     /*!*/
      UBYTE CodingType     : 4;     /*!*/

      //Byte 1
      UBYTE SampleSize        : 2;  /*!*/
      UBYTE SamplingFrequency : 3;  /*!*/
      UBYTE Reserved2         : 3;  /*!*/

      //Byte 2
      UBYTE CodingTypeExt  : 5;     /*!*/
      UBYTE Reserved3      : 3;     /*!*/

      //Byte 3
      UBYTE SpeakerPlacement  : 8;  /*!*/

      //Byte 4
      UBYTE LFEPlaybackLevel  : 2;  /*!*/
      UBYTE Reserved4         : 1;  /*!*/
      UBYTE LevelShiftValue   : 4;  /*!*/
      UBYTE DownMixedInhibit  : 1;  /*!*/

      //Byte 5
      UBYTE Reserved5 : 8;          /*!*/

      //Byte 6
      UBYTE Reserved6 : 8;          /*!*/

      //Byte 7
      UBYTE Reserved7 : 8;          /*!*/

      //Byte 8
      UBYTE Reserved8 : 8;          /*!*/

      //Byte 9
      UBYTE Reserved9 : 8;          /*!*/
   };
   UBYTE pData[10];                 /*!*/
} VHD_DV_AUDIO_INFOFRAME;

/*_ VHD_DV_AUDIO_AES_STS ____________________________________________________*/
/*!
   Summary
   DV audio AES channel status
   Description
   This structure contains the audio
   AES channel status block.  */
typedef union _VHD_DV_AUDIO_AES_STS
{
   struct
   {
      //Byte 0
      UBYTE Professional   : 1;     /*!*/
      UBYTE LinearPCM      : 1;     /*!*/
      UBYTE Copyright      : 1;     /*!*/
      UBYTE Emphasis       : 3;     /*!*/
      UBYTE Reserved1      : 2;     /*!*/

      //Byte 1
      UBYTE CategoryCode   : 8;     /*!*/

      //Byte 2
      UBYTE SourceNb    : 4;        /*!*/
      UBYTE ChannelNb   : 4;        /*!*/

      //Byte 3
      UBYTE SamplingFrequency : 4;  /*!*/
      UBYTE ClockAccuracy     : 2;  /*!*/
      UBYTE Reserved2         : 2;  /*!*/

      //Byte 4
      UBYTE MaxWordLengthSize : 1;  /*!*/
      UBYTE SampleWordLength  : 3;  /*!*/
      UBYTE Reserved3         : 4;  /*!*/

      //BYTE 5
      UBYTE Reserved4 : 8;          /*!*/

      //BYTE 6
      UBYTE Reserved5 : 8;          /*!*/

      //BYTE 7
      UBYTE Reserved6 : 8;          /*!*/

   };
   UBYTE pData[8];                  /*!*/
} VHD_DV_AUDIO_AES_STS;

/* _VHD_DV_HDMI_HDR_INFOFRAME ____________________________________________________*/
/*!
   Summary
   HDMI HDR InfoFrame
   Description
   This structure contains the HDR
   InfoFrame block
   See Also
   VHD_GetStreamHDMIHDRInfo, VHD_SetStreamHDMIHDRInfo */
typedef struct _VHD_DV_HDMI_HDR_INFOFRAME
{
   UBYTE    Version;                                        /*! Version */
   UBYTE    LengthHdrInfoFrame;                             /*! Length of HDR InfoFrame */
   UBYTE    EOTF : 3;                                       /*! Electro-Optical Transfer Function */
   UBYTE    StaticMetadataDescriptorID : 3;                 /*!*/

   union
   {
      struct
      {
         UBYTE    Display_Primaries_X_0_LSB;                /*!*/
         UBYTE    Display_Primaries_X_0_MSB;                /*!*/
         UBYTE    Display_Primaries_Y_0_LSB;                /*!*/
         UBYTE    Display_Primaries_Y_0_MSB;                /*!*/
         UBYTE    Display_Primaries_X_1_LSB;                /*!*/
         UBYTE    Display_Primaries_X_1_MSB;                /*!*/
         UBYTE    Display_Primaries_Y_1_LSB;                /*!*/
         UBYTE    Display_Primaries_Y_1_MSB;                /*!*/
         UBYTE    Display_Primaries_X_2_LSB;                /*!*/
         UBYTE    Display_Primaries_X_2_MSB;                /*!*/
         UBYTE    Display_Primaries_Y_2_LSB;                /*!*/
         UBYTE    Display_Primaries_Y_2_MSB;                /*!*/
         UBYTE    White_Point_X_LSB;                        /*!*/
         UBYTE    White_Point_X_MSB;                        /*!*/
         UBYTE    White_Point_Y_LSB;                        /*!*/
         UBYTE    White_Point_Y_MSB;                        /*!*/
         UBYTE    Max_Display_Mastering_Luminance_LSB;      /*!*/
         UBYTE    Max_Display_Mastering_Luminance_MSB;      /*!*/
         UBYTE    Min_Display_Mastering_Luminance_LSB;      /*!*/
         UBYTE    Min_Display_Mastering_Luminance_MSB;      /*!*/
         UBYTE    Maximum_Content_Light_Level_LSB;          /*!*/
         UBYTE    Maximum_Content_Light_Level_MSB;          /*!*/
         UBYTE    Maximum_Frame_Average_Light_Level_LSB;    /*!*/
         UBYTE    Maximum_Frame_Average_Light_Level_MSB;    /*!*/
      };
      UBYTE pData[24];                                      /*!*/
   };
}VHD_DV_HDMI_HDR_INFOFRAME;


/* _VHD_DV_HDMI_AVI_INFOFRAME ____________________________________________________*/
/*!
Summary
HDMI AVI InfoFrame
Description
This structure contains the AVI
InfoFrame block
See Also
VHD_GetStreamHDMIAVIInfo, VHD_SetStreamHDMIAVIInfo */
typedef union _VHD_DV_HDMI_AVI_INFOFRAME
{
   struct
   {
      /* Byte 0 */
      UBYTE    ScanInformation : 2;                      /*!*/
      UBYTE    BarDataPresent : 2;                       /*!*/
      UBYTE    ActiveFormatInformationPresent : 1;       /*!*/
      UBYTE    RgbOrYUV : 2;                             /*!*/
      UBYTE    Reserved1 : 1;                            /*!*/

      /* Byte 1 */
      UBYTE    ActivePortionAspectRatio : 4;             /*!*/
      UBYTE    PictureAspectRatio : 2;                   /*!*/
      UBYTE    Colorimetry : 2;                          /*!*/

      /* Byte 2 */
      UBYTE    NonUniformPictureScaling : 2;             /*!*/
      UBYTE    RgbQuantizationRange : 2;                 /*!*/
      UBYTE    ExtendedColorimetry : 3;                  /*!*/
      UBYTE    ITContent : 1;                            /*!*/

      /* Byte 3 */
      UBYTE    VideoIdentificationCode : 7;              /*!*/
      UBYTE    Reserved2 : 1;                            /*!*/ 

      /* Byte 4 */
      UBYTE    PixelRepetitionFactor : 4;                /*!*/
      UBYTE    ContentType : 2;                          /*!*/
      UBYTE    YccQuantizationRange : 2;                 /*!*/

      /* Byte 5 to 12*/
      UBYTE    ETB07_ETB00;                              /*!*/
      UBYTE    ETB15_ETB08;                              /*!*/
      UBYTE    SBB07_SBB00;                              /*!*/
      UBYTE    SBB15_SBB08;                              /*!*/
      UBYTE    ELB07_ELB00;                              /*!*/
      UBYTE    ELB15_ELB08;                              /*!*/
      UBYTE    SRB07_SRB00;                              /*!*/
      UBYTE    SRB15_SRB08;                              /*!*/

   };
   UBYTE pData[13];                                      /*!*/
}VHD_DV_HDMI_AVI_INFOFRAME;

/* _VHD_DV_HDMI_VENDOR_SPECIFIC_INFOFRAME ____________________________________________________*/
/*!
Summary
HDMI vendor specific InfoFrame
Description
This structure contains the vendor specific
InfoFrame block
See Also
VHD_GetStreamHDMIVendorSpecificInfo, VHD_SetStreamHDMIVendorSpecificInfo */
typedef union _VHD_DV_HDMI_VS_INFOFRAME
{
   struct
   {
      //Byte 0
      UBYTE    IEEE_ThirdTwoHexDigits;                         /*!*/
      //Byte 1
      UBYTE    IEEE_SecondTwoHexDigits;                        /*!*/
      //Byte 2
      UBYTE    IEEE_FirstTwoHexDigits;                         /*!*/

      //Byte 3
      UBYTE    Reserved1 : 5;                                  /*!*/
      UBYTE    HdmiVideoFormat : 3;                            /*!*/
      //Byte 4
      union
      {
         struct
         {
            UBYTE    VIC;                                      /*!*/
         };
         struct
         {
            UBYTE    Reserved2 : 4;                            /*!*/
            UBYTE    Structure3D : 4;                          /*!*/
         };
         UBYTE pData2[1];                                      /*!*/
      };
      //Byte 5
      UBYTE    Reserved3 : 5;
      UBYTE    ExtData3D : 3;                                  /*!*/
   };
   UBYTE pData[6];                                             /*!*/
}VHD_DV_HDMI_VS_INFOFRAME;

/*_ VHD_DV_DPLINKSTATUS ____________________________________________________*/
/*!
   Summary
   Digital video DisplayPort link status.

   Description
   The VHD_DV_DPLINKSTATUS structure is used to report the digital video DisplayPort link status
   See Also
   VHD_GetDPLinkStatus
*/
typedef struct _VHD_DV_DPLINKSTATUS
{
   ULONG Size;                   /*! Structure size */
   ULONG LaneCount;              /*! Number of negotiated DisplayPort lanes */
   BOOL32 CableDetected;         /*! Information about cable detection */
   BOOL32 PowerDetected;         /*! Information about power detection */
   VHD_DV_DPLINKRATE LinkRate;   /*! Negotiated link rate */
}VHD_DV_DPLINKSTATUS;

#pragma pack (pop)

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif


/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Dv
*/

/*** VHD_PresetEEDID ****************************************************/
/*!
   Summary
   E-EDID information preset
   Description
   This function fills in a caller-allocated buffer with a
   preset E-EDID.
   Parameters
   Preset :           E\-EDID preset (see VHD_DV_EEDID_PRESET)
   pEEDIDBuffer :     Pointer to a caller\-allocated buffer
                      receiving the preset E\-EDID
   EEDIDBufferSize :  E\-EDID buffer size. This size should be 0,
                      128 or 256 bytes depending on the E\-EDID
                      preset
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   The filled in buffer may be used with VHD_LoadEEDID function
   to actually load the E-EDID in the DV PROM of the selected
   channel.
   See Also
   VHD_DV_EEDID_PRESET VHD_LoadEEDID
*/
VIDEOMASTER_HD_API ULONG VHD_PresetEEDID (VHD_DV_EEDID_PRESET Preset, BYTE *pEEDIDBuffer, ULONG EEDIDBufferSize);


/*** VHD_LoadEEDID ****************************************************/
/*!VHD_LoadEEDID@HANDLE@BYTE *@ULONG
   Summary
   E-EDID information reload
   Description
   This function reloads the E-EDID information with
   the provided buffer
   Parameters
   StrmHandle :       Handle of the stream to load E\-EDID
   pEEDIDBuffer :     Pointer to the buffer containing the E\-EDID
                      to load in the DV PROM
   EEDIDBufferSize :  E\-EDID buffer size. This size must be 0,
                      128 or 256 bytes
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   This function loads the DV PROM of the selected channel with
   the given E-EDID buffer.

   The user should set the VHD_DV_SP_DISABLE_EDID_AUTO_LOAD to
   TRUE when using this function to disable default E-EDID
   loading on DV mode setting.

   The VHD_PresetEEDID function can be used to preset the E-EDID
   buffer.
   See Also
   VHD_PresetEEDID                                                 */
VIDEOMASTER_HD_API ULONG VHD_LoadEEDID (HANDLE StrmHandle, BYTE *pEEDIDBuffer, ULONG EEDIDBufferSize);


/*** VHD_ReadEEDID ****************************************************/
/*!VHD_ReadEEDID@HANDLE@ULONG@BYTE *@ULONG *
   Summary
   Reads E-EDID information (on DV family boards) or reads monitor E-EDID
   through HDMI output (DELTA 3G)
   Description
   On DV family boards, this function reads the board E-EDID information and
   writes it to the provided buffer.
   On DELTA-3G, this function reads the monitor E-EDID
   information through HDMI output and writes it to the provided buffer.
   Parameters
   BrdHandle :         Handle of the board to load E\-EDID.
   ChannelIndex :      Index of the channel to load E\-EDID.
   pEEDIDBuffer :      Pointer to the user's allocated buffer
                       that will be filled in by the E\-EDID
                       (\>=256 bytes).
   pEEDIDBufferSize :  Pointer to the user's allocated buffer
                       size (\>= 256).
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration).
   Remarks
   Only available on DV family boards.

   This function reads the E-EDID DV PROM of the selected
   channel (on DV family boards).

   pEEDIDBufferSize must specify the size of the user's
   allocated buffer. It will return the number of read byte.

   pEEDIDBufferSize must be 256 (DELTA-3G remark).

   PLease remind that the setting of DV mode reloads a default
   E-EDID information if the VHD_DV_SP_DISABLE_EDID_AUTO_LOAD
   property is not set.
   See Also
   VHD_PresetEEDID, VHD_LoadEEDID,
   VHD_DV_SP_DISABLE_EDID_AUTO_LOAD                            */
VIDEOMASTER_HD_API ULONG VHD_ReadEEDID(HANDLE BrdHandle,ULONG ChannelIndex,BYTE *pEEDIDBuffer, ULONG *pEEDIDBufferSize);

/*** VHD_PresetHDMIStreamProperties ******************************************/
/*!VHD_PresetHDMIStreamProperties
   Summary
   HDMI stream properties preset
   Description
   This function presets HDMI reception stream
   properties according to the specified video timing standard
   and main characteristics.
   Parameters
   SlotHandle :    Handle of the slot to operate on
   HDMIVideoStd :  HDMI video standard (see
                   VHD_HDMI_VIDEOSTANDARD)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration).

   See Also
   VHD_DV_STREAMPROPERTY VHD_HDMI_VIDEOSTANDARD VHD_SetStreamProperty
   VHD_GetStreamProperty                                        */
VIDEOMASTER_HD_API ULONG VHD_PresetHDMIStreamProperties (HANDLE StrmHandle, VHD_DV_HDMI_VIDEOSTANDARD DvHDMIVideoStd);


/*** VHD_GetSlotDvAudioInfo ******************************************/
/*!VHD_GetSlotDvAudioInfo
   Summary
   DV detect audio information
   Description
   This function detect DV audio type, InfoFrame and AES channel status
   Parameters
   SlotHandle :          Handle of the slot to operate on
   pDvAudioType :        Pointer to caller\-allocated variable to
                           return audio type (see VHD_DV_AUDIO_TYPE)
   pDvAudioInfoFrame :   Pointer to caller\-allocated variable to
                           return audio InfoFrame (see VHD_HDMI_AUDIO_INFOFRAME)
   pDvAudioAESSts :      Pointer to caller\-allocated variable to
                           return audio AES channel status (see VHD_HDMI_AUDIO_AES_STS)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetSlotDvAudioInfo(HANDLE SlotHandle, VHD_DV_AUDIO_TYPE *pDvAudioType, VHD_DV_AUDIO_INFOFRAME *pDvAudioInfoFrame, VHD_DV_AUDIO_AES_STS *pDvAudioAESSts);


/*** VHD_GetStreamHDMIHDRInfo ******************************************/
/*!VHD_GetStreamHDMIHDRInfo
   Summary
   HDMI detect HDR information
   Description

   Parameters
   StrmHandle :            Handle of the stream to get HDR information
   pHDMIHDRInfoFrame :     Pointer to caller\-allocated variable to
                           return HDR Infoframe (see VHD_HDMI_HDR_INFOFRAME)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetStreamHDMIHDRInfo(HANDLE StrmHandle, VHD_DV_HDMI_HDR_INFOFRAME *pDvHDMIHDRInfoFrame);

/*** VHD_GetDPLinkStatus ******************************************/
/*!VHD_GetDPLinkStatus
   Summary
   Get DisplayPort link status.
   Description

   Parameters
   BrdHandle:              Handle of the board you are dealing with.
   ChannelIndex:           Index of the channel to get link status on.
   pLinkStatus:            Pointer to the user's allocated buffer
                           that will be filled in.
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetDPLinkStatus(HANDLE BrdHandle, ULONG ChannelIndex, VHD_DV_DPLINKSTATUS *pLinkStatus);

/*** VHD_SetHPDState ******************************************/
/*!VHD_SetHPDState
   Summary
   Set hot plug detect state
   Description

   Parameters
   BrdHandle:              Handle of the board you are dealing with.
   ChannelIdx:             Index of the channel to set the hot plug detect state on.
   HPDState:               Hot plug detect state to set. Default is VHD_DV_HPDSTATE_ENABLE.
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_SetHPDState(HANDLE BrdHandle, ULONG ChannelIdx, VHD_DV_HPDSTATE HPDState);

/*** VHD_GetHPDState ******************************************/
/*!VHD_GetHPDState
Summary
Get hot plug detect state
Description

Parameters
BrdHandle:              Handle of the board you are dealing with.
ChannelIdx:             Index of the channel to get the hot plug detect state on.
pHPDState:               Pointer to the user's allocated buffer that will be filled in.
Returns
The function returns the status of its execution as
VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetHPDState(HANDLE BrdHandle, ULONG ChannelIdx, VHD_DV_HPDSTATE *pHPDState);

/*** VHD_GetHdmiVideoCharacteristics ******************************************/
/*!VHD_GetHdmiVideoCharacteristics
Summary
Translates HDMI video standard to video characteristics
Description
This function retrieves the video standard characteristics
associated to the given video standard
Parameters
VideoStd :     Video standard to translate
pWidth :       Pointer to caller\-allocated variable to return
width
pHeight :      Pointer to caller\-allocated variable to return
height
pInterlaced :  Pointer to caller\-allocated variable to return
interlace info
pFramerate :   Pointer to caller\-allocated variable to return
framerate
Returns
The function returns the status of its execution as
VideoMasterHD error code (see VHD_ERRORCODE enumeration).      */
VIDEOMASTER_HD_API ULONG VHD_GetHdmiVideoCharacteristics(VHD_DV_HDMI_VIDEOSTANDARD VideoStd, ULONG* pWidth, ULONG* pHeight, BOOL32* pInterlaced, ULONG* pFramerate);


/*** VHD_GetHdmiBufferSize ******************************************/
/*!VHD_GetHdmiBufferSize
Summary
HDMI video characteristics to buffer size
Description
This function converts frame size with additional information
on framerate, buffer packing and processing mode into a buffer size.
Parameters
Width :           Width
Height :          Height
Interlaced :      Interlaced or progressive
Framerate :       Framerate
BufferPacking :   Buffer packing (see VHD_BUFFERPACKING enum)
ProcMode :        Processing mode (see VHD_DV_STREAMPROCMODE enum)
pBufferSize :     Pointer to caller\-allocated variable
receiving the computed buffer size
Returns
The function returns the status of its execution as
VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetHdmiBufferSize(ULONG Width, ULONG Height, BOOL32 Interlaced, ULONG Framerate, VHD_BUFFERPACKING BufferPacking, VHD_DV_STREAMPROCMODE ProcMode, ULONG* pBufferSize);

/*** VHD_PresetTimingStreamProperties ******************************************/
/*!VHD_PresetTimingStreamProperties@HANDLE@VHD_DV_STANDARD@ULONG@ULONG@ULONG@BOOL32
   Summary
   DV timing stream properties preset
   Description
   This function presets DV product reception or transmission
   timing stream properties according to the specified video timing standard
   and main characteristics.
   Parameters
   StrmHandle :    Handle of the stream to operate on
   DvStd :         Analog graphic standard (see
                      VHD_DV_STANDARD)
   ActiveWidth :   Active width. Must be a multiple of 8.
   ActiveHeight :  Active height.
   RefreshRate :   Refresh rate in Hz.
   Interlaced :    TRUE if interlaced. FALSE if progressive.
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration).

   The function returns VHDERR_NOTFOUND if the specified format
   doesn't exists in the specified DV standard.
   See Also
   VHD_DV_STREAMPROPERTY VHD_DV_STANDARD VHD_SetStreamProperty
   VHD_GetStreamProperty                                        */
VIDEOMASTER_HD_API ULONG VHD_PresetTimingStreamProperties(HANDLE StrmHandle, VHD_DV_STANDARD DvStd, ULONG ActiveWidth, ULONG ActiveHeight, ULONG RefreshRate, BOOL32 Interlaced);

/*** VHD_GetHPDStatus ******************************************/
/*!VHD_GetHPDStatus
   Summary
   Gets HDP status
   Description
   This function gets the HDP status of the given board with additional information
   on how often a cable plugged-in/plugged-out event has been recorded.
   Parameters
   BrdHandle :          Handle of the board to operate on
   ChannelIdx:          Index of the channel to get the hot plug detect state on.
   pDevicePluggedIn :   Pointer to caller\-allocated variable
                           receiving the current HPD state
   pNbTimesPluggedIn :  Pointer to caller\-allocated variable
                           receiving the number of times a "plugged in"
                           signal has been recorded
   pNbTimesPluggedOut : Pointer to caller\-allocated variable
                           receiving the number of times a "plugged out"
                           signal has been recorded
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_GetHPDStatus(HANDLE BrdHandle, ULONG ChannelIdx, BOOL32 *pDevicePluggedIn, ULONGLONG *pPluggedInCount, ULONGLONG *pPluggedOutCount);

/*** VHD_SetStreamDvAudioInfo ******************************************/
/*!VHD_SetStreamDvAudioInfo
   Summary
   DV set audio information
   Description
   This function set InfoFrame and AES channel status
   Parameters
   StrmHandle :         Handle of the stream to operate on
   pDvAudioInfoFrame :  Optional pointer to caller\-allocated variable
                           containing the audio InfoFrame to set (see VHD_DV_AUDIO_INFOFRAME)
   pDvAudioAESSts :     Optional pointer to caller\-allocated variable
                           containing the audio AES channel status (see VHD_DV_AUDIO_AES_STS)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_SetStreamDvAudioInfo(HANDLE StrmHandle, VHD_DV_AUDIO_INFOFRAME *pDvAudioInfoFrame, VHD_DV_AUDIO_AES_STS *pDvAudioAESSts);

/*** VHD_SetStreamHDMIHDRInfo ******************************************/
/*!VHD_SetStreamHDMIHDRInfo
   Summary
   HDMI set HDR infoframe information
   Description

   Parameters
   StrmHandle :            Handle of the stream to set HDR infoframe information
   pHDMIHDRInfoFrame :     Pointer to caller\-allocated variable to
                           setup HDR Infoframe (see VHD_DV_HDMI_HDR_INFOFRAME)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_SetStreamHDMIHDRInfo(HANDLE StrmHandle, VHD_DV_HDMI_HDR_INFOFRAME *pDvHDMIHDRInfoFrame);

/*** VHD_SetStreamHDMIAVIInfo ******************************************/
/*!VHD_SetStreamHDMIAVIInfo
   Summary
   HDMI set AVI infoframe information
   Description

   Parameters
   StrmHandle :            Handle of the stream to set AVI infoframe information
   pDvHDMIAVIInfoFrame :   Pointer to caller\-allocated variable to
                           setup AVI Infoframe (see VHD_DV_HDMI_AVI_INFOFRAME)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_SetStreamHDMIAVIInfo(HANDLE StrmHandle, VHD_DV_HDMI_AVI_INFOFRAME *pDvHDMIAVIInfoFrame);

/*** VHD_GetStreamHDMIAVIInfo ******************************************/
/*!VHD_GetStreamHDMIAVIInfo
   Summary
   HDMI get AVI infoframe information
   Description

   Parameters
   StrmHandle :            Handle of the stream to get AVI infoframe information
   pDvHDMIAVIInfoFrame :   Pointer to caller\-allocated variable to
                           return AVI Infoframe (see VHD_DV_HDMI_AVI_INFOFRAME)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetStreamHDMIAVIInfo(HANDLE StrmHandle, VHD_DV_HDMI_AVI_INFOFRAME *pDvHDMIAVIInfoFrame);

/*** VHD_GetStreamHDMIVSInfo ******************************************/
/*!VHD_GetStreamHDMIVSInfo
   Summary
   HDMI get VS infoframe information
   Description

   Parameters
   StrmHandle :            Handle of the stream to get VS infoframe information
   pDvHDMIVSInfoFrame :    Pointer to caller\-allocated variable to
                           return VS Infoframe (see VHD_DV_HDMI_VS_INFOFRAME)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetStreamHDMIVSInfo(HANDLE StrmHandle, VHD_DV_HDMI_VS_INFOFRAME *pDvHDMIVSInfoFrame);

/*** VHD_SetStreamHDMIVSInfo ******************************************/
/*!VHD_SetStreamHDMIVSInfo
   Summary
   HDMI set VS infoframe information
   Description

   Parameters
   StrmHandle :            Handle of the stream to set VS infoframe information
   pDvHDMIVSInfoFrame :    Pointer to caller\-allocated variable to
                           setup VS Infoframe (see VHD_DV_HDMI_VS_INFOFRAME)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_SetStreamHDMIVSInfo(HANDLE StrmHandle, VHD_DV_HDMI_VS_INFOFRAME *pDvHDMIVSInfoFrame);

#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_DV_H_
