/*! VideomasterHD_Sdi_VbiData.h

    Copyright (c) 2012, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : VBI Data Extension API

  Company : DELTACAST

  Author  : BC                                            Date: 2012/11/14

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_SDI_VBIDATA_H_
#define _VIDEOMASTERHD_SDI_VBIDATA_H_

#ifdef __cplusplus
extern "C" {
#endif


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_VbiData
*/
#define MAX_CC_DATA_SIZE 90


/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_VbiData
*/

/*_ VHD_CC_TYPE ____________________________________________________*/
/*!
   Summary
   Closed caption types
   Description
   The VHD_CC_TYPE enumeration lists all the supported
   Closed caption types.
   
   These values are used by the VHD_CC_INFO.
   See Also
   VHD_SlotExtractClosedCaptions                                      */
typedef enum _VHD_CC_TYPE
{
   VHD_CC_EIA_608B,        /*! Close Caption EIA 608B */
   VHD_CC_EIA_608B_VANC,   /*! Close Caption EIA 608B on vertical ancillary data */
   VHD_CC_EIA_708          /*! Close Caption EIA 708 */
} VHD_CC_TYPE;

/*_ VHD_SDI_AFD_AR_CODE _______________________________________________*/
/*!
   Summary
   Videomaster AFD and AR codes
   Description
   The VHD_AFD_AR_CODE enumeration lists all the existing AFD code values.
   
   These values are used in for VHD_SlotEmbedAFD and
   VHD_SlotExtractAFD functions calls.
                                                 */
typedef enum _VHD_AFD_AR_CODE
{
   VHD_AFD_AR_U4_3=0,               /*!Undefined 4:3*/
   VHD_AFD_AR_U16_9=1,              /*!Undefined 16:9*/
   VHD_AFD_AR_TLB16_9=4,            /*!Letterbox 16:9 image, at top of the coded frame*/
   VHD_AFD_AR_FF16_9=6,             /*!Full frame 16:9 image, the same as the coded frame*/
   VHD_AFD_AR_TLB14_9=7,            /*!Letterbox 14:9 image, at top of the coded frame*/
   VHD_AFD_AR_HCPB14_9=8,           /*!Pillarbox 14:9 image, horizontally centered in the coded frame*/
   VHD_AFD_AR_LBARG4_3=9,           /*!Letterbox image with an aspect ratio greater than 16:9, vertically centered in the coded frame*/
   VHD_AFD_AR_LBARG16_9=10,         /*!Letterbox image with an aspect ratio greater than 16:9, vertically centered in the coded frame*/
   VHD_AFD_AR_FF4_3=16,             /*!Full frame 4:3 image, the same as the coded frame*/
   VHD_AFD_AR_FF16_9P=17,           /*!Full frame 16:9 image, the same as the coded frame*/
   VHD_AFD_AR_FF4_3P=18,            /*!Full frame 4:3 image, the same as the coded frame*/
   VHD_AFD_AR_HCPB4_3=19,           /*!Pillarbox 4:3 image, horizontally centered in the coded frame*/
   VHD_AFD_AR_VCLB16_9=20,          /*!Letterbox 16:9 image, vertically centered in the coded frame with all image areas protected*/
   VHD_AFD_AR_AIAPFF16_9=21,        /*!Full frame 16:9 image, with all image areas protected*/
   VHD_AFD_AR_VCLB14_9=22,          /*!Letterbox 14:9 image, vertically centered in the coded frame*/
   VHD_AFD_AR_HCPB14_9P=23,         /*!Pillarbox 14:9 image, horizontally centered in the coded frame*/
   VHD_AFD_AR_FF4_3A14_9C=26,       /*!Full frame 4:3 image, with alternative 14:9 center*/
   VHD_AFD_AR_PB4_3A14_9C=27,       /*!Pillarbox 4:3 image, with alternative 14:9 center*/
   VHD_AFD_AR_LB16_9A14_9C=28,      /*!Letterbox 16:9 image, with alternative 14:9 center*/
   VHD_AFD_AR_FF16_9A14_9C=29,      /*!Full frame 16:9 image, with alternative 14:9 center*/
   VHD_AFD_AR_LB16_9A4_3C=30,       /*!Letterbox 16:9 image, with alternative 4:3 center*/
   VHD_AFD_AR_FF16_9A4_3C=31,       /*!Full frame 16:9 image, with alternative 4:3 center*/
   NB_VHD_AFD_AR_CODE
} VHD_AFD_AR_CODE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_VbiData
*/

/*_ VHD_WSS_SLOT ________________________________________________________*/
/*!
   Summary
   WSS Slot
   Description
   The VHD_WSS_SLOT structure contains information about a WSS SLOT. */
typedef struct _VHD_WSS_SLOT
{
   int LineNumber;          /*! Video line to search on, or 0 to use standard default */
   ULONG WSSData;           /*! WSS data stored on 14 LSB */
} VHD_WSS_SLOT;

/*_ VHD_CC_INFO ________________________________________________________*/
/*!
   Summary
   Closed caption info
   Description
   The VHD_CC_INFO structure contains information about a closed caption. */
typedef struct _VHD_CC_INFO
{
   VHD_CC_TYPE CCType;     /*! CC standard used */
   int pLineNumber[2];     /*! Video lines to search on. If pLineNumber[0] or 
                               pLineNumber[1] is set to 0, the standard default 
                               will be used */
} VHD_CC_INFO ;

/*_ VHD_CC_DATA ________________________________________________________*/
/*!
   Summary
   Closed caption data
   Description
   The VHD_CC_DATA structure contains closed caption data. */
typedef struct _VHD_CC_DATA
{
   int DataSize;                    /*! CC data size */
   BYTE pData[MAX_CC_DATA_SIZE];    /*! CC data */
} VHD_CC_DATA ;

/*_ VHD_CC_SLOT ________________________________________________________*/
/*!
   Summary
   Closed caption slot
   Description
   The VHD_CC_SLOT structure contains closed caption slot. */
typedef struct _VHD_CC_SLOT
{
   VHD_CC_INFO CCInfo;              /*! CC info */
   VHD_CC_DATA CCData;              /*! CC data */
} VHD_CC_SLOT;

/*_ VHD_TT_PAGE_NUM ________________________________________________*/
/*!
   Summary
   Teletext page number
   Description
   The VHD_TT_PAGE_NUM structure contains a teletext page number. */
typedef struct _VHD_TT_PAGE_NUM
{
   ULONG PageTens;                  /*! Page tens */
   ULONG PageUnits;                 /*! Page units */
} VHD_TT_PAGE_NUM;

/*_ VHD_TT_SUBCODE ________________________________________________*/
/*!
   Summary
   Teletext subcode
   Description
   The VHD_TT_SUBCODE structure contains a teletext subcode. */
typedef struct _VHD_TT_SUBCODE
{
   ULONG S1;                        /*! S1 (least significant) */
   ULONG S2;                        /*! S2 */
   ULONG S3;                        /*! S3 */
   ULONG S4;                        /*! S4 (most significant) */
} VHD_TT_SUBCODE;

/*_ VHD_TT_CONTROL_BITS ________________________________________________*/
/*!
   Summary
   Teletext control bits
   Description
   The VHD_TT_CONTROL_BITS structure contains control bits of a teletext page. */
typedef struct _VHD_TT_CONTROL_BITS
{
   BOOL32 C4_ErasePage;               /*! Erase page */
   BOOL32 C5_Newsflash;               /*! Newsflash */
   BOOL32 C6_Subtitle;                /*! Subtitle */
   BOOL32 C7_SuppressHeader;          /*! Suppress header */
   BOOL32 C8_UpdateIndicator;         /*! Update indicator */
   BOOL32 C9_InterruptedSequence;     /*! Interrupted sequence */
   BOOL32 C10_InhibitSequence;        /*! Inhibit sequence */
   BOOL32 C11_MagazineSerial;         /*! Magazine serial */
   BOOL32 C12_NatOptCharSubset;       /*! National option character subset */
   BOOL32 C13_NatOptCharSubset;       /*! National option character subset */
   BOOL32 C14_NatOptCharSubset;       /*! National option character subset */
} VHD_TT_CONTROL_BITS;

/*_ VHD_TT_HEADER ________________________________________________________*/
/*!
   Summary
   Teletext header
   Description
   The VHD_TT_HEADER structure contains a teletext header. */
typedef struct _VHD_TT_HEADER
{
   VHD_TT_PAGE_NUM TTPageNumber;       /*! TT page number */
   VHD_TT_SUBCODE TTSubCode;           /*! TT Subcode */
   VHD_TT_CONTROL_BITS TTControlBits;  /*! TT control bits */
   BYTE pHeaderData[32];               /*! Header data */
} VHD_TT_HEADER;

/*_ VHD_TT_PACKET ________________________________________________________*/
/*!
   Summary
   Teletext packet
   Description
   The VHD_TT_PACKET structure contains a teletext packet. */
typedef struct _VHD_TT_PACKET
{
   ULONG MagazineNumber;                /*! Magazine number */
   ULONG PacketNumber;                  /*! Packet number */
   union 
   {
      VHD_TT_HEADER TTHeader;           /*! TT Header (Packet number = 0) */
      BYTE pTTData[40];                 /*! TT Data (Packet number != 0) */
   };
} VHD_TT_PACKET;

/*_ VHD_OP42_SLOT ________________________________________________________*/
/*!
   Summary
   Teletext page
   Description
   The VHD_OP42_SLOT structure contains a teletext page. */
typedef struct _VHD_OP42_SLOT
{
   VHD_TT_PACKET pTTPacket[2];         /*! TT packet */
   int pLineNumber[2];                 /*! Video lines to search on. If pLineNumber[0] or 
                                           pLineNumber[1] is set to 0, the standard default 
                                           will be used */
} VHD_OP42_SLOT;

/*_ _VHD_AFD_AR_SLOT ________________________________________________________*/
/*!
   Summary
   AFD and AR slot
   Description
   The _VHD_AFD_AR_SLOT structure contains the AFD and AR code,line number and RP186 boolean. */
typedef struct _VHD_AFD_AR_SLOT
{
   ULONG AFD_ARCode;                   /*! AFD_AR Code(to cast with VHD_AFD_AR_CODE enum) */
   int LineNumber;                     /*! Video lines to search on. If LineNumber 
                                           is set to 0, the standard default 
                                           will be used */
   BOOL32 RP186;                       /*! SD(true) or HD(false) standard*/ 
} VHD_AFD_AR_SLOT;

/*_ VHD_VBI_PACKET ________________________________________________________*/
/*!
   Summary
   OP47 VBI packet
   Description
   The VHD_VBI_PACKET structure contains a teletext packet. */
typedef struct _VHD_OP47_VBI_PACKET
{
   ULONG LineNumber;                  /*! Line Number */
   ULONG FieldNumber;                 /*! Field Number (0 = even field, 1 = odd field)*/  
   ULONG MagazineNumber;              /*! Magazine number */
   ULONG PacketNumber;                /*! Packet number */
   BYTE pData[40];                    /*! Data */
} VHD_OP47_VBI_PACKET;

/*_ VHD_OP47_SLOT ________________________________________________________*/
/*!
   Summary
   OP47 data
   Description
   The VHD_OP47_SLOT structure contains the OP47 data. */
typedef struct _VHD_OP47_SLOT
{
   VHD_OP47_VBI_PACKET pVbiPacket[5]; /*! Vbi Packet */
   ULONG NbPackets;                   /*! Number of Vbi Packets to insert */
   ULONG LineNumber;                  /*! Line Number */
} VHD_OP47_SLOT;

#ifndef EXCLUDE_API_FUNCTIONS

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_VbiData
*/

/*** VHD_SlotExtractWSS *******************************************************/
/*!VHD_SlotExtractWSS
   
   Summary
   WSS slot extraction
   Description
   This function extracts the WSS Slot of the given slot.
   Parameters
   SlotHandle : Handle of the slot to work on
   pWSS :       Pointer to a caller\-allocated structure
                receiving the WSS slot.

   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractWSS (HANDLE SlotHandle, VHD_WSS_SLOT *pWSS);

/*** VHD_SlotEmbedWSS *******************************************************/
/*!VHD_SlotEmbedWSS
   
   Summary
   Widescreen signaling embedding.
   Description
   This function embeds the widescreen signaling in the 
   provided slot, according to the specified standard.
   Parameters   
   SlotHandle : Handle of the slot to work on
   pWSS :        Pointer to a caller\-allocated structure
                containing the WSS slot.

   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedWSS (HANDLE SlotHandle, VHD_WSS_SLOT *pWSS);

/*** VHD_SlotExtractClosedCaptions *******************************************************/
/*!VHD_SlotExtractClosedCaptions
   
   Summary
   Closed captions slot extraction
   Description
   This function extracts the CC Slot of the given slot.
   Parameters
   SlotHandle : Handle of the slot to work on
   pCC :        Pointer to a caller\-allocated structure
                receiving the CC slot.

   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractClosedCaptions (HANDLE SlotHandle, VHD_CC_SLOT *pCC);

/*** VHD_SlotEmbedClosedCaptions *******************************************************/
/*!VHD_SlotEmbedClosedCaptions
   
   Summary
   Closed caption embedding.
   Description
   This function embeds the provided CC in the provided
   slot, according to the specified standard.
   Parameters   
   SlotHandle : Handle of the slot to work on
   pCC :        Pointer to a caller\-allocated structure
                containing the CC slot.

   Remarks
   If parity bits are needed for the specified standard, they 
   will be automatically generated.
   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedClosedCaptions (HANDLE SlotHandle, VHD_CC_SLOT *pCC);

/*** VHD_SlotExtractOP42Subtitles *******************************************************/
/*!VHD_SlotExtractOP42Subtitles
   
   Summary
   OP42 subtitles slot extraction
   Description
   This function extracts the OP42 subtitles Slot of the given slot.
   Parameters
   SlotHandle : Handle of the slot to work on
   pOP42 :      Pointer to a caller\-allocated structure
                receiving the OP42 slot.

   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractOP42Subtitles (HANDLE SlotHandle, VHD_OP42_SLOT *pOP42);

/*** VHD_SlotEmbedOP42Subtitles *******************************************************/
/*!VHD_SlotEmbedOP42Subtitles
   
   Summary
   OP42 subtitles embedding.
   Description
   This function embeds the provided OP42 subtitle slot in the 
   provided slot, according to the specified standard.
   Parameters   
   SlotHandle : Handle of the slot to work on
   pOP42 :        Pointer to a caller\-allocated structure
                containing the OP42 slot.

   Remarks
   If parity bits are needed for the specified standard, they 
   will be automatically generated.
   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedOP42Subtitles (HANDLE SlotHandle, VHD_OP42_SLOT *pOP42);

/*** VHD_SlotExtractAFD **********************************************************/
/*!VHD_SlotExtractAFD
   Summary
   Active format description and aspect ratio extraction from SDI slot
   Description
   This function extract the active format description and aspect ratio code
   from the provided SDI slot.

   Parameters
   SlotHandle :   Handle of the slot to work on
   pAFD_AR :      Pointer to a caller\-allocated structure
   containing the AFD_AR slot.
  
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
    */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractAFD(HANDLE SlotHandle,VHD_AFD_AR_SLOT *pAFD_AR);

/*** VHD_SlotEmbedAFD **********************************************************/
/*!VHD_SlotEmbedAFD
   Summary
   Active format description and aspect ratio embed in SDI slot
   Description
   This function embed the active format description and aspect ratio code
   in the provided SDI slot.

   Parameters
   SlotHandle :   Handle of the slot to work on
   pAFD_AR :      Pointer to a caller\-allocated structure
   containing the AFD_AR slot.

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
    */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedAFD(HANDLE SlotHandle,VHD_AFD_AR_SLOT *pAFD_AR);

/*** VHD_SlotExtractOP47 *******************************************************/
/*!VHD_SlotExtractOP47
   
   Summary
   OP47 data slot extraction
   Description
   This function extracts the OP47 data slot of the given slot.
   Parameters
   SlotHandle : Handle of the slot to work on
   pOP47 :      Pointer to a caller\-allocated structure
                receiving the OP47 slot.

   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractOP47 (HANDLE SlotHandle, VHD_OP47_SLOT *pOP47);

/*** VHD_SlotEmbedOP47 *******************************************************/
/*!VHD_SlotEmbedOP47
   
   Summary
   OP47 data embedding.
   Description
   This function embeds the provided OP47 data slot in the 
   provided slot, according to the specified standard.
   Parameters   
   SlotHandle : Handle of the slot to work on
   pOP47 :      Pointer to a caller\-allocated structure
                containing the OP47 slot.

   Remarks
   If parity bits are needed for the specified standard, they 
   will be automatically generated.
   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)     */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedOP47 (HANDLE SlotHandle, VHD_OP47_SLOT *pOP47);


#endif

#ifdef __cplusplus
}
#endif

#endif // _VIDEOMASTERHD_SDI_VBIDATA_H_

