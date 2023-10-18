/*! VideomasterHD_EDID.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : lr                             Date: 2019/03/26

  Purpose : Specifies enumeration, structures and functions used to access and interact with
            EDID buffers.

            See the following specifications for more details
               - VESA E-EDID Standard Release A, v2.0 – EDID structure v1.4
               - CEA-861
*/

#ifndef _VIDEOMASTERHD_EDID_H_
#define _VIDEOMASTERHD_EDID_H_

#include "VideoMasterHD_Dv.h"

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_EDID
*/

#define VHD_EDID_MAX_WARNINGS                            25
#define VHD_EDID_BLOCK_BUFFER_SIZE                       128
#define VHD_EDID_MANUFACTURER_ID_STRING_MAX_LENGTH       4
#define VHD_EDID_DESCRIPTOR_STRING_BUFFER_MAX_LENGTH     14
#define VHD_EDID_MAX_NB_ASPECT_RATIOS                    32
#define VHD_EDID_MAX_NB_ADDITIONAL_TIMINGS               128
#define VHD_EDID_MAX_NB_ESTABLISHED_TIMINGS              128
#define VHD_EDID_MAX_NB_STANDARD_TIMING_INFORMATION      8
#define VHD_EDID_MAX_NB_ADDITIONAL_WHITE_POINT_DATA      2
#define VHD_EDID_MAX_NB_ADDITIONAL_STANDARD_TIMINGS      6
#define VHD_EDID_MAX_NB_CVT_TIMINGS                      4
#define VHD_EDID_MAX_NB_DESCRIPTORS                      4
#define VHD_EDID_MAX_NB_EXTENSIONS                       256
#define VHD_EDID_LOC_STRING_MAX_NB_STRING_TABLES         16
#define VHD_EDID_LOC_STRING_MAX_STRING_LENGTH            32
#define VHD_EDID_CEA_MAX_NB_DATA_BLOCKS                  20
#define VHD_EDID_CEA_MAX_NB_DETAILED_TIMING_DESCRIPTORS  6
#define VHD_EDID_CEA_MAX_NB_AUDIO_DATA                   16
#define VHD_EDID_CEA_MAX_NB_VIDEO_DATA                   32

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_EDID
*/

/*_ VHD_EDID_WARNING_CODE ____________________________________________________*/
/*!
Summary
   EDID warning codes
Description
   The VHD_EDID_WARNING_CODE enumeration lists all the possible warnings that
   the parsing functions can return.
See Also
   VHD_EDID_WARNINGS
*/

typedef enum _VHD_EDID_WARNING_CODE
{
   VHD_EDID_WARNING_CODE_NO_WARNING,
   VHD_EDID_WARNING_CODE_INVALID_CHECKSUM,
   VHD_EDID_WARNING_CODE_INCOHERENT_DATA,
   VHD_EDID_WARNING_CODE_UNDEFINED_BLOCK_TYPE,
   NB_VHD_EDID_WARNING_CODE
}VHD_EDID_WARNING_CODE;

/*_ VHD_EDID_EXTENSION_TYPE ____________________________________________________*/
/*!
Summary
   EDID extension types
Description
   The VHD_EDID_EXTENSION_TYPE enumeration lists all the supported
   EDID extension types.
See Also
   VHD_EDID_DATA
*/
typedef enum _VHD_EDID_EXTENSION_TYPE
{
   VHD_EDID_EXTENSION_TYPE_BLOCK_MAP,
   VHD_EDID_EXTENSION_TYPE_CEA_861,
   VHD_EDID_EXTENSION_TYPE_VIDEO_TIMING_BLOCK,
   VHD_EDID_EXTENSION_TYPE_EDID_2_0,
   VHD_EDID_EXTENSION_TYPE_DISPLAY_INFORMATION,
   VHD_EDID_EXTENSION_TYPE_LOCALIZED_STRING,
   VHD_EDID_EXTENSION_TYPE_MICRODISPLAY_INTERFACE,
   VHD_EDID_EXTENSION_TYPE_DISPLAY_ID,
   VHD_EDID_EXTENSION_TYPE_DISPLAY_TCS_DATA_BLOCK,
   VHD_EDID_EXTENSION_TYPE_DISPLAY_DEVICE_DATA_BLOCK,
   VHD_EDID_EXTENSION_TYPE_UNRECOGNIZED,
   NB_VHD_EDID_EXTENSION_TYPE
}VHD_EDID_EXTENSION_TYPE;

/*_ VHD_EDID_ESTABLISHED_TIMING ____________________________________________________*/
/*!
Summary
   EDID established timings
Description
   The VHD_EDID_ESTABLISHED_TIMING enumeration lists all the supported
   EDID established timings.
See Also
   VHD_EDID_DESCRIPTION,
   VHD_GetEstablishedTimingVideoCharacteristics
*/
typedef enum _VHD_EDID_ESTABLISHED_TIMING
{
   VHD_EDID_ESTABLISHED_TIMING_720x400p70,
   VHD_EDID_ESTABLISHED_TIMING_720x400p88,
   VHD_EDID_ESTABLISHED_TIMING_640x480p60,
   VHD_EDID_ESTABLISHED_TIMING_640x480p67,
   VHD_EDID_ESTABLISHED_TIMING_640x480p72,
   VHD_EDID_ESTABLISHED_TIMING_640x480p75,
   VHD_EDID_ESTABLISHED_TIMING_800x600p56,
   VHD_EDID_ESTABLISHED_TIMING_800x600p60,
   VHD_EDID_ESTABLISHED_TIMING_800x600p72,
   VHD_EDID_ESTABLISHED_TIMING_800x600p75,
   VHD_EDID_ESTABLISHED_TIMING_832x624p75,
   VHD_EDID_ESTABLISHED_TIMING_1024x768i87,
   VHD_EDID_ESTABLISHED_TIMING_1024x768p60,
   VHD_EDID_ESTABLISHED_TIMING_1024x768p70,
   VHD_EDID_ESTABLISHED_TIMING_1024x768p75,
   VHD_EDID_ESTABLISHED_TIMING_1280x1024p75,
   VHD_EDID_ESTABLISHED_TIMING_1152x870p75,
   NB_VHD_EDID_ESTABLISHED_TIMING
}VHD_EDID_ESTABLISHED_TIMING;

/*_ VHD_EDID_BIT_DEPTH ____________________________________________________*/
/*!
Summary
   EDID bit depths
Description
   The VHD_EDID_BIT_DEPTH enumeration lists all the supported
   EDID bit depths.
See Also
   VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS
*/
typedef enum _VHD_EDID_BIT_DEPTH
{
   VHD_EDID_BIT_DEPTH_UNDEFINED,
   VHD_EDID_BIT_DEPTH_6,
   VHD_EDID_BIT_DEPTH_8,
   VHD_EDID_BIT_DEPTH_10,
   VHD_EDID_BIT_DEPTH_12,
   VHD_EDID_BIT_DEPTH_14,
   VHD_EDID_BIT_DEPTH_16,
   NB_VHD_EDID_BIT_DEPTH
}VHD_EDID_BIT_DEPTH;

/*_ VHD_EDID_VIDEO_INTERFACE ____________________________________________________*/
/*!
Summary
   EDID video interfaces
Description
   The VHD_EDID_VIDEO_INTERFACE enumeration lists all the supported
   EDID video interfaces.
See Also
   VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS
*/
typedef enum _VHD_EDID_VIDEO_INTERFACE
{
   VHD_EDID_VIDEO_INTERFACE_UNDEFINED,
   VHD_EDID_VIDEO_INTERFACE_HDMI_A,
   VHD_EDID_VIDEO_INTERFACE_HDMI_B,
   VHD_EDID_VIDEO_INTERFACE_MDDI,
   VHD_EDID_VIDEO_INTERFACE_DISPLAY_PORT,
   NB_VHD_EDID_VIDEO_INTERFACE
}VHD_EDID_VIDEO_INTERFACE;

/*_ VHD_EDID_DISPLAY_TYPE_DIGITAL ____________________________________________________*/
/*!
Summary
   EDID digital display types
Description
   The VHD_EDID_DISPLAY_TYPE_DIGITAL enumeration lists all the supported
   EDID digital display types.
See Also
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE
*/
typedef enum _VHD_EDID_DISPLAY_TYPE_DIGITAL
{
   VHD_EDID_DISPLAY_TYPE_DIGITAL_RGB_444,
   VHD_EDID_DISPLAY_TYPE_DIGITAL_RGB_444_YCRCB_444,
   VHD_EDID_DISPLAY_TYPE_DIGITAL_RGB_444_YCRCB_422,
   VHD_EDID_DISPLAY_TYPE_DIGITAL_RGB_444_YCRCB_444_YCRCB_422,
   NB_VHD_EDID_DISPLAY_TYPE_DIGITAL
}VHD_EDID_DISPLAY_TYPE_DIGITAL;

/*_ VHD_EDID_DISPLAY_TYPE_ANALOG ____________________________________________________*/
/*!
Summary
   EDID analog display types
Description
   The VHD_EDID_DISPLAY_TYPE_ANALOG enumeration lists all the supported
   EDID analog display types.
See Also
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE
*/
typedef enum _VHD_EDID_DISPLAY_TYPE_ANALOG
{
   VHD_EDID_DISPLAY_TYPE_ANALOG_UNDEFINED,
   VHD_EDID_DISPLAY_TYPE_ANALOG_MONOCHROME,
   VHD_EDID_DISPLAY_TYPE_ANALOG_RGB_COLOR,
   VHD_EDID_DISPLAY_TYPE_ANALOG_NON_RGB_COLOR,
   NB_VHD_EDID_DISPLAY_TYPE_ANALOG
}VHD_EDID_DISPLAY_TYPE_ANALOG;

/*_ VHD_EDID_ASPECT_RATIO ____________________________________________________*/
/*!
Summary
   EDID aspect ratios
Description
   The VHD_EDID_ASPECT_RATIO enumeration lists all the supported
   EDID aspect ratios.
See Also
   VHD_EDID_STANDARD_TIMING_INFORMATION, VHD_EDID_DISPLAY_RANGE_LIMITS_CVT
*/
typedef enum _VHD_EDID_ASPECT_RATIO
{
   VHD_EDID_ASPECT_RATIO_1_1,
   VHD_EDID_ASPECT_RATIO_5_4,
   VHD_EDID_ASPECT_RATIO_4_3,
   VHD_EDID_ASPECT_RATIO_16_10,
   VHD_EDID_ASPECT_RATIO_16_9,
   VHD_EDID_ASPECT_RATIO_15_9,
   NB_VHD_EDID_ASPECT_RATIO
}VHD_EDID_ASPECT_RATIO;

/*_ VHD_EDID_STEREO_MODE ____________________________________________________*/
/*!
Summary
   EDID stereo modes
Description
   The VHD_EDID_STEREO_MODE enumeration lists all the supported
   EDID stereo modes.
See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR
*/
typedef enum _VHD_EDID_STEREO_MODE
{
   VHD_EDID_STEREO_MODE_NO_STEREO,
   VHD_EDID_STEREO_MODE_FIELD_SEQUENTIAL_SYNC_DURING_RIGHT,
   VHD_EDID_STEREO_MODE_FIELD_SEQUENTIAL_SYNC_DURING_LEFT,
   VHD_EDID_STEREO_MODE_4_WAY_INTERLEAVED,
   VHD_EDID_STEREO_MODE_RIGHT_IMAGE_ON_EVEN_LINES,
   VHD_EDID_STEREO_MODE_LEFT_IMAGE_ON_EVEN_LINES,
   VHD_EDID_STEREO_MODE_SIDE_BY_SIDE,
   NB_VHD_EDID_STEREO_MODE
}VHD_EDID_STEREO_MODE;

/*_ VHD_EDID_SYNC_TYPE ____________________________________________________*/
/*!
Summary
   EDID sync types
Description
   The VHD_EDID_SYNC_TYPE enumeration lists all the supported
   EDID sync types.
See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR
*/
typedef enum _VHD_EDID_SYNC_TYPE
{
   VHD_EDID_SYNC_TYPE_ANALOG_COMPOSITE,
   VHD_EDID_SYNC_TYPE_BIPOLAR_ANALOG_COMPOSITE,
   VHD_EDID_SYNC_TYPE_DIGITAL_COMPOSITE,
   VHD_EDID_SYNC_TYPE_DIGITAL_SEPARATE_SYNC,
   NB_VHD_EDID_SYNC_TYPE
}VHD_EDID_SYNC_TYPE;

/*_ VHD_EDID_DESCRIPTOR_TYPE ____________________________________________________*/
/*!
Summary
   EDID descriptor types
Description
   The VHD_EDID_DESCRIPTOR_TYPE enumeration lists all the supported
   EDID descriptor types.
See Also
   VHD_EDID_DESCRIPTION
*/
typedef enum _VHD_EDID_DESCRIPTOR_TYPE
{
   VHD_EDID_DESCRIPTOR_TYPE_DETAILED_TIMING_DESCRIPTOR,
   VHD_EDID_DESCRIPTOR_TYPE_DISPLAY_SERIAL_NUMBER,
   VHD_EDID_DESCRIPTOR_TYPE_UNSPECIFIED_TEXT,
   VHD_EDID_DESCRIPTOR_TYPE_DISPLAY_RANGE_LIMITS,
   VHD_EDID_DESCRIPTOR_TYPE_DISPLAY_NAME,
   VHD_EDID_DESCRIPTOR_TYPE_ADDITIONAL_WHITE_POINT_DATA,
   VHD_EDID_DESCRIPTOR_TYPE_ADDITIONAL_STANDARD_TIMING,
   VHD_EDID_DESCRIPTOR_TYPE_DISPLAY_COLOR_MANAGEMENT,
   VHD_EDID_DESCRIPTOR_TYPE_CVT_TIMING_CODES,
   VHD_EDID_DESCRIPTOR_TYPE_ADDITIONAL_STANDARD_TIMING_3,
   VHD_EDID_DESCRIPTOR_TYPE_DUMMY,
   NB_VHD_EDID_DESCRIPTOR_TYPE
}VHD_EDID_DESCRIPTOR_TYPE;

/*_ VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE ____________________________________________________*/
/*!
Summary
   EDID extended timing information types
Description
   The VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE enumeration lists all the supported
   EDID extended timing information types.
See Also
   VHD_EDID_DISPLAY_RANGE_LIMITS
*/
typedef enum _VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE
{
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE_DEFAULT_GTF,
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE_NO_TIMING_INFORMATION,
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE_SECONDARY_GTF_SUPPORTED,
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE_CVT,
   NB_VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE
}VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE;

/*_ VHD_EDID_ADDITIONAL_TIMING ____________________________________________________*/
/*!
Summary
   EDID additional timings
Description
   The VHD_EDID_ADDITIONAL_TIMING enumeration lists all the supported
   EDID additional timings.
See Also
   VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR
*/
typedef enum _VHD_EDID_ADDITIONAL_TIMING
{
   VHD_EDID_ADDITIONAL_TIMING_640x350p85,
   VHD_EDID_ADDITIONAL_TIMING_640x400p85,
   VHD_EDID_ADDITIONAL_TIMING_720x400p85,
   VHD_EDID_ADDITIONAL_TIMING_640x480p85,
   VHD_EDID_ADDITIONAL_TIMING_848x480p60,
   VHD_EDID_ADDITIONAL_TIMING_800x600p85,
   VHD_EDID_ADDITIONAL_TIMING_1024x768p85,
   VHD_EDID_ADDITIONAL_TIMING_1152x864p85,
   VHD_EDID_ADDITIONAL_TIMING_1280x768p60_RB,
   VHD_EDID_ADDITIONAL_TIMING_1280x768p60,
   VHD_EDID_ADDITIONAL_TIMING_1280x768p75,
   VHD_EDID_ADDITIONAL_TIMING_1280x768p85,
   VHD_EDID_ADDITIONAL_TIMING_1280x960p60,
   VHD_EDID_ADDITIONAL_TIMING_1280x960p85,
   VHD_EDID_ADDITIONAL_TIMING_1280x1024p60,
   VHD_EDID_ADDITIONAL_TIMING_1280x1024p85,
   VHD_EDID_ADDITIONAL_TIMING_1360x768p60,
   VHD_EDID_ADDITIONAL_TIMING_1440x900p60_RB,
   VHD_EDID_ADDITIONAL_TIMING_1440x900p60,
   VHD_EDID_ADDITIONAL_TIMING_1440x900p75,
   VHD_EDID_ADDITIONAL_TIMING_1440x900p85,
   VHD_EDID_ADDITIONAL_TIMING_1440x1050p60_RB,
   VHD_EDID_ADDITIONAL_TIMING_1440x1050p60,
   VHD_EDID_ADDITIONAL_TIMING_1440x1050p75,
   VHD_EDID_ADDITIONAL_TIMING_1440x1050p85,
   VHD_EDID_ADDITIONAL_TIMING_1680x1050p60_RB,
   VHD_EDID_ADDITIONAL_TIMING_1680x1050p60,
   VHD_EDID_ADDITIONAL_TIMING_1680x1050p75,
   VHD_EDID_ADDITIONAL_TIMING_1680x1050p85,
   VHD_EDID_ADDITIONAL_TIMING_1600x1200p60,
   VHD_EDID_ADDITIONAL_TIMING_1600x1200p65,
   VHD_EDID_ADDITIONAL_TIMING_1600x1200p70,
   VHD_EDID_ADDITIONAL_TIMING_1600x1200p75,
   VHD_EDID_ADDITIONAL_TIMING_1600x1200p85,
   VHD_EDID_ADDITIONAL_TIMING_1792x1344p60,
   VHD_EDID_ADDITIONAL_TIMING_1792x1344p75,
   VHD_EDID_ADDITIONAL_TIMING_1856x1392p60,
   VHD_EDID_ADDITIONAL_TIMING_1856x1392p75,
   VHD_EDID_ADDITIONAL_TIMING_1920x1200p60_RB,
   VHD_EDID_ADDITIONAL_TIMING_1920x1200p60,
   VHD_EDID_ADDITIONAL_TIMING_1920x1200p75,
   VHD_EDID_ADDITIONAL_TIMING_1920x1200p85,
   VHD_EDID_ADDITIONAL_TIMING_1920x1440p60,
   VHD_EDID_ADDITIONAL_TIMING_1920x1440p75,
   NB_VHD_EDID_ADDITIONAL_TIMING
}VHD_EDID_ADDITIONAL_TIMING;

/*_ VHD_EDID_CEA_861_BLOCK_TYPE ____________________________________________________*/
/*!
Summary
   EDID CEA-861 extension block types
Description
   The VHD_EDID_CEA_861_BLOCK_TYPE enumeration lists all the supported
   EDID CEA-861 extension block types.
See Also
   VHD_EDID_EXTENSION_CEA_861
*/
typedef enum _VHD_EDID_CEA_861_BLOCK_TYPE
{
   VHD_EDID_CEA_861_BLOCK_TYPE_AUDIO,
   VHD_EDID_CEA_861_BLOCK_TYPE_VIDEO,
   VHD_EDID_CEA_861_BLOCK_TYPE_VENDOR_SPECIFIC,
   VHD_EDID_CEA_861_BLOCK_TYPE_SPEAKER,
   VHD_EDID_CEA_861_BLOCK_TYPE_VESA_DISPLAY_TCS,
   VHD_EDID_CEA_861_BLOCK_TYPE_VIDEO_CAPABILITY,
   VHD_EDID_CEA_861_BLOCK_TYPE_VENDOR_SPECIFIC_VIDEO,
   VHD_EDID_CEA_861_BLOCK_TYPE_VESA_DISPLAY_DEVICE,
   VHD_EDID_CEA_861_BLOCK_TYPE_VESA_VIDEO_TIMING,
   VHD_EDID_CEA_861_BLOCK_TYPE_COLORIMETRY,
   VHD_EDID_CEA_861_BLOCK_TYPE_HDR_STATIC_METADATA,
   VHD_EDID_CEA_861_BLOCK_TYPE_HDR_DYNAMIC_METADATA,
   VHD_EDID_CEA_861_BLOCK_TYPE_VIDEO_FORMAT_PREFERENCE,
   VHD_EDID_CEA_861_BLOCK_TYPE_YCBCR_420_VIDEO,
   VHD_EDID_CEA_861_BLOCK_TYPE_YCBCR_420_CAPABILITY_MAP,
   VHD_EDID_CEA_861_BLOCK_TYPE_VENDOR_SPECIFIC_AUDIO,
   VHD_EDID_CEA_861_BLOCK_TYPE_ROOM_CONFIGURATION,
   VHD_EDID_CEA_861_BLOCK_TYPE_SPEAKER_LOCATION,
   VHD_EDID_CEA_861_BLOCK_TYPE_INFOFRAME,
   VHD_EDID_CEA_861_BLOCK_TYPE_UNRECOGNIZED,
   NB_VHD_EDID_CEA_861_BLOCK_TYPE
}VHD_EDID_CEA_861_BLOCK_TYPE;

/*_ VHD_EDID_CEA_861_AUDIO_FORMAT ____________________________________________________*/
/*!
Summary
   EDID CEA-861 extension audio formats
Description
   The VHD_EDID_CEA_861_AUDIO_FORMAT enumeration lists all the supported
   EDID CEA-861 extension audio formats.
See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA
*/
typedef enum _VHD_EDID_CEA_861_AUDIO_FORMAT
{
   VHD_EDID_CEA_861_AUDIO_FORMAT_LPCM,
   VHD_EDID_CEA_861_AUDIO_FORMAT_AC_3,
   VHD_EDID_CEA_861_AUDIO_FORMAT_MPEG_1,
   VHD_EDID_CEA_861_AUDIO_FORMAT_MP3,
   VHD_EDID_CEA_861_AUDIO_FORMAT_MPEG_2,
   VHD_EDID_CEA_861_AUDIO_FORMAT_AAC,
   VHD_EDID_CEA_861_AUDIO_FORMAT_DTS,
   VHD_EDID_CEA_861_AUDIO_FORMAT_ATRAC,
   VHD_EDID_CEA_861_AUDIO_FORMAT_SACD,
   VHD_EDID_CEA_861_AUDIO_FORMAT_DD_PLUS,
   VHD_EDID_CEA_861_AUDIO_FORMAT_DTS_HD,
   VHD_EDID_CEA_861_AUDIO_FORMAT_DOLBY_TRUEHD,
   VHD_EDID_CEA_861_AUDIO_FORMAT_DST,
   VHD_EDID_CEA_861_AUDIO_FORMAT_WMA_PRO,
   NB_VHD_EDID_CEA_861_AUDIO_FORMAT
}VHD_EDID_CEA_861_AUDIO_FORMAT;

/*_ VHD_EDID_UTF_TYPE ____________________________________________________*/
/*!
Summary
   EDID UTF types
Description
   The VHD_EDID_UTF_TYPE enumeration lists all the supported
   EDID UTF types.
See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA
*/
typedef enum _VHD_EDID_UTF_TYPE
{
   VHD_EDID_UTF_TYPE_UTF_8,
   VHD_EDID_UTF_TYPE_UTF_16_BE,
   VHD_EDID_UTF_TYPE_UTF_32_BE,
   NB_VHD_EDID_UTF_TYPE
}VHD_EDID_UTF_TYPE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_EDID
*/

/*_ VHD_EDID_WARNINGS ____________________________________________________*/
/*!
   Summary
   EDID warning data structure
   Description
   The VHD_EDID_WARNINGS structure holds the warnings encountered
   while parsing an EDID buffer.

   See Also
   VHD_GetEDIDBuffer, VHD_GetEDIDData
*/
typedef struct _VHD_EDID_WARNINGS
{
   VHD_EDID_WARNING_CODE pWarnings[VHD_EDID_MAX_WARNINGS]; /*!< Warning array */
   ULONG NbWarnings; /*!< Number of warnings (can be larger than VHD_EDID_MAX_WARNINGS!) */
}VHD_EDID_WARNINGS;

/*_ VHD_EDID_HEADER_INFORMATION ____________________________________________________*/
/*!
   Summary
   EDID header information data structure
   Description
   The VHD_EDID_HEADER_INFORMATION structure holds the data related to some given
   EDID header information.

   See Also
   VHD_EDID_DESCRIPTION
*/
typedef struct _VHD_EDID_HEADER_INFORMATION
{
   char pManufacturerId[VHD_EDID_MANUFACTURER_ID_STRING_MAX_LENGTH]; /*!< Manufacturer ID */
   UWORD ManufacturerProductCode; /*!< Manufacturer product code */
   ULONG SerialNumber; /*!< Serial number */
   UBYTE ManufactureWeek; /*!< Week of manufacture */
   ULONG ManufactureYear; /*!< Year of manufacture (if week is 255, it is the model year instead) */
   UBYTE EDIDVersion; /*!< EDID version */
   UBYTE EDIDRevision; /*!< EDID revision */
}VHD_EDID_HEADER_INFORMATION;

/*_ VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS ____________________________________________________*/
/*!
   Summary
   EDID digital display parameters data structure
   Description
   The VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS structure holds the data related to some given
   EDID digital display parameters.

   See Also
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS,
   VHD_EDID_BIT_DEPTH, VHD_EDID_VIDEO_INTERFACE
*/
typedef struct _VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS
{
   VHD_EDID_BIT_DEPTH BitDepth; /*!< Bit depth (see VHD_EDID_BIT_DEPTH) */
   VHD_EDID_VIDEO_INTERFACE VideoInterface; /*!< Video interface (see VHD_EDID_VIDEO_INTERFACE) */
}VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS;

/*_ VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS ____________________________________________________*/
/*!
   Summary
   EDID analog display parameters data structure
   Description
   The VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS structure holds the data related to some given
   EDID analog display parameters.

   See Also
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS
*/
typedef struct _VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS
{
   float WhiteLevel; /*!< Video white level, relative to blank (V) */
   float SyncLevel; /*!< Video sync level, relative to blank (V) */
   BOOL32 BlankToBlackSetupExpected; /*!< TRUE if blank-to-black setup (pedestal) expected, FALSE otherwise */
   BOOL32 SeparateSyncSupported; /*!< TRUE if separate sync supported, FALSE otherwise */
   BOOL32 CompositeSyncSupported; /*!< TRUE if composite sync (on HSync) supported, FALSE otherwise */
   BOOL32 SyncOnGreenSupported; /*!< TRUE if sync on green supported, FALSE otherwise */
   BOOL32 VSyncPulseSerrate; /*!< TRUE if VSync pulse must be serrated when composite or sync-on-green is used, FALSE otherwise */
}VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS;

/*_ VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS ____________________________________________________*/
/*!
   Summary
   EDID basic display parameters video input parameters union
   Description
   The VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS union holds the data related to some given
   EDID basic display parameters video input parameters.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored along side a boolean
   value telling whether the display is digital or analog,
   giving information on what field should be accessed.

   See Also
   VHD_EDID_BASIC_DISPLAY_PARAMETERS,
   VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS,
   VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS
*/
typedef union _VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS
{
   VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS Digital; /*!< Digital display parameters (see VHD_EDID_BASIC_DISPLAY_DIGITAL_PARAMETERS) */
   VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS Analog; /*!< Analog display parameters (see VHD_EDID_BASIC_DISPLAY_ANALOG_PARAMETERS) */
}VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS;

/*_ VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE ____________________________________________________*/
/*!
   Summary
   EDID basic display parameters display type union
   Description
   The VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE union holds the data related to a given
   EDID basic display parameters display type.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored along side a boolean
   value telling whether the display is digital or analog,
   giving information on what field should be accessed.

   See Also
   VHD_EDID_BASIC_DISPLAY_PARAMETERS,
   VHD_EDID_DISPLAY_TYPE_DIGITAL, VHD_EDID_DISPLAY_TYPE_ANALOG
*/
typedef union _VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE
{
   VHD_EDID_DISPLAY_TYPE_DIGITAL Digital; /*!< Digital display type (see VHD_EDID_DISPLAY_TYPE_DIGITAL) */
   VHD_EDID_DISPLAY_TYPE_ANALOG Analog; /*!< Analog display type (see VHD_EDID_DISPLAY_TYPE_ANALOG) */
}VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE;

/*_ VHD_EDID_BASIC_DISPLAY_PARAMETERS ____________________________________________________*/
/*!
   Summary
   EDID basic display parameters data structure
   Description
   The VHD_EDID_BASIC_DISPLAY_PARAMETERS structure holds the data related to some given
   EDID basic display parameters.

   See Also
   VHD_EDID_DESCRIPTION,
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS,
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE
*/
typedef struct _VHD_EDID_BASIC_DISPLAY_PARAMETERS
{
   BOOL32 DigitalInput; /*!< TRUE if digital input, FALSE otherwise */
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS VideoInputParameters; /*!< Video input parameters (see VHD_EDID_BASIC_DISPLAY_PARAMETERS_VIDEO_INPUT_PARAMETERS) */
   UBYTE HorizontalScreenSize; /*!< Horizontal screen size (cm) */
   UBYTE VerticalScreenSize; /*!< Vertical screen size (cm) */
   float DisplayGamma; /*!< Display gamma */
   BOOL32 DPMSStandbySupported; /*!< TRUE if DPMS standby supported, FALSE otherwise */
   BOOL32 DPMSSuspendSupported; /*!< TRUE if DPMS suspend supported, FALSE otherwise */
   BOOL32 DPMSActiveOffSupported; /*!< TRUE if DPMS active-off supported, FALSE otherwise */
   VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE DisplayType; /*!< Display type (see VHD_EDID_BASIC_DISPLAY_PARAMETERS_DISPLAY_TYPE) */
   BOOL32 StandardsRGBColorSpace; /*!< TRUE if standard sRGB colour space, FALSE otherwise */
   BOOL32 PreferredTimingMode; /*!< TRUE if the preferred timing mode includes native pixel format and refresh rate, FALSE otherwise */
   BOOL32 ContinuousTimingsSupported; /*!< TRUE if continuous timings with GTF or CVT, FALSE otherwise */
}VHD_EDID_BASIC_DISPLAY_PARAMETERS;

/*_ VHD_EDID_CHROMATICITY_COORDINATES ____________________________________________________*/
/*!
   Summary
   EDID chromaticity coordinates data structure
   Description
   The VHD_EDID_CHROMATICITY_COORDINATES structure holds the data related to some given
   EDID chromaticity coordinates.

   See Also
   VHD_EDID_DESCRIPTION
*/
typedef struct _VHD_EDID_CHROMATICITY_COORDINATES
{
   float RedPosX; /*!< Red x value */
   float RedPosY; /*!< Red y value */
   float GreenPosX; /*!< Green x value */
   float GreenPosY; /*!< Green y value */
   float BluePosX; /*!< Blue x value */
   float BluePosY; /*!< Blue y value */
   float WhitePosX; /*!< White x value */
   float WhitePosY; /*!< White y value */
}VHD_EDID_CHROMATICITY_COORDINATES;

/*_ VHD_EDID_STANDARD_TIMING_INFORMATION ____________________________________________________*/
/*!
   Summary
   EDID standard timing information data structure
   Description
   The VHD_EDID_STANDARD_TIMING_INFORMATION structure holds the data related to some given
   EDID standard timing information.

   See Also
   VHD_EDID_DESCRIPTION,
   VHD_GetStandardTimingVideoCharacteristics
*/
typedef struct _VHD_EDID_STANDARD_TIMING_INFORMATION
{
   UWORD XResolution; /*!< X resolution */
   VHD_EDID_ASPECT_RATIO AspectRatio; /*!< Image aspect ratio (see VHD_EDID_ASPECT_RATIO) */
   UWORD VerticalFrequency; /*!< Vertical frequency (Hz) */
}VHD_EDID_STANDARD_TIMING_INFORMATION;

/*_ VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID detailed timing analog sync data structure
   Description
   The VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR structure holds
   the data related to a given EDID detailed timing analog sync.

   See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO
*/
typedef struct _VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR
{
   BOOL32 Bipolar; /*!< TRUE if bipolar analog composite, FALSE otherwise */
   BOOL32 VSyncSerration; /*!< TRUE if VSync serration (HSync during VSync), FALSE otherwise */
   BOOL32 SyncOnAllThreeRGBLines; /*!< TRUE if sync on all 3 RGB lines, FALSE if green only */
}VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR;

/*_ VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID detailed timing digital composite sync data structure
   Description
   The VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR structure holds
   the data related to a given EDID detailed timing digital composite sync.

   See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO
*/
typedef struct _VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR
{
   BOOL32 PositiveVerticalSyncPolarity; /*!< TRUE if positive vertical sync polarity, FALSE if negative */
}VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR;

/*_ VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID detailed timing digital separate sync data structure
   Description
   The VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR structure holds
   the data related to a given EDID detailed timing digital separate sync.

   See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO
*/
typedef struct _VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR
{
   BOOL32 VSyncSerration; /*!< TRUE if VSync serration (HSync during VSync), FALSE otherwise */
   BOOL32 PositiveHorizontalSyncPolarity; /*!< TRUE if positive horizontal sync polarity, FALSE if negative */
}VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR;

/*!
   Summary
   EDID detailed timing sync information union
   Description
   The VHD_EDID_EXTENDED_TIMING_INFORMATION union holds the data related to some given
   EDID detailed timing sync information.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored along side its 
   sync type (see VHD_EDID_SYNC_TYPE),
   giving information on what field should be accessed.

   See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR,
   VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR,
   VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR,
   VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR
*/
typedef union _VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO
{
   VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR AnalogSync; /*!< Analog sync descriptor (see VHD_EDID_DETAILED_TIMING_ANALOG_SYNC_DESCRIPTOR) */
   VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR DigitalCompositeSync; /*!< Digital composite (on HSync) descriptor (see VHD_EDID_DETAILED_TIMING_DIGITAL_COMPOSITE_SYNC_DESCRIPTOR) */
   VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR DigitalSeparateSync; /*!< Digital separate sync descriptor (see VHD_EDID_DETAILED_TIMING_DIGITAL_SEPARATE_SYNC_DESCRIPTOR) */
}VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO;

/*_ VHD_EDID_DETAILED_TIMING_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID detailed timing descriptor data structure
   Description
   The VHD_EDID_DETAILED_TIMING_DESCRIPTOR structure holds the data related to a given
   EDID detailed timing descriptor.

   See Also
   VHD_EDID_DESCRIPTOR, VHD_EDID_EXTENSION_CEA_861,
   VHD_EDID_STEREO_MODE, VHD_EDID_SYNC_TYPE, VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO
*/
typedef struct _VHD_EDID_DETAILED_TIMING_DESCRIPTOR
{
   ULONG PixelClock; /*!< Pixel clock (Hz) */
   UWORD HorizontalActivePixels; /*!< Horizontal active pixels */
   UWORD HorizontalBlankingPixels; /*!< Horizontal blanking pixels */
   UWORD HorizontalFrontPorch; /*!< Horizontal front porch (sync offset) pixels */
   UWORD HorizontalSyncPulseWidth; /*!< Horizontal sync pulse width pixels */
   UWORD HorizontalImageSize; /*!< Horizontal image size (mm) */
   UBYTE HorizontalBorderPixels; /*!< Horizontal border pixels (one side, total is twice this value) */
   UWORD VerticalActiveLines; /*!< Vertical active lines */
   UWORD VerticalBlankingLines; /*!< Vertical blanking lines */
   UWORD VerticalFrontPorch; /*!< Vertical front porch (sync offset) lines */
   UWORD VerticalSyncPulseWidth; /*!< Vertical sync pulse width lines */
   UWORD VerticalImageSize; /*!< Vertical image size (mm) */
   UBYTE VerticalBorderLines; /*!< Vertical border lines (one side, total is twice this value) */
   BOOL32 Interlaced; /*!< TRUE if interlaced, FALSE otherwise */
   VHD_EDID_STEREO_MODE StereoMode; /*!< Stereo mode (see VHD_EDID_STEREO_MODE) */
   VHD_EDID_SYNC_TYPE SyncType; /*!< Sync type (see VHD_EDID_SYNC_TYPE) */
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO SyncDescription; /*!< Sync description information (see VHD_EDID_DETAILED_TIMING_DESCRIPTOR_SYNC_INFO) */
   BOOL32 TwoWayLineInterleaved; /*!< TRUE if 2-way line-interleaved or side-by-side interleaved stereo, FALSE otherwise */
}VHD_EDID_DETAILED_TIMING_DESCRIPTOR;

/*_ VHD_EDID_DISPLAY_RANGE_LIMITS_GTF ____________________________________________________*/
/*!
   Summary
   EDID display range limits GTF data structure
   Description
   The VHD_EDID_DISPLAY_RANGE_LIMITS_GTF structure holds the data related to some given
   EDID display range limits GTF data.

   See Also
   VHD_EDID_EXTENDED_TIMING_INFORMATION
*/
typedef struct _VHD_EDID_DISPLAY_RANGE_LIMITS_GTF
{
   ULONG StartFrequency; /*!< Start frequency (Hz) */
   float CValue; /*!< C value */
   UWORD MValue; /*!< M value */
   UBYTE KValue; /*!< K value */
   float JValue; /*!< J value */
}VHD_EDID_DISPLAY_RANGE_LIMITS_GTF;

/*_ VHD_EDID_DISPLAY_RANGE_LIMITS_CVT ____________________________________________________*/
/*!
   Summary
   EDID display range limits CVT data structure
   Description
   The VHD_EDID_DISPLAY_RANGE_LIMITS_CVT structure holds the data related to a given
   EDID display range limits CVT data.

   See Also
   VHD_EDID_EXTENDED_TIMING_INFORMATION, 
   VHD_EDID_ASPECT_RATIO
*/
typedef struct _VHD_EDID_DISPLAY_RANGE_LIMITS_CVT
{
   UBYTE MajorVersion; /*!< Major version number */
   UBYTE MinorVersion; /*!< Minor version number */
   ULONG AdditionalClockPrecision; /*!< Additional clock precision (Hz) (to be subtracted from maximum pixel clock rate, see VHD_EDID_DISPLAY_RANGE_LIMITS) */
   UWORD MaximumActivePixelsPerLine; /*!< Maximum active pixels per line */
   VHD_EDID_ASPECT_RATIO pAspectRatios[VHD_EDID_MAX_NB_ASPECT_RATIOS]; /*!< Array of supported aspect ratios (see VHD_EDID_ASPECT_RATIO) */
   ULONG NbAspectRatios;
   VHD_EDID_ASPECT_RATIO PreferredAspectRatio; /*!< Aspect ratio preference (see VHD_EDID_ASPECT_RATIO) */
   BOOL32 ReducedBlankingPreferred; /*!< TRUE if CVT-RB reduced blanking is preferred, FALSE otherwise */
   BOOL32 StandardBlanking; /*!< TRUE if CVT standard blanking is preferred, FALSE otherwise */
   BOOL32 HorizontalShrink; /*!< TRUE if horizontal shrink is supported, FALSE otherwise */
   BOOL32 HorizontalStretch; /*!< TRUE if horizontal stretch is supported, FALSE otherwise */
   BOOL32 VerticalShrink; /*!< TRUE if vertical shrink is supported, FALSE otherwise */
   BOOL32 VerticalStretch; /*!< TRUE if vertical stretch is supported, FALSE otherwise */
   UBYTE PreferredVerticalRefreshRate; /*!< Preferred vertical refresh rate (Hz) */
}VHD_EDID_DISPLAY_RANGE_LIMITS_CVT;

/*!
   Summary
   EDID extended timing information union
   Description
   The VHD_EDID_EXTENDED_TIMING_INFORMATION union holds the data related to a given
   EDID extended timing information.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored along side its 
   extended timing information type (see VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE),
   giving information on what field should be accessed.

   See Also
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE,
   VHD_EDID_DISPLAY_RANGE_LIMITS_GTF, VHD_EDID_DISPLAY_RANGE_LIMITS_CVT
*/
typedef union _VHD_EDID_EXTENDED_TIMING_INFORMATION
{
   VHD_EDID_DISPLAY_RANGE_LIMITS_GTF GTFInformation; /*!< GTF information (see VHD_EDID_DISPLAY_RANGE_LIMITS_GTF) */
   VHD_EDID_DISPLAY_RANGE_LIMITS_CVT CVTInformation; /*!< CVT information (see VHD_EDID_DISPLAY_RANGE_LIMITS_CVT) */
}VHD_EDID_EXTENDED_TIMING_INFORMATION;

/*_ VHD_EDID_DISPLAY_RANGE_LIMITS ____________________________________________________*/
/*!
   Summary
   EDID display range limits data structure
   Description
   The VHD_EDID_DISPLAY_RANGE_LIMITS structure holds the data related to some given
   EDID display range limits data.

   See Also
   VHD_EDID_DESCRIPTOR,
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE, VHD_EDID_EXTENDED_TIMING_INFORMATION
*/
typedef struct _VHD_EDID_DISPLAY_RANGE_LIMITS
{
   ULONG MinimumHorizontalLineRate; /*!< Minimum horizontal line rate (Hz) */
   ULONG MaximumHorizontalLineRate; /*!< Maximum horizontal line rate (Hz) */
   UWORD MinimumVerticalFieldRate; /*!< Minimum vertical field rate (Hz) */
   UWORD MaximumVerticalFieldRate; /*!< Maximum vertical field rate (Hz) */
   ULONG MaximumPixelClockRate; /*!< Maximum pixel clock rate (Hz) */
   VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE ExtendedTimingInformationType; /*!< Extended timing information type (see VHD_EDID_EXTENDED_TIMING_INFORMATION_TYPE) */
   VHD_EDID_EXTENDED_TIMING_INFORMATION ExtendedTimingInformation; /*!< Extended timing information (see VHD_EDID_EXTENDED_TIMING_INFORMATION) */
}VHD_EDID_DISPLAY_RANGE_LIMITS;

/*_ VHD_EDID_WHITE_POINT_DATA ____________________________________________________*/
/*!
   Summary
   EDID white point data structure
   Description
   The VHD_EDID_WHITE_POINT_DATA structure holds the data related to some given
   EDID white point data.

   See Also
   VHD_EDID_DESCRIPTOR
*/
typedef struct _VHD_EDID_WHITE_POINT_DATA
{
   BOOL32 Used; /*!< TRUE if white point data is relevant, FALSE otherwise */
   UBYTE Index; /*!< White point number index */
   float PosX; /*!< White point x value */
   float PosY; /*!< White point y value */
   float GammaValue; /*!< White point gamma value */
}VHD_EDID_WHITE_POINT_DATA;

/*_ VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID standard timing information descriptor data structure
   Description
   The VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR structure holds the data related to a given
   EDID standard timing information descriptor.

   See Also
   VHD_EDID_DESCRIPTOR, VHD_EDID_STANDARD_TIMING_INFORMATION
*/
typedef struct _VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR
{
   VHD_EDID_STANDARD_TIMING_INFORMATION pAdditionalStandardTimings[VHD_EDID_MAX_NB_ADDITIONAL_STANDARD_TIMINGS]; /*!< Array of standard timing information (see VHD_EDID_STANDARD_TIMING_INFORMATION) */
   UBYTE NbStandardTimingInformation; /*!< Number of standard timing information (see VHD_EDID_STANDARD_TIMING_INFORMATION) */
}VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR;

/*_ VHD_EDID_COLOR_MANAGEMENT_DATA ____________________________________________________*/
/*!
   Summary
   EDID color management data structure
   Description
   The VHD_EDID_COLOR_MANAGEMENT_DATA structure holds the data related to some given
   EDID color management data.

   See Also
   VHD_EDID_DESCRIPTOR
*/
typedef struct _VHD_EDID_COLOR_MANAGEMENT_DATA
{
   UBYTE Version; /*!< Version number s*/
   UWORD RedA3; /*!< Red a3 */
   UWORD RedA2; /*!< Red a2 */
   UWORD GreenA3; /*!< Green a3 */
   UWORD GreenA2; /*!< Green a2 */
   UWORD BlueA3; /*!< Blue a3 */
   UWORD BlueA2; /*!< Blue a2 */
}VHD_EDID_COLOR_MANAGEMENT_DATA;

/*_ VHD_EDID_CVT_TIMING ____________________________________________________*/
/*!
   Summary
   EDID CVT timing  data structure
   Description
   The VHD_EDID_CVT_TIMING structure holds the data related to a given
   EDID CVT timing.

   See Also
   VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR, VHD_EDID_ASPECT_RATIO
*/
typedef struct _VHD_EDID_CVT_TIMING
{
   UWORD AddressableLines; /*!< Number of addressable lines */
   UBYTE PreferredVericalRate; /*!< Preferred vertical rate*/
   VHD_EDID_ASPECT_RATIO AspectRatio; /*!< Aspect ratio (see VHD_EDID_ASPECT_RATIO) */
   BOOL32 Supports50Hz; /*!< Supports 50Hz vertical rate */
   BOOL32 Supports60Hz; /*!< Supports 60Hz vertical rate */
   BOOL32 Supports75Hz; /*!< Supports 75Hz vertical rate */
   BOOL32 Supports85Hz; /*!< Supports 85Hz vertical rate */
   BOOL32 Supports60HzCVTRB; /*!< Supports 60Hz CVT-RB vertical rate */
}VHD_EDID_CVT_TIMING;

/*_ VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID CVT timing descriptor data structure
   Description
   The VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR structure holds the data related to a given
   EDID CVT timing descriptor.

   See Also
   VHD_EDID_DESCRIPTOR, VHD_EDID_CVT_TIMING
*/
typedef struct _VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR
{
   UBYTE Version; /*!< Version number */
   VHD_EDID_CVT_TIMING pCVTTimings[VHD_EDID_MAX_NB_CVT_TIMINGS]; /*!< Array of CVT timings (see VHD_EDID_CVT_TIMING) */
}VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR;

/*_ VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID additional standard timings descriptor data structure
   Description
   The VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR structure holds the data related to a given
   EDID additional standard timings descriptor.

   See Also
   VHD_EDID_DESCRIPTOR, VHD_EDID_ADDITIONAL_TIMING
*/
typedef struct _VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR
{
   UBYTE Version; /*!< Version number */
   VHD_EDID_ADDITIONAL_TIMING pSupportedAdditionalTimings[VHD_EDID_MAX_NB_ADDITIONAL_TIMINGS]; /*!< Array of supported additional standard timings (see VHD_EDID_ADDITIONAL_TIMING) */
   ULONG NbSupportedAdditionalTimings;
}VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR;

/*_ VHD_EDID_DESCRIPTOR_DATA ____________________________________________________*/
/*!
   Summary
   EDID descriptor union
   Description
   The VHD_EDID_DESCRIPTOR_DATA union holds the data related to a given
   EDID descriptor.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored in an array indexed by
   descriptor types (see VHD_EDID_DESCRIPTOR_TYPE), allowing one
   to know which field should be used based on that descriptor type.

   See Also
   VHD_EDID_DESCRIPTOR_TYPE, VHD_EDID_DETAILED_TIMING_DESCRIPTOR,
   VHD_EDID_DISPLAY_RANGE_LIMITS, VHD_EDID_WHITE_POINT_DATA,
   VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR, VHD_EDID_COLOR_MANAGEMENT_DATA
*/
typedef union _VHD_EDID_DESCRIPTOR_DATA
{
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR DetailedTimingDescription; /*!< Detailed timing descriptor (see VHD_EDID_DETAILED_TIMING_DESCRIPTOR) */
   char pDisplaySerialNumber[VHD_EDID_DESCRIPTOR_STRING_BUFFER_MAX_LENGTH]; /*!< Display serial number string */
   char pUnspecifiedText[VHD_EDID_DESCRIPTOR_STRING_BUFFER_MAX_LENGTH]; /*!< Unspecified text */
   VHD_EDID_DISPLAY_RANGE_LIMITS DisplayRangeLimits; /*!< Display range limits (see VHD_EDID_DISPLAY_RANGE_LIMITS) */
   char pDisplayName[VHD_EDID_DESCRIPTOR_STRING_BUFFER_MAX_LENGTH]; /*!< Display name */
   VHD_EDID_WHITE_POINT_DATA pAdditionalWhitePointData[VHD_EDID_MAX_NB_ADDITIONAL_WHITE_POINT_DATA]; /*!< Array of additional white point data (see VHD_EDID_WHITE_POINT_DATA) */
   VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR StandardTimingInformationDescriptor; /*!< Standard timing information descriptor (see VHD_EDID_STANDARD_TIMING_INFORMATION_DESCRIPTOR) */
   VHD_EDID_COLOR_MANAGEMENT_DATA ColorManagementData; /*!< Color management data (see VHD_EDID_COLOR_MANAGEMENT_DATA) */
   VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR CVTTimingCodesDescriptor; /*!< CVT timing codes descriptor (see VHD_EDID_CVT_TIMING_CODE_DESCRIPTOR) */
   VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR AdditionalStandardTimingsDescriptor; /*!< Additional standard timings descriptor (see VHD_EDID_ADDITIONAL_STANDARD_TIMINGS_DESCRIPTOR) */
}VHD_EDID_DESCRIPTOR_DATA;

/*_ VHD_EDID_DESCRIPTOR ____________________________________________________*/
/*!
   Summary
   EDID descriptor union
   Description
   The VHD_EDID_DESCRIPTOR structure holds the type and data related
   to a given EDID descriptor block.

   See Also
   VHD_EDID_DESCRIPTOR_TYPE, VHD_EDID_DESCRIPTOR_DATA
*/
typedef struct _VHD_EDID_DESCRIPTOR
{
   VHD_EDID_DESCRIPTOR_TYPE DescriptorType;
   VHD_EDID_DESCRIPTOR_DATA DescriptorData;
}VHD_EDID_DESCRIPTOR;

/*_ VHD_EDID_DESCRIPTION ____________________________________________________*/
/*!
   Summary
   EDID description data structure
   Description
   The VHD_EDID_DESCRIPTION structure holds the data related to a given
   EDID description.

   See Also
   VHD_EDID_DATA,
   VHD_EDID_HEADER_INFORMATION, VHD_EDID_BASIC_DISPLAY_PARAMETERS
   VHD_EDID_CHROMATICITY_COORDINATES, VHD_EDID_STANDARD_TIMING_INFORMATION
   VHD_EDID_ESTABLISHED_TIMING, VHD_EDID_DESCRIPTOR
*/
typedef struct _VHD_EDID_DESCRIPTION
{
   VHD_EDID_HEADER_INFORMATION HeaderInformation; /*!< Header information (see VHD_EDID_HEADER_INFORMATION) */
   VHD_EDID_BASIC_DISPLAY_PARAMETERS DisplayParameters; /*!< Basic display parameters (see VHD_EDID_BASIC_DISPLAY_PARAMETERS) */
   VHD_EDID_CHROMATICITY_COORDINATES ChromaticityCoordinates; /*!< Chromaticity coordinates (see VHD_EDID_CHROMATICITY_COORDINATES) */
   VHD_EDID_ESTABLISHED_TIMING pSupportedEstablishedTimings[VHD_EDID_MAX_NB_ESTABLISHED_TIMINGS]; /*!< Array of supported established timing (see VHD_EDID_ESTABLISHED_TIMING) */
   ULONG NbSupportedEstablishedTimings;
   VHD_EDID_STANDARD_TIMING_INFORMATION pStandardTimingInformation[VHD_EDID_MAX_NB_STANDARD_TIMING_INFORMATION]; /*!< Array of standard timing information (see VHD_EDID_STANDARD_TIMING_INFORMATION) */
   UBYTE NbStandardTimingInformation; /*!< Number of standard timing information (see VHD_EDID_STANDARD_TIMING_INFORMATION) */
   VHD_EDID_DESCRIPTOR pDescriptors[VHD_EDID_MAX_NB_DESCRIPTORS]; /*!< Array of descriptors (see VHD_EDID_DESCRIPTOR) */
   ULONG NbDescriptors; /*!< Total number of descriptors (see VHD_EDID_DESCRIPTOR) */
}VHD_EDID_DESCRIPTION;

/*_ VHD_EDID_EXTENSION_UNSUPPORTED ____________________________________________________*/
/*!
   Summary
   EDID unsupported extension data structure
   Description
   The VHD_EDID_EXTENSION_UNSUPPORTED structure holds the data related to a given
   EDID unsupported extension.

   In this case, unsupported means that the raw data of the EDID extension is 
   stored in this structure and it is up to the used to process it.

   See Also
   VHD_EDID_EXTENSION
*/
typedef struct _VHD_EDID_EXTENSION_UNSUPPORTED
{
   UBYTE pData[VHD_EDID_BLOCK_BUFFER_SIZE - 2]; /*!< Unsupported extension data buffer */
   ULONG BufferSize; /*!< Buffer size */
}VHD_EDID_EXTENSION_UNSUPPORTED;

/*_ VHD_EDID_EXTENSION_BLOCK_MAP ____________________________________________________*/
/*!
   Summary
   EDID block map extension data structure
   Description
   The VHD_EDID_EXTENSION_BLOCK_MAP structure holds the data related to a given
   EDID block map extension.

   See Also
   VHD_EDID_EXTENSION, VHD_EDID_EXTENSION_TYPE
*/
typedef struct _VHD_EDID_EXTENSION_BLOCK_MAP
{
   VHD_EDID_EXTENSION_TYPE pExtensionMap[VHD_EDID_BLOCK_BUFFER_SIZE - 2]; /*!< Extension map */
   ULONG NbExtensions;
}VHD_EDID_EXTENSION_BLOCK_MAP;

/*_ VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE ____________________________________________________*/
/*!
   Summary
   EDID localized string table data structure
   Description
   The VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE structure holds the data related to a given
   EDID localized string table.

   See Also
   VHD_EDID_EXTENSION_LOCALIZED_STRING
*/
typedef struct _VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE
{
   UWORD LanguageIDCodeNumber; /*!< 3-digit language code number */
   char pLanguageID[4]; /*!< Language ID */
   VHD_EDID_UTF_TYPE UTFType; /*!< UTF type*/
   UBYTE pManufacturerName[VHD_EDID_LOC_STRING_MAX_STRING_LENGTH]; /*!< Array of bytes representing the manufacturer name, using the UTF type and in the language defined in this structure */
   UBYTE ManufacturerNameLength; /*!< Length of the manufacturer name string */
   UBYTE pModelName[VHD_EDID_LOC_STRING_MAX_STRING_LENGTH]; /*!<Array of bytes representing the model name, using the UTF type and in the language defined in this structure  */
   UBYTE ModelNameLength; /*!< Length of the model name string */
   UBYTE pSerialNumberString[VHD_EDID_LOC_STRING_MAX_STRING_LENGTH]; /*!< Array of bytes representing the serial number string, using the UTF type and in the language defined in this structure */
   UBYTE SerialNumberLength; /*!< Length of the serial number string */
}VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE;

/*_ VHD_EDID_EXTENSION_LOCALIZED_STRING ____________________________________________________*/
/*!
   Summary
   EDID localized string extension data structure
   Description
   The VHD_EDID_EXTENSION_LOCALIZED_STRING structure holds the data related to a given
   EDID localized string extension.

   See Also
   VHD_EDID_EXTENSION, VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE
*/
typedef struct _VHD_EDID_EXTENSION_LOCALIZED_STRING
{
   UBYTE Version; /*!< Version number */
   UBYTE Revision; /*!< Revision number */
   UBYTE UnicodeVersionMajor; /*!< Unicode major version number */
   UBYTE UnicodeVersionMinor; /*!< Unicode minor version number */
   UBYTE UnicodeVersionUpdate; /*!< Unicode update version number */
   VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE pLocalizedStringTable[VHD_EDID_LOC_STRING_MAX_NB_STRING_TABLES]; /*!< Array of string tables (see VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE) */
   ULONG NbStringTables; /*!< Number of string tables (see VHD_EDID_EXTENSION_LOCALIZED_STRING_TABLE); */
}VHD_EDID_EXTENSION_LOCALIZED_STRING;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension audio data block data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA structure holds the data related to some given
   EDID CEA-861 extension audio data block data.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO, VHD_EDID_CEA_861_AUDIO_FORMAT
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA
{
   VHD_EDID_CEA_861_AUDIO_FORMAT AudioFormat; /*!< Audio format (see VHD_EDID_CEA_861_AUDIO_FORMAT) */
   UBYTE NbChannels; /*!< Number of audio channels */
   BOOL32 Supports32kHz; /*!< 32kHz sampling frequency supported */
   BOOL32 Supports44kHz; /*!< 44kHz sampling frequency supported */
   BOOL32 Supports48kHz; /*!< 48kHz sampling frequency supported */
   BOOL32 Supports88kHz; /*!< 88kHz sampling frequency supported */
   BOOL32 Supports96kHz; /*!< 96kHz sampling frequency supported */
   BOOL32 Supports176kHz; /*!< 176kHz sampling frequency supported */
   BOOL32 Supports192kHz; /*!< 192kHz sampling frequency supported */
   BOOL32 SupportsLPCM16Bit; /*!< 16-bit LPCM supported (relevant only if LPCM audio format) */
   BOOL32 SupportsLPCM20Bit; /*!< 20-bit LPCM supported (relevant only if LPCM audio format) */
   BOOL32 SupportsLPCM24Bit; /*!< 24-bit LPCM supported (relevant only if LPCM audio format) */
   ULONG MaximumBitrate; /*!< Maximum supported bitrate (relevant only if audio format is not LPCM) */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension array of audio data blocks data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA structure holds the data related to some given
   EDID CEA-861 extension array of audio data blocks.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO
{
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA pAudioData[VHD_EDID_CEA_MAX_NB_AUDIO_DATA]; /*!< Array of Audio Data Block data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA) */
   UBYTE NbAudioData; /*!< Number of Audio Data Block data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO_DATA) */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension video data block data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA structure holds the data related to some given
   EDID CEA-861 extension video data block data.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO,
   VHD_GetCEA861BlockVideoCharacteristics
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA
{
   BOOL32 NativeResolution; /*!< TRUE if should be considered a native resolution, FALSE for non-native */
   UBYTE VIC; /*!< Index value to a table of standard resolutions/timings from CEA/EIA-861 */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension array of video data blocks data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO structure holds the data related to some given
   EDID CEA-861 extension array of video data blocks.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO
{
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA pVideoData[VHD_EDID_CEA_MAX_NB_VIDEO_DATA]; /*!< Array of Video Data Block data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA) */
   UBYTE NbVideoData; /*!< Number of Video Data Block data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA) */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension HDMI1.3a data block data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A structure holds the data related to some given
   EDID CEA-861 extension HDMI1.3a data block data.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A
{
   BOOL32 AISupported; /*!< TRUE if sink supports a function that needs info from ACP or ISRC packets */
   BOOL32 DeepColor48BitSupported; /*!< TRUE if sink supports 16-bit-per-channel deep color */
   BOOL32 DeepColor36BitSupported; /*!< TRUE if sink supports 12-bit-per-channel deep color */
   BOOL32 DeepColor30BitSupported; /*!< TRUE if sink supports 10-bit-per-channel deep color */
   BOOL32 DeepColor444Supported; /*!< TRUE if sink supports 4:4:4 in deep color modes */
   BOOL32 DVIDualSupported; /*!< TRUE if sink supports DVI Dual Link Operation */
   ULONG MaxTMDSFrequency; /*!< Max TDMS frequency */
   BOOL32 LatencyFields; /*!< Video and audio latency fields are relevant */
   BOOL32 InterlacedLatencyFields; /*!< Interlaced video and audio latency fields are relevant */
   UWORD VideoLatency; /*!< Video latency in ms */
   UWORD AudioLatency; /*!< Audio latency in ms */
   UWORD InterlacedVideoLatency; /*!< Video latency for interlaced sources in ms */
   UWORD InterlacedAudioLatency; /*!< Audio latency for interlaced sources in ms */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_PAYLOAD ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension vendor specific data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_PAYLOAD structure holds the data related to some given
   EDID CEA-861 extension vendor specific data.

   In this case, if the IEEE Registration Identifier is not the HDMI one,
   the raw data is left unprocessed and stored in this structure.
   It is up to the user to process it.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_PAYLOAD
{
   UBYTE pPayload[VHD_EDID_BLOCK_BUFFER_SIZE]; /*!< Payload buffer */
   ULONG PayloadBufferSize; /*!< Payload buffer size */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_PAYLOAD;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension vendor specific data union
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA union
   holds the data related to some given EDID CEA-861 extension vendor specific data.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored along side a IEEE Registration Identifier.
   If this ID is equal to 00-0C-03 (for HDMI Licensing), then the HDMI 1.3a data
   is accessible. Otherwise, the payload is left unprocessed.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_PAYLOAD
*/
typedef union _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA
{
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A HDMI13AData; /*!< HDMI 1.3a data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_HDMI_1_3_A) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_PAYLOAD Payload; /*!< Unidentified payload */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension vendor specific data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC structure holds the data related to some given
   EDID CEA-861 extension vendor specific data.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC
{
   ULONG IEEERegistrationID; /*!< IEEE Registration Identifier */
   UWORD SourcePhysicalAddress; /*!< CEC physical address for upstream CEC devices */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA Data; /*!< Data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC_DATA) */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension speaker data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER structure holds the data related to some given
   EDID CEA-861 extension speaker data.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER
{
   BOOL32 FrontCenterPresent; /*!< TRUE if front center speaker is present, FALSE if absent */
   BOOL32 FrontLeftRightCenterPresent; /*!< TRUE if front left center / front right center speakers are present, FALSE if absent */
   BOOL32 FrontLeftRightPresent; /*!< TRUE if front left / front right speakers are present, FALSE if absent */
   BOOL32 RearCenterPresent; /*!< TRUE if rear center speaker is present, FALSE if absent */
   BOOL32 RearLeftRightCenterPresent; /*!< TRUE if rear left center / rear right center speakers are present, FALSE if absent */
   BOOL32 RearLeftRightPresent; /*!< TRUE if rear left / rear right speakers are present, FALSE if absent */
   BOOL32 LFEPresent; /*!< TRUE if LFE is present, FALSE if absent */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_UNSUPPORTED ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension unsupported data block data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_UNSUPPORTED structure holds the data related to some given
   EDID CEA-861 extension unsupported data block.

   See Also
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_UNSUPPORTED
{
   UBYTE pData[VHD_EDID_BLOCK_BUFFER_SIZE]; /*!< Data buffer */
   ULONG DataBufferSize; /*!< Data buffer size */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_UNSUPPORTED;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_DATA ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension data block union
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_DATA union holds the data related to a given
   EDID CEA-861 extension data block.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored in an array indexed by
   data block types (see VHD_EDID_CEA_861_BLOCK_TYPE), allowing one
   to know which field should be used based on that data block type.

   See Also
   VHD_EDID_CEA_861_BLOCK_TYPE, VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO, VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER,
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC
*/
typedef union _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_DATA
{
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO VideoDataBlock; /*!< Video Data Block (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO AudioDataBlock; /*!< Audio Data Block (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_AUDIO) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER SpeakerDataBlock; /*!< Speaker Data Block (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_SPEAKER) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC VendorDataBlock; /*!< Vendor Data Block (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VENDOR_SPECIFIC) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_UNSUPPORTED UnsupportedDataBlock; /*!< Unsupported Data Block (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_UNSUPPORTED) */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_DATA;

/*_ VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension data block union
   Description
   The VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK structure holds the type and data
   related to a given EDID CEA-861 extension data block.

   See Also
   VHD_EDID_CEA_861_BLOCK_TYPE, VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK
{
   VHD_EDID_CEA_861_BLOCK_TYPE DataBlockType; /*!< Data block type (see VHD_EDID_CEA_861_BLOCK_TYPE) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_DATA DataBlockData; /*!< Data block data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK) */
}VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK;

/*_ VHD_EDID_EXTENSION_CEA_861 ____________________________________________________*/
/*!
   Summary
   EDID CEA-861 extension data structure
   Description
   The VHD_EDID_EXTENSION_CEA_861 structure holds the data related to a given
   EDID CEA-861 extension.

   See Also
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR, VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK
*/
typedef struct _VHD_EDID_EXTENSION_CEA_861
{
   UBYTE Version; /*!< Version number */
   BOOL32 UnderscanSupported; /*!< TRUE if display supports underscan, FALSE if not */
   BOOL32 BasicAudioSupported; /*!< TRUE if display supports basic audio, FALSE if not */
   BOOL32 YCbCr444Supported; /*!< TRUE if display supports YCbCr 4:4:4, FALSE if not */
   BOOL32 YCbCr422Supported; /*!< TRUE if display supports YCbCr 4:2:2, FALSE if not */
   UBYTE NbNativeDetailedTimingDescriptors; /*!< Total number of native formats in the Detailed Timing Descriptors included in this block (see VHD_EDID_DETAILED_TIMING_DESCRIPTOR) */
   VHD_EDID_DETAILED_TIMING_DESCRIPTOR pDetailedTimingDescriptors[VHD_EDID_CEA_MAX_NB_DETAILED_TIMING_DESCRIPTORS]; /*!< Array of Detailed Timing Descriptors (see VHD_EDID_DETAILED_TIMING_DESCRIPTOR) */
   UBYTE NbDetailedTimingDescriptors; /*!< Number of Detailed Timing Descriptors (see VHD_EDID_DETAILED_TIMING_DESCRIPTOR) */
   VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK pDataBlockCollection[VHD_EDID_CEA_MAX_NB_DATA_BLOCKS]; /*!< Array of Data Blocks (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK) */
   UBYTE NbDataBlocks; /*!< Number of Data Blocks (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK, VHD_EDID_CEA_861_BLOCK_TYPE) */
}VHD_EDID_EXTENSION_CEA_861;

/*_ VHD_EDID_EXTENSION_DATA ____________________________________________________*/
/*!
   Summary
   EDID extension data union
   Description
   The VHD_EDID_EXTENSION_DATA union holds the data related to a given
   EDID extension.

   Note that only one of its field is relevant at a time.
   Typically, this structure is stored in an array indexed by
   extension types (see VHD_EDID_EXTENSION_TYPE), allowing one
   to know which field should be used based on that extension type.

   See Also
   VHD_EDID_EXTENSION_TYPE,
   VHD_EDID_EXTENSION_UNSUPPORTED, VHD_EDID_EXTENSION_CEA_861
   VHD_EDID_EXTENSION_LOCALIZED_STRING, VHD_EDID_EXTENSION_BLOCK_MAP
*/
typedef union _VHD_EDID_EXTENSION_DATA
{
   VHD_EDID_EXTENSION_BLOCK_MAP BlockMapExtension; /*!< Block map extension (see VHD_EDID_EXTENSION_BLOCK_MAP) */
   VHD_EDID_EXTENSION_CEA_861 CEA861Extension; /*!< CEA-861 extension data (see VHD_EDID_EXTENSION_CEA_861) */
   VHD_EDID_EXTENSION_LOCALIZED_STRING LocalizedStringExtension; /*!< Localized string extension (see VHD_EDID_EXTENSION_LOCALIZED_STRING) */
   VHD_EDID_EXTENSION_UNSUPPORTED UnsupportedExtension; /*!< Unsupported extension data (see VHD_EDID_EXTENSION_UNSUPPORTED) */
}VHD_EDID_EXTENSION_DATA;

/*_ VHD_EDID_EXTENSION ____________________________________________________*/
/*!
   Summary
   EDID extension
   Description
   The VHD_EDID_EXTENSION structure holds the type and data
   related to a given EDID extension.

   See Also
   VHD_EDID_EXTENSION_TYPE, VHD_EDID_EXTENSION
*/
typedef struct _VHD_EDID_EXTENSION
{
   VHD_EDID_EXTENSION_TYPE ExtensionType; /*!< Extension type (see VHD_EDID_EXTENSION_TYPE) */
   VHD_EDID_EXTENSION_DATA ExtensionData; /*!< Extension data (see VHD_EDID_EXTENSION) */
}VHD_EDID_EXTENSION;

/*_ VHD_EDID_DATA ____________________________________________________*/
/*!
   Summary
   EDID data structure
   Description
   The VHD_EDID_DATA structure holds the data related to a given
   EDID buffer.

   In order to provide all the information contained in an EDID buffer,
   this structure is architectured as a tree of structures, each one dedicated to
   a given section of the EDID information.

   Because of this hierarchy and how arrays are statically allocated, the size of
   this structure will most certainly be too high for it to be managed on the stack
   and will therefore most likely require dynamic allocation on the heap.
   For the same reasons, functions taking this structure as a parameter should not
   use pass-by-value semantics.

   This structure is typically either populated by a user and then
   translated into a byte-buffer thanks to <link VHD_GetEDIDBuffer>
   or is filled in from an EDID byte-buffer via <link VHD_GetEDIDData>
   See Also
   VHD_GetEDIDBuffer, VHD_GetEDIDData
*/
typedef struct _VHD_EDID_DATA
{
   VHD_EDID_DESCRIPTION Description; /*!< Holds the EDID description data (see VHD_EDID_DESCRIPTION)*/
   VHD_EDID_EXTENSION pExtensions[VHD_EDID_MAX_NB_EXTENSIONS]; /*!< Array of extension data (see VHD_EDID_EXTENSION) */
   ULONG NbExtensions; /*!< Total number of extensions */
}VHD_EDID_DATA;

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*** VHD_GetEDIDBuffer ***************************************************/
/*!VHD_GetEDIDBuffer
   Summary
      Gets the EDID buffer from a EDID data structure
   Description
      This function gets the EDID buffer from the given EDID data
      and returns it along with its size through two of its arguments.
      If the input size of the buffer is smaller than the size of the EDID
      buffer to copy, the required size is written to pBufferSize and an error
      is returned.
   Parameters
      EDIDData : EDID data structure
      pEDIDBuffer : Pointer to user-allocated variable where the EDID buffer is written
      pBufferSize : Pointer to user-allocated variable where the maximum size of 
                     the user buffer is given and the actual size of the buffer is written
      pWarnings : Pointer to user-allocated variable where the warnings are returned
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetEDIDBuffer(VHD_EDID_DATA EDIDData, UBYTE *pEDIDBuffer, ULONG *pBufferSize, VHD_EDID_WARNINGS* pWarnings);

/*** VHD_GetEDIDData ***************************************************/
/*!VHD_GetEDIDData
   Summary
      Gets the EDID data structure from a EDID buffer
   Description
      This function gets the EDID data structure from the given EDID buffer
      and returns it through one of its arguments.
   Parameters
      pEDIDBuffer : EDID buffer
      BufferSize : EDID buffer size
      pEDIDData : Pointer to user-allocated variable where the EDID data is returned
      pWarnings : Pointer to user-allocated variable where the warnings are returned
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetEDIDData(UBYTE *pEDIDBuffer, ULONG BufferSize, VHD_EDID_DATA* pEDIDData, VHD_EDID_WARNINGS* pWarnings);


/*** VHD_GetEstablishedTimingVideoCharacteristics ***************************************************/
/*!VHD_GetEstablishedTimingVideoCharacteristics
   Summary
      Gets the video characteristics from an established timing
   Description
      This function gets the video characteristics from an established timing
      and returns it through one of its arguments.
   Parameters
      EstablishedTiming : Established timing (see VHD_EDID_ESTABLISHED_TIMING)
      pActiveWidth : Pointer to user-allocated variable where the active width is returned
      pActiveHeight : Pointer to user-allocated variable where the active height is returned
      pRefreshRate : Pointer to user-allocated variable where the refresh rate is returned
      pInterlaced : Pointer to user-allocated variable where the interlaced information is returned
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetEstablishedTimingVideoCharacteristics(VHD_EDID_ESTABLISHED_TIMING EstablishedTiming
                                                                     , ULONG* pActiveWidth, ULONG* pActiveHeight, ULONG* pRefreshRate, BOOL32* pInterlaced);

/*** VHD_GetStandardTimingVideoCharacteristics ***************************************************/
/*!VHD_GetStandardTimingVideoCharacteristics
   Summary
      Gets the video characteristics from a standard timing information
   Description
      This function gets the video characteristics from a standard timing information
      and returns it through one of its arguments.
   Parameters
      StandardTimingInfo : Standard timing information (see VHD_EDID_STANDARD_TIMING_INFORMATION)
      pActiveWidth : Pointer to user-allocated variable where the active width is returned
      pActiveHeight : Pointer to user-allocated variable where the active height is returned
      pRefreshRate : Pointer to user-allocated variable where the refresh rate is returned
      pInterlaced : Pointer to user-allocated variable where the interlaced information is returned
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetStandardTimingVideoCharacteristics(VHD_EDID_STANDARD_TIMING_INFORMATION StandardTimingInfo
                                                                  , ULONG* pActiveWidth, ULONG* pActiveHeight, ULONG* pRefreshRate, BOOL32* pInterlaced);

/*** VHD_GetCEA861BlockVideoCharacteristics ***************************************************/
/*!VHD_GetCEA861BlockVideoCharacteristics
   Summary
      Gets the video characteristics from a CEA-861 video data block
   Description
      This function gets the video characteristics from a CEA-861 video data block
      and returns it through one of its arguments.
   Parameters
      VideoData : CEA-861 video data block data (see VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA)
      pActiveWidth : Pointer to user-allocated variable where the active width is returned
      pActiveHeight : Pointer to user-allocated variable where the active height is returned
      pRefreshRate : Pointer to user-allocated variable where the refresh rate is returned
      pInterlaced : Pointer to user-allocated variable where the interlaced information is returned
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetCEA861BlockVideoCharacteristics(VHD_EDID_EXTENSION_CEA_861_DATA_BLOCK_VIDEO_DATA VideoData
                                                               , ULONG* pActiveWidth, ULONG* pActiveHeight, ULONG* pRefreshRate, BOOL32* pInterlaced);

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_EDID_H_