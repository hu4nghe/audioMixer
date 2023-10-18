/*! VideomasterHD_Sdi_Hdr_Metadata.h

    Copyright (c) 2019, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package :

  Company : DELTACAST

  Author  : ms                             Date: 2019/02/20

  Purpose :

*/


#ifndef _VIDEOMASTERHD_SDI_HDR_METADATA_H_
#define _VIDEOMASTERHD_SDI_HDR_METADATA_H_

#include "VideoMasterHD_Core.h"


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Sdi_Hdr_Metadata
*/

#define MAX_HDRMETADATA_DATA_SIZE 255
#define MAX_HDRMETADATA_PACKETS 45
#define MAX_HDRMETADATA_ST2108_FRAMEDATA_SIZE 253


/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Sdi_Hdr_Metadata
*/

/*_ VHD_HDRMETADATA_TYPE ____________________________________________________*/
/*!
   Summary
   HDR metadata types
   Description
   The VHD_HDRMETADATA_TYPE enumeration lists all the supported
   HDR metadata types.

   These values are used by the VHD_HDRMETADATA_INFO.
   See Also
   VHD_SlotExtractHDRMetadata                                      */
typedef enum _VHD_HDRMETADATA_TYPE
{
   VHD_HDRMETADATA_ST2108,                   /*! HDR/WCG Metadata Packing and Signaling in the VANC Data Space (SMPTE ST 2108-1) */
   NB_VHD_HDRMETADATA_TYPES
}VHD_HDRMETADATA_TYPE;

/*_ VHD_HDRMETADATA_ST2108_FRAME_TYPE ____________________________________________________*/
/*!
   Summary
   ST2108 HDR metadata frame types
   Description
   The VHD_HDRMETADATA_ST2108_FRAME_TYPE enumeration lists all the supported
   ST2108 HDR metadata frame types.

   These values are used by the VHD_HDRMETADATA_ST2108_FRAME structure (SMPTE ST 2108-1).  */
typedef enum _VHD_HDRMETADATA_ST2108_FRAME_TYPE
{
   VHD_HDRMETADATA_ST2108_STATIC_TYPE_1,     /*! Mastering display color volume SEI message (Rec. ITU-T H.265) */
   VHD_HDRMETADATA_ST2108_STATIC_TYPE_2,     /*! Content light level information SEI message (Rec. ITU-T H.265) */
   VHD_HDRMETADATA_ST2108_DYNAMIC_TYPE_1,    /*! ATSC A/341 ST 2094-10_data SEI message (ATSC A/341) */
   VHD_HDRMETADATA_ST2108_DYNAMIC_TYPE_2,    /*! Reserved for dynamic metadata type corresponding to SMPTE ST 2094-20 */
   VHD_HDRMETADATA_ST2108_DYNAMIC_TYPE_3,    /*! Reserved for dynamic metadata type corresponding to SMPTE ST 2094-30 */
   VHD_HDRMETADATA_ST2108_DYNAMIC_TYPE_4,    /*! Reserved for dynamic metadata type corresponding to SMPTE ST 2094-40 */
   VHD_HDRMETADATA_ST2108_DYNAMIC_TYPE_5,    /*! SL-HDR information SEI message (ETSI TS 103 433-1 SL-HDR1) */
   NB_VHD_HDRMETADATA_ST2108_TYPES
}VHD_HDRMETADATA_ST2108_FRAME_TYPE;


/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Sdi_Hdr_Metadata
*/

/*_ VHD_HDRMETADATA_INFO ________________________________________________________*/
/*!
   Summary
   HDR metadata packet info
   Description
   The VHD_HDRMETADATA_INFO structure contains information about the HDR metadata packet. */
typedef struct _VHD_HDRMETADATA_INFO
{
   int StructSize;                           /*! Size of the structure */
   int LineNumber;                           /*! HDR metadata packet Line number */
   VHD_SAMPLETYPE SampleType;                /*! HDR metadata packet ANC sample type */
   VHD_HDRMETADATA_TYPE HDRMetadataType;     /*! HDR metadata packet type */
}VHD_HDRMETADATA_INFO;

/*_ VHD_HDRMETADATA_DATA ________________________________________________________*/
/*!
   Summary
   HDR metadata packet data
   Description
   The VHD_HDRMETADATA_DATA structure contains the HDR metadata packet data. */
typedef struct _VHD_HDRMETADATA_DATA
{
   int StructSize;                           /*! Size of the structure */
   int DataSize;                             /*! HDR metadata packet data size */
   BYTE pData[MAX_HDRMETADATA_DATA_SIZE];    /*! HDR metadata packet data zone */
}VHD_HDRMETADATA_DATA;

/*_ VHD_HDRMETADATA_PACKET ________________________________________________________*/
/*!
   Summary
   HDR metadata packet
   Description
   The VHD_HDRMETADATA_PACKET structure contains the HDR metadata packet data. */
typedef struct _VHD_HDRMETADATA_PACKET
{
   int StructSize;                           /*! Size of the structure */
   VHD_HDRMETADATA_INFO HDRMetadataInfo;     /*! HDR metadata packet info */
   VHD_HDRMETADATA_DATA HDRMetadataData;     /*! HDR metadata packet data */
}VHD_HDRMETADATA_PACKET;

/*_ VHD_HDRMETADATA_SLOT ________________________________________________________*/
/*!
   Summary
   HDR metadata packets
   Description
   The VHD_HDRMETADATA_SLOT structure contains the HDR metadata packets. */
typedef struct _VHD_HDRMETADATA_SLOT
{
   int StructSize;                                                         /*! Size of the structure */
   int PacketsCount;                                                       /*! HDR metadata packets count in the slot */
   VHD_HDRMETADATA_PACKET pHDRMetadataPackets[MAX_HDRMETADATA_PACKETS];    /*! HDR metadata packets zone */
}VHD_HDRMETADATA_SLOT;

/*_ VHD_HDRMETADATA_ST2108_FRAME ________________________________________________________*/
/*!
   Summary
   ST2108 HDR metadata frames
   Description
   The VHD_HDRMETADATA_ST2108_FRAME structure contains the ST2108 HDR metadata frames. */
typedef struct _VHD_HDRMETADATA_ST2108_FRAME
{
   UBYTE FrameType;                                         /*! ST2108 HDR metadata frame type */
   UBYTE FrameLength;                                       /*! ST2108 HDR metadata frame length */
   UBYTE pData[MAX_HDRMETADATA_ST2108_FRAMEDATA_SIZE];      /*! ST2108 HDR metadata data zone */
}VHD_HDRMETADATA_ST2108_FRAME;


#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Sdi_Hdr_Metadata
*/
/*** VHD_SlotExtractHDRMetadata *******************************************************/
/*!VHD_SlotExtractHDRMetadata

   Summary
   HDR metadata slot extraction
   Description
   This function extracts the HDR metadata slot of the given slot.

   Parameters
   SlotHandle : Handle of the slot to work on
   pHDRMetaData : Pointer to a caller\-allocated structure
                  receiving the HDR metadata slot.
   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */

VIDEOMASTER_HD_API ULONG VHD_SlotExtractHDRMetadata(HANDLE SlotHandle, VHD_HDRMETADATA_SLOT *pHDRMetaData);

/*** VHD_SlotEmbedHDRMetadata *******************************************************/
/*!VHD_SlotEmbedHDRMetadata

   Summary
   HDR metadata slot embedding.
   Description
   This function embeds the provided HDR metadata slot in the provided
   slot, according to the specified standard.

   Parameters
   SlotHandle : Handle of the slot to work on
   HDRMetaData : structure containing the HDR metadata slot.

   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedHDRMetadata(HANDLE SlotHandle, VHD_HDRMETADATA_SLOT HDRMetaData);

#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_SDI_HDR_METADATA_H_
