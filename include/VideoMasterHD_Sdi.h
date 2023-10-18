/*! VideomasterHD_Sdi.h

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


#ifndef _VIDEOMASTERHD_SDI_H_
#define _VIDEOMASTERHD_SDI_H_

#include "VideoMasterHD_Anc.h"


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Sdi
*/


/*_ VideomasterHD_Sdi STATUS INFORMATION BIT MASKS ___________________________________*/

#define VHD_MAXNB_VBICAPTURELINE 64       /*!VHD_MAXNB_VBICAPTURELINE
                                             Maximum number of video lines that may be configured for VBI
                                             capture using VHD_VbiSetCaptureLines                         */

   /*! RX channel status bit masks. These constants define status bit masks for the VHD_CORE_BP_RXx_STATUS board properties */
#define VHD_SDI_RXSTS_BADVIDEOSTD           0x00000004  /*! RX channel bad video standard indicator. This bit is set to '1' when the channel cannot recognize incoming video standard */
#define VHD_SDI_RXSTS_BADDATA               0x00000008  /*! RX channel bad data indicator. This bit is set to '1' when the channel detected errors in incoming video signal */
#define VHD_SDI_RXSTS_ALIGNED_COUPLE        0x00000020  /*! RX channel couple aligned indicator. This bit is set to '1' when the two started channels coupled in stereoscopy mode are aligned (<512 pxl) or four started channels coupled in 4k mode are aligned (<512 pxl)*/
#define VHD_SDI_RXSTS_DEPRECATED            0x00000040  /*! Deprecated */
#define VHD_SDI_RXSTS_DUAL_LINK_PHYSICAL    0x00004000  /*! RX channel Dual Link indicator */
#define VHD_SDI_RXSTS_QUAD_LINK_PHYSICAL    0x00000400  /*! RX channel Quad Link indicator */
#define VHD_SDI_RXSTS_LINK_A                0x00000080  /*! RX channel first link (A) indicator in a Dual/Quad Link stream */
#define VHD_SDI_RXSTS_LINK_B                0x00000800  /*! RX channel second link (B) indicator in a Dual/Quad Link stream */
#define VHD_SDI_RXSTS_LINK_C                0x00001000  /*! RX channel third link (C) indicator in a Quad Link stream */
#define VHD_SDI_RXSTS_LINK_D                0x00002000  /*! RX channel fourth link (D) indicator in a Quad Link stream */
#define VHD_SDI_RXSTS_LEVELB_3G             0x00000100  /*! RX channel 3G level B indicator */
#define VHD_SDI_RXSTS_CARRIER_UNDETECTED    0x00000200  /*! RX channel carrier undetected indicator. This bit is set to '1' when the carrier is not detected on incoming signal */

#define VHD_SDI_RXSTS_DL_LINK_A VHD_SDI_RXSTS_LINK_A 
#define VHD_SDI_RXSTS_DUAL_LINK VHD_SDI_RXSTS_DEPRECATED  /*! RX channel Dual Link virtual indicator */

   /*! Genlock status bit masks. These constants define status bit masks for the VHD_SDI_BP_GENLOCK_STATUS board properties */
#define VHD_SDI_GNLKSTS_NOREF     0x00000001  /*!VHD_SDI_GNLKSTS_NOREF
                                                 Genlocking circuitry <i>no reference</i> indicator. This bit
                                                 is set to '1' when no valid input reference is detected by
                                                 the genlocking circuitry                                     */
#define VHD_SDI_GNLKSTS_UNLOCKED  0x00000002  /*!VHD_SDI_GNLKSTS_UNLOCKED
                                                 Unlocked genlocking circuitry indicator. This bit is set to
                                                 '1' when the genlocking circuitry cannot lock itself onto the
                                                 incoming signal                                               */

   /*! HDMI status bit masks. These constants define status bit masks for the VHD_SDI_BP_HDMIx_STATUS board properties */
#define VHD_SDI_HDMISTS_BADVIDEOSTD 0x00000001  /*!VHD_SDI_HDMISTS_BADVIDEOSTD
                                                   HDMI source bad video standard indicator.This bit is set to
                                                   '1' when the HDMI source video standard is not supported by the monitor  */

/*_ VideomasterHD_Sdi EVENT SOURCES __________________________________________________*/

   /*! Event sources bit masks. These constants define event source bit masks for the StateChangeMask parameter of VHD_OpenBoardHandle */
#define VHD_SDI_EVTSRC_GENLOCK    0x04000000  /*! Genlock state changes event source */

/*_ VideomasterHD_Sdi DATA TYPE __________________________________________________*/
/*! Data types bit masks. These constants define data type bit masks for the VHD_CORE_SP_MUTED_DATA_MASK stream property */
#define VHD_SDI_DATA_VIDEO       0x00000001  /*! Video data */
#define VHD_SDI_DATA_ANC         0x00000002  /*! ANC data */
#define VHD_SDI_DATA_THUMBNAIL   0x00000004  /*! Thumbnail data */
#define VHD_SDI_DATA_VIDEO2      0x00000008  /*! Video data of the second channel */
#define VHD_SDI_DATA_ANC2        0x00000010  /*! ANC data of the second channel */
#define VHD_SDI_DATA_THUMBNAIL2  0x00000020  /*! Thumbnail data of the second channel */
#define VHD_SDI_DATA_VIDEO3      0x00000040  /*! Video data of the third channel */
#define VHD_SDI_DATA_VIDEO4      0x00000080  /*! Video data of the fourth channel */
#define VHD_SDI_DATA_ANC3        0x00000100  /*! ANC data of the third channel */
#define VHD_SDI_DATA_ANC4        0x00000200  /*! ANC data of the fourth channel */
#define VHD_SDI_DATA_THUMBNAIL3  0x00000400  /*! Thumbnail data of the third channel */
#define VHD_SDI_DATA_THUMBNAIL4  0x00000800  /*! Thumbnail data of the fourth channel */
#define VHD_SDI_DATA_RAW         0x00001000  /*! RAW data */
#define VHD_SDI_DATA_RAW2        0x00002000  /*! RAW data of the second channel */
#define VHD_SDI_DATA_RAW3        0x00004000  /*! RAW data of the third channel */
#define VHD_SDI_DATA_RAW4        0x00008000  /*! RAW data of the fourth channel */

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Sdi
*/

/*_ VHD_SDI_BOARDPROPERTY _______________________________________________*/
/*!
   Summary
   VideoMaster SDI board properties
   Description
   The VHD_SDI_BOARDPROPERTY enumeration lists all the board
   properties available on SDI cards.
   
   These values are used as indexes for VHD_GetBoardProperty and
   VHD_SetBoardProperty functions calls.
   See Also
   VHD_GetBoardProperty VHD_SetBoardProperty                     */
typedef enum _VHD_SDI_BOARDPROPERTY
{
   VHD_SDI_BP_RX0_STANDARD=ENUMBASE_SDI,  /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX0_STANDARD
                                             Incoming video standard on RX0 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX1_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX1_STANDARD
                                             Incoming video standard on RX1 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX2_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX2_STANDARD
                                             Incoming video standard on RX2 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX3_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX3_STANDARD
                                             Incoming video standard on RX3 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_CLOCK_SYSTEM,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_CLOCK_SYSTEM
                                             On read, read back clock system if genlock source is local.
                                             Otherwise, detected clock system on selected genlock input if locked.
                                             On write, board clock system selection and genlock system restart
                                             that could disturb RX/TX streams.
                                             (see VHD_CLOCKDIVISOR), default is VHD_CLOCKDIV_1.                      */
   VHD_SDI_BP_GENLOCK_SOURCE,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK_SOURCE
                                             Board genlock source selection (see VHD_GENLOCKSOURCE)
                                             , default is VHD_GENLOCK_LOCAL                                          */
   VHD_SDI_BP_GENLOCK_OFFSET,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK_OFFSET
                                             Phase offset (in pixels) to apply to genlocked TX streams
                                             towards their reference (default is 0, max is pixel number per frame)   */
   VHD_SDI_BP_GENLOCK_STATUS,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK_STATUS
                                             Genlock status (see VHD_SDI_GNLKSTS_xxx)                                */
   VHD_SDI_BP_GENLOCK_VIDEO_STANDARD,     /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK_VIDEO_STANDARD
                                             On read, detected video standard on selected genlock input
                                             if locked (see VHD_VIDEOSTANDARD). Because of a genlock reset,
                                             a detection following a clock divisor setting could failed.
                                             On write, configured genlock video standard
                                             (VHD_VIDEOSTD_* = manual setting, VHD_VIDEOSTD_AUTO_DETECT_GENLOCK = auto)
                                             , default is VHD_VIDEOSTD_AUTO_DETECT_GENLOCK                           */
   VHD_SDI_BP_GENLOCK_CIRCUITRY,          /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK_CIRCUITRY
                                             TRUE if the board own genlock circuitry, FALSE if no genlock
                                             circuitry is present. As an example, RX-only boards do not
                                             need genlock circuitry                                                  */
   VHD_SDI_BP_RX0_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX0_CLOCK_DIV
                                          Incoming clock divisor on RX0 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX1_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX1_CLOCK_DIV
                                          Incoming clock divisor on RX1 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX2_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX2_CLOCK_DIV
                                          Incoming clock divisor on RX2 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX3_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX3_CLOCK_DIV
                                          Incoming clock divisor on RX3 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_MASTERTIMESTAMP_DEPRECATED, /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_MASTERTIMESTAMP_DEPRECATED
                                           Board master timestamp (global frame counter)                             */
   VHD_SDI_BP_HDMI0SOURCE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_HDMI0SOURCE
                                          HDMI0 source (see VHD_HDMISOURCE)                                          */
   VHD_SDI_BP_HDMI1SOURCE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_HDMI1SOURCE
                                          HDMI1 source (see VHD_HDMISOURCE)                                          */
   VHD_SDI_BP_HDMI0_STATUS,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_HDMI0_STATUS
                                          HDMI0 status (see VHD_SDI_HDMISTS_xxx)                                     */
   VHD_SDI_BP_HDMI1_STATUS,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_HDMI1_STATUS
                                          HDMI1 status (see VHD_SDI_HDMISTS_xxx)                                     */
   VHD_SDI_BP_HDMI0PACKING,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_HDMI0PACKING
                                          HDMI0 packing (see VHD_BUFFERPACKING)                                      */
   VHD_SDI_BP_HDMI1PACKING,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_HDMI1PACKING
                                          HDMI1 packing (see VHD_BUFFERPACKING)                                      */
   VHD_SDI_BP_GENLOCK_WAITING_FRAMES,   /*! reserved */
   VHD_SDI_BP_GENLOCK_JITTER_WINDOW,    /*! reserved */
   VHD_SDI_BP_GENLOCK_JITTER,           /*! reserved */
   VHD_SDI_BP_RX4_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX4_STANDARD
                                             Incoming video standard on RX3 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX5_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX5_STANDARD
                                             Incoming video standard on RX3 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX6_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX6_STANDARD
                                             Incoming video standard on RX3 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX7_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX7_STANDARD
                                             Incoming video standard on RX3 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX4_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX4_CLOCK_DIV
                                          Incoming clock divisor on RX0 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX5_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX5_CLOCK_DIV
                                          Incoming clock divisor on RX1 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX6_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX6_CLOCK_DIV
                                          Incoming clock divisor on RX2 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX7_CLOCK_DIV,            /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX7_CLOCK_DIV
                                          Incoming clock divisor on RX3 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_CLOCK_SYSTEM2,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_CLOCK_SYSTEM2
                                            On read, read back clock system2 if genlock2 source is local.
                                            Otherwise, detected clock system on selected genlock2 input
                                            if locked. On write, board clock system2 selection and
                                            genlock2 system restart that could disturb RX/TX streams.
                                            (see VHD_CLOCKDIVISOR), default is VHD_CLOCKDIV_1. This
                                            feature is only available on <b>DELTA-hd-elp-d 44</b> 
                                            and <b>DELTA-3G-elp-2key-d</b>.                                          */
   VHD_SDI_BP_GENLOCK2_CIRCUITRY,       /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK2_CIRCUITRY
                                          TRUE if the board own genlock2 circuitry, FALSE if no genlock2
                                          circuitry is present.                                                      */
   VHD_SDI_BP_GENLOCK2_SOURCE,          /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK2_SOURCE
                                           Board genlock2 source selection (see VHD_GENLOCKSOURCE) ,
                                           default is VHD_GENLOCK_LOCAL. This feature is only available
                                           on <b>DELTA-hd-elp-d 44</b> and <b>DELTA-3G-elp-2key-d</b>.               */
   VHD_SDI_BP_GENLOCK2_OFFSET,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK2_OFFSET
                                              Phase offset (in pixels) to apply to genlocked TX streams
                                              towards their reference (default is 0, max is pixel number
                                              per frame). This feature is only available on <b>DELTA-hd-elp-d
                                              44</b> and <b>DELTA-3G-elp-2key-d</b>.                                 */
   VHD_SDI_BP_GENLOCK2_STATUS,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK2_STATUS
                                              Genlock2 status (see VHD_SDI_GNLKSTS_xxx). This feature is
                                              only available on <b>DELTA-hd-elp-d 44</b> 
                                              and <b>DELTA-3G-elp-2key-d</b>.                                        */
   VHD_SDI_BP_GENLOCK2_VIDEO_STANDARD,  /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK2_VIDEO_STANDARD
                                           On read, detected video standard on selected genlock2 input
                                           if locked (see VHD_VIDEOSTANDARD). Because of a genlock2
                                           reset, a detection following a clock divisor setting could
                                           failed. On write, configured genlock2 video standard
                                           (VHD_VIDEOSTD_* = manual setting,
                                           VHD_VIDEOSTD_AUTO_DETECT_GENLOCK = auto) , default is
                                           VHD_VIDEOSTD_AUTO_DETECT_GENLOCK. This feature is only
                                           available on <b>DELTA-hd-elp-d 44</b> and <b>DELTA-3G-elp-2key-d</b>.     */
   VHD_SDI_BP_CLOCK_ADJUST,               /*!__VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_CLOCK_ADJUST
                                          Control the first onboard VCXO that is used to adjust the onboard reference clock frequency.
                                          please contact support@deltacast.tv if you need to use this function */
   VHD_SDI_BP_CLOCK2_ADJUST,              /*!__VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_CLOCK2_ADJUST
                                          Control the second onboard VCXO that is used to adjust the onboard reference clock2 frequency.
                                          please contact support@deltacast.tv if you need to use this function */
   VHD_SDI_BP_RX0_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX0_INTERFACE
                                             Incoming interface on RX0 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX1_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX1_INTERFACE
                                             Incoming interface on RX1 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX2_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX2_INTERFACE
                                             Incoming interface on RX2 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX3_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX3_INTERFACE
                                             Incoming interface on RX3 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX4_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX4_INTERFACE
                                             Incoming interface on RX4 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX5_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX5_INTERFACE
                                             Incoming interface on RX5 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX6_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX6_INTERFACE
                                             Incoming interface on RX6 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX7_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX7_INTERFACE
                                             Incoming interface on RX7 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX0_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX0_GENLOCK_OFFSET
                                             RX0 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX1_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX1_GENLOCK_OFFSET
                                             RX1 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX2_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX2_GENLOCK_OFFSET
                                             RX2 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX3_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX3_GENLOCK_OFFSET
                                             RX3 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX4_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX4_GENLOCK_OFFSET
                                             RX4 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX5_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX5_GENLOCK_OFFSET
                                             RX5 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX6_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX6_GENLOCK_OFFSET
                                             RX6 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX7_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX7_GENLOCK_OFFSET
                                             RX7 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_IS_TICORX,                  /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_IS_TICORX
                                             TRUE if the board supports RX TICO SDI, FALSE if not supported  */
   VHD_SDI_BP_IS_TICOTX,                  /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_IS_TICOTX
                                             TRUE if the board supports TX TICO SDI, FALSE if not supported  */
   VHD_SDI_BP_GENLOCK_LOCAL_INCREMENT,    /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_GENLOCK_LOCAL_INCREMENT
                                             Adjustable local genlock increment value. 
                                             It is expressed in hundredth of ppm (0.01 ppm).
                                             The value can range from -10000 to 10000 (default is 0). */
   VHD_SDI_BP_RX8_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX8_STANDARD
                                             Incoming video standard on RX8 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX9_STANDARD,               /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX9_STANDARD
                                             Incoming video standard on RX9 connector (see VHD_VIDEOSTANDARD)        */
   VHD_SDI_BP_RX10_STANDARD,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX10_STANDARD
                                             Incoming video standard on RX10 connector (see VHD_VIDEOSTANDARD)       */
   VHD_SDI_BP_RX11_STANDARD,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX11_STANDARD
                                             Incoming video standard on RX11 connector (see VHD_VIDEOSTANDARD)       */
   VHD_SDI_BP_RX8_CLOCK_DIV,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX8_CLOCK_DIV
                                             Incoming clock divisor on RX8 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX9_CLOCK_DIV,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX9_CLOCK_DIV
                                             Incoming clock divisor on RX9 connector (see VHD_CLOCKDIVISOR)             */
   VHD_SDI_BP_RX10_CLOCK_DIV,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX10_CLOCK_DIV
                                             Incoming clock divisor on RX10 connector (see VHD_CLOCKDIVISOR)            */
   VHD_SDI_BP_RX11_CLOCK_DIV,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX11_CLOCK_DIV
                                             Incoming clock divisor on RX11 connector (see VHD_CLOCKDIVISOR)            */
   VHD_SDI_BP_RX8_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX8_INTERFACE
                                             Incoming interface on RX8 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX9_INTERFACE,              /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX9_INTERFACE
                                             Incoming interface on RX9 connector (see VHD_INTERFACE)        */
   VHD_SDI_BP_RX10_INTERFACE,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX10_INTERFACE
                                             Incoming interface on RX10 connector (see VHD_INTERFACE)       */
   VHD_SDI_BP_RX11_INTERFACE,             /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX11_INTERFACE
                                             Incoming interface on RX11 connector (see VHD_INTERFACE)       */
   VHD_SDI_BP_RX8_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX8_GENLOCK_OFFSET
                                             RX8 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX9_GENLOCK_OFFSET,         /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX9_GENLOCK_OFFSET
                                             RX9 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX10_GENLOCK_OFFSET,        /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX10_GENLOCK_OFFSET
                                             RX10 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_RX11_GENLOCK_OFFSET,        /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_RX11_GENLOCK_OFFSET
                                             RX11 signal phase offset towards reference clock
                                             Only for genlock system 0                                      */
   VHD_SDI_BP_BLACKBURST_OUTPUT_SOURCE,   /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_BLACKBURST_OUTPUT_SOURCE
                                             Board blackburst output source selection (see VHD_BLACKBURST_OUTPUT_SOURCE)
                                             , default is VHD_BLACKBURST_OUTPUT_SOURCE_DISABLED             */
   VHD_SDI_BP_BLACKBURST_OUTPUT_VIDEO_STANDARD,    /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_BLACKBURST_OUTPUT_VIDEO_STANDARD
                                                      Get/set the video standard from which the output of the blackburst should be generated
                                                      It can return/take a value listed in VHD_VIDEOSTANDARD  */
   VHD_SDI_BP_BLACKBURST_OUTPUT_STATUS,   /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_BLACKBURST_OUTPUT_STATUS
                                             Blackburst output status (see VHD_BLACKBURST_OUTPUT_STATUS)      */
   VHD_SDI_BP_BLACKBURST_OUTPUT_OFFSET,   /*!_VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_BLACKBURST_OUTPUT_OFFSET
                                             Phase offset (in pixels) to apply to blackburst output
                                             towards their reference (default is 0, max is pixel number
                                             per frame).                       */
   NB_VHD_SDI_BOARDPROPERTIES
} VHD_SDI_BOARDPROPERTY;


/*_ VHD_SDI_STREAMPROPERTY ______________________________________________*/
/*!
Summary
VideoMaster SDI streams properties

Description
The VHD_SDI_STREAMPROPERTY enumeration lists all the available SDI
stream properties.

These values are used as indexes for VHD_GetStreamProperty and 
VHD_SetStreamProperty functions calls.

See Also
VHD_GetStreamProperty
VHD_SetStreamProperty
*/
typedef enum _VHD_SDI_STREAMPROPERTY
{
   VHD_SDI_SP_TX_GENLOCK=ENUMBASE_SDI,          /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_TX_GENLOCK
                                                   TX logical stream genlocking control (default is FALSE)  */
   VHD_SDI_SP_VIDEO_STANDARD,                   /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_VIDEO_STANDARD
                                                   Logical stream video standard selection (see VHD_VIDEOSTANDARD)
                                                   ,default is VHD_VIDEOSTD_S259M_PAL for SD boards
                                                  and VHD_VIDEOSTD_S274M_1080p_30Hz for HD boards           */
   VHD_SDI_SP_COMPUTE_CRC,					         /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_COMPUTE_CRC
                          					            Only available with transmission raw stream.
                                                   If this property is set to TRUE, the board computes
                          					            and overrides the CRC of each HD line (EDH packet of each SD
                          					            field). Otherwise, the board transmits the provided buffer
                                                   without modifying CRC and EDH (default is FALSE)         */
   VHD_SDI_SP_VBI_10BITS,                       /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_VBI_10BITS
                                                   VBI 10-Bits or 8-bits packing selection
                                                   ,default is FALSE (8-Bits)                               */
   VHD_SDI_SP_TX_GENLOCK_SELECTION,             /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_TX_GENLOCK_SELECTION
                                                   specify genlock circuitry to use if several are present, 
                                                   default is Gnlk 0                                        */
   VHD_SDI_SP_INTERFACE,                        /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_INTERFACE
                                                   specify how the stream must be managed (see VHD_INTERFACE)
                                                   , default is VHD_INTERFACE_DEPRECATED for backward compatibility reason */
   VHD_SDI_SP_YUVK_NO_CHROMA_ON_KEY,            /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_YUVK_NO_CHROMA_ON_KEY
                                                   if false (default), chroma values of Key stream are equal to Fill ones
                                                   if true, chroma values of Key stream are forced to Neutral value (512 on 10-bit) */
   VHD_SDI_SP_ENABLE_VBI_PARSING,               /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_ENABLE_VBI_PARSING
                                                   if false (default). VANC, on VBI line set for capture, are not detected
                                                   if true, parsing of 10 bits VBI for searching VANC data when set for capture*/
   VHD_SDI_SP_CRC_LINE_ERRORS,                  /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_CRC_LINE_ERRORS
                                                   Counts the number of slots with errors in CRC/EDH line since the stream has been
                                                   started. Note that, the first slot EDH error detection, when starting a stream, 
                                                   may be not complete and need to be discarded because there is missing information. 
                                                   This is due the EDH packets generation who is made on the frame N and N-1. 
*/
   VHD_SDI_SP_CHECK_CRC_SWITCHING_LINE,         /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_CHECK_CRC_SWITCHING_LINE
                                                   If this property is set to TRUE, the CRC check on the switching line 
                                                   is disabled (default is TRUE)                             */
   VHD_SDI_SP_CLOCK_SYSTEM,                     /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_CLOCK_SYSTEM
                                                   Read back clock system (see VHD_CLOCKDIVISOR) if genlock source is local.
                                                   Otherwise, detected clock system on selected genlock input if locked.
                                                   - Read only                                                */
   VHD_SDI_SP_INSERT_S352_PACKET,               /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_INSERT_S352_PACKET
                                                   Insert SMPTE 352m packets in the blanking data space. */

   VHD_SDI_SP_TX_OFFSET,                        /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_TX_OFFSET
                                                   specify TX offset (default is 0)                          */ 
   VHD_SDI_SP_RX_2_OFFSET,                      /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_RX_2_OFFSET
                                                   Second physical link signal phase offset towards first physical link in 
                                                   a Dual/Quad Link stream                                        */
   VHD_SDI_SP_RX_3_OFFSET,                      /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_RX_3_OFFSET
                                                  Third physical link signal phase offset towards first physical link in 
                                                  a Quad Link stream                                        */
   VHD_SDI_SP_RX_4_OFFSET,                      /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_RX_4_OFFSET
                                                  Fourth physical link signal phase offset towards first physical link in 
                                                  a Quad Link stream                                        */
   VHD_SDI_SP_TRANSFER_CHARACTERISTICS,         /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_TRANSFER_CHARACTERISTICS
                                                  Specifies signal transfer characteristics, default is VHD_SDI_TC_SDR_TV 
                                                  (see VHD_SDI_TRANSFER_CHARACTERISTICS) */
   VHD_SDI_SP_COLORIMETRY,                      /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_COLORIMETRY
                                                  Specifies signal colorimetry, default is VHD_SDI_COLORIMETRY_REC_709 
                                                  (see VHD_SDI_COLORIMETRY) */
   VHD_SDI_SP_SIGNAL_PACKING,                   /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_SIGNAL_PACKING
                                                  Specifies signal packing, default is VHD_SDI_SIGNALPACKING_YUV_422_10
                                                  (see VHD_SDI_SIGNAL_PACKING)*/
   VHD_SDI_SP_RECOVERFROM_OUT_OF_RANGE,         /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_RECOVERFROM_OUT_OF_RANGE
                                                   Recovering from out-of-range pixel in active video
                                                   (TRUE = enabled, FALSE = disabled) */
   VHD_SDI_SP_RECOVERFROM_SYNC,                 /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_RECOVERFROM_SYNC
                                                   Recovering from bad, missing or phantom SAV-EAF sync word value
                                                   (TRUE = enabled, FALSE = disabled) */
   VHD_SDI_SP_RECOVERFROM_LINE_NB,              /*!_VHD_SDI_STREAMPROPERTY::VHD_SDI_SP_RECOVERFROM_LINE_NB
                                                   Recovering from invalid line number signaled in SAV-EAV
                                                   (TRUE = enabled, FALSE = disabled) */
   VHD_SDI_SP_DISABLE_ANC_HANDLING,
   NB_VHD_SDI_STREAMPROPERTIES
} VHD_SDI_STREAMPROPERTY;


/*_ VHD_CLOCKDIVISOR __________________________________________*/
/*!
Summary
VideoMaster SDI clock systems

Description
The VHD_CLOCKDIVISOR enumeration lists all supported sample
rate divisors used in VHD_SDI_BP_CLOCK_SYSTEM board property.

See Also
<LINK VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_CLOCK_SYSTEM>              
*/
typedef enum _VHD_CLOCKDIVISOR
{
   VHD_CLOCKDIV_1 = 0,           /*!_VHD_CLOCKDIVISOR::VHD_CLOCKDIV_1
                                    Clock rate divisor to produce a frame rate of 24,25,50,30 or
                                    60 fps (default)                                             */
   VHD_CLOCKDIV_1001,            /*!_VHD_CLOCKDIVISOR::VHD_CLOCKDIV_1001
                                    Clock rate divisor to produce a frame rate of 23.98, 29.97 or
                                    59.94 fps                                                     */
   NB_VHD_CLOCKDIVISORS
} VHD_CLOCKDIVISOR;


/*_ VHD_GENLOCKSOURCE ________________________________________________*/
/*!
Summary
VideoMaster SDI board genlock sources

Description
The VHD_GENLOCKSOURCE enumeration lists all supported genlock
sources used in VHD_SDI_BP_GENLOCK_SOURCE board property.

See Also
<LINK VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_GENLOCK_SOURCE>              
*/
typedef enum _VHD_GENLOCKSOURCE
{
   VHD_GENLOCK_LOCAL = 0,           /*! Local clock (default) */
   VHD_GENLOCK_RX0,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX0
                                       Genlock source is RX0 SDI input */
   VHD_GENLOCK_RX1,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX1
                                       Genlock source is RX1 SDI input */
   VHD_GENLOCK_BB0,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_BB0
                                       Genlock source 0 is analog BlackBurst input */
   VHD_GENLOCK_RX2,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX2
                                       Genlock source is RX2 SDI input */
   VHD_GENLOCK_RX3,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX3
                                       Genlock source is RX3 SDI input */
   VHD_GENLOCK_RX4,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX4
                                       Genlock source is RX4 SDI input */
   VHD_GENLOCK_RX5,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX5
                                       Genlock source is RX5 SDI input */
   VHD_GENLOCK_RX6,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX6
                                       Genlock source is RX6 SDI input */
   VHD_GENLOCK_RX7,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX7
                                       Genlock source is RX7 SDI input */
   VHD_GENLOCK_BB1,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_BB1
                                       Genlock source 1 is analog BlackBurst input */
   VHD_GENLOCK_LOCAL_ADJUSTABLE,    /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_LOCAL_ADJUSTABLE
                                       Adjustable local genlock source
                                       (see VHD_SDI_BOARDPROPERTY::VHD_SDI_BP_VIRTUAL_GNLK_INCREMENT) */
   VHD_GENLOCK_ASI_RX4_DEPRECATED,  /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_ASI_RX4_DEPRECATED
                                       Genlock source is RX4 ASI input */
   VHD_GENLOCK_ASI_RX5_DEPRECATED,  /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_ASI_RX5_DEPRECATED
                                       Genlock source is RX5 ASI input */
   VHD_GENLOCK_ASI_RX6_DEPRECATED,  /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_ASI_RX6_DEPRECATED
                                       Genlock source is RX6 ASI input */
   VHD_GENLOCK_ASI_RX7_DEPRECATED,  /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_ASI_RX7_DEPRECATED
                                       Genlock source is RX7 ASI input */
   VHD_GENLOCK_RX8,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX8
                                       Genlock source is RX8 SDI input */ 
   VHD_GENLOCK_RX9,                 /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX9
                                       Genlock source is RX9 SDI input */ 
   VHD_GENLOCK_RX10,                /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX10
                                       Genlock source is RX10 SDI input */ 
   VHD_GENLOCK_RX11,                /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_RX11
                                       Genlock source is RX11 SDI input */ 
   VHD_GENLOCK_MULTICARD,           /*!_VHD_GENLOCKSOURCE::VHD_GENLOCK_MULTICARD
                                       Genlock source is coming from the external clock input connector */
   NB_VHD_GENLOCKSOURCES
} VHD_GENLOCKSOURCE;

#define VHD_GENLOCK_BB VHD_GENLOCK_BB0 /* Backward compatibility */

/*_ VHD_VIDEOSTANDARD ________________________________________________*/
/*!
   Summary
   VideoMaster supported SDI video standards
   Description
   The VHD_VIDEOSTANDARD enumeration lists all the supported SDI
   video standards
   
   These values are used in VHD_SDI_SP_VIDEO_STANDARD stream
   property.
   See Also
   <link VHD_SDI_STREAMPROPERTY, VHD_SDI_SP_VIDEO_STANDARD>      */
  

typedef enum _VHD_VIDEOSTANDARD
{
   VHD_VIDEOSTD_S274M_1080p_25Hz = 0,  /*! SMPTE 274M - HD 1080p @ 25Hz standard */
   VHD_VIDEOSTD_S274M_1080p_30Hz,      /*! SMPTE 274M - HD 1080p @ 30Hz standard (default) */
   VHD_VIDEOSTD_S274M_1080i_50Hz,      /*! SMPTE 274M - HD 1080i @ 50Hz standard */
   VHD_VIDEOSTD_S274M_1080i_60Hz,      /*! SMPTE 274M - HD 1080i @ 60Hz standard */
   VHD_VIDEOSTD_S296M_720p_50Hz,       /*! SMPTE 296M - HD 720p @ 50Hz standard */
   VHD_VIDEOSTD_S296M_720p_60Hz,       /*! SMPTE 296M - HD 720p @ 60Hz standard */
   VHD_VIDEOSTD_S259M_PAL,             /*! SMPTE 259M - SD PAL standard */
   VHD_VIDEOSTD_S259M_NTSC_487,        /*! SMPTE 259M - SD NTSC standard */
   VHD_VIDEOSTD_S274M_1080p_24Hz,      /*! SMPTE 274M - HD 1080p @ 24Hz standard */
   VHD_VIDEOSTD_S274M_1080p_60Hz,      /*! SMPTE 274M - 3G 1080p @ 60Hz standard */
   VHD_VIDEOSTD_S274M_1080p_50Hz,      /*! SMPTE 274M - 3G 1080p @ 50Hz standard */
   VHD_VIDEOSTD_S274M_1080psf_24Hz,    /*! SMPTE 274M - HD 1080psf @ 24Hz standard */
   VHD_VIDEOSTD_S274M_1080psf_25Hz,    /*! SMPTE 274M - HD 1080psf @ 25Hz standard */
   VHD_VIDEOSTD_S274M_1080psf_30Hz,    /*! SMPTE 274M - HD 1080psf @ 30Hz standard */
   VHD_VIDEOSTD_S296M_720p_24Hz,       /*! SMPTE 296M - HD 720p @ 24Hz standard */
   VHD_VIDEOSTD_S296M_720p_25Hz,       /*! SMPTE 296M - HD 720p @ 25Hz standard */
   VHD_VIDEOSTD_S296M_720p_30Hz,       /*! SMPTE 296M - HD 720p @ 30Hz standard */
   VHD_VIDEOSTD_S2048M_2048p_24Hz,     /*! SMPTE 2048M - HD 2048p @ 24 Hz standard */
   VHD_VIDEOSTD_S2048M_2048p_25Hz,     /*! SMPTE 2048M - HD 2048p @ 25 Hz standard */
   VHD_VIDEOSTD_S2048M_2048p_30Hz,     /*! SMPTE 2048M - HD 2048p @ 30 Hz standard */
   VHD_VIDEOSTD_S2048M_2048psf_24Hz,   /*! SMPTE 2048M - HD 2048psf @ 24 Hz standard */
   VHD_VIDEOSTD_S2048M_2048psf_25Hz,   /*! SMPTE 2048M - HD 2048psf @ 25 Hz standard */
   VHD_VIDEOSTD_S2048M_2048psf_30Hz,   /*! SMPTE 2048M - HD 2048psf @ 30 Hz standard */
   VHD_VIDEOSTD_S2048M_2048p_60Hz,     /*! SMPTE 2048M - 3G 2048p @ 60Hz standard */
   VHD_VIDEOSTD_S2048M_2048p_50Hz,     /*! SMPTE 2048M - 3G 2048p @ 50Hz standard */
   VHD_VIDEOSTD_S2048M_2048p_48Hz,     /*! SMPTE 2048M - 3G 2048p @ 50Hz standard */
   VHD_VIDEOSTD_3840x2160p_24Hz,       /*! 3840x2160 - 4x HD 1080p @ 24Hz merged */
   VHD_VIDEOSTD_3840x2160p_25Hz,       /*! 3840x2160 - 4x HD 1080p @ 25Hz merged */
   VHD_VIDEOSTD_3840x2160p_30Hz,       /*! 3840x2160 - 4x HD 1080p @ 30Hz merged */
   VHD_VIDEOSTD_3840x2160p_50Hz,       /*! 3840x2160 - 4x 3G 1080p @ 50Hz merged */
   VHD_VIDEOSTD_3840x2160p_60Hz,       /*! 3840x2160 - 4x 3G 1080p @ 60Hz merged */
   VHD_VIDEOSTD_4096x2160p_24Hz,       /*! 4096x2160 - 4x HD 2048p @ 24Hz merged */
   VHD_VIDEOSTD_4096x2160p_25Hz,       /*! 4096x2160 - 4x HD 2048p @ 25Hz merged */
   VHD_VIDEOSTD_4096x2160p_30Hz,       /*! 4096x2160 - 4x HD 2048p @ 30Hz merged */
   VHD_VIDEOSTD_4096x2160p_48Hz,       /*! 4096x2160 - 4x 3G 2048p @ 48Hz merged */
   VHD_VIDEOSTD_4096x2160p_50Hz,       /*! 4096x2160 - 4x 3G 2048p @ 50Hz merged */
   VHD_VIDEOSTD_4096x2160p_60Hz,       /*! 4096x2160 - 4x 3G 2048p @ 60Hz merged */
   VHD_VIDEOSTD_S259M_NTSC_480,        /*! SMPTE 259M - SD NTSC standard - 480 active lines */
   VHD_VIDEOSTD_7680x4320p_24Hz,       /*! 7680x4320 - 4x 6G 3840x2160 @ 24Hz merged */
   VHD_VIDEOSTD_7680x4320p_25Hz,       /*! 7680x4320 - 4x 6G 3840x2160 @ 25Hz merged */
   VHD_VIDEOSTD_7680x4320p_30Hz,       /*! 7680x4320 - 4x 6G 3840x2160 @ 30Hz merged */
   VHD_VIDEOSTD_7680x4320p_50Hz,       /*! 7680x4320 - 4x 12G 3840x2160 @ 50Hz merged */
   VHD_VIDEOSTD_7680x4320p_60Hz,       /*! 7680x4320 - 4x 12G 3840x2160 @ 60Hz merged */
   VHD_VIDEOSTD_3840x2160psf_24Hz,     /*! 3840x2160 - 4x HD 1080psf @ 24Hz merged */
   VHD_VIDEOSTD_3840x2160psf_25Hz,     /*! 3840x2160 - 4x HD 1080psf @ 25Hz merged */
   VHD_VIDEOSTD_3840x2160psf_30Hz,     /*! 3840x2160 - 4x HD 1080psf @ 30Hz merged */
   VHD_VIDEOSTD_4096x2160psf_24Hz,     /*! 4096x2160 - 4x HD 2048psf @ 24Hz merged */
   VHD_VIDEOSTD_4096x2160psf_25Hz,     /*! 4096x2160 - 4x HD 2048psf @ 25Hz merged */
   VHD_VIDEOSTD_4096x2160psf_30Hz,     /*! 4096x2160 - 4x HD 2048psf @ 30Hz merged */
   VHD_VIDEOSTD_8192x4320p_24Hz,       /*! 8192x4320 - 4x 6G 2048psf @ 24Hz merged */
   VHD_VIDEOSTD_8192x4320p_25Hz,       /*! 8192x4320 - 4x 6G 2048psf @ 25Hz merged */
   VHD_VIDEOSTD_8192x4320p_30Hz,       /*! 8192x4320 - 4x 6G 2048psf @ 30Hz merged */
   VHD_VIDEOSTD_8192x4320p_48Hz,       /*! 8192x4320 - 4x 12G 2048psf @ 48Hz merged */
   VHD_VIDEOSTD_8192x4320p_50Hz,       /*! 8192x4320 - 4x 12G 2048psf @ 50Hz merged */
   VHD_VIDEOSTD_8192x4320p_60Hz,       /*! 8192x4320 - 4x 12G 2048psf @ 60Hz merged */
   NB_VHD_VIDEOSTANDARDS               
} VHD_VIDEOSTANDARD;

/*!VHD_VIDEOSTD_AUTO_DETECT_GENLOCK
   Auto detection of genlock video standard (used with <link VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_GENLOCK_VIDEO_STANDARD>) */
#define VHD_VIDEOSTD_AUTO_DETECT_GENLOCK   (VHD_VIDEOSTANDARD)(-1)

#define VHD_VIDEOSTD_S259M_NTSC VHD_VIDEOSTD_S259M_NTSC_487 /* Backward compatibility */

/*_ VHD_SDI_STREAMPROCMODE ________________________________________*/
/*!
Summary
VideoMaster SDI streams processing modes

Description
The VHD_SDI_STREAMPROCMODE enumeration lists all the SDI stream 
processing modes.

These values are used during VHD_OpenStreamHandle function calls.

See Also
VHD_OpenStreamHandle
*/

typedef enum _VHD_SDI_STREAMPROCMODE
{
   VHD_SDI_STPROC_RAW=ENUMBASE_SDI,           /*!_VHD_SDI_STREAMPROCMODE::VHD_SDI_STPROC_RAW
                                        Raw data mode (full bitstream handling) */
   VHD_SDI_STPROC_JOINED,            /*! Joined processed mode (synchronous video/anc handling) */
   VHD_SDI_STPROC_DISJOINED_VIDEO,   /*!_VHD_SDI_STREAMPROCMODE::VHD_SDI_STPROC_DISJOINED_VIDEO
                                        Disjoined processed mode (video handling only) */
   VHD_SDI_STPROC_DISJOINED_ANC,     /*!_VHD_SDI_STREAMPROCMODE::VHD_SDI_STPROC_DISJOINED_ANC
                                        Disjoined processed mode (ANC/VBI handling only) */
   VHD_SDI_STPROC_DISJOINED_THUMBNAIL,/*!_VHD_SDI_STREAMPROCMODE::VHD_SDI_STPROC_DISJOINED_THUMBNAIL
                                        Disjoined processed mode (thumbnail handling only) */
   NB_VHD_SDI_STREAMPROCMODE
} VHD_SDI_STREAMPROCMODE;

/*_ VHD_SDI_BUFFERTYPE ________________________________________*/
/*!
   Summary
   VideoMaster SDI buffer type
   Description
   The VHD_SDI_BUFFERTYPE enumeration lists all the SDI buffer
   types.
   
   These values are used during VHD_GetSlotBuffer function calls
   See Also
   VHD_GetSlotBuffer, VHD_STREAMTYPE
   Remarks
   Currently, only one buffer type is available                  */

typedef enum _VHD_SDI_BUFFERTYPE
{
   VHD_SDI_BT_VIDEO = 0,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_VIDEO
                                        SDI video frames buffer type */
   VHD_SDI_BT_VIDEO_2 = 1,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_VIDEO_2
                                        Second SDI video frames buffer type (only for VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_ANC_C = 2,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C
                                        ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y = 3,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y
                                        ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_2 = 4,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_2
                                        Second ANC C playlist buffer type (only for VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_ANC_Y_2 = 5,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_2
                                        Second ANC Y playlist buffer type (only for VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_VIDEO_3 = 6,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_VIDEO_3
                                        Third SDI video frames buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_C_3 = 7,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_3
                                        Third ANC C playlist buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_Y_3 = 8,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_3
                                        Third ANC Y playlist buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_VIDEO_4 = 9,             /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_VIDEO_4
                                        Fourth SDI video frames buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_C_4 = 10,            /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_4
                                        Fourth ANC C playlist buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_Y_4 = 11,            /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_4
                                        Fourth ANC Y playlist buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_THUMBNAIL = 12,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_THUMBNAIL
                                        SDI thumbnail frames buffer type */
   VHD_SDI_BT_THUMBNAIL_2 = 13,        /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_THUMBNAIL_2
                                        Second SDI video thumbnail buffer type (only for VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_ANC_C_B = 14,            /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_B
                                        ANC C playlist buffer type (dual)*/
   VHD_SDI_BT_ANC_Y_B = 15,            /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_B
                                        ANC Y playlist buffer type (dual)*/
   VHD_SDI_BT_ANC_C_2_B = 16,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_2_B
                                        Second ANC C playlist buffer type (only for dual VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_ANC_Y_2_B = 17,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_2_B
                                        Second ANC Y playlist buffer type (only for dual VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_ANC_C_3_B = 18,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_3_B
                                        Third ANC C playlist buffer type (only for dual VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_Y_3_B = 19,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_3_B
                                        Third ANC Y playlist buffer type (only for dual VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_C_4_B = 20,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_4_B
                                        Fourth ANC C playlist buffer type (only for dual VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_Y_4_B = 21,          /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_4_B
                                        Fourth ANC Y playlist buffer type (only for dual VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_THUMBNAIL_3 = 22,        /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_THUMBNAIL_3
                                        Third SDI video thumbnail buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_THUMBNAIL_4 = 23,        /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_THUMBNAIL_4
                                        Fourth SDI video thumbnail buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_RAW = 24,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_RAW
                                        RAW buffer type */
   VHD_SDI_BT_RAW_2 = 25,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_RAW_2
                                        Second RAW buffer type (only for VHD_ST_COUPLED_* stream types)*/
   VHD_SDI_BT_RAW_3 = 26,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_RAW
                                        Third RAW buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_RAW_4 = 27,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_RAW_2
                                       Fourth RAW buffer type (only for VHD_ST_COUPLED_RX0123 or VHD_ST_COUPLED_TX0123 stream types)*/
   VHD_SDI_BT_ANC_C_5,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Fifth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_5,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_5
                                          Fifth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_5_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5_B
                                          Fifth ANC C playlist buffer type (dual) */
   VHD_SDI_BT_ANC_Y_5_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_Y_5_B
                                          Fifth ANC Y playlist buffer type (dual) */
   VHD_SDI_BT_ANC_C_6,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Sixth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_6,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Sixth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_6_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Sixth ANC C playlist buffer type (dual) */
   VHD_SDI_BT_ANC_Y_6_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Sixth ANC Y playlist buffer type (dual) */
   VHD_SDI_BT_ANC_C_7,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Seventh ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_7,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Seventh ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_7_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Seventh ANC C playlist buffer type (dual) */
   VHD_SDI_BT_ANC_Y_7_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Seventh ANC Y playlist buffer type (dual) */
   VHD_SDI_BT_ANC_C_8,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Eighth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_8,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Eighth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_8_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Eighth ANC C playlist buffer type (dual) */
   VHD_SDI_BT_ANC_Y_8_B,               /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Eighth ANC Y playlist buffer type (dual) */
   VHD_SDI_BT_ANC_C_9,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Ninth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_9,                 /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Ninth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_10,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Tenth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_10,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Tenth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_11,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Eleventh ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_11,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Eleventh ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_12,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Twelfth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_12,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Twelfth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_13,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Thirteenth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_13,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Thirteenth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_14,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Fourteenth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_14,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Fourteenth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_15,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Fifteenth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_15,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Fifteenth ANC Y playlist buffer type */
   VHD_SDI_BT_ANC_C_16,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Sixteenth ANC C playlist buffer type */
   VHD_SDI_BT_ANC_Y_16,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_ANC_C_5
                                          Sixteenth ANC Y playlist buffer type */
   VHD_SDI_BT_PLANAR_Y,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_Y
                                          Y-plan buffer type (planar-only scenarios) */
   VHD_SDI_BT_PLANAR_U,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_U
                                          U-plan buffer type (planar-only scenarios)  */
   VHD_SDI_BT_PLANAR_V,                /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_V
                                          V-plan buffer type (planar-only scenarios)  */
   VHD_SDI_BT_PLANAR_Y_2,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_Y_2
                                          Second Y-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_U_2,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_U_2
                                          Second U-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_V_2,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_V_2
                                          Second V-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_Y_3,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_Y_3
                                          Third Y-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_U_3,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_U_3
                                          Third U-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_V_3,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_V_3
                                          Third V-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_Y_4,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_Y_4
                                          Fourth Y-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_U_4,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_U_4
                                          Fourth U-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   VHD_SDI_BT_PLANAR_V_4,              /*!_VHD_SDI_BUFFERTYPE::VHD_SDI_BT_PLANAR_V_4
                                          Fourth V-plan buffer type (planar-only scenarios, only for VHD_ST_COUPLED_* stream types) */
   NB_VHD_SDI_BUFFERTYPE
} VHD_SDI_BUFFERTYPE;


/*_ VHD_HDMISOURCE _____________________________________________*/
/*!
   Summary
   VideoMaster HDMI source
   Description
   The VHD_HDMISOURCE enumeration lists all the available sources
   for the HDMI monitoring
   
   These values are used in VHD_SDI_BP_HDMI0SOURCE and 
   VHD_SDI_BP_HDMI1SOURCE board property and only apply
   to 3G boards.
   See Also
   <link VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_HDMI0SOURCE>
   <link VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_HDMI1SOURCE>
*/
typedef enum _VHD_HDMISOURCE
{
   VHD_HDMISRC_NONE,                      /*! No signal */
   VHD_HDMISRC_PHYSICAL_RX0,              /*! Physical RX0 signal*/
   VHD_HDMISRC_PHYSICAL_RX1,              /*! Physical RX1 signal*/
   VHD_HDMISRC_PHYSICAL_TX0,              /*! Physical TX0 signal*/
   VHD_HDMISRC_PHYSICAL_TX1,              /*! Physical TX1 signal*/
   VHD_HDMISRC_PHYSICAL_TX2,              /*! Physical TX2 signal*/
   VHD_HDMISRC_PHYSICAL_TX3,              /*! Physical TX3 signal*/
   VHD_HDMISRC_PHYSICAL_TX0_SBS_TX1,      /*! Physical TX0 and TX1 signals side by side*/
   VHD_HDMISRC_PHYSICAL_TX0_SBS_TX2,      /*! Physical TX0 and TX2 signals side by side*/
   VHD_HDMISRC_PHYSICAL_TX2_SBS_TX3,      /*! Physical TX2 and TX3 signals side by side*/
   VHD_HDMISRC_PHYSICAL_TX1_SBS_TX3,      /*! Physical TX1 and TX3 signals side by side*/
   NB_VHD_HDMISOURCE
}VHD_HDMISOURCE;

/*_ VHD_INTERFACE _____________________________________________*/
/*!
   Summary
   VideoMaster interface
   Description
   The VHD_INTERFACE enumeration lists all the available interface
   
   These values are used in VHD_SDI_SP_INTERFACE
   See Also
   <link VHD_SDI_BOARDPROPERTY, VHD_SDI_SP_INTERFACE>
*/
typedef enum _VHD_INTERFACE
{
   VHD_INTERFACE_DEPRECATED,                    /*! */
   VHD_INTERFACE_SD_259,                        /*! SD SMPTE 259 interface*/
   VHD_INTERFACE_HD_292_1,                      /*! HD SMPTE 291-1 interface*/
   VHD_INTERFACE_HD_DUAL,                       /*! HD Dual Link SMPTE 372 interface*/
   VHD_INTERFACE_3G_A_425_1,                    /*! 3G-A SMPTE 425-1 interface*/
   VHD_INTERFACE_4XHD_QUADRANT,                 /*! 4xHD interface (4K image is split into 4 quadrants for transport)*/
   VHD_INTERFACE_4X3G_A_QUADRANT,               /*! 4x3G-A interface (4K image is split into 4 quadrants for transport)*/
   VHD_INTERFACE_SD_DUAL,                       /*! SD Dual Link (application of SMPTE 372 to SD) */
   VHD_INTERFACE_3G_A_DUAL,                     /*! 3G-A Dual interface (application of SMPTE 372 to 3GA)*/
   VHD_INTERFACE_3G_B_DL_425_1,                 /*! 3G-B SMPTE 425-1 interface for mapping of SMPTE ST 372 dual-link*/
   VHD_INTERFACE_4X3G_B_DL_QUADRANT,            /*! 4x3G-B SMPTE 425-1 interface for mapping of SMPTE ST 372 dual-link (4K image is split into 4 quadrants for transport)*/
   VHD_INTERFACE_2X3G_B_DS_425_3,               /*! 2x3G-B SMPTE 425-3 interface  (4K image is split into 4 images with the 2-sample interleave division rule for transport)*/
   VHD_INTERFACE_4X3G_A_425_5,                  /*! 4x3G-A SMPTE 425-5 interface  (4K image is split into 4 images with the 2-sample interleave division rule for transport)*/
   VHD_INTERFACE_4X3G_B_DL_425_5,               /*! 4x3G-B SMPTE 425-5 interface  (4K image is split into 4 images with the 2-sample interleave division rule for transport)*/
   VHD_INTERFACE_3G_B_DL_425_1_DUAL,            /*! 3G-B SMPTE 425-1 interface for mapping of SMPTE ST 372 dual-link, dual interface*/
   VHD_INTERFACE_2X3G_B_DS_425_3_DUAL,          /*! 2x3G-B SMPTE 425-3 interface  (4K image is split into 4 images with the 2-sample interleave division rule for transport), dual interface*/
   VHD_INTERFACE_4XHD_QUADRANT_DUAL,            /*! 4xHD interface (4K image is split into 4 quadrants for transport), dual interface*/
   VHD_INTERFACE_4X3G_A_QUADRANT_DUAL,          /*! 4x3G-A interface (4K image is split into 4 quadrants for transport), dual interface*/
   VHD_INTERFACE_4X3G_A_425_5_DUAL,             /*! 4x3G-A SMPTE 425-5 interface  (4K image is split into 4 images with the 2-sample interleave division rule for transport), dual interface*/
   VHD_INTERFACE_4X3G_B_DL_QUADRANT_DUAL,       /*! 4x3G-B SMPTE 425-1 interface for mapping of SMPTE ST 372 dual-link (4K image is split into 4 quadrants for transport), dual interface*/
   VHD_INTERFACE_4X3G_B_DL_425_5_DUAL,          /*! 4x3G-B SMPTE 425-5 interface  (4K image is split into 4 images with the 2-sample interleave division rule for transport), dual interface*/
   VHD_INTERFACE_TICO_3G_A_425_1,               /*! 4K image transports with TICO over 3G-A SMPTE 425-1 interface*/
   VHD_INTERFACE_TICO_HD_292_1,                 /*! 4K image transports with TICO over HD SMPTE 291-1 interface*/
   VHD_INTERFACE_6G_2081_10,                    /*! 6G over SMPTE 2081-10 interface*/
   VHD_INTERFACE_12G_2082_10,                   /*! 12G over SMPTE 2082-10 interface*/
   VHD_INTERFACE_3G_B_DS_425_1,                 /*! 3G-B dual stream SMPTE 425-1 interface*/
   VHD_INTERFACE_4X6G_2081_10_QUADRANT,         /*! 4x6G over SMPTE 2081-10 interface (8K image is split into 4 quadrants for transport)*/
   VHD_INTERFACE_4X12G_2082_10_QUADRANT,        /*! 4x12G over SMPTE 2082-10 interface (8K image is split into 4 quadrants for transport)*/
   VHD_INTERFACE_6G_2081_10_DUAL,               /*! 6G over SMPTE 2081-10, dual interface */
   VHD_INTERFACE_12G_2082_10_DUAL,              /*! 12G over SMPTE 2082-10, dual interface */
   VHD_INTERFACE_4X6G_2081_12,                  /*! 4x6G over SMPTE 2081-12 */
   VHD_INTERFACE_4X12G_2082_12,                 /*! 4x12G over SMPTE 2082-12*/
   NB_VHD_INTERFACE
}VHD_INTERFACE;

#define VHD_INTERFACE_AUTO                   VHD_INTERFACE_DEPRECATED                     /*! Backward compatibility */
#define VHD_INTERFACE_3G_B_425_1_DL          VHD_INTERFACE_3G_B_DL_425_1                  /*! Backward compatibility */
#define VHD_INTERFACE_4XHD                   VHD_INTERFACE_4XHD_QUADRANT                  /*! Backward compatibility */
#define VHD_INTERFACE_4X3G_A                 VHD_INTERFACE_4X3G_A_QUADRANT                /*! Backward compatibility */
#define VHD_INTERFACE_4X3G_B_DL              VHD_INTERFACE_4X3G_B_DL_QUADRANT             /*! Backward compatibility */
#define VHD_INTERFACE_3G_B_425_1_DL_DUAL     VHD_INTERFACE_3G_B_DL_425_1_DUAL             /*! Backward compatibility */
#define VHD_INTERFACE_4XHD_DUAL              VHD_INTERFACE_4XHD_QUADRANT_DUAL             /*! Backward compatibility */
#define VHD_INTERFACE_4X3G_A_DUAL            VHD_INTERFACE_4X3G_A_QUADRANT_DUAL           /*! Backward compatibility */
#define VHD_INTERFACE_4X3G_B_DL_DUAL         VHD_INTERFACE_4X3G_B_DL_QUADRANT_DUAL        /*! Backward compatibility */
#define VHD_INTERFACE_HD_DUAL_372            VHD_INTERFACE_HD_DUAL                        /*! Backward compatibility */


/*_ VHD_SDI_BOARD_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster SDI board capability
  Description
  The VHD_SDI_BOARD_CAPABILITY enumeration lists all the available SDI board capabilities
   
  These values are used in VHD_GetBoardCapability function
  See Also
  <link VHD_GetBoardCapability>
*/
typedef enum _VHD_SDI_BOARD_CAPABILITY
{
   VHD_SDI_BOARD_CAP_PROCESSED_AND_RAW_CAPTURE = ENUMBASE_SDI,       /*! Return true if the board supports simultaneous access to RAW and Video buffer type with VHD_GetSlotBuffer function handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_OUT_OF_RANGE,                         /*! Return true if the board supports out of range status handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_CORRUPTED_SYNC,                       /*! Return true if the board supports corrupted sync status handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_MISSING_SYNC,                         /*! Return true if the board supports missing sync status handling feature*/		
   VHD_SDI_BOARD_CAP_RX_STATUS_PARASITE_SYNC,                        /*! Return true if the board supports parasite sync status handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_INVALID_LINE_NB,                      /*! Return true if the board supports invalid line number status handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_CRC_EDF_ERR,                          /*! Return true if the board supports CRC/EDH error status handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_CORRUPTED_ANC,                        /*! Return true if the board supports corrupted ANC status handling feature*/
   VHD_SDI_BOARD_CAP_RX_STATUS_ANC_INTO_SWZ,                         /*! Return true if the board supports ANC into switching line status handling feature*/
   VHD_SDI_BOARD_CAP_HDR_SIGNALING,                                  /*! Return true if the board supports HDR signaling inside payload identifier*/
   VHD_SDI_BOARD_CAP_RX_RECOVERING_OUT_OF_RANGE,                     /*! Return true if the board supports recovering from out-of-range pixel in active video*/
   VHD_SDI_BOARD_CAP_RX_RECOVERING_SYNC,                             /*! Return true if the board supports recovering from bad, missing or phantom SAV-EAF sync word value*/
   VHD_SDI_BOARD_CAP_RX_RECOVERING_LINE_NB,                          /*! Return true if the board supports recovering from invalid line number signaled in SAV-EAV*/
   VHD_SDI_BOARD_CAP_GENLOCK_LOCAL_ADJUSTABLE,                       /*! Return true if the board supports adjustable local genlock feature*/
   VHD_SDI_BOARD_CAP_COUPLED_STREAMS,                                /*! Return the maximum number of streams that can be coupled on the board*/
   VHD_SDI_BOARD_CAP_BLACKBURST_OUTPUT,                              /*! Return true if the board supports blackburst output feature*/
   NB_VHD_SDI_BOARD_CAPABILITY
}VHD_SDI_BOARD_CAPABILITY;

/*_ VHD_SDI_TRANSFER_CHARACTERISTICS _____________________________________________*/
/*!
Summary
VideoMaster SDI transfer characteristics
Description
The VHD_SDI_TRANSFER_CHARACTERISTICS enumeration lists all the available SDI transfer characteristics.
Only valid for ST425-1 and ST372 standards.

These values are used in VHD_SDI_SP_TRANSFER_CHARACTERISTICS
See Also
<link VHD_SDI_STREAMPROPERTY>
*/
typedef enum _VHD_SDI_TRANSFER_CHARACTERISTICS
{
   VHD_SDI_TC_SDR_TV,                     /*! SDR-TV in accordance with Recommendation ITU-R BT.709 as referenced by SMPTE ST 274 and ST 296 */
   VHD_SDI_TC_HLG,                        /*! HLG HDR-TV in accordance with Recommendation ITU-R BT.2100 */
   VHD_SDI_TC_PQ,                         /*! PQ HDR-TV in accordance with Recommendation ITU-R BT.2100 */
   NB_VHD_SDI_TRANSFER_CHARACTERISTICS
}VHD_SDI_TRANSFER_CHARACTERISTICS;

/*_ VHD_SDI_COLORIMETRY _____________________________________________*/
/*!
Summary
VideoMaster SDI colorimetry
Description
The VHD_SDI_COLORIMETRY enumeration lists all the available SDI colorimetry.
Only valid for ST425-1 and ST372 standards.

These values are used in VHD_SDI_SP_COLORIMETRY 
See Also
<link VHD_SDI_STREAMPROPERTY>
*/
typedef enum _VHD_SDI_COLORIMETRY
{
   VHD_SDI_COLORIMETRY_REC_709,  /*! Rec 709 colorimetry in accordance with Recommendation ITU-R BT.709 as referenced by SMPTE ST 274 and ST 296 */
   VHD_SDI_COLORIMETRY_UHDTV,    /*! UHDTV colorimetry in accordance with the Reference Primaries and reference white as defined in Recommendation ITU-R BT.2100 */
   NB_VHD_SDI_COLORIMETRY
}VHD_SDI_COLORIMETRY;

/*_ VHD_SDI_SIGNALPACKING _____________________________________________*/
/*!
Summary
VideoMaster SDI signal packing
Description
The VHD_SDI_SIGNAL_PACKING  enumeration lists all the available SDI colorimetry.
Only valid for ST425-1 and ST372 standards.

These values are used in VHD_SDI_SP_SIGNAL_PACKING
See Also
<link VHD_SDI_STREAMPROPERTY>
*/
typedef enum _VHD_SIGNALPACKING
{
   VHD_SDI_SIGNALPACKING_YUV_422_10,      /*! Y'C'bC'r luminance and color difference signal */
   VHD_SDI_SIGNALPACKING_ICTCP_422_10,    /*! ICTCP luminance and color difference signal */
   NB_VHD_SDI_SIGNAL_PACKING
}VHD_SDI_SIGNALPACKING;

/*_ VHD_BLACKBURST_OUTPUT_SOURCE ________________________________________________*/
/*!
Summary
VideoMaster SDI board blackburst output sources

Description
The VHD_BLACKBURST_OUTPUT_SOURCE enumeration lists all supported blackburst output
sources used in VHD_SDI_BP_BLACKBURST_OUTPUT_SOURCE board property.

See Also
<LINK VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_BLACKBURST_OUTPUT_SOURCE>              
*/
typedef enum _VHD_BLACKBURST_OUTPUT_SOURCE
{
   VHD_BLACKBURST_OUTPUT_SOURCE_DISABLED = 0,            /*!VHD_BLACKBURST_OUTPUT_SOURCE::VHD_BLACKBURST_OUTPUT_SOURCE_DISABLED
                                                            Blackburst output source is disable (default) */
   VHD_BLACKBURST_OUTPUT_SOURCE_FREERUN,                 /*!VHD_BLACKBURST_OUTPUT_SOURCE::VHD_BLACKBURST_OUTPUT_SOURCE_FREERUN
                                                            Blackburst output source is freerun (default) */
   VHD_BLACKBURST_OUTPUT_SOURCE_BB_LOOPBACK,             /*!VHD_BLACKBURST_OUTPUT_SOURCE::VHD_BLACKBURST_OUTPUT_SOURCE_BB_LOOPBACK
                                                            Blackburst output source is loopback (default) */
   VHD_BLACKBURST_OUTPUT_SOURCE_GENLOCK,                 /*!VHD_BLACKBURST_OUTPUT_SOURCE::VHD_BLACKBURST_OUTPUT_SOURCE_GENLOCK
                                                            Blackburst output source is genlock (default) */
   NB_VHD_BLACKBURST_OUTPUT_SOURCE
} VHD_BLACKBURST_OUTPUT_SOURCE;

/*_ VHD_BLACKBURST_OUTPUT_STATUS ________________________________________________*/
/*!
Summary
VideoMaster SDI board blackburst output status

Description
The VHD_BLACKBURST_OUTPUT_STATUS enumeration lists all supported blackburst output
status used in VHD_SDI_BP_BLACKBURST_OUTPUT_STATUS board property.

See Also
<LINK VHD_SDI_BOARDPROPERTY, VHD_SDI_BP_BLACKBURST_OUTPUT_STATUS>              
*/
typedef enum _VHD_BLACKBURST_OUTPUT_STATUS
{
   VHD_BLACKBURST_OUTPUT_STATUS_UNLOCKED = 1,     /*!VHD_BLACKBURST_OUTPUT_STATUS::VHD_BLACKBURST_OUTPUT_STATUS_UNLOCKED
                                                   Blackburst output status is unlocked */
   NB_VHD_BLACKBURST_OUTPUT_STATUS
} VHD_BLACKBURST_OUTPUT_STATUS;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Sdi
*/


/*_ VHD_VBILINE __________________________________________________*/
/*!
   Summary
   VBI line capture configuration
   Description
   The VHD_VBILINE structure defines a capture parameter for VBI
   data. This structure is used in an array in
   VHD_VbiSetCapturedLines in order to configure up to
   VHD_MAXNB_VBICAPTURELINE lines to capture VBI from
   See Also
   VHD_VbiSetCaptureLines                                        */

typedef struct _VHD_VBILINE
{
   int   LineNumber;    /*! Specifies the line number (1-based) to capture VBI from */
   BOOL32  CaptureFromY;  /*! Specifies if Y samples must be captured on this line */
   BOOL32  CaptureFromC;  /*! Specifies if C samples must be captured on this line */
} VHD_VBILINE;


/*_ VHD_SDI_SLOTSTATUS _______________________________________________________*/
/*!
   Summary
   SDI slot status structure
   Description
   The VHD_SDI_SLOTSTATUS structure is used to report the status
   of an SDI slot.
   See Also
   VHD_GetSlotStatus
*/
typedef struct _VHD_SDI_SLOTSTATUS
{
   ULONG  Size;                        /*! The size, in bytes, of this data structure. 
                                           Set this member to sizeof(VHD_SDI_SLOTSTATUS) before calling the VHD_GetSlotStatus function. */
   BOOL32 RX_OutOfRange;               /*!_VHD_SDI_SLOTSTATUS::RX_OutOfRange
                                             TRUE when the hardware receiver does detect an incorrect value 
                                             for luminance and chrominance samples in the received frame.
                                             The correct value should be between 64 and 940 for luminance samples, 
                                             and 64 and 960 for chrominance samples. */
   BOOL32 RX_CorruptedSync;            /*!_VHD_SDI_SLOTSTATUS::RX_CorruptedSync
                                             TRUE when the hardware receiver does detect an invalid value 
                                             in SDI sync codes of the received frame,
                                             for example corruption in the XYZ word in the sync code. */
   BOOL32 RX_MissingSync;              /*!_VHD_SDI_SLOTSTATUS::RX_MissingSync
                                             TRUE when the hardware receiver does detect all the SDI sync code 
                                             but there is missing SDI sync codes in the received frame. */
   BOOL32 RX_ParasiteSync;             /*!_VHD_SDI_SLOTSTATUS::RX_ParasiteSync
                                             TRUE when the hardware receiver does detect all the SDI sync code 
                                             but there is parasite SDI sync codes in the received frame.*/
   BOOL32 RX_InvalidLineNumber;        /*!_VHD_SDI_SLOTSTATUS::RX_InvalidLineNumber
                                             TRUE when the hardware receiver does detect an invalid sequence 
                                             in the line numbers in the received frame.*/
   BOOL32 RX_EXT_CRC_EDH_Error;        /*!_VHD_SDI_SLOTSTATUS::RX_EXT_CRC_EDH_Error
                                             TRUE when the hardware receiver does detect corruption 
                                             when computing and checking the CRC(HD and 3G)/EDH(SD only) fields of the received frame.*/
   BOOL32 RX_CorruptedANC;             /*!_VHD_SDI_SLOTSTATUS::RX_CorruptedANC
                                             TRUE when the hardware receiver does detect corruption 
                                             when computing and checking the checksum field of the ANC data packets. */
   BOOL32 RX_ANCIntoSWZ;               /*!_VHD_SDI_SLOTSTATUS::RX_CorruptedANC
                                             TRUE when the hardware receiver does detect ANC 
                                             into the switching line zone of the received frame. */
}VHD_SDI_SLOTSTATUS;



#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Sdi
*/

/*** VHD_SlotGetNbCrcLineErrors ****************************************************/
/*!VHD_SlotGetNbCrcLineErrors@HANDLE@ULONG *
   Summary
   Slot number of CRC line errors query 
   Description
   On DELTA-3G-elp-key-d 4K and DELTA-3G-elp-d 4c,8c, this function retrieves 
   the number of CRC line errors associated to the given slot.
   On DELTA-hd-elp-d xx, DELTA-3G-elp xx and DELTA-3G-elp-d xx, this function 
   signals CRC errors associated to the given slot. If an error (or more) occurs,
   the number of CRC line error will be set to 1.
   Parameters
   SlotHandle :      Handle of the slot to operate on
   pNbCrcLineErrors : Pointer to caller\-allocated variable
                     receiving the number of CRC line errors
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_SlotGetNbCrcLineErrors (HANDLE SlotHandle, ULONG *pNbCrcLineErrors);

/*_ Ancillary data buffers navigation functions _____________________________*/


/*_ VBI data buffers navigation functions ___________________________________*/


/*** VHD_VbiSetCaptureLines **************************************************/
/*!VHD_VbiSetCaptureLines@HANDLE@VHD_VBILINE
   Summary
   VBI capture lines configuration
   Description
   This function configures the video lines from which VBI data
   must be captured on a SDI reception stream.
   
   The concerned stream must be of processing mode including
   ANC/VBI handling
   
   The function must be called before starting the capture using
   VHD_StartStream. The VBI capture configuration remains active
   until the stream handle is closed using
   VHD_CloseStreamHandle, or until it is re-configured by
   calling this function again.
   Parameters
   StrmHandle :     Handle of the stream to work on
   pCaptureLines :  Array of structure defining the video lines
                    to capture VBI from. To capture less than
                    VHD_MAXNB_VBICAPTURELINE lines, simply reset
                    all other entries to zero
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Please note that no ancillary data packets will be captured
   in active video part of the lines configured for VBI capture.
   
   When working in SD, the CaptureFromY and CaptureFromC fields
   of the pCaptureLines array are meaningless. In this case, Y
   and C samples are always captured and multiplexed together in
   the VBI buffer
   See Also
   VHD_VBILINE VHD_MAXNB_VBICAPTURELINE                          */
VIDEOMASTER_HD_API ULONG VHD_VbiSetCaptureLines (HANDLE StrmHandle, VHD_VBILINE pCaptureLines[VHD_MAXNB_VBICAPTURELINE]);

/*** VHD_VbiSetCaptureLines2 **************************************************/
/*!VHD_VbiSetCaptureLines2@HANDLE@VHD_VBILINE
   Summary
   VBI capture lines configuration on the second coupled stream
   Description
   This function configures the video lines from which VBI data
   must be captured on the second coupled SDI reception stream.
   
   The concerned stream must be of type VHD_ST_COUPLED_RX01 or
   VHD_ST_COUPLED_RX23, and of processing mode including
   ANC/VBI handling.
   
   The function must be called before starting the capture using
   VHD_StartStream. The VBI capture configuration remains active
   until the stream handle is closed using
   VHD_CloseStreamHandle, or until it is re-configured by
   calling this function again.
   Parameters
   StrmHandle :     Handle of the stream to work on
   pCaptureLines :  Array of structure defining the video lines
                    to capture VBI from. To capture less than
                    VHD_MAXNB_VBICAPTURELINE lines, simply reset
                    all other entries to zero
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Please note that no ancillary data packets will be captured
   in active video part of the lines configured for VBI capture.
   
   When working in SD, the CaptureFromY and CaptureFromC fields
   of the pCaptureLines array are meaningless. In this case, Y
   and C samples are always captured and multiplexed together in
   the VBI buffer
   See Also
   VHD_VBILINE VHD_MAXNB_VBICAPTURELINE                          */
VIDEOMASTER_HD_API ULONG VHD_VbiSetCaptureLines2 (HANDLE StrmHandle, VHD_VBILINE pCaptureLines[VHD_MAXNB_VBICAPTURELINE]);

/*** VHD_VbiSetCaptureLinesEx **************************************************/
/*!VHD_VbiSetCaptureLinesEx
   Summary
   VBI capture lines configuration on the specified stream
   Description
   This function configures the video lines from which VBI data
   must be captured on the specified SDI reception stream. If ChannelIndex = -1
   the function configures the video lines on each available SDI reception stream.
   
   The concerned stream must be of processing mode including
   ANC/VBI handling.
   
   The function must be called before starting the capture using
   VHD_StartStream. The VBI capture configuration remains active
   until the stream handle is closed using
   VHD_CloseStreamHandle, or until it is re-configured by
   calling this function again.
   Parameters
   StrmHandle :     Handle of the stream to work on
   pCaptureLines :  Array of structure defining the video lines
                    to capture VBI from. To capture less than
                    VHD_MAXNB_VBICAPTURELINE lines, simply reset
                    all other entries to zero
   ChannelIndex :   Specify the SDI reception stream on which the VBI
                    data must be captured
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Please note that no ancillary data packets will be captured
   in active video part of the lines configured for VBI capture.
   
   When working in SD, the CaptureFromY and CaptureFromC fields
   of the pCaptureLines array are meaningless. In this case, Y
   and C samples are always captured and multiplexed together in
   the VBI buffer
   See Also
   VHD_VBILINE VHD_MAXNB_VBICAPTURELINE                          */
VIDEOMASTER_HD_API ULONG VHD_VbiSetCaptureLinesEx (HANDLE StrmHandle, VHD_VBILINE pCaptureLines[VHD_MAXNB_VBICAPTURELINE], ULONG ChannelIndex);

/*** VHD_SlotVbiGetLine **********************************************************/
/*!VHD_SlotVbiGetLine
   Summary
   VBI lines retrieval
   Description
   This function retrieves the specified VBI line raw content
   from the provided SDI slot.
   
   The concerned stream must be of processing mode including
   ANC/VBI handling, and the requested video line must be
   included in the list passed to VHD_VbiSetCaptureLines
   Parameters
   SlotHandle :    Handle of the slot to work on
   LineNumber :    Video line number to get VBI from (1..N, with
                   N depending on the standard)
   VbiStream :     Specifies if working on Y or C samples stream
                   (in SD, Y and C samples are multiplexed
                   together in C stream)
   ppLineBuffer :  Pointer receiving a pointer to raw VBI line
                   buffer
   pBufferSize :   Pointer receiving the size of the buffer
                   provided to ppLineBuffer
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   When working in SD, the VbiStream argument value must be
   VHD_SAMPLE_C, since Y and C samples are always captured and
   multiplexed together in the VBI buffer
   See Also
   VHD_VBILINE VHD_MAXNB_VBICAPTURELINE VHD_VbiSetCaptureLines   */
VIDEOMASTER_HD_API ULONG VHD_SlotVbiGetLine (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE VbiStream, BYTE **ppLineBuffer, ULONG *pBufferSize);

/*** VHD_SlotVbiRemoveLine **********************************************************/
/*!VHD_SlotVbiRemoveLine
   Summary
   VBI lines remove from SDI slot
   Description
   This function remove the specified VBI line
   from the provided SDI slot.
   Parameters
   SlotHandle :    Handle of the slot to work on
   LineNumber :    Video line number to get VBI from (1..N, with
                   N depending on the standard)
   VbiStream :     Specifies if working on Y or C samples stream
                   (in SD, Y and C samples are multiplexed
                   together in C stream)
   
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
    */
VIDEOMASTER_HD_API ULONG VHD_SlotVbiRemoveLine (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE VbiStream);


/*** VHD_SlotVbiInsertLine *******************************************************/
/*!VHD_SlotVbiInsertLine@HANDLE@int@VHD_SAMPLETYPE@BYTE *@ULONG
   Summary
   VBI lines insertion
   Description
   This function inserts the specified VBI line raw content on
   the provided SDI slot.
   
   The concerned stream must be of processing mode including
   ANC/VBI handling
   Parameters
   SlotHandle :   Handle of the slot to work on
   LineNumber :   Video line number to insert VBI on (1..N, with
                  N depending on the standard)
   VbiStream :    Specifies if working on Y or C samples stream
                  (in SD, Y and C samples are multiplexed
                  together in C stream)
   pLineBuffer :  Pointer to raw VBI content to insert to line
   BufferSize :   Size (in bytes) of the pLineBuffer
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Please note that no ancillary data packets will be inserted
   in active video part of the lines configured for VBI
   insertion.
   
   When working in SD, the VbiStream argument is ignored, since
   Y and C samples are always captured and multiplexed together
   in the VBI buffer
   
   
   
   The provided buffer size cannot exceed the active line size,
   depending on the video standard used. If the buffer is
   smaller than line size, then it will be automatically
   completed with idle level samples
   See Also
   VHD_VBILINE VHD_MAXNB_VBICAPTURELINE                          */
VIDEOMASTER_HD_API ULONG VHD_SlotVbiInsertLine (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE VbiStream, BYTE *pLineBuffer, ULONG BufferSize);

/*** VHD_GetVideoCharacteristics **********************************************************/
/*!VHD_GetVideoCharacteristics
   Summary
   Retrieves video standard characteristics
   Description
   This function retrieves the video standard characteristics
   associated to the given video standard
   Parameters
   VideoStd :     Video standard (see VHD_VIDEOSTANDARD enum)
   pWidth :       Pointer to caller\-allocated variable
                     receiving the width
   pHeight :      Pointer to caller\-allocated variable
                     receiving the height
   pInterlaced :  Pointer to caller\-allocated variable
                     receiving the interlace boolean value
   pFramerate :   Pointer to caller\-allocated variable
                     receiving the framerate
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
    */
VIDEOMASTER_HD_API ULONG VHD_GetVideoCharacteristics(VHD_VIDEOSTANDARD VideoStd, ULONG* pWidth, ULONG* pHeight, BOOL32* pInterlaced, ULONG* pFramerate);

/*** VHD_GetSdiBufferSize **********************************************************/
/*!VHD_GetSdiBufferSize
   Summary
   Converts video information to buffer size
   Description
   This function converts a video standard with additional information
   on buffer packing, interface and processing mode into a buffer size.
   Parameters
   VideoStd :        Video standard (see VHD_VIDEOSTANDARD enum)
   BufferPacking :   Buffer packing (see VHD_BUFFERPACKING enum)
   Interface :       Interface (see VHD_INTERFACE enum)
   ProcMode :        Processing mode (see VHD_SDI_STREAMPROCMODE enum)
   pBufferSize :     Pointer to caller\-allocated variable
                     receiving the computed buffer size
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
    */
VIDEOMASTER_HD_API ULONG VHD_GetSdiBufferSize(VHD_VIDEOSTANDARD VideoStd, VHD_BUFFERPACKING BufferPacking, VHD_INTERFACE Interface, VHD_SDI_STREAMPROCMODE ProcMode, ULONG* pBufferSize);

/*** VHD_GetBoardCapSDIVideoStandard ***************************************************/
/*!VHD_GetBoardCapSDIVideoStandard
   Summary
   VideoMaster board capability video standard
   Description
   This function retrieves the SDI video standard capability of the specified board
   Parameters
   BoardHandle :        Handle of the board to get capability from
   VideoStandard :      VideoStandard to query the board capability for.
   pIsCapable :         Pointer to caller\-allocated boolean variable to return
                        the video standard capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      
*/
VIDEOMASTER_HD_API ULONG VHD_GetBoardCapSDIVideoStandard(HANDLE BoardHandle, VHD_STREAMTYPE StreamType, VHD_VIDEOSTANDARD VideoStandard, BOOL32 *pIsCapable);

/*** VHD_GetStreamCapSDIVideoStandard ***************************************************/
/*!VHD_GetStreamCapSDIVideoStandard
   Summary
   VideoMaster stream capability video standard
   Description
   This function retrieves the SDI video standard capability of the specified stream
   Parameters
   StreamHandle :       Handle of the stream to get capability from
   VideoStandard :      VideoStandard to query the stream capability for.
   pIsCapable :         Pointer to caller\-allocated boolean variable to return
                        the video standard capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetStreamCapSDIVideoStandard(HANDLE StreamHandle, VHD_VIDEOSTANDARD VideoStandard, BOOL32 *pIsCapable);

/*** VHD_GetStreamCapSDIBufferType ***************************************************/
/*!VHD_GetStreamCapSDIBufferType
Summary
VideoMaster stream capability SDI buffer type
Description
This function retrieves the SDI buffer type capability of the specified stream
Parameters
StreamHandle :       Handle of the stream to get capability from
BufferType :         Buffer type to query the stream capability for.
pIsCapable :         Pointer to caller\-allocated boolean variable to return
                     the buffer type capability value

Returns
The function returns the status of its execution as
VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetStreamCapSDIBufferType(HANDLE StreamHandle, VHD_SDI_BUFFERTYPE BufferType, BOOL32 *pIsCapable);

/*** VHD_GetStreamCapANCSampleType ***************************************************/
/*!VHD_GetStreamCapANCSampleType
   Summary
   VideoMaster stream capability ANC sample type
   Description
   This function retrieves the ANC sample type capability of the specified stream
   Parameters
   StreamHandle :       Handle of the stream to get capability from
   SampleType :         Sample type to query the stream capability for.
   pIsCapable :         Pointer to caller\-allocated boolean variable to return
                        the sample type capability value

   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetStreamCapANCSampleType(HANDLE StreamHandle, VHD_SAMPLETYPE SampleType, BOOL32 *pIsCapable);

/*** VHD_GetBoardCapSDIInterface ***************************************************/
/*!VHD_GetBoardCapSDIInterface
   Summary
   VideoMaster board capability interface
   Description
   This function retrieves the SDI interface capability of the specified board
   Parameters
   BoardHandle :        Handle of the board to get capability from
   StreamType :         StreamType to query the board capability for.
   Interface :          Interface to query the board capability for.
   pIsCapable :         Pointer to caller\-allocated boolean variable to return
                        the interface capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      
   */
VIDEOMASTER_HD_API ULONG VHD_GetBoardCapSDIInterface(HANDLE BoardHandle, VHD_STREAMTYPE StreamType, VHD_INTERFACE Interface, BOOL32 *pIsCapable);

/*** VHD_GetStreamCapSDIInterface ***************************************************/
/*!VHD_GetStreamCapSDIInterface
   Summary
   VideoMaster stream capability interface
   Description
   This function retrieves the SDI interface capability of the specified stream
   Parameters
   StreamHandle :       Handle of the stream to get capability from
   Interface :          Interface to query the stream capability for.
   pIsCapable :         Pointer to caller\-allocated boolean variable to return
                        the interface capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
VIDEOMASTER_HD_API ULONG VHD_GetStreamCapSDIInterface(HANDLE StreamHandle, VHD_INTERFACE Interface, BOOL32 *pIsCapable);
#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_SDI_H_
