/*! VideomasterHD_Sdi_Timecode.h

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


#ifndef _VIDEOMASTERHD_SDI_TIMECODE_H_
#define _VIDEOMASTERHD_SDI_TIMECODE_H_

#include "VideoMasterHD_Core.h"


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Timecode
*/


/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Timecode
*/

/*_ VHD_TIMECODETYPE _________________________________________________*/
/*!
   Summary
   VideoMaster embedded timecode types
   Description
   The VHD_TIMECODETYPE enumeration lists all the available
   timecode embedding modes.
   See Also
   VHD_SlotExtractTimecode VHD_SlotEmbedTimecode
   VHD_TIMECODESLOT                                         */

typedef enum _VHD_TIMECODETYPE
{
   VHD_TIMECODE_RP188_LTC = 0,   /*!_VHD_TIMECODETYPE::VHD_TIMECODE_RP188_LTC
                                    LTC timecode embedded in ancillary data according to SMPTE
                                    RP188                                                      */
   VHD_TIMECODE_RP188_VITC1,     /*!_VHD_TIMECODETYPE::VHD_TIMECODE_RP188_VITC1
                                    First VITC timecode embedded in ancillary data according to
                                    SMPTE RP188                                                 */
   VHD_TIMECODE_RP188_VITC2,     /*!_VHD_TIMECODETYPE::VHD_TIMECODE_RP188_VITC2
                                    Second VITC timecode embedded in ancillary data according to
                                    SMPTE RP188                                                  */
   VHD_TIMECODE_S266M_DVITC,     /*! DVITC embedded in VBI according to SMPTE 266M (only valid for SD standards) */
   NB_VHD_TIMECODETYPES
} VHD_TIMECODETYPE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Timecode
*/

/*_ VHD_TIMECODEINFO ___________________________________________*/
/*!
   Summary
   SDI timecode embedding information structure
   Description
   The VHD_TIMECODEINFO structure contains information about
   where timecode has been found in reception streams, or about
   where to embed timecode in transmission streams. In all
   cases, the TcType field must be filled in by the caller in
   order to specify the standard to comply with.
   See Also
   VHD_SlotExtractTimecode VHD_SlotEmbedTimecode
   VHD_TIMECODETYPE VHD_TIMECODESLOT                            */

typedef struct _VHD_TIMECODEINFO
{
   VHD_TIMECODETYPE  TcType;           /*! Timecode embedding standard */
   VHD_SAMPLETYPE    SampleStream;     /*! Specifies if working in Y or in C stream. This field is only relevant when working on 
                                       SMPTE RP188 timecodes in HD streams. In all other cases, the timecode is carried in Y stream.
                                       Setting this field to VHD_SAMPLE_Y_AND_C on reception streams result in looking for timecode in both Y and C streams */
   int               pTcLine[2];       /*! Specifies the video lines (1-based) to embed/look for timecode :
                                       * On reception streams, both value may be used to look for time code 
                                       - Set pTcLine[1] to zero to only look in pTcLine[0]
                                       - Set both pTcLine[0] and pTcLine[1] to browse all lines until timecode is found
                                       * On transmission streams, it depends on the standard used :
                                       - When working with SMPTE RP188 LTC, only pTcLine[0] is used
                                       - When working with SMPTE RP188 VITC, pTcLine[0] is used
                                       - When working with SMPTE 266M, pTCLine defines the two major insertion lines
                                       - If zero values are given for pTcLine[0] and pTcLine[1], then default location is used, according to the relevant standards */
   BOOL32              DuplicateVITC;    /*! TRUE if D-VITC must duplicated on major insertion lines + 2 on transmission streams. Unused on reception streams */
} VHD_TIMECODEINFO;



/*_ VHD_TIMECODESLOT __________________________________________________*/
/*!
   Summary
   SDI timecode structure
   Description
   The VHD_TIMECODESLOT structure contains a SDI timecode value
   and associated embedding information.
   
   It is used respectively in VHD_SlotExtractTimecode and
   VHD_SlotEmbedTimecode API functions to extract a timecode
   value from an ancillary data slot, or to embed such a
   timecode within ancillary data of a frame.
   See Also
   VHD_SlotExtractTimecode VHD_SlotEmbedTimecode
   VHD_TIMECODETYPE VHD_TIMECODE                                */

typedef struct _VHD_TIMECODESLOT
{
   VHD_TIMECODEINFO  TcInfo;     /*! Timecode embedding type */
   VHD_TIMECODE      TcData;     /*! Timecode data */
} VHD_TIMECODESLOT;






#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif


/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Timecode
*/



/*** VHD_SlotExtractTimecode *****************************************************/
/*!VHD_SlotExtractTimecode@HANDLE@VHD_TIMECODESLOT *
   Summary
   Timecode extraction
   Description
   This function looks for the requested timecode type in the
   provided SDI slot.
   
   The concerned stream must be of processing mode including
   ANC/VBI handling
   
   
   
   The VHD_TIMECODESLOT structure exchanged with the caller is
   used both to specify the timecode extraction mode, and to
   return the extracted timecode value
   Parameters
   SlotHandle :  Handle of the slot to operate on
   pTimecode :   Pointer to a caller\-allocated structure
                 specifying the timecode extraction mode, and
                 used to give back the extracted timecode to the
                 caller
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Timecode may be embedded in the SDI signal according to two
   standards :
   
     * SMPTE RP 188 defines a transmission format for conveyance
       of linear (LTC) or vertical interval (VITC) timecode in the
       ancillary data space of a SDI signal. It specifies ANC
       timecode (ATC) embedding for both HD and SD. When extracting
       in this mode, VideoMaster may be configured to look for
       specified ATC (LTC, VITC1 or VITC2) on one line, two lines,
       or on every line until found. This configuration is achieved
       using the pTcLine field of the timecode structure
     * SMPTE 266M describes the signal format of a digital
       vertical interval timecode (D&#45;VITC). It specifies VBI
       timecode embedding for SD signals only. When extracting in
       this mode, first use VHD_VbiSetCaptureLines to configure
       VideoMaster to capture relevant VBI lines. Then,
       VideoMaster may be configured to look for D&#45;VITC on one
       line, two lines, or on every line until found. This
       configuration is achieved using the pTcLine field of the
       timecode structure
   Once a slot is locked, this function may be called several
   times, in order to look for different timecode types as an
   \example
   See Also
   VHD_LockSlotHandle VHD_VbiSetCaptureLines VHD_TIMECODESLOT        */
VIDEOMASTER_HD_API ULONG VHD_SlotExtractTimecode (HANDLE SlotHandle, VHD_TIMECODESLOT *pTimecode);


/*** VHD_SlotEmbedTimecode *******************************************************/
/*!VHD_SlotEmbedTimecode@HANDLE@VHD_TIMECODESLOT
   Summary
   Timecode embedding
   Description
   This function embeds the provided timecode in the provided
   SDI slot, according to the specified standard.
   
   The concerned stream must be of processing mode including
   ANC/VBI handling
   Parameters
   SlotHandle :  Handle of the slot to operate on
   Timecode :    Structure specifying the timecode to embed and
                 the embedding mode
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Timecode may be embedded in the SDI signal according to two
   standards :
   
     * SMPTE RP 188 defines a transmission format for conveyance
       of linear (LTC) or vertical interval (VITC) timecode in the
       ancillary data space of a SDI signal. It specifies ANC
       timecode (ATC) embedding for both HD and SD. When embedding
       in this mode, VideoMaster inserts ATC packet on the line
       specified by the pTcLine[0] field of the timecode structure.
       If this value is set to zero, then default location is
       chosen, according to the video standard used
     * SMPTE 266M describes the signal format of a digital
       vertical interval timecode (D&#45;VITC). It specifies VBI
       timecode embedding for SD signals only. When embedding in
       this mode, VideoMaster inserts D&#45;VITC packet on the two
       lines defined by the pTcLine field of the timecode structure.
       If these two fields are set to zero, then default location is chosen
       according to the video standard used
   Once a slot is locked, this function may be called several
   times, in order to insert different timecode types as an example
   See Also
   VHD_LockSlotHandle VHD_TIMECODESLOT                               */
VIDEOMASTER_HD_API ULONG VHD_SlotEmbedTimecode (HANDLE SlotHandle, VHD_TIMECODESLOT Timecode);

#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_SDI_TIMECODE_H_
