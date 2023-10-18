/*! VideomasterHD_Core.h

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


#ifndef _VIDEOMASTERHD_CORE_H_
#define _VIDEOMASTERHD_CORE_H_

#if !defined STATIC_LIB
#  if defined WIN32 || defined __CYGWIN__
#     ifdef BUILDING_API
#        ifdef __GNUC__
#           define VIDEOMASTER_HD_API __attribute__ ((dllexport))
#        else
#           define VIDEOMASTER_HD_API __declspec(dllexport)
#        endif
#     else
#        ifdef __GNUC__
#           define VIDEOMASTER_HD_API __attribute__ ((dllimport))
#        else
#           define VIDEOMASTER_HD_API __declspec(dllimport)
#        endif
#     endif
#  else
#     include <stdint.h>
#     if __GNUC__ >= 4
#        define VIDEOMASTER_HD_API __attribute__ ((visibility ("default")))
#     else
#        define VIDEOMASTER_HD_API
#     endif
#  endif
#else
#  define VIDEOMASTER_HD_API
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef INFINITE
#define INFINITE 0xFFFFFFFF
#endif

#ifndef NULL
#define NULL 0
#endif

typedef signed short int SHORT;
typedef unsigned short int USHORT;
typedef void* HANDLE;
typedef unsigned char BYTE;
typedef unsigned char UBYTE;
typedef void* LPVOID;

#if defined(__linux__)
typedef long long LONGLONG;
typedef int BOOL;
typedef BOOL BOOL32;
typedef unsigned short int WORD;
typedef uint16_t UWORD;
typedef int32_t LONG;
typedef uint32_t ULONG;
typedef unsigned long long ULONGLONG;
#elif defined(__APPLE__)
#include <libkern/OSTypes.h>
typedef SInt64 LONGLONG;
typedef SInt32 BOOL32;
typedef UInt16 WORD;
typedef UInt16 UWORD;
typedef SInt32 LONG;
typedef UInt32 ULONG;
typedef UInt64 ULONGLONG;
#else
typedef __int64 LONGLONG;
typedef int BOOL;
typedef BOOL BOOL32;
typedef unsigned short int WORD;
typedef long LONG;
typedef unsigned long ULONG;
typedef unsigned long long ULONGLONG;
#endif

/*! Callback type for clock reconstruction mechanism */
typedef LONGLONG(*ClockReconstructionCallback_t)();

/*! Callback type for FW Update mecanism */
typedef void(*FwUpdateCallback_t)(ULONG);

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Core
*/
#define ENUMBASE_MASK         0xFF000000
#define ENUMBASE_CORE         0x01000000
#define ENUMBASE_SDI          0x02000000
#define ENUMBASE_KEYER        0x03000000
#define ENUMBASE_ASI          0x04000000
#define ENUMBASE_IP_BRD       0x05000000
#define ENUMBASE_IP_PROC      0x06000000
#define ENUMBASE_S2022_BRD    0x07000000
#define ENUMBASE_S2022_PROC   0x08000000
#define ENUMBASE_IP_STACK     0x09000000
#define ENUMBASE_S2022_STACK  0x0A000000
#define ENUMBASE_ST2110_20    0x0C000000
#define ENUMBASE_ST2110_30    0x0D000000
#define ENUMBASE_DV           0x10000000
#define ENUMBASE_DVI          ENUMBASE_DV /*! Backward compatibility */
#define ENUMBASE_ST2110_BRD   0x20000000
#define ENUMBASE_GATEWAY      0x30000000

#define VHD_CLOCK_RECONSTRUCTION_MAX_NB_HANDLES 8

/*_ VideomasterHD_Core STATUS INFORMATION BIT MASKS ___________________________________*/

   /*! RX channel status bit masks. These constants define status bit masks for the VHD_CORE_BP_RXx_STATUS board properties */
#define VHD_CORE_RXSTS_OVERRUN     0x00000001  /*! RX channel overrun indicator. This bit is set to '1' when the software cannot sustain the incoming data rate */
#define VHD_CORE_RXSTS_UNLOCKED    0x00000002  /*! RX channel unlocked indicator. This bit is set to '1' when the channel cannot lock on incoming signal */

   /*! TX channel status bit masks. These constants define status bit masks for the VHD_CORE_BP_TXx_STATUS board properties */
#define VHD_CORE_TXSTS_UNDERRUN    0x00000001  /*! TX channel underrun indicator. This bit is set to '1' when the software cannot sustain the incoming data rate */


/*_ VideomasterHD_Core EVENT SOURCES __________________________________________________*/

   /*! Event sources bit masks. These constants define event source bit masks for the StateChangeMask parameter of VHD_OpenBoardHandle */
#define VHD_CORE_EVTSRC_RX0        0x00000001  /*! RX0 channel state changes event source */
#define VHD_CORE_EVTSRC_RX1        0x00000002  /*! RX1 channel state changes event source */
#define VHD_CORE_EVTSRC_RX2        0x00000004  /*! RX2 channel state changes event source */
#define VHD_CORE_EVTSRC_RX3        0x00000008  /*! RX3 channel state changes event source */
#define VHD_CORE_EVTSRC_RX4        0x00000010  /*! RX4 channel state changes event source */
#define VHD_CORE_EVTSRC_RX5        0x00000020  /*! RX5 channel state changes event source */
#define VHD_CORE_EVTSRC_RX6        0x00000040  /*! RX6 channel state changes event source */
#define VHD_CORE_EVTSRC_RX7        0x00000080  /*! RX7 channel state changes event source */
#define VHD_CORE_EVTSRC_TX0        0x00000100  /*! TX0 channel state changes event source */
#define VHD_CORE_EVTSRC_TX1        0x00000200  /*! TX1 channel state changes event source */
#define VHD_CORE_EVTSRC_TX2        0x00000400  /*! TX2 channel state changes event source */
#define VHD_CORE_EVTSRC_TX3        0x00000800  /*! TX3 channel state changes event source */
#define VHD_CORE_EVTSRC_WATCHDOG   0x40000000  /*! Watchdog timer expired (by-pass relays loop re-established) */


/*_ VideomasterHD_Core RXmiTXj RX and TX channel mask combination _____________________*/
#define VHD_GET_RX_M_TX_ST(RX_IDX, TX_IDX)  (VHD_ST_RX_MODIFY_TX + (((RX_IDX)&0x1F)<<5) + ((TX_IDX)&0x1F))

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Core
*/

/*_ VHD_CHANNEL_MODE ____________________________________________________*/
/*!
   Summary
   VideoMaster channel mode
   Description
   The VHD_CHANNEL_MODE enumeration lists all the supported
   channel mode type.

   These values are used by the VHD_CORE_BP_RXx_MODE board
   property, it is only available on mixed type channels
   See Also
   VHD_GetBoardProperty, VHD_SetBoardProperty                         */

typedef enum _VHD_CHANNEL_MODE
{
   VHD_CHANNEL_MODE_SDI = 0,                  /*! SDI channel mode */
   VHD_CHANNEL_MODE_ASI,                      /*! ASI channel mode */
   NB_VHD_CHANNEL_MODE
} VHD_CHANNEL_MODE;

/*_ VHD_BOARDTYPE ____________________________________________________*/
/*!
   Summary
   VideoMaster board types
   Description
   The VHD_BOARDTYPE enumeration lists all the supported
   DELTACAST board types.

   These values are used by the VHD_CORE_BP_BOARD_TYPE board
   property
   See Also
   VHD_GetBoardProperty                                      */

typedef enum _VHD_BOARDTYPE
{
   VHD_BOARDTYPE_HD = 0,                  /*! DELTA-hd board */
   VHD_BOARDTYPE_HDKEY_DEPRECATED,        /*!Deprecated enumeration value */
   VHD_BOARDTYPE_SD,                      /*!_VHD_BOARDTYPE::VHD_BOARDTYPE_SD
                                             DELTA-sdi board */
   VHD_BOARDTYPE_SDKEY,                   /*!_VHD_BOARDTYPE::VHD_BOARDTYPE_SDKEY
                                             Future use */
   VHD_BOARDTYPE_DVI_DEPRECATED,          /*! Deprecated enumeration value */
   VHD_BOARDTYPE_MIXEDINTERFACE,          /*! Mixed interfaces board */
   VHD_BOARDTYPE_3G,                      /*! DELTA-3G board */
   VHD_BOARDTYPE_3GKEY,                   /*! DELTA-key 3G board */
   VHD_BOARDTYPE_HDMI,                    /*! DELTA-h4k board */
   VHD_BOARDTYPE_FLEX_DEPRECATED,         /*! Deprecated enumeration value */
   VHD_BOARDTYPE_ASI,                     /*! DELTA-asi board */
   VHD_BOARDTYPE_IP,                      /*! DELTA-ip board */
   VHD_BOARDTYPE_HDMI20,                  /*! DELTA-h4k2 board */
   VHD_BOARDTYPE_FLEX_DP,                 /*! FLEX-dp board*/
   VHD_BOARDTYPE_FLEX_SDI,                /*! FLEX-sdi board*/
   VHD_BOARDTYPE_12G,                     /*! DELTA-12G board */
   VHD_BOARDTYPE_FLEX_HMI,                /*! FLEX-hmi board */
   NB_VHD_BOARDTYPES
} VHD_BOARDTYPE;

#define VHD_BOARDTYPE_CODEC VHD_BOARDTYPE_MIXEDINTERFACE /*! Backward-compatibility */


/*_ VHD_CORE_BOARDPROPERTY _______________________________________________*/
/*!
   Summary
   VideoMaster core board properties
   Description
   The VHD_CORE_BOARDPROPERTY enumeration lists all the
   available board properties common to all supported hardware
   families.

   These values are used as indexes for VHD_GetBoardProperty and
   VHD_SetBoardProperty functions calls.
   See Also
   VHD_GetBoardProperty VHD_SetBoardProperty                     */
typedef enum _VHD_CORE_BOARDPROPERTY
{
   /* Software board handling */
   VHD_CORE_BP_DRIVER_VERSION = ENUMBASE_CORE,        /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_DRIVER_VERSION
                                                         Driver version, as a 32-bit unsigned integer of form
                                                         0xMMmmBBBB                                                  */
   VHD_CORE_BP_REF_COUNT,                             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_REF_COUNT
                                                         Opened board handles counter                                */
   VHD_CORE_BP_SETUP_LOCK,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_SETUP_LOCK
                                                         Board setup lock (default is FALSE)                         */
   VHD_CORE_BP_STATE_CHANGE_EVENT_MASK,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_STATE_CHANGE_EVENT_MASK
                                                         Future use                                                  */

   /* Board information */
   VHD_CORE_BP_BOARD_TYPE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BOARD_TYPE
                                                         Deltacast board family type                                 */
   VHD_CORE_BP_FIRMWARE_FPGA_VERSION,                 /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_FIRMWARE_FPGA_VERSION
                                                         FPGA version, if any                                        */
   VHD_CORE_BP_FIRMWARE2_VERSION_DEPRECATED,          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_FIRMWARE2_VERSION_DEPRECATED
                                                         CPLD version, if any                                        */
   VHD_CORE_BP_FIRMWARE_ARM_MICROCODE_VERSION,        /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_FIRMWARE_ARM_MICROCODE_VERSION
                                                         ARM microcode version, if any                            */
   VHD_CORE_BP_SERIALNUMBER_LSW,                      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_SERIALNUMBER_LSW
                                                         Silicon serial number (32 least significant bits)           */
   VHD_CORE_BP_SERIALNUMBER_MSW,                      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_SERIALNUMBER_MSW
                                                         Silicon serial number (32 most significant bits)            */
   VHD_CORE_BP_SERIALNUMBER_EX,                       /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_SERIALNUMBER_EX
                                                         Silicon serial number extension (DELTA-dvi only)            */
   VHD_CORE_BP_NBOF_LANE,                             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_NBOF_LANE
                                                         Number of negotiated PCI express lanes. This property is only
                                                         available for PCI express cards.                            */
   VHD_CORE_BP_LOWPROFILE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_LOWPROFILE
                                                         TRUE if the board is of low-profile form factor, FALSE if it
                                                         is of full PCI height form factor                           */
   VHD_CORE_BP_NB_RXCHANNELS,                         /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_NB_RXCHANNELS
                                                         Number of physical reception channels */
   VHD_CORE_BP_NB_TXCHANNELS,                         /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_NB_TXCHANNELS
                                                         Number of physical transmission channels */

   /* Board configuration */
   VHD_CORE_BP_BYPASS_RELAY_0,                        /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BYPASS_RELAY_0
                                                         RX0-TX0 by-pass relay control (TRUE = loopthrough enabled,
                                                         FALSE = relay disabled), default is TRUE.                    */
   VHD_CORE_BP_BYPASS_RELAY_1,                        /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BYPASS_RELAY_1
                                                         RX1-TX1 by-pass relay control (TRUE = loopthrough enabled,
                                                         FALSE = relay disabled), default is TRUE.                    */
   VHD_CORE_BP_WATCHDOG_TIMER,                        /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_WATCHDOG_TIMER
                                                         By-pass relays watchdog timer value (in msec, max 30000
                                                         msec). Watchdog re-establish by-pass relays loop-through if
                                                         not re-armed using VHD_RearmWatchdog every period configured
                                                         by this value. Set value to 0 to disable watchdog (default)  */

   /* Channel status */
   VHD_CORE_BP_CHN_AVAILABILITY,          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_CHN_AVAILABILITY
                                             Physical channel availability mask (bit0 = RX0, bit1 = RX1, bit2 = RX2, bit3 = RX3,
                                                                                 bit4 = TX0, bit5 = TX1, bit6 = TX2, bit7 = TX3,
                                                                                 bit8 = RX4, bit9 = RX5, bit10 = RX6, bit11 = RX7,
                                                                                 bit12 = TX4, bit13 = TX5, bit14 = TX6, bit15 = TX7,
                                                                                 bit16 = RX8, bit17 = RX9, bit18 = RX10, bit19 = RX11,
                                                                                 bit20 = TX8, bit21 = TX9, bit22 = TX10, bit23 = TX11).
                                             A channel is available if the corresponding mask bit is set to 1 */
   VHD_CORE_BP_RX0_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX0_STATUS
                                             RX0 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX1_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX1_STATUS
                                             RX1 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX2_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX2_STATUS
                                             RX2 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX3_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX3_STATUS
                                             RX3 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_TX0_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX0_STATUS
                                             TX0 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX1_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX1_STATUS
                                             TX1 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX2_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX2_STATUS
                                             TX2 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX3_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX3_STATUS
                                             TX3 channel status (see VHD_xx_TXSTS_xxx) */

   /* Channel type */
   VHD_CORE_BP_RX0_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX0_TYPE
                                                         RX0 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX1_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX1_TYPE
                                                         RX1 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX2_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX2_TYPE
                                                         RX2 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX3_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX3_TYPE
                                                         RX3 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX0_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX0_TYPE
                                                         TX0 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX1_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX1_TYPE
                                                         TX1 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX2_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX2_TYPE
                                                         TX2 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX3_TYPE,                              /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX3_TYPE
                                                         TX3 channel type (see VHD_CHANNELTYPE) */

   /* Preallocation size */
   VHD_CORE_BP_PREALLOCPOOL0SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL0SIZE
                                          Preallocated memory Pool 0 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL1SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL1SIZE
                                          Preallocated memory Pool 1 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL2SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL2SIZE
                                          Preallocated memory Pool 2 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL3SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL3SIZE
                                          Preallocated memory Pool 3 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_RX4_STATUS,             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX4_STATUS
                                          RX0 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX5_STATUS,             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX5_STATUS
                                          RX1 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX6_STATUS,             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX6_STATUS
                                          RX2 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX7_STATUS,             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX7_STATUS
                                          RX3 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX4_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX4_TYPE
                                          RX0 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX5_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX5_TYPE
                                          RX1 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX6_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX6_TYPE
                                          RX2 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX7_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX7_TYPE
                                          RX3 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_BUS_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BUS_TYPE
                                          Bus type (see VHD_BUSTYPE)*/
   VHD_CORE_BP_TEMPERATURE,            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TEMPERATURE
                                          Current FPGA temperature in Celcius degrees */
   VHD_CORE_BP_BYPASS_RELAY_2,         /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BYPASS_RELAY_2
                                          RX2-TX2 by-pass relay control (TRUE = loopthrough enabled,
                                          FALSE = relay disabled), default is TRUE.                    */
   VHD_CORE_BP_BYPASS_RELAY_3,         /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BYPASS_RELAY_3
                                          RX3-TX3 by-pass relay control (TRUE = loopthrough enabled,
                                          FALSE = relay disabled), default is TRUE.                    */
   VHD_CORE_BP_TX4_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX4_STATUS
                                             TX4 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX5_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX5_STATUS
                                             TX5 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX6_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX6_STATUS
                                             TX6 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX7_STATUS,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX7_STATUS
                                             TX7 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX4_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX4_TYPE
                                          TX4 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX5_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX5_TYPE
                                          TX5 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX6_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX6_TYPE
                                          TX6 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX7_TYPE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX7_TYPE
                                          TX7 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_IS_BIDIR,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_IS_BIDIR
                                          TRUE if the card is bidirectionnel */
   VHD_CORE_BP_FIRMWARE_SCP_MICROCODE_VERSION,     /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_FIRMWARE_SCP_MICROCODE_VERSION
                                                      SCP microcode version, if any                            */

                                          /* Preallocation size */
   VHD_CORE_BP_PREALLOCPOOL4SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL4SIZE
                                          Preallocated memory Pool 4 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL5SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL5SIZE
                                          Preallocated memory Pool 5 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL6SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL6SIZE
                                          Preallocated memory Pool 6 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL7SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 7 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL8SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 8 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL9SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 9 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL10SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 10 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL11SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 11 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL12SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 12 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL13SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 13 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL14SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 14 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL15SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 15 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PREALLOCPOOL16SIZE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PREALLOCPOOL7SIZE
                                          Preallocated memory Pool 16 size, in bytes, or zero if the
                                          preallocated memory pool does not exist                   */
   VHD_CORE_BP_PRODUCT_VERSION,         /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_PRODUCT_VERSION
                                          Product version, as a 32-bit unsigned integer of form
                                          0x0000MMmm    */

   VHD_CORE_BP_SYSTEM_TIME_CLK_TYPE,    /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_SYSTEM_TIME_CLK_TYPE
                                          Contains the system time type used by VHD_GetSlotSystemTime*/
   VHD_CORE_BP_BOARDADDRESS,            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_BOARDADDRESS
                                          Board address as 5-bit unsigned byte */
   VHD_CORE_BP_WATCHDOGTYPE,            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_WATCHDOGTYPE
                                          Watchdog type (see VHD_WATCHDOG_TYPE enum, default is VHD_WATCHDOG_TYPE_RXTX_PASSTHROUGH)*/
   /* Channel mode */
   VHD_CORE_BP_RX0_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX0_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX1_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX1_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX2_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX2_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX3_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX3_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX4_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX4_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX5_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX5_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX6_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX6_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/
   VHD_CORE_BP_RX7_MODE,                /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX7_MODE                                   
                                          setup the channel mode on mixed type channels (see VHD_CHANNEL_MODE), default is SDI mode*/

   VHD_CORE_BP_REQUESTED_FIRMWARE_FPGA_VERSION,                   /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_REQUESTED_FIRMWARE_FPGA_VERSION
                                                                     FPGA firmware version requested, if any                       */ 

   VHD_CORE_BP_REQUESTED_FIRMWARE_ARM_MICROCODE_VERSION,          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_REQUESTED_FIRMWARE_ARM_MICROCODE_VERSION
                                                                     ARM microcode firmware version requested, if any              */

   VHD_CORE_BP_REQUESTED_FIRMWARE_SCP_MICROCODE_VERSION,          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_REQUESTED_FIRMWARE_SCP_MICROCODE_VERSION
                                                                     SCP microcode firmware version requested, if any              */

   VHD_CORE_BP_RX8_TYPE,                             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX8_TYPE
                                                       RX8 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX9_TYPE,                             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX9_TYPE
                                                       RX9 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX10_TYPE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX10_TYPE
                                                       RX10 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX11_TYPE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX11_TYPE
                                                       RX11 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_RX8_STATUS,                           /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX8_STATUS
                                                       RX8 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX9_STATUS,                           /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX9_STATUS
                                                       RX9 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX10_STATUS,                          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX10_STATUS
                                                       RX10 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_RX11_STATUS,                          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_RX11_STATUS
                                                       RX11 channel status (see VHD_xx_RXSTS_xxx) */
   VHD_CORE_BP_TX8_TYPE,                             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX8_TYPE
                                                       TX8 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX9_TYPE,                             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX9_TYPE
                                                       TX9 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX10_TYPE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX10_TYPE
                                                       TX10 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX11_TYPE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX11_TYPE
                                                       TX11 channel type (see VHD_CHANNELTYPE) */
   VHD_CORE_BP_TX8_STATUS,                           /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX8_STATUS
                                                       TX8 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX9_STATUS,                           /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX9_STATUS
                                                       TX9 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX10_STATUS,                          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX10_STATUS
                                                       TX10 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_TX11_STATUS,                          /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_TX11_STATUS
                                                       TX11 channel status (see VHD_xx_TXSTS_xxx) */
   VHD_CORE_BP_FPGA_RESTART_NEEDED_AFTER_UPDATE,     /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_FPGA_RESTART_NEEDED_AFTER_UPDATE
                                                       FPGA restart needed */
   VHD_CORE_BP_ARM_RESTART_NEEDED_AFTER_UPDATE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_ARM_RESTART_NEEDED_AFTER_UPDATE
                                                       ARM restart needed */
   VHD_CORE_BP_SCP_RESTART_NEEDED_AFTER_UPDATE,      /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_SCP_RESTART_NEEDED_AFTER_UPDATE
                                                       SCP restart needed */
   VHD_CORE_BP_NUMA_NODE,                            /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_NUMA_NODE
                                                       Get NUMA node */
   VHD_CORE_BP_LOWLATENCY_ANC_BLOCK_SIZE,             /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_LOWLATENCY_ANC_BLOCK_SIZE
                                                         Specifies the number of ANC lines that should be grouped in blocks (RX only) */
   VHD_CORE_BP_MRRS,                                  /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_BP_MRRS
                                                         Setup the MRRS to 512B or 256B */
   NB_VHD_CORE_BOARDPROPERTIES
} VHD_CORE_BOARDPROPERTY;

#define VHD_CORE_BP_FIRMWARE_VERSION VHD_CORE_BP_FIRMWARE_FPGA_VERSION
#define VHD_CORE_BP_FIRMWARE3_VERSION VHD_CORE_BP_FIRMWARE_ARM_MICROCODE_VERSION
#define VHD_CORE_BP_FIRMWARE4_VERSION VHD_CORE_BP_FIRMWARE_SCP_MICROCODE_VERSION

#define VHD_CORE_BP_REQUESTED_FIRMWARE_VERSION VHD_CORE_BP_REQUESTED_FIRMWARE_FPGA_VERSION
#define VHD_CORE_BP_REQUESTED_FIRMWARE3_VERSION VHD_CORE_BP_REQUESTED_FIRMWARE_ARM_MICROCODE_VERSION


/*_ VHD_CORE_STREAMPROPERTY ______________________________________________*/
/*!
   Summary
   VideoMaster core streams properties
   Description
   The VHD_CORE_STREAMPROPERTY enumeration lists all the
   available stream properties common to all supported hardware
   families.

   These values are used as indexes for VHD_GetStreamProperty
   and VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                  */
typedef enum _VHD_CORE_STREAMPROPERTY
{
   VHD_CORE_SP_REF_COUNT=ENUMBASE_CORE,   /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_REF_COUNT
                                             Opened stream handles counter                                        */
   VHD_CORE_SP_FORCE_EXCLUSIVE,           /*! _VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_FORCE_EXCLUSIVE
                                             Force exclusive access to this stream : no other handle may
                                             be created on the same stream type on this board (default is FALSE)  */
   VHD_CORE_SP_TRANSFER_SCHEME,           /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_TRANSFER_SCHEME
                                             Stream transfers handling scheme (see VHD_TRANSFERSCHEME).
                                             Affect reception stream only (default is VHD_TRANSFER_UNCONSTRAINED )        */
   VHD_CORE_SP_IO_TIMEOUT,                /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_IO_TIMEOUT
                                             Slot locking time-out value, in milliseconds (default is 100
                                             msec)                                                                */
   VHD_CORE_SP_TX_OUTPUT,                  /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_TX_OUTPUT
                                             Transmission stream output control (see VHD_OUTPUTMODE)
                                             , default is VHD_OUTPUT_STREAM                                       */
   VHD_CORE_SP_SLOTS_COUNT,               /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_SLOTS_COUNT
                                             Counts the number of slots transferred since the stream has
                                             been started                                                         */
   VHD_CORE_SP_SLOTS_DROPPED,             /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_SLOTS_DROPPED
                                             Counts the number of dropped slots since the stream has been
                                             started                                                              */
   VHD_CORE_SP_BUFFERQUEUE_DEPTH,         /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_BUFFERQUEUE_DEPTH
                                             Stream driver buffers queue depth, in number of slots
                                             (minimum is 2, maximum is 32, default is 4)                          */
   VHD_CORE_SP_BUFFERQUEUE_FILLING,       /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_BUFFERQUEUE_FILLING
                                             Current filling level of stream driver buffer queue, in
                                             number of slots                                                      */
   VHD_CORE_SP_BUFFERQUEUE_PRELOAD,       /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_BUFFERQUEUE_PRELOAD
                                             Number of TX buffer to preload before actual channel start.
                                             May be zero (default) to disable TX preload, or must be
                                             comprised between 1 and VHD_CORE_SP_BUFFERQUEUE_DEPTH + 1            */
   VHD_CORE_SP_BUFFER_PACKING,            /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_BUFFER_PACKING
                                             Stream buffers data packing (see VHD_BUFFERPACKING)
                                             , default is VHD_BUFPACK_VIDEO_YUV422_8                              */
   VHD_CORE_SP_DELAY,                     /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_DELAY
                                             Number of frames to be delayed (hardware delay line,
                                             DELTA-key only), minimum is 1, maximum is 7, default is 1            */
   VHD_CORE_SP_MUTED_DATA_MASK,           /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_MUTED_DATA_MASK
                                             On a RX stream, this property defines the data that shouldn't be
                                             temporarily captured.                                                */
   VHD_CORE_SP_FIELD_MODE,                /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_FIELD_MODE
                                             Switch between frame and field mode for interlaced format
                                             , default is FALSE (frame mode)                                      */
   VHD_CORE_SP_FIELD_MERGE,               /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_FIELD_MERGE
                                             Activate field merging for interlaced stream (default is FALSE)      */
   VHD_CORE_SP_LINE_PADDING,              /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_LINE_PADDING
                                             Activate 64 or 128 bytes line padding (default is 0)                 */
   VHD_CORE_SP_FRAME_DECIMATION_NUM,      /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_FRAME_DECIMATION_NUM
                                             On a RX stream, this property defines numerator of framerate decimation.
                                             May be 1 (default) to disable frame decimation, or must be
                                             comprised between 1 and 255. Must be smaller than
                                             VHD_CORE_SP_FRAME_DECIMATION_DEN.                                    */
   VHD_CORE_SP_FRAME_DECIMATION_DEN,      /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_FRAME_DECIMATION_DEN
                                             On a RX stream, this property defines denominator of framerate decimation.
                                             Must be comprised between 1 and 255. Must be bigger than
                                             VHD_CORE_SP_FRAME_DECIMATION_NUM.                                    */
   VHD_CORE_SP_LOWLATENCY_MODE,           /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_LOWLATENCY_MODE
                                             Low latency mode. Default is VHD_LLM_DISABLED
                                             (See VHD_LOW_LATENCY_MODE enum).                                     */
   VHD_CORE_SP_ONBOARDBUFFER_DEPTH,       /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_ONBOARDBUFFER_DEPTH
                                             On a TX stream, max number of buffers on board.
                                             It is a read-only property                                           */
   VHD_CORE_SP_ONBOARDBUFFER_FILLING,     /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_ONBOARDBUFFER_FILLING
                                             On a TX stream, current number of buffers on board.
                                             The number of buffers only concerns that stream.
                                             It is a read-only property                                           */
   VHD_CORE_SP_FRAME_ACCURACY_TYPE,       /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_FRAME_ACCURACY_TYPE
                                             On a TX stream, specifies/tells the current frame accuracy type in used
                                             (see VHD_FRAME_ACCURACY_TYPE enum and VHD_SetStartTime).      */
   VHD_CORE_SP_DISCARD_BUFFER_ON_UNDERRUN,/*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_DISCARD_BUFFER_ON_UNDERRUN
                                             On a TX stream, enables unlock calls following an underrun to discard
                                             as many buffers as there were underrun. Specifically useful for streams
                                             synchronized with VHD_CORE_SP_FRAME_ACCURACY_TYPE set to
                                             VHD_FRAME_ACCURACY_TYPE_FLEX  and VHD_GatewaySync. */
   VHD_CORE_SP_THUMBNAIL_RATIO,           /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_THUMBNAIL_RATIO
                                             On a RX stream (see processing mode with thumbnails data handling),
                                             enables to get/set the thumbnails ratio applied to the stream
                                             (See VHD_THUMBNAIL_RATIO enum, default value is VHD_THUMBNAIL_RATIO_1_OVER_4).
                                             Setting a value is only possible if the board supports configurable thumbnails
                                             (see VHD_CORE_BOARD_CAP_CONFIGURABLE_THUMBNAILS ) */
   VHD_CORE_SP_PLANAR_WITH_SEPARATE_BUFFERS, /*!_VHD_CORE_STREAMPROPERTY::VHD_CORE_SP_PLANAR_WITH_SEPARATE_BUFFERS
                                                Activate the use of separate buffer/pointer per plan for planar buffer packing (default is FALSE).
                                                By default, all the plans are packed in one buffer/pointer. */

   NB_VHD_CORE_STREAMPROPERTIES
} VHD_CORE_STREAMPROPERTY;

/*_ VHD_STREAMTYPE ___________________________________________________*/
/*!
   Summary
   VideoMaster stream types
   Description
   The VHD_STREAMTYPE enumeration lists all the stream types.

   These values are used during VHD_OpenStreamHandle function
   calls.
   See Also
   VHD_OpenStreamHandle                                       */

typedef enum _VHD_STREAMTYPE
{
   VHD_ST_RX0=0,                        /*!_VHD_STREAMTYPE::VHD_ST_RX0
                                           Reception stream on RX0 physical channel */
   VHD_ST_RX1=1,                        /*!_VHD_STREAMTYPE::VHD_ST_RX1
                                           Reception stream on RX1 physical channel */
   VHD_ST_RX2=9,                        /*!_VHD_STREAMTYPE::VHD_ST_RX2
                                           Reception stream on RX2 physical channel */
   VHD_ST_RX3=10,                       /*!_VHD_STREAMTYPE::VHD_ST_RX3
                                           Reception stream on RX3 physical channel */
   VHD_ST_TX0=2,                        /*!_VHD_STREAMTYPE::VHD_ST_TX0
                                           Transmission stream on TX0 physical channel, or TX0 PC stream
                                           feeding hardware keyer */
   VHD_ST_TX1=3,                        /*!_VHD_STREAMTYPE::VHD_ST_TX1
                                           Transmission stream on TX1 physical channel, or TX1 PC stream
                                           feeding hardware keyer                                        */
   VHD_ST_TX2=11,                       /*!_VHD_STREAMTYPE::VHD_ST_TX2
                                           Transmission stream on TX2 physical channel */
   VHD_ST_TX3=12,                       /*!_VHD_STREAMTYPE::VHD_ST_TX3
                                       Transmission stream on TX3 physical channel */
   VHD_ST_RX0_MODIFY_TX0_DEPRECATED=6,  /*!_VHD_STREAMTYPE::VHD_ST_RX0_MODIFY_TX0_DEPRECATED
                                       RX-modify-TX stream coupling RX0 to TX0 physical channels */
   VHD_ST_RX1_MODIFY_TX1_DEPRECATED=7,  /*!_VHD_STREAMTYPE::VHD_ST_RX1_MODIFY_TX1_DEPRECATED
                                       RX-modify-TX stream coupling RX1 to TX1 physical channels */

   VHD_ST_RX0_HW_PROCESS =13,           /*!_VHD_STREAMTYPE::VHD_ST_RX0_HW_PROCESS
                                           Process on RX0, ex: Delay Line */
   VHD_ST_RX1_HW_PROCESS =14,           /*!_VHD_STREAMTYPE::VHD_ST_RX1_HW_PROCESS
                                              Process on RX1, ex: Delay Line */
   VHD_ST_COUPLED_RX01=15,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX01
                                           Coupled reception on RX0 and RX1 physical channel */
   VHD_ST_COUPLED_RX23=16,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX23
                                           Coupled reception on RX2 and RX3 physical channel */
   VHD_ST_COUPLED_TX01=17,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX01
                                           Coupled transmission on TX0 and TX1 physical channel */
   VHD_ST_COUPLED_TX23=18,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX23
                                           Coupled transmission on TX2 and TX3 physical channel */
   VHD_ST_COUPLED_TX02=19,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX02
                                           Coupled transmission on TX0 and TX2 physical channel */
   VHD_ST_RX4=20,                       /*!_VHD_STREAMTYPE::VHD_ST_RX4
                                           Reception stream on RX4 physical channel */
   VHD_ST_RX5=21,                       /*!_VHD_STREAMTYPE::VHD_ST_RX5
                                           Reception stream on RX5 physical channel */
   VHD_ST_RX6=22,                       /*!_VHD_STREAMTYPE::VHD_ST_RX6
                                           Reception stream on RX6 physical channel */
   VHD_ST_RX7=23,                       /*!_VHD_STREAMTYPE::VHD_ST_RX7
                                           Reception stream on RX7 physical channel */
   VHD_ST_COUPLED_RX45=24,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX45
                                           Coupled reception on RX4 and RX5 physical channel */
   VHD_ST_COUPLED_RX67=25,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX67
                                           Coupled reception on RX6 and RX7 physical channel */
   VHD_ST_COUPLED_RX0123=26,            /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX0123
                                           Coupled reception on RX0, RX1, RX2 and RX3 physical channel */
   VHD_ST_COUPLED_TX0123=27,            /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX0123
                                           Coupled reception on TX0, TX1, TX2 and TX3 physical channel */
   VHD_ST_COUPLED_RX4567=28,            /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX4567
                                           Coupled reception on RX4, RX5, RX6 and RX7 physical channel */
   VHD_ST_RX2_MODIFY_TX2_DEPRECATED=29, /*!_VHD_STREAMTYPE::VHD_ST_RX2_MODIFY_TX2_DEPRECATED
                                           RX-modify-TX stream coupling RX2 to TX2 physical channels */
   VHD_ST_RX3_MODIFY_TX3_DEPRECATED=30, /*!_VHD_STREAMTYPE::VHD_ST_RX3_MODIFY_TX3_DEPRECATED
                                           RX-modify-TX stream coupling RX3 to TX3 physical channels */
   VHD_ST_COUPLED_RX02=31,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX02
                                           Coupled reception on RX0 and RX2 physical channel */
   VHD_ST_COUPLED_RX46=32,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX46
                                           Coupled reception on RX4 and RX6 physical channel */
   VHD_ST_TX4=33,                       /*!_VHD_STREAMTYPE::VHD_ST_TX4
                                           Transmission stream on TX4 physical channel */
   VHD_ST_TX5=34,                       /*!_VHD_STREAMTYPE::VHD_ST_TX5
                                           Transmission stream on TX5 physical channel */
   VHD_ST_TX6=35,                       /*!_VHD_STREAMTYPE::VHD_ST_TX6
                                           Transmission stream on TX6 physical channel */
   VHD_ST_TX7=36,                       /*!_VHD_STREAMTYPE::VHD_ST_TX7
                                           Transmission stream on TX7 physical channel */
   VHD_ST_COUPLED_TX4567=37,            /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX4567
                                           Coupled reception on TX4, TX5, TX6 and TX7 physical channel */
   VHD_ST_COUPLED_TX45=38,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX45
                                           Coupled reception on TX4 and TX5 physical channel */
   VHD_ST_COUPLED_TX67=39,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX67
                                           Coupled reception on TX6 and TX7 physical channel */
   VHD_ST_RX2_HW_PROCESS = 40,          /*!_VHD_STREAMTYPE::VHD_ST_RX2_HW_PROCESS
                                           Process on RX2, ex: Delay Line */
   VHD_ST_RX3_HW_PROCESS = 41,          /*!_VHD_STREAMTYPE::VHD_ST_RX3_HW_PROCESS
                                           Process on RX3, ex: Delay Line */
   VHD_ST_COUPLED_RX0246 = 42,          /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX0246
                                           Coupled reception on RX0, RX2, RX4 and RX6 physical channel */
   VHD_ST_COUPLED_TX0246 = 43,          /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX0246
                                           Coupled transmission on TX0, TX2, TX4 and TX6 physical channel */
   VHD_ST_RX8=44,                       /*!_VHD_STREAMTYPE::VHD_ST_RX8
                                           Transmission stream on RX8 physical channel */
   VHD_ST_RX9=45,                       /*!_VHD_STREAMTYPE::VHD_ST_RX9
                                           Transmission stream on RX9 physical channel */
   VHD_ST_RX10=46,                      /*!_VHD_STREAMTYPE::VHD_ST_RX10
                                           Transmission stream on RX10 physical channel */
   VHD_ST_RX11=47,                      /*!_VHD_STREAMTYPE::VHD_ST_RX11
                                           Transmission stream on RX11 physical channel */
   VHD_ST_TX8=48,                       /*!_VHD_STREAMTYPE::VHD_ST_TX8
                                           Transmission stream on TX8 physical channel */
   VHD_ST_TX9=49,                       /*!_VHD_STREAMTYPE::VHD_ST_TX9
                                           Transmission stream on TX9 physical channel */
   VHD_ST_TX10=50,                      /*!_VHD_STREAMTYPE::VHD_ST_TX10
                                           Transmission stream on TX10 physical channel */
   VHD_ST_TX11=51,                      /*!_VHD_STREAMTYPE::VHD_ST_TX11
                                           Transmission stream on TX11 physical channel */
   VHD_ST_COUPLED_RX89=52,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX89
                                           Coupled reception on RX8 and RX9 physical channel */
   VHD_ST_COUPLED_RX1011=53,            /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX1011
                                           Coupled reception on RX10 and RX11 physical channel */
   VHD_ST_COUPLED_TX89=54,              /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX89
                                           Coupled reception on TX8 and TX9 physical channel */ 
   VHD_ST_COUPLED_TX1011=55,            /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX1011
                                           Coupled reception on TX10 and TX11 physical channel */
   VHD_ST_COUPLED_RX891011=56,          /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX891011
                                           Coupled reception on RX8, RX9, RX10 and RX11 physical channel */
   VHD_ST_COUPLED_TX891011=57,          /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX891011
                                           Coupled reception on TX8, TX9, TX10 and TX11 physical channel */
   VHD_ST_COUPLED_RX810=58,             /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_RX810
                                           Coupled reception on RX8 and RX10 physical channel */
   VHD_ST_COUPLED_TX810=59,             /*!_VHD_STREAMTYPE::VHD_ST_COUPLED_TX810
                                           Coupled reception on TX8 and TX10 physical channel */
   VHD_ST_RX_MODIFY_TX = 0x00000400,    /*!_VHD_STREAMTYPE::VHD_ST_RX_MODIFY_TX
                                           RXmiTXj stream coupling RXi to TXj physical channels */ 

   NB_VHD_STREAMTYPES = 0x00000800
} VHD_STREAMTYPE;

/* Compatibility define to match with old name */
#define VHD_ST_COUPLED_RX0RX1    VHD_ST_COUPLED_RX01
#define VHD_ST_COUPLED_RX2RX3    VHD_ST_COUPLED_RX23
#define VHD_ST_COUPLED_TX0TX1    VHD_ST_COUPLED_TX01
#define VHD_ST_COUPLED_TX2TX3    VHD_ST_COUPLED_TX23
#define VHD_ST_COUPLED_TX0TX2    VHD_ST_COUPLED_TX02
#define VHD_ST_COUPLED_RX4RX5    VHD_ST_COUPLED_RX45
#define VHD_ST_COUPLED_RX6RX7    VHD_ST_COUPLED_RX67

#define VHD_ST_RX0_HW_PROCESS_TX0  VHD_ST_RX0_HW_PROCESS
#define VHD_ST_RX1_HW_PROCESS_TX1  VHD_ST_RX1_HW_PROCESS


/*_ VHD_CHANNELTYPE _______________________________________________*/
/*!
   Summary
   Physical channel type
   Description
   The VHD_CHANNELTYPE enumeration lists all the available
   channel type

   These values are used in VHD_CORE_BP_RXx_TYPE and
   VHD_CORE_BP_TXx_TYPE board properties.
   See Also
   <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_xxx_TYPE>     */

typedef enum _VHD_CHANNELTYPE
{
   VHD_CHNTYPE_DISABLE = 0,            /*!_VHD_CHANNELTYPE::VHD_CHNTYPE_DISABLE
                                          Channel not present in the board layout, corresponding
                                          functionalities are disabled                           */
   VHD_CHNTYPE_SDSDI,                  /*! SD-SDI channel */
   VHD_CHNTYPE_HDSDI,                  /*! HD-SDI channel */
   VHD_CHNTYPE_3GSDI,                  /*! 3G-SDI channel */
   VHD_CHNTYPE_DVI,                    /*! DVI channel */
   VHD_CHNTYPE_ASI,                    /*! ASI channel */
   VHD_CHNTYPE_HDMI,                   /*! HDMI channel */
   VHD_CHNTYPE_DISPLAYPORT,            /*! Display port channel */
   VHD_CHNTYPE_12GSDI,                 /*! 12G-SDI channel */
   VHD_CHNTYPE_IP_2110,                /*! IP 2110 channel */
   VHD_CHNTYPE_3GSDI_ASI,              /*! 3G-SDI/ASI channel */
   VHD_CHNTYPE_12GSDI_ASI,              /*! 12G-SDI/ASI channel */
   NB_VHD_CHANNELTYPE
} VHD_CHANNELTYPE;


/*_ VHD_BUSTYPE _______________________________________________*/
/*!
   Summary
   Bus type
   Description
   The VHD_BUSTYPE enumeration lists all the available
   bus type

   See Also
   <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_BUS_TYPE>     */

typedef enum _VHD_BUSTYPE
{
   VHD_BUSTYPE_PCI = 0,               /*! PCI bus */
   VHD_BUSTYPE_PCIe,                  /*! PCIe bus */
   VHD_BUSTYPE_PCIe_gen2,             /*! PCIe gen2 bus */
   VHD_BUSTYPE_PCIe_gen3,             /*! PCIe gen3 bus */
   NB_VHD_BUSTYPE
} VHD_BUSTYPE;

/*_ VHD_TRANSFERSCHEME _______________________________________________*/
/*!
   Summary
   VideoMaster streams data transfers schemes
   Description
   The VHD_TRANSFERSCHEME enumeration lists all the available
   stream transfer schemes

   These values are used in VHD_CORE_SP_TRANSFER_SCHEME stream
   property.
   See Also
   <link VHD_CORE_STREAMPROPERTY, VHD_CORE_SP_TRANSFER_SCHEME> */

typedef enum _VHD_TRANSFERSCHEME
{
   VHD_TRANSFER_UNCONSTRAINED = 0,        /*!_VHD_TRANSFERSCHEME::VHD_TRANSFER_UNCONSTRAINED
                                             Unconstrained data transfers (default). Reception stream
                                             always provides last captured slot. No effect in transmission */
   VHD_TRANSFER_SLAVED,                   /*!_VHD_TRANSFERSCHEME::VHD_TRANSFER_SLAVED
                                             Slaved data transfers. Reception stream always provides
                                             oldest captured slot. No effect in transmission         */
   VHD_TRANSFER_FRAMEACCURATE_DEPRECATED, /*!_VHD_TRANSFERSCHEME::VHD_TRANSFER_FRAMEACCURATE_DEPRECATED
                                             Deprecated */
   NB_VHD_TRANSFERSCHEMES
} VHD_TRANSFERSCHEME;

/*_ VHD_BUFFERPACKING __________________________________________*/
/*!
Summary
VideoMaster streams buffer packing schemes
Description
The VHD_BUFFERPACKING enumeration lists all the available
buffer packing schemes

These values are used in VHD_CORE_SP_BUFFER_PACKING stream
property.
See Also
<link VHD_CORE_STREAMPROPERTY, VHD_CORE_SP_BUFFER_PACKING>
*/

typedef enum _VHD_BUFFERPACKING
{
   VHD_BUFPACK_VIDEO_YUV422_8 = 0,              /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV422_8
                                                   4:2:2 8-bit YUV video packing (default, detailed <link YUV422_8 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_YUVK4224_8,                /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUVK4224_8
                                                   4:2:2:4 8-bit YUVK video packing (detailed <link YUVK4224_8 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_YUV422_10,                 /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV422_10
                                                   4:2:2 10-bit YUV video packing (detailed <link YUV422_10 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_YUVK4224_10,               /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUVK4224_10
                                                   4:2:2:4 10-bit YUVK video packing (detailed <link YUVK4224_10 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_YUV4444_8,                 /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV4444_8
                                                   4:4:4:4 8-bit YUV video packing (K forced to blank, detailed <link YUV4444_8/ YUVK4444_8 Video Packings, here>) */
   VHD_BUFPACK_VIDEO_YUVK4444_8,                /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUVK4444_8
                                                   4:4:4:4 8-bit YUVK video packing (detailed <link YUV4444_8/ YUVK4444_8 Video Packings, here>) */
   VHD_BUFPACK_VIDEO_YUV444_10,                 /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV444_10
                                                   4:4:4 10-bit YUV video packing (detailed <link YUV444_10 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_YUVK4444_10,               /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUVK4444_10
                                                   4:4:4:4 10-bit YUVK video packing (detailed <link YUVK4444_10 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_RGB_32,                    /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_RGB_32
                                                   4:4:4 8-bit RGB video packing (detailed <link RGB_32 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_RGBA_32,                   /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_RGBA_32
                                                   4:4:4:4 8-bit RGBA video packing (detailed <link RGBA_32 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_RGB_24,                    /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_RGB_24
                                                   4:4:4 8-bit RGB video packing (24 bits) (detailed <link RGB_24 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YVU420_8,	         /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YVU420_8
                                                   4:2:0 8-bit YUV planar video packing (YV12)(detailed <link YV12 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YUV420_8,	         /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YUV420_8
                                                   4:2:0 8-bit YUV planar video packing (I420)(detailed <link I420 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YVU420_10_MSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YVU420_10_MSB_PAD
                                                   4:2:0 10-bit MSB PAD YVU planar video packing (detailed <link YVU420_10_MSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YVU420_10_LSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YVU420_10_LSB_PAD
                                                   4:2:0 10-bit LSB PAD YVU planar video packing (detailed <link YVU420_10_LSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YUV420_10_MSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YUV420_10_MSB_PAD
                                                   4:2:0 10-bit MSB PAD YUV planar video packing (detailed <link YUV420_10_MSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YUV420_10_LSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YUV420_10_LSB_PAD
                                                   4:2:0 10-bit LSB PAD YUV planar video packing (detailed <link YUV420_10_LSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_RGB_64,                    /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_RGB_64
                                                   4:4:4:4 16-bit RGB video packing (detailed <link RGB_64 Video Packing, here>)  */
   VHD_BUFPACK_VIDEO_YUV422_16,                 /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV422_16
                                                   4:2:2 16-bit YUV video packing (detailed <link YUV422_16 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_YUV444_8,                  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV444_8
                                                   4:4:4 8-bit YUV video packing (detailed <link YUV444_8 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_ICTCP_422_8,              /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_ICTCP_422_8
                                                   4:2:2 8-bit ICtCp video packing (detailed <link ICTCP422_8 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_ICTCP_422_10,             /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_ICTCP_422_10
                                                   4:2:2 10-bit ICtCp video packing (detailed <link ICTCP422_10 Video Packing, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YUV422_10_LSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YUV422_10_LSB_PAD
                                                4:2:2 10-bit LSB PAD YUV planar video packing (detailed <link YUV422_10_LSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YUV422_10_MSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YUV422_10_MSB_PAD
                                                4:2:2 10-bit MSB PAD YUV planar video packing (detailed <link YUV422_10_MSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YVU422_10_LSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YVU422_10_LSB_PAD
                                                4:2:2 10-bit LSB PAD YVU planar video packing (detailed <link YVU422_10_LSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YVU422_10_MSB_PAD,  /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YVU422_10_MSB_PAD
                                                4:2:2 10-bit MSB PAD YVU planar video packing (detailed <link YVU422_10_MSB_PAD, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YUV422_8,	         /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YUV422_8
                                                4:2:2 8-bit YUV planar video packing (detailed <link PLANAR_YUV422_8, here>) */
   VHD_BUFPACK_VIDEO_PLANAR_YVU422_8,	         /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_PLANAR_YVU422_8
                                                4:2:2 8-bit YVU planar video packing (detailed <link PLANAR_YVU422_8, here>) */
   VHD_BUFPACK_VIDEO_YUV422_10_NOPAD_BIGEND,    /*!_VHD_BUFFERPACKING::VHD_BUFPACK_VIDEO_YUV422_10_NOPAD_BIGEND
                                                4:2:2 10-bit NOPAD BIGEND YUV video packing (detailed <link YUV422_10_NOPAD_BIGEND Video Packing, here>) */
   NB_VHD_BUFPACKINGS
} VHD_BUFFERPACKING;

#define VHD_VIDEOPACK_V208               VHD_BUFPACK_VIDEO_YUV422_8              /*!VHD_VIDEOPACK_V208
                                                                                    Old V208 Video Packing is called now YUV422_8. */
#define VHD_VIDEOPACK_AV208              VHD_BUFPACK_VIDEO_YUVK4224_8            /*!VHD_VIDEOPACK_AV208
                                                                                    Old AV208 Video Packing is called now YUVK4224_8. */
#define VHD_VIDEOPACK_V210               VHD_BUFPACK_VIDEO_YUV422_10             /*!VHD_VIDEOPACK_V210
                                                                                    Old V210 Video Packing is called now YUV422_10. */
#define VHD_VIDEOPACK_AV210              VHD_BUFPACK_VIDEO_YUVK4224_10           /*!VHD_VIDEOPACK_AV210
                                                                                    Old AV210 Video Packing is called now YUVK4224_10. */
#define VHD_VIDEOPACK_V408               VHD_BUFPACK_VIDEO_YUV4444_8             /*!VHD_VIDEOPACK_V408
                                                                                    Old V408 Video Packing is called now YUV4444_8. */
#define VHD_VIDEOPACK_AV408              VHD_BUFPACK_VIDEO_YUVK4444_8            /*!VHD_VIDEOPACK_AV408
                                                                                    Old AV408 Video Packing is called now YUVK4444_8. */
#define VHD_VIDEOPACK_V410               VHD_BUFPACK_VIDEO_YUV444_10             /*!VHD_VIDEOPACK_V410
                                                                                    Old V410 Video Packing is called now YUV444_10. */
#define VHD_VIDEOPACK_AV410              VHD_BUFPACK_VIDEO_YUVK4444_10           /*!VHD_VIDEOPACK_AV410
                                                                                    Old AV410 Video Packing is called now YUVK4444_10. */
#define VHD_VIDEOPACK_C408               VHD_BUFPACK_VIDEO_RGB_32                /*!VHD_VIDEOPACK_C408
                                                                                    Old C408 Video Packing is called now RGB_32. */
#define VHD_VIDEOPACK_AC408              VHD_BUFPACK_VIDEO_RGBA_32               /*!VHD_VIDEOPACK_AC408
                                                                                    Old AC408 Video Packing becomes RGBA_32. */
#define VHD_BUFPACK_VIDEO_PLANAR_YV12    VHD_BUFPACK_VIDEO_PLANAR_YVU420_8	      /*!VHD_BUFPACK_VIDEO_PLANAR_YV12
                                                                                    Old YV12 Buffer Packing becomes PLANAR_YVU420_8. */
#define VHD_BUFPACK_VIDEO_PLANAR_I420    VHD_BUFPACK_VIDEO_PLANAR_YUV420_8       /*!VHD_BUFPACK_VIDEO_PLANAR_I420
                                                                                    Old I420 Buffer Packing becomes PLANAR_YUV420_8. */
#define VHD_BUFFPACK_VIDEO_ICTCP_422_8   VHD_BUFPACK_VIDEO_ICTCP_422_8

#define VHD_BUFFPACK_VIDEO_ICTCP_422_10  VHD_BUFPACK_VIDEO_ICTCP_422_10

#define NB_VHD_VIDEOPACKINGS  NB_VHD_BUFPACKINGS


/*_ VHD_OUTPUTMODE _____________________________________________*/
/*!
   Summary
   VideoMaster TX streams output modes
   Description
   The VHD_OUTPUTMODE enumeration lists all the available output
   modes

   These values are used in VHD_CORE_SP_TX_OUTPUT stream
   property and only apply to SDI transmission streams.
   See Also
   <link VHD_CORE_STREAMPROPERTY, VHD_CORE_SP_TX_OUTPUT>         */

typedef enum _VHD_OUTPUTMODE
{
   VHD_OUTPUT_STREAM = 0,                 /*! Direct output from logical stream (default) */
   VHD_OUTPUT_TEST,                       /*!_VHD_OUTPUTMODE::VHD_OUTPUT_TEST
                                             Test (green) output (only available on DELTA-hd) */
   VHD_OUTPUT_NONE,                       /*! No output. TX channel is in tri-state until the VHD_CORE_SP_TX_OUTPUT is explicitly set to an other value.
                                              Remark : On a DELTA-hd, setting VHD_CORE_BP_BYPASS_RELAY_x to FALSE reconnects the corresponding TX channel to the stream or the test pattern as a side effect. */
   NB_VHD_OUTPUTMODES
} VHD_OUTPUTMODE;



/*_ VHD_ERRORCODE ____________________________________________________*/
/*!
<keywords Error, Error Codes>

Summary
VideoMaster error codes

Description
The VHD_ERRORCODE enumeration lists all error codes that can
be generated by the API functions
*/

typedef enum _VHD_ERRORCODE
{
   VHDERR_NOERROR,                              /*! No error */
   VHDERR_FATALERROR,                           /*! Fatal error occurred (should re-install) */
   VHDERR_OPERATIONFAILED,                      /*! Operation failed (undefined error) */
   VHDERR_NOTENOUGHRESOURCE,                    /*! Not enough resource to complete the operation */
   VHDERR_NOTIMPLEMENTED,                       /*! Not implemented yet */
   VHDERR_NOTFOUND,                             /*! Required element was not found */

   VHDERR_BADARG,                               /*! Bad argument value */
   VHDERR_INVALIDPOINTER,                       /*! Invalid pointer */
   VHDERR_INVALIDHANDLE,                        /*! Invalid handle */
   VHDERR_INVALIDPROPERTY,                      /*! Invalid property index */
   VHDERR_INVALIDSTREAM,                        /*! Invalid stream or invalid stream type */

   VHDERR_RESOURCELOCKED,                       /*! Resource is currently locked */

   VHDERR_BOARDNOTPRESENT,                      /*! Board is not available */
   VHDERR_INCOHERENTBOARDSTATE,                 /*! Incoherent board state or register value */
   VHDERR_INCOHERENTDRIVERSTATE,                /*! Incoherent driver state */
   VHDERR_INCOHERENTLIBSTATE,                   /*! Incoherent library state */
   VHDERR_SETUPLOCKED,                          /*! Configuration is locked */
   VHDERR_CHANNELUSED,                          /*! Requested channel is already used or doesn't exist */
   VHDERR_STREAMUSED,                           /*! Requested stream is already used */
   VHDERR_READONLYPROPERTY,                     /*! Property is read-only */
   VHDERR_OFFLINEPROPERTY,                      /*! Property is off line-only */
   VHDERR_TXPROPERTY,                           /*! Property is of TX streams */
   VHDERR_TIMEOUT,                              /*! Time-out occurred */
   VHDERR_STREAMNOTRUNNING,                     /*! Stream is not running */
   VHDERR_BADINPUTSIGNAL,                       /*! Bad input signal, or unsupported standard */
   VHDERR_BADREFERENCESIGNAL,                   /*! Bad genlock signal, or unsupported standard */
   VHDERR_FRAMELOCKED,                          /*! Frame already locked */
   VHDERR_FRAMEUNLOCKED,                        /*! Frame already unlocked */
   VHDERR_INCOMPATIBLESYSTEM,                   /*! Selected video standard is incompatible with running clock system */

   VHDERR_ANCLINEISEMPTY,                       /*! ANC line is empty */
   VHDERR_ANCLINEISFULL,                        /*! ANC line is full */

   VHDERR_BUFFERTOOSMALL,                       /*! Buffer too small */
   VHDERR_BADANC,                               /*! Received ANC aren't standard */
   VHDERR_BADCONFIG,                            /*! Invalid configuration */

   VHDERR_FIRMWAREMISMATCH,                     /*! The loaded firmware is not compatible with the installed driver */
   VHDERR_LIBRARYMISMATCH,                      /*! The loaded VideoMaster library is not compatible with the installed driver */

   VHDERR_FAILSAFE,                             /*! The fail safe firmware is loaded. You need to Update your firmware */
   VHDERR_RXPROPERTY,                           /*! Property is of RX streams */

   VHDERR_ALREADYINITIALIZED,                   /*! The system is already initialized */
   VHDERR_NOTINITIALIZED,                       /*! The system isn't initialized */
   VHDERR_CROSSTHREAD,                          /*! Cross-thread operations are not supported */

   VHDERR_INCOHERENTDATA,                       /*! Incoherent data */
   VHDERR_BADSIZE,                              /*! Wrong buffer size */

   VHDERR_WAKEUP,                               /*! The wakeup requires all boards to be closed */
   VHDERR_DEVICE_REMOVED,                       /*! The device has been removed, the clients should stop referencing this driver instance so the OS can unload it */

   VHDERR_DATANOTREADY,                         /*! Data is not ready */
   VHDERR_NOSFPMODULE_DEPRECATED,               /*! Deprecated enumeration value */
   VHDERR_SFPMODULELOCKED_DEPRECATED,           /*! Deprecated enumeration value */
   VHDERR_INVALIDTABLE_DEPRECATED,              /*! SFP module table not set or invalid */
   VHDERR_TEMPERATURETOOHIGH,                   /*! The board is in low power mode due to high temperature */

   VHDERR_LTCSOURCEUNLOCKED,                    /*! LTC source unlocked */

   VHDERR_INVALIDACCESSRIGHT,                   /*! Invalid access right */

   VHDERR_LICENSERESTRICTION_DEPRECATED,                   /*! The actual license doesn't allow this operation */

   VHDERR_SOFTWAREPROTECTION_FAILURE_DEPRECATED,           /*! Software protection operation failed */
   VHDERR_SOFTWAREPROTECTION_IDNOTFOUND_DEPRECATED,        /*! Software protection host id cannot be found */
   VHDERR_SOFTWAREPROTECTION_BADLICENSEINFO_DEPRECATED,    /*! Software protection bad license information */
   VHDERR_SOFTWAREPROTECTION_UNAUTHORIZEDHOST_DEPRECATED,  /*! Software protection unauthorized host */
   VHDERR_SOFTWAREPROTECTION_STREAMSTARTED_DEPRECATED,     /*! Software protection stream already started. All stream must be stopped to setup license information */

   VHDERR_BAD_PARITY,                           /*! The parity must change between to VHD_QueueOutSlot call */

   VHDERR_INVALIDCAPABILITY,                    /*! Invalid capability index */
   VHDERR_DEPRECATED,                           /*! define, enumeration, function or structure is deprecated */
   VHDERR_DEVICENEEDSRESTART,                   /*! Device needs restart of the computer */
   VHDERR_FWUPDATEINPROGRESS,                   /*! FW update in progress */
   VHDERR_NOMOREDATATOPROCESS,                  /*! No more data to processs */

   NB_VHD_ERRORCODES
} VHD_ERRORCODE;

/*_ VHD_BIDIRCFG_4C _____________________________________________*/
/*!
   Summary
   VideoMaster bidirectional channel configuration
   Description
   The VHD_BIDIRCFG_4C enumeration lists all the available bidirectional
   channel configuration for a DELTA 4c card.

   These values are used in VHD_SetBiDirCfg function
   See Also
   <link VHD_SetBiDirCfg>
*/
typedef enum _VHD_BIDIRCFG_4C
{
   VHD_BIDIR_40,  /*! RX0, RX1, RX2 and RX3 configuration*/
   VHD_BIDIR_31,  /*! RX0, RX1, RX2 and TX0 configuration*/
   VHD_BIDIR_22,  /*! RX0, RX1, TX0 and TX1 configuration*/
   VHD_BIDIR_13,  /*! RX0, TX0, TX1 and TX2 configuration*/
   VHD_BIDIR_04,  /*! TX0, TX1, TX2 and TX3 configuration*/
   NB_VHD_BIDIR_4C
}VHD_BIDIRCFG_4C;

/*_ VHD_BIDIRCFG_8C _____________________________________________*/
/*!
   Summary
   VideoMaster bidirectional channel configuration
   Description
   The VHD_BIDIRCFG_8C enumeration lists all the available bidirectional
   channel configuration for a DELTA 8c card.

   These values are used in VHD_SetBiDirCfg function
   See Also
   <link VHD_SetBiDirCfg>
*/
typedef enum _VHD_BIDIRCFG_8C
{
   VHD_BIDIR_80,  /*! RX0, RX1, RX2, RX3, RX4, RX5, RX6 and RX7 configuration*/
   VHD_BIDIR_71,  /*! RX0, RX1, RX2, RX3, RX4, RX5, RX6 and TX0 configuration*/
   VHD_BIDIR_62,  /*! RX0, RX1, RX2, RX3, RX4, RX5, TX0 and TX1 configuration*/
   VHD_BIDIR_53,  /*! RX0, RX1, RX2, RX3, RX4, TX0, TX1 and TX2 configuration*/
   VHD_BIDIR_44,  /*! RX0, RX1, RX2, RX3, TX0, TX1, TX2 and TX3 configuration*/
   VHD_BIDIR_35,  /*! RX0, RX1, RX2, TX0, TX1, TX2, TX3 and TX4 configuration*/
   VHD_BIDIR_26,  /*! RX0, RX1, TX0, TX1, TX2, TX3, TX4 and TX5 configuration*/
   VHD_BIDIR_17,  /*! RX0, TX0, TX1, TX2, TX3, TX4, TX5 and TX6 configuration*/
   VHD_BIDIR_08,  /*! TX0, TX1, TX2, TX3, TX4, TX5, TX6 and TX7 configuration*/
   NB_VHD_BIDIR_8C
}VHD_BIDIRCFG_8C;

/* VideomasterHD bidirectional channel configuration dynamic*/
#define VHD_BIDIR_DYNAMIC  0xFFFFFFFF  //DELTA 4c and DELTA 8c cards will be seen respectively like a 44 and a 88 cards, this will allow the user to use freely all the RX or the TX of the card without bidirectional channel reconfiguration.

/*_ VHD_COMPANION_CARD_TYPE _____________________________________________*/
/*!
   Summary
   VideoMaster companion card type
   Description
   The VHD_COMPANION_CARD_TYPE enumeration lists all the available companion card types

   These values are used in VHD_DetectCompanionCard function
   See Also
   <link VHD_DetectCompanionCard>
*/

typedef enum _VHD_COMPANION_CARD_TYPE
{
   VHD_LTC_COMPANION_CARD=0,       /*! A-LTC companion card*/
   NB_VHD_COMPANION_CARD_TYPE
}VHD_COMPANION_CARD_TYPE;

/*_ VHD_TIMECODE_SOURCE _____________________________________________*/
/*!
   Summary
   VideoMaster timecode source
   Description
   The VHD_TIMECODE_SOURCE enumeration lists all the available timecode sources

   These values are used in VHD_GetTimecode and VHD_GetSlotTimecode functions
   See Also
   <link VHD_GetTimecode, VHD_GetSlotTimecode>
*/
typedef enum _VHD_TIMECODE_SOURCE
{
   VHD_TC_SRC_LTC_COMPANION_CARD,     /*! A-LTC companion card timecode source*/
   VHD_TC_SRC_LTC_ONBOARD,            /*! On board timecode source*/
   NB_VHD_TC_SRC
}VHD_TIMECODE_SOURCE;

/*_ VHD_HOSTID_TYPE _____________________________________________*/
/*!
   Summary
   VideoMaster host ID type
   Description
   The VHD_HOSTID_TYPE enumeration lists all the available host id types

   These values are returned by the VHD_GetHostID functions
   See Also
   <link VHD_GetHostID>
*/
typedef enum _VHD_HOSTID_TYPE
{
   VHD_HOSTID_TYPE_STRING, /*! HostID string type */
   NB_VHD_HOSTID_TYPE
}VHD_HOSTID_TYPE;


/*_ VHD_CORE_BOARD_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster core board capability
  Description
  The VHD_CORE_BOARD_CAPABILITY enumeration lists all the available core board capabilities

  These values are used in VHD_GetBoardCapability function
  See Also
  <link VHD_GetBoardCapability>
*/
typedef enum _VHD_CORE_BOARD_CAPABILITY
{
   VHD_CORE_BOARD_CAP_GENLOCK = ENUMBASE_CORE,           /*! Return the number of genlock circuitry available on the board*/
   VHD_CORE_BOARD_CAP_CLOCK_ADJUST,                      /*! Return true if the board supports clock adjust handling feature*/
   VHD_CORE_BOARD_CAP_RX_PHASE_MEASURE,                  /*! Return true if the board supports RX phase measure handling feature*/
   VHD_CORE_BOARD_CAP_PER_CHN_TX_OFFSET,                 /*! Return true if the board supports channel TX offset handling feature*/
   VHD_CORE_BOARD_CAP_MASTERTIMESTAMP_DEPRECATED,        /*! Return true if the board supports master timestamp handling feature*/
   VHD_CORE_BOARD_CAP_27MHZ_TIMESTAMP,                   /*! Return true if the board supports 27 MHz timestamp handling feature*/
   VHD_CORE_BOARD_CAP_LTC_COMPANION_CARD,                /*! Return true if the board supports LTC companion card handling feature*/
   VHD_CORE_BOARD_CAP_BYPASS_RELAY,                      /*! Return the number of bypass relay available on the board*/
   VHD_CORE_BOARD_CAP_WATCHDOG_RXTX_PASSTHROUGH,         /*! Return true if the board supports RX-TX passthrough watchdog handling feature*/
   VHD_CORE_BOARD_CAP_HDMI_MONITORING,                   /*! Return true if the board supports HDMI monitoring handling feature*/
   VHD_CORE_BOARD_CAP_THUMBNAILS,                        /*! Return true if the board supports thumbnails handling feature*/
   VHD_CORE_BOARD_CAP_DELAY_LINE,                        /*! Return true if the board supports delay line handling feature*/
   VHD_CORE_BOARD_CAP_INPUT_CSC,                         /*! Return true if the board supports input CSC handling feature*/
   VHD_CORE_BOARD_CAP_OUTPUT_CSC,                        /*! Return true if the board supports output CSC handling feature*/
   VHD_CORE_BOARD_CAP_FIELD_MODE,                        /*! Return true if the board supports field handling feature*/
   VHD_CORE_BOARD_CAP_LINE_PADDING,                      /*! Return true if the board supports line padding handling feature*/
   VHD_CORE_BOARD_CAP_FIELD_MERGING,                     /*! Return true if the board supports field merging handling feature*/
   VHD_CORE_BOARD_CAP_BIDIR,                             /*! Return true if the board supports BiDir configuration handling feature*/
   VHD_CORE_BOARD_CAP_TEMPERATURE_MONITORING,            /*! Return true if the board supports temperature monitoring handling feature*/
   VHD_CORE_BOARD_CAP_ACTIVE_LOOPBACK,                   /*! Returns the number of available active loopback */
   VHD_CORE_BOARD_CAP_GPIO,                              /*! Returns the number of available GPIO on ext connector */
   VHD_CORE_BOARD_CAP_LOWLATENCY,                        /*! Return true if the board supports low latency handling feature*/
   VHD_CORE_BOARD_CAP_LTC_ONBOARD,                       /*! Return true if the board supports on board LTC feature*/
   VHD_CORE_BOARD_CAP_GENLOCK_SELECTION,                 /*! Returns true if the board supports genlock selection feature */
   VHD_CORE_BOARD_CAP_BLACKBURST,                        /*! Return the number of blackburst connector available on the board */
   VHD_CORE_BOARD_CAP_BIDIR_DYNAMIC,                     /*! Return true if the board supports dynamic BiDir configuration handling feature*/
   VHD_CORE_BOARD_CAP_FRAME_DECIMATION,                  /*! Return true if the board supports frame decimation handling feature*/
   VHD_CORE_BOARD_CAP_BRANDING_CHALLENGE,                /*! Return true if the board supports branding challenge handling feature*/ 
   VHD_CORE_BOARD_CAP_WATCHDOG_TX_TRISTATE,              /*! Return true if the board supports TX tristate watchdog handling feature*/
   VHD_CORE_BOARD_CAP_FRAME_ACCURACY_TYPE_FLEX,          /*! Return true if the board supports frame accuracy type "FLEX" */
   VHD_CORE_BOARD_CAP_FRAME_ACCURACY_TYPE_PCSYNC,        /*! Return true if the board supports frame accuracy type "PCSYNC" (or "clock reconstruction") */
   VHD_CORE_BOARD_CAP_12G_BIDIR_DYNAMIC,                 /*! Return true if the board supports 12 G dynamic BiDir configuration handling feature*/
   VHD_CORE_BOARD_CAP_CONFIGURABLE_THUMBNAILS,           /*! Return true if the board supports configurable thumbnails feature*/
   VHD_CORE_BOARD_CAP_THUMBNAILS_FRAME_DECIMATION,       /*! Return true if the board supports thumbnails frame decimation handling feature*/
   VHD_CORE_BOARD_CAP_CONTROL_MRRS,                      /*! Return true if the board supports MRRS configuration */
   NB_VHD_CORE_BOARD_CAPABILITY
}VHD_CORE_BOARD_CAPABILITY;

#define VHD_CORE_BOARD_CAP_WATCHDOG  VHD_CORE_BOARD_CAP_WATCHDOG_RXTX_PASSTHROUGH /*! Backward-compatibility*/

/*_ VHD_LOWLATENCY_MODE _____________________________________________*/
/*!
  Summary
  VideoMaster low latency mode enumeration
  Description
  The VHD_LOWLATENCY_MODE enumeration lists all the available low latency mode.

  These values are used in VHD_GetStreamProperty and VHD_SetStreamProperty function
  See Also
  <link VHD_CORE_SP_LOWLATENCY_MODE, VHD_GetStreamProperty, VHD_SetStreamProperty>
*/
typedef enum _VHD_LOWLATENCY_MODE
{
   VHD_LLM_DISABLED,                /*! Low latency mode is disabled. */
   VHD_LLM_HALF_FRAME_DEPRECATED,   /*! Deprecated enumeration value */
   VHD_LLM_QUARTER_FRAME_DEPRECATED,/*! Deprecated enumeration value */
   VHD_LLM_EIGHTH_FRAME_DEPRECATED, /*! Deprecated enumeration value */
   VHD_LLM_DATA_BLOCK,              /*! Data block low latency */
   NB_VHD_LOWLATENCY_MODE
}VHD_LOWLATENCY_MODE;

#define VHD_LLM_HALF_FRAME    VHD_LLM_HALF_FRAME_DEPRECATED /*! Backward-compatibility*/
#define VHD_LLM_QUARTER_FRAME VHD_LLM_QUARTER_FRAME_DEPRECATED /*! Backward-compatibility*/
#define VHD_LLM_EIGHTH_FRAME  VHD_LLM_EIGHTH_FRAME_DEPRECATED /*! Backward-compatibility*/

/*_ VHD_SYSTEM_TIME_CLK_TYPE _____________________________________________*/
/*!
Summary
VideoMaster System clock type
Description
The VHD_SYSTEM_TIME_CLK_TYPE enumeration lists all the available system clock types.

These values are used in kernel and the corresponding time can be retrieve with function VHD_GetSlotSystemTime
See Also
<link VHD_GetBoardProperty, VHD_SetBoardProperty>
*/
typedef enum _VHD_SYSTEM_TIME_CLK_TYPE
{
   VHD_ST_CLK_TYPE_MONOTONIC_RAW, /*! Monotonic raw time (based on an oscillator value and not subject to any adjustment, better used for more accuracy over short intervals of time) */ 
   VHD_ST_CLK_TYPE_MONOTONIC,     /*! Monotonic time (based on an incremented value generated by interrupts of the system clock. Only subject to incremental corrections and better
   used for longer-term timers measured in minutes, hours, days. See User Guide for more information) */
   VHD_ST_CLK_TYPE_REALTIME,      /*! Real Time (based on computer time. See User Guide for more information) */
   NB_VHD_SYSTEM_TIME_CLK_TYPE
}VHD_SYSTEM_TIME_CLK_TYPE;

/*_ VHD_WATCHDOG_TYPE _____________________________________________*/
/*!
Summary
VideoMaster Watchdog type
Description
The VHD_WATCHDOG_TYPE enumeration lists all the available watchdog types.

These values are used with VHD_CORE_BP_WATCHDOGTYPE board property
See Also
<link VHD_GetBoardProperty, VHD_SetBoardProperty>
*/
typedef enum _VHD_WATCHDOG_TYPE
{
   VHD_WATCHDOG_TYPE_RXTX_PASSTHROUGH, /*! RX-TX relays watchdog*/
   VHD_WATCHDOG_TYPE_TX_TRISTATE,      /*! TX tristate watchdog*/
   NB_VHD_WATCHDOG_TYPE
}VHD_WATCHDOG_TYPE;

/*_ VHD_FRAME_ACCURACY_TYPE _____________________________________________*/
/*!
Summary
VideoMaster Frame accuracy type
Description
The VHD_FRAME_ACCURACY_TYPE enumeration lists all the available frame accuracy mechanism types.

See Also
<link VHD_GetStreamProperty, VHD_SetStreamProperty>
*/
typedef enum _VHD_FRAME_ACCURACY_TYPE
{
   VHD_FRAME_ACCURACY_TYPE_NONE,    /*! No frame accuracy type */ 
   VHD_FRAME_ACCURACY_TYPE_FLEX,    /*! FLEX frame accuracy type */ 
   VHD_FRAME_ACCURACY_TYPE_PCSYNC,  /*! PCSYNC (clock reconstruction) frame accuracy type */ 
   NB_VHD_FRAME_ACCURACY_TYPE
}VHD_FRAME_ACCURACY_TYPE;

/*_ VHD_FRAME_ACCURACY_PCSYNC_STATUS _____________________________________________*/
/*!
Summary
VideoMaster Frame accuracy PCSYNC status
Description
The VHD_FRAME_ACCURACY_PCSYNC_STATUS enumeration lists all the possible status of the PCSYNC mechanism.

See Also
<link VHD_GetClockReconstructionConfidence>
*/
typedef enum _VHD_FRAME_ACCURACY_PCSYNC_STATUS
{
   VHD_FRAME_ACCURACY_PCSYNC_STATUS_LOCKED,              /*! The clock reconstruction mechanism is producing parameters that are correctly synced with the relevant boards */ 
   VHD_FRAME_ACCURACY_PCSYNC_STATUS_IN_PROGRESS,         /*! The clock reconstruction mechanism is producing parameters */ 
   VHD_FRAME_ACCURACY_PCSYNC_STATUS_NOT_ENOUGH_DATA,     /*! Not enough data samples have been gathered to produce any set of parameters */ 
   VHD_FRAME_ACCURACY_PCSYNC_STATUS_FILTERING_OUT_DATA,  /*! The algorithm has rejected consecutively rejected the last 5 data samples (or more) */ 
   NB_VHD_FRAME_ACCURACY_PCSYNC_STATUS
}VHD_FRAME_ACCURACY_PCSYNC_STATUS;

/*_ VHD_TIMER_SOURCE  _____________________________________________*/
/*!
Summary
VideoMaster Genlock Tick Event timer source
Description
The VHD_TIMER_SOURCE enumeration lists all the available clock source for a timer.
*/
typedef enum _VHD_TIMER_SOURCE
{
   VHD_TIMER_SOURCE_GENLOCK,       /*! FPGA produces interrupts at Genlock tick */ 
   VHD_TIMER_SOURCE_TX0,           /*! FPGA produces interrupts based on the configuration of the MTG for TX0 */ 
   NB_VHD_TIMER_SOURCE
}VHD_TIMER_SOURCE;

/*_ VHD_CORE_GATEWAY_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster core gateway capability
  Description
  The VHD_CORE_GATEWAY_CAPABILITY enumeration lists all the available core gateway capabilities

  These values are used in VHD_GetGatewayCapability function
  See Also
  <link VHD_GetGatewayCapability>
*/
typedef enum _VHD_CORE_GATEWAY_CAPABILITY
{
   VHD_CORE_GATEWAY_CAP_SYNC_SIGNAL = ENUMBASE_GATEWAY,     /*! Returns true if the gateway supports sending a synchronization signal to its connected devices */
   NB_VHD_CORE_GATEWAY_CAPABILITY
}VHD_CORE_GATEWAY_CAPABILITY;

/*_ VHD_CORE_GATEWAYPROPERTY _______________________________________________*/
/*!
   Summary
   VideoMaster core gateway properties
   Description
   The VHD_CORE_GATEWAYPROPERTY enumeration lists all the
   available gateway properties common to all supported hardware
   families.

   These values are used as indexes for VHD_GetGatewayProperty 
   function calls.
   See Also
   VHD_GetGatewayProperty                     */
typedef enum _VHD_CORE_GATEWAYPROPERTY
{
   /* Software board handling */
   VHD_CORE_GP_FIRMWARE_SWITCH_VERSION = ENUMBASE_GATEWAY,   /*!_VHD_CORE_GATEWAYPROPERTY::VHD_CORE_GP_FIRMWARE_SWITCH_VERSION 
                                                                Switch version, if any                                        */
   VHD_CORE_GP_FIRMWARE_SWITCH_CONFIG_VERSION,               /*!_VHD_CORE_GATEWAYPROPERTY::VHD_CORE_GP_FIRMWARE_SWITCH_CONFIG_VERSION
                                                                Switch config version, if any                                        */
   VHD_CORE_GP_FIRMWARE_UC_VERSION,                          /*!_VHD_CORE_GATEWAYPROPERTY::VHD_CORE_GP_FIRMWARE_UC_VERSION
                                                                Micro-controller version, if any                            */
   VHD_CORE_GP_REQUESTED_FIRMWARE_SWITCH_VERSION,            /*!_VHD_CORE_GATEWAYPROPERTY::VHD_CORE_GP_REQUESTED_FIRMWARE_SWITCH_VERSION
                                                                Switch version requested, if any                         */ 
   VHD_CORE_GP_REQUESTED_FIRMWARE_SWITCH_CONFIG_VERSION,     /*!_VHD_CORE_GATEWAYPROPERTY::VHD_CORE_GP_REQUESTED_FIRMWARE_SWITCH_CONFIG_VERSION
                                                                Switch config version requested, if any              */
   VHD_CORE_GP_REQUESTED_FIRMWARE_UC_VERSION,                /*!_VHD_CORE_GATEWAYPROPERTY::VHD_CORE_GP_REQUESTED_FIRMWARE_UC_VERSION
                                                                Micro-controller version requested, if any              */
   VHD_CORE_GP_SWITCH_RESTART_NEEDED_AFTER_UPDATE,           /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_GP_SWITCH_RESTART_NEEDED_AFTER_UPDATE
                                                                Switch restart needed */
   VHD_CORE_GP_SWITCH_CONFIG_RESTART_NEEDED_AFTER_UPDATE,    /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_GP_SWITCH_CONFIG_RESTART_NEEDED_AFTER_UPDATE
                                                                Switch config restart needed */
   VHD_CORE_GP_UC_RESTART_NEEDED_AFTER_UPDATE,               /*!_VHD_CORE_BOARDPROPERTY::VHD_CORE_GP_UC_RESTART_NEEDED_AFTER_UPDATE
                                                                UC restart needed */
   NB_VHD_CORE_GATEWAYPROPERTIES
} VHD_CORE_GATEWAYPROPERTY;

/*_ VHD_BRD_FIRMWARE_TYPE _______________________________________________*/
/*!
   Summary
   VideoMaster board firmware type
   Description
   The VHD_BRD_FIRMWARE_TYPE enumeration lists all the
   available board firmware type.

   These values are used as indexes for VHD_GetBoardFirmwareInfo 
   function calls.
   See Also
   VHD_GetBoardFirmwareInfo                     */
typedef enum _VHD_BRD_FIRMWARE_TYPE
 {
    VHD_BRD_FIRMWARE_FPGA = 0,               /*! FPGA firmware type */    
    VHD_BRD_FIRMWARE_ARM_MICROCODE,          /*! ARM microcode firmware type */ 
    VHD_BRD_FIRMWARE_SCP_MICROCODE,          /*! SCP microcode firmware type */ 
    NB_VHD_BRD_FIRMWARE_TYPE
 } VHD_BRD_FIRMWARE_TYPE;

/*_ VHD_CORE_BRD_CONFIG_SET _______________________________________________*/
/*!
   Summary
   VideoMaster board config set
   Description
   The VHD_CORE_BRD_CONFIG_SET enumeration lists all the
   available board config set type.

   These values are used in the VHD_BRD_CONFIG structure.
   See Also
   VHD_GetBoardConfigSet                     */
typedef enum _VHD_CORE_BRD_CONFIG_SET
 {
    VHD_CORE_BRD_CONFIG_SET_NONE = 0,              /*! Config set none */
    VHD_CORE_BRD_CONFIG_SET_IP_BOARDS,             /*! Config set IP boards */   
    VHD_CORE_BRD_CONFIG_SET_3G_8C_BOARDS,          /*! Config set 3G 8C boards */
    VHD_CORE_BRD_CONFIG_SET_12G_2C_BOARDS,         /*! Config set 12G 2C boards */
    VHD_CORE_BRD_CONFIG_SET_12G_4C_BOARDS,         /*! Config set 12G 4C boards */
    VHD_CORE_BRD_CONFIG_SET_ST2110_BOARDS,         /*! Config set ST2110 boards */
    NB_VHD_CORE_BRD_CONFIG_SET
 } VHD_CORE_BRD_CONFIG_SET;
 
/*_ VHD_CORE_BRD_CONFIG_IP_BOARDS _______________________________________________*/
/*!
   Summary
   VideoMaster board config set
   Description
   The VHD_CORE_BRD_CONFIG_IP_BOARDS enumeration lists all the
   available board config IP.

   These values are used in the VHD_BRD_CONFIG structure.
   See Also
   VHD_GetBoardConfigSet                     */
 typedef enum _VHD_CORE_BRD_CONFIG_IP_BOARDS
 {
    VHD_CORE_BRD_CONFIG_IP_BOARDS_RX = 0,       /*! Config set IP boards RX */          
    VHD_CORE_BRD_CONFIG_IP_BOARDS_TX,           /*! Config set IP boards TX */
    NB_VHD_CORE_BRD_CONFIG_IP_BOARDS
 } VHD_CORE_BRD_CONFIG_IP_BOARDS;
 
 /*_ VHD_CORE_BRD_CONFIG_3G_8C_BOARDS _______________________________________________*/
/*!
   Summary
   VideoMaster board config set
   Description
   The VHD_CORE_BRD_CONFIG_3G_8C_BOARDS enumeration lists all the
   available board config 3G 8C.

   These values are used in the VHD_BRD_CONFIG structure.
   See Also
   VHD_GetBoardConfigSet                     */
 typedef enum _VHD_CORE_BRD_CONFIG_3G_8C_BOARDS
 {
    VHD_CORE_BRD_CONFIG_3G_8C_BOARDS_80 = 0,     /*! Config set 3G 8C boards 80 */             
    VHD_CORE_BRD_CONFIG_3G_8C_BOARDS_84,         /*! Config set 3G 8C boards 84 */ 
    VHD_CORE_BRD_CONFIG_3G_8C_BOARDS_8B,         /*! Config set 3G 8C boards 8B */ 
    VHD_CORE_BRD_CONFIG_3G_8C_BOARDS_8C,         /*! Config set 3G 8C boards 8C */ 
    VHD_CORE_BRD_CONFIG_3G_8C_BOARDS_4C_ASI4C,   /*! Config set 3G 8C boards 4C ASI 4C */ 
    NB_VHD_CORE_BRD_CONFIG_3G_8C_BOARDS
 } VHD_CORE_BRD_CONFIG_3G_8C_BOARDS;
 
 /*_ VHD_CORE_BRD_CONFIG_12G_2C_BOARDS _______________________________________________*/
/*!
   Summary
   VideoMaster board config set
   Description
   The VHD_CORE_BRD_CONFIG_12G_2C_BOARDS enumeration lists all the
   available board config 12G 2C.

   These values are used in the VHD_BRD_CONFIG structure.
   See Also
   VHD_GetBoardConfigSet                     */
 typedef enum _VHD_CORE_BRD_CONFIG_12G_2C_BOARDS
 {
    VHD_CORE_BRD_CONFIG_12G_2C_BOARDS_20 = 0,      /*! Config set 12G 2C boards 20 */             
    VHD_CORE_BRD_CONFIG_12G_2C_BOARDS_2C,          /*! Config set 12G 2C boards 2C */ 
    VHD_CORE_BRD_CONFIG_12G_2C_BOARDS_ASI8C,       /*! Config set 12G 2C boards ASI 8C */ 
    NB_VHD_CORE_BRD_CONFIG_12G_2C_BOARDS
 } VHD_CORE_BRD_CONFIG_12G_2C_BOARDS;
 
 /*_ VHD_CORE_BRD_CONFIG_12G_4C_BOARDS _______________________________________________*/
/*!
   Summary
   VideoMaster board config set
   Description
   The VHD_CORE_BRD_CONFIG_12G_4C_BOARDS enumeration lists all the
   available board config 12G 4C.

   These values are used in the VHD_BRD_CONFIG structure.
   See Also
   VHD_GetBoardConfigSet                     */
 typedef enum _VHD_CORE_BRD_CONFIG_12G_4C_BOARDS
 {
    VHD_CORE_BRD_CONFIG_12G_4C_BOARDS_40 = 0,      /*! Config set 12G 4C boards 40 */            
    VHD_CORE_BRD_CONFIG_12G_4C_BOARDS_04,          /*! Config set 12G 4C boards 04 */ 
    VHD_CORE_BRD_CONFIG_12G_4C_BOARDS_4C,          /*! Config set 12G 4C boards 4C */ 
    NB_VHD_CORE_BRD_CONFIG_12G_4C_BOARDS
 } VHD_CORE_BRD_CONFIG_12G_4C_BOARDS;
 
 /*_ VHD_CORE_BRD_CONFIG_ST2110_BOARDS _______________________________________________*/
/*!
   Summary
   VideoMaster board config set
   Description
   The VHD_CORE_BRD_CONFIG_ST2110_BOARDS enumeration lists all the
   available board config ST2110.

   These values are used in the VHD_BRD_CONFIG structure.
   See Also
   VHD_GetBoardConfigSet                     */
 typedef enum _VHD_CORE_BRD_CONFIG_ST2110_BOARDS
 {
    VHD_CORE_BRD_CONFIG_ST2110_BOARDS_ST2022_RX = 0,     /*! Config set ST2110 boards ST2022 RX */             
    VHD_CORE_BRD_CONFIG_ST2110_BOARDS_ST2022_TX,         /*! Config set ST2110 boards ST2022 TX */
    VHD_CORE_BRD_CONFIG_ST2110_BOARDS_ST2110_RX,         /*! Config set ST2110 boards ST2110 RX */
    VHD_CORE_BRD_CONFIG_ST2110_BOARDS_ST2110_TX,         /*! Config set ST2110 boards ST2110 TX */
    NB_VHD_CORE_BRD_CONFIG_ST2110_BOARDS
 } VHD_CORE_BRD_CONFIG_ST2110_BOARDS;
 
 /*_ VHD_GTW_FIRMWARE_TYPE _______________________________________________*/
/*!
   Summary
   VideoMaster board firmware type
   Description
   The VHD_GTW_FIRMWARE_TYPE enumeration lists all the
   available board firmware type.

   These values are used as indexes for VHD_GetGatewayFirmwareInfo 
   function calls.
   See Also
   VHD_GetGatewayFirmwareInfo                     */
 typedef enum _VHD_GTW_FIRMWARE_TYPE
 {
    VHD_GTW_FIRMWARE_MICROCONTROLLER = 0,   /*! Micro-controller firmware type */  
    VHD_GTW_FIRMWARE_SWITCH,                /*! Switch firmware type */  
    VHD_GTW_FIRMWARE_SWITCH_CONFIG,         /*! Switch config firmware type */  
    NB_VHD_GTW_FIRMWARE_TYPE
 } VHD_GTW_FIRMWARE_TYPE;

/*_ VHD_THUMBNAIL_RATIO _______________________________________________*/
/*!
  Summary
  VideoMaster thumbnails ratio
  Description
  The VHD_THUMBNAIL_RATIO enumeration lists all the
  available thumbnails ratio type.

  These values are used as indexes with the VHD_CORE_SP_THUMBNAIL_RATIO 
  stream property.
  See Also
  <link VHD_GetStreamProperty, VHD_SetStreamProperty>        */
typedef enum _VHD_THUMBNAIL_RATIO
{
   VHD_THUMBNAIL_RATIO_1_OVER_2 = 0,   /*! Thumbnail ratio 1/2 */
   VHD_THUMBNAIL_RATIO_1_OVER_3,       /*! Thumbnail ratio 1/3 */
   VHD_THUMBNAIL_RATIO_1_OVER_4,       /*! Thumbnail ratio 1/4 */
   VHD_THUMBNAIL_RATIO_1_OVER_6,       /*! Thumbnail ratio 1/6 */
   NB_VHD_THUMBNAIL_RATIO
} VHD_THUMBNAIL_RATIO;

/*_ VHD_MRRS _______________________________________________*/
/*!
  Summary
  VideoMaster MRRS values
  Description
  The VHD_MRRS enumeration lists all the available VHD_MRRS values.

  These values are used with the VHD_CORE_BP_MRRS board property.
  See Also
  <link VHD_GetBoardProperty, VHD_SetBoardProperty>        */
typedef enum _VHD_MRRS
{
   VHD_MRRS_256B,
   VHD_MRRS_512B,
   NB_VHD_MRRS
} VHD_MRRS;


/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Core
*/

/*_ VHD_TIMECODE _______________________________________________________*/
/*!
   Summary
   SDI embedded timecode structure
   Description
   The VHD_TIMECODE structure abstracts a timecode value.
   See Also
   VHD_SlotExtractTimecode VHD_SlotEmbedTimecode
   VHD_TIMECODETYPE VHD_TIMECODESLOT                      */
typedef struct _VHD_TIMECODE
{
   BYTE  Hour;                /*! Timecode hour component */
   BYTE  Minute;              /*! Timecode minute component */
   BYTE  Second;              /*! Timecode second component */
   BYTE  Frame;               /*! Timecode frame component */
   ULONG BinaryGroups;        /*! Timecode binary groups component. This field comprises 8 groups of 4-bit, stored in a 32-bit variable with LSB being the LSB of BG1 until MSB being MSB of BG8 */
   BYTE  Flags;               /*! Timecode 6 flag bits, as specified by SMPTE 12M
                                   * Bit 0: Drop frame flag
                                   * Bit 1: Color frame flag
                                   * Bit 2: Field identification flag
                                   * Bit 3: Binary group flag BGF0
                                   * Bit 4: Binary group flag BGF1
                                   * Bit 5: Binary group flag BGF2
                              */
   BYTE  pDBB[2];             /*! Timecode distributed binary bit groups component (ATC only) */
} VHD_TIMECODE;

/*_ VHD_CLOCK_RECONSTRUCTION_PARAMETERS _____________________________________________*/
/*!
Summary
VideoMaster Clock reconstruction parameters
Description
The VHD_CLOCK_RECONSTRUCTION_PARAMETERS structure gathers all the parameters necessary to start the clock reconstruction mechanism.

See Also
<link VHD_StartClockReconstruction>
*/
typedef struct _VHD_CLOCK_RECONSTRUCTION_PARAMETERS
{
   ULONG StructSize;                            /*! Should be equal to sizeof(VHD_CLOCK_RECONSTRUCTION_PARAMETERS) and is used for versioning purpose */
   ClockReconstructionCallback_t pTimeCallback; /*! Callback used to retrieve the time in user-provided clockspace.
                                                   The callback, when called, should return the current time for the user (in microseconds).
                                                   This parameters is optional and can be NULL. In this case, the local system time is used. */
   ULONGLONG ThreadAffinity;                    /*! Thread affinity mask for all threads of the feature */
} VHD_CLOCK_RECONSTRUCTION_PARAMETERS;

/*_ VHD_BRD_CONFIG _____________________________________________*/
/*!
Summary
VideoMaster Board config structure
Description
The VHD_BRD_CONFIG structure gathers all the config enumeration to use with 
the VHD_GetBoardConfigSet function .

See Also
<link VHD_GetBoardConfigSet>
*/
typedef struct _VHD_BRD_CONFIG
 {
    VHD_CORE_BRD_CONFIG_SET BoardConfigSet_E;                     /*! Board config set */                             
    union {                                                          
       VHD_CORE_BRD_CONFIG_IP_BOARDS ConfigIpBoards_E;            /*! Config IP boards */
       VHD_CORE_BRD_CONFIG_3G_8C_BOARDS Config3G8CBoards_E;       /*! Config 3G 8C boards */
       VHD_CORE_BRD_CONFIG_12G_2C_BOARDS Config12G2CBoards_E;     /*! Config 12G 2C boards */
       VHD_CORE_BRD_CONFIG_12G_4C_BOARDS Config12G4CBoards_E;     /*! Config 12G 4C boards */
       VHD_CORE_BRD_CONFIG_ST2110_BOARDS ConfigSt2110Boards_E;    /*! Config ST2110 boards */
    };
 }VHD_BRD_CONFIG;

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif



/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Core
*/



/*_ API management functions ________________________________________________*/



/*** VHD_GetApiInfo **********************************************************/
/*!VHD_GetApiInfo@ULONG *@ULONG *
   Summary
   VideoMaster API information query
   Description
   This function provides information about the VideoMaster
   library, and about the number of detected Deltacast cards
   Parameters
   pApiVersion :  Optional pointer to a variable wherein the
                  library stores its version number
   pNbBoards :    Optional pointer to a variable wherein the
                  library stores the number of detected Deltacast
                  cards
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)       */
VIDEOMASTER_HD_API ULONG VHD_GetApiInfo (ULONG *pApiVersion, ULONG *pNbBoards);




/*_ Boards handling functions _______________________________________________*/



/*** VHD_OpenBoardHandle *****************************************************/
/*!VHD_OpenBoardHandle@ULONG@HANDLE *@HANDLE@ULONG
   Summary
   Board handle opening
   Description
   This function opens a handle to the specified board
   Parameters
   BoardIndex :          Zero\-based index of the board to open a
                         handle on
   pBrdHandle :          Pointer to a caller\-allocated variable
                         receiving the board handle
   OnStateChangeEvent :  Future use. Must be NULL.
   StateChangeMask :     Future use. Must be zero.
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_CloseBoardHandle                                           */
VIDEOMASTER_HD_API ULONG VHD_OpenBoardHandle (ULONG BoardIndex, HANDLE *pBrdHandle, HANDLE OnStateChangeEvent, ULONG StateChangeMask);


/*** VHD_CloseBoardHandle ****************************************************/
/*!
   Summary
   Board handle closing
   Description
   This function closes a board handle previously opened with
   VHD_OpenBoardHandle
   Parameters
   BrdHandle :  Handle of the board to close
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   If there are still running logical streams in the context of
   this board handle, they are closed. This does not mean
   physical channels are stopped, since they could still be
   accessed in another context
   See Also
   VHD_OpenBoardHandle
*/
VIDEOMASTER_HD_API ULONG VHD_CloseBoardHandle (HANDLE BrdHandle);


/*** VHD_SetBoardProperty ****************************************************/
/*!VHD_SetBoardProperty@HANDLE@ULONG@ULONG
   Summary
   Board property configuration
   Description
   This function configures the value of the specified board
   property
   Parameters
   BrdHandle :  Handle of the board to set property on
   Property :   Property to set, must be a value of the various
                board properties enumerations
   Value :      Property value to configure
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_CORE_BOARDPROPERTY VHD_SDI_BOARDPROPERTY
   VHD_GetBoardProperty                                         */
VIDEOMASTER_HD_API ULONG VHD_SetBoardProperty (HANDLE BrdHandle, ULONG Property, ULONG Value);


/*** VHD_GetBoardProperty ****************************************************/
/*!VHD_GetBoardProperty@HANDLE@ULONG@ULONG *
   Summary
   Board property query
   Description
   This function retrieves value of the specified board property
   Parameters
   BrdHandle :  Handle of the board to get property from
   Property :   Property to get, must be a value of the various
                board properties enumerations
   pValue :     Pointer to caller\-allocated variable to return
                property value
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_CORE_BOARDPROPERTY VHD_SDI_BOARDPROPERTY
   VHD_SetBoardProperty                                          */
VIDEOMASTER_HD_API ULONG VHD_GetBoardProperty (HANDLE BrdHandle, ULONG Property, ULONG *pValue);


/*** VHD_RearmWatchdog *******************************************************/
/*!VHD_RearmWatchdog@HANDLE
   Summary
   Board watchdog re-arming
   Description
   This function re-arms the by-pass relays watchdog of the
   specified board
   Parameters
   BrdHandle :  Handle of the board to re\-arm watchdog on
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   The DELTA-hd, DELTA-key and DELTA-mixed asi boards comprise
   by-pass relays that electrically connect each RX-TX pair in
   case of power failure.

   These by-pass relays may also be used to protect your video
   system against software crashes, by the way of the featured
   watchdog.



   Watchdog is an onboard timer that is programmed using the <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_WATCHDOG_TIMER>
   board property. Once it is set, the board re-establish relays
   loopthrough if the watchdog has not been re-armed using the
   present function within the time specified by <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_WATCHDOG_TIMER>,
   or disabled by setting this property to zero
   See Also
   <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_WATCHDOG_TIMER>                                                           */
VIDEOMASTER_HD_API ULONG VHD_RearmWatchdog (HANDLE BrdHandle);

/*** VHD_GetBoard27MhzTime ****************************************************/
/*!VHD_GetBoard27MhzTime@HANDLE@LONGLONG *
   Summary
   Board 27Mhz time query
   Description
   This function retrieves the 27Mhz time sample
   associated to the given board.
   Parameters
   BoardHandle :     Handle of the board to operate on
   p27MHzTimeStamp : Pointer to caller\-allocated variable
                     receiving the 27Mhz time
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetBoard27MhzTime(HANDLE BoardHandle, LONGLONG *p27MHzTimeStamp);



/*_ Streams handling functions ______________________________________________*/



/*** VHD_OpenStreamHandle ****************************************************/
/*!VHD_OpenStreamHandle@HANDLE@ULONG@ULONG@BOOL32 *@HANDLE *@HANDLE
   Summary
   VideoMaster stream handle opening
   Description
   This function opens a handle to the specified logical stream
   Parameters
   BrdHandle :         Handle of the board to open a stream
                       handle on
   StrmType :          Type of logical stream to open, must be a
                       value of the VHD_STREAMTYPE enumeration
   ProcessingMode :    Mode the stream is processed, must be a
                       value of the VHD_xxx_STREAMPROCMODE
                       enumeration
   pSetupLock :        Pointer to a boolean variable if must lock
                       configuration on that stream, or NULL
                       otherwise. If not NULL, then the boolean
                       is updated by VideoMaster to signal if
                       the handle owns the configuration lock or
                       not
   pStrmHandle :       Pointer to a caller\-allocated variable
                       receiving the stream handle
   OnDataReadyEvent :  Handle of an caller\-created event. Must be NULL if not used.
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_OpenBoardHandle VHD_CloseStreamHandle VHD_STREAMTYPE
   VHD_SDI_STREAMPROCMODE VHD_DV_STREAMPROCMODE
   VHD_ASI_STREAMPROCMODE                                         */
VIDEOMASTER_HD_API ULONG VHD_OpenStreamHandle (HANDLE BrdHandle, ULONG StrmType, ULONG ProcessingMode, BOOL32 *pSetupLock, HANDLE *pStrmHandle, HANDLE OnDataReadyEvent);



/*** VHD_CloseStreamHandle ***************************************************/
/*!
   Summary
   VideoMaster stream handle closing
   Description
   This function closes a logical stream handle previously
   opened with VHD_OpenStreamHandle
   Parameters
   StrmHandle :  Handle of the stream to close
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Closing a logical stream handle stops corresponding physical
   channels only if the stream is not accessed anymore (closing
   of last handle on that stream)
   See Also
   VHD_OpenStreamHandle
*/
VIDEOMASTER_HD_API ULONG VHD_CloseStreamHandle (HANDLE StrmHandle);


/*** VHD_SetStreamProperty ***************************************************/
/*!VHD_SetStreamProperty@HANDLE@ULONG@ULONG
   Summary
   VideoMaster stream property configuration
   Description
   This function configures the value of the specified stream
   property
   Parameters
   StrmHandle :  Handle of the stream to set property on
   Property :    Property to set, must be a value of the various
                 stream properties enumerations
   Value :       Property value to configure
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Setting stream properties is only allowed if the caller
   handle has the configuration lock on the stream.
   See Also
   VHD_CORE_STREAMPROPERTY VHD_SDI_STREAMPROPERTY
   VHD_DV_STREAMPROPERTY VHD_ASI_STREAMPROPERTY
   VHD_GetStreamProperty                                         */
VIDEOMASTER_HD_API ULONG VHD_SetStreamProperty (HANDLE StrmHandle, ULONG Property, ULONG Value);


/*** VHD_GetStreamProperty ***************************************************/
/*!VHD_GetStreamProperty@HANDLE@ULONG@ULONG *
   Summary
   VideoMaster stream property query
   Description
   This function retrieves value of the specified stream
   property
   Parameters
   StrmHandle :  Handle of the stream to get property from
   Property :    Property to get, must be a value of the various
                 stream properties enumerations
   pValue :      Pointer to caller\-allocated variable to return
                 property value
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)


   In DVI, auto-detection properties are not available on RX1
   if RX0 is started in dual link


   See Also
   VHD_CORE_STREAMPROPERTY VHD_SDI_STREAMPROPERTY
   VHD_DV_STREAMPROPERTY VHD_ASI_STREAMPROPERTY
   VHD_SetStreamProperty                                         */
VIDEOMASTER_HD_API ULONG VHD_GetStreamProperty (HANDLE StrmHandle, ULONG Property, ULONG *pValue);


/*** VHD_StartStream *********************************************************/
/*!VHD_StartStream@HANDLE
   Summary
   VideoMaster stream starting
   Description
   This function starts the specified stream
   Parameters
   StrmHandle :  Handle of the stream to start
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Once the stream is started, all offline properties become
   unavailable.



   If VHD_StartStream returns <link VHD_ERRORCODE, VHDERR_NOTENOUGHRESOURCE>,
   this most of the time means that the underlying driver was
   unable to allocate the buffer queue used to transfer data
   from and to the card. This can be verified by reading back
   the <link VHD_CORE_STREAMPROPERTY, VHD_CORE_SP_BUFFERQUEUE_DEPTH>
   stream property. In this case, try reducing the <link VHD_CORE_STREAMPROPERTY, VHD_CORE_SP_BUFFERQUEUE_DEPTH>
   property or increasing the amount of RAM in your PC. When
   using <link Memory preallocation, Memory Preallocation>, <link VHD_ERRORCODE, VHDERR_NOTENOUGHRESOURCE>
   is returned if the preallocated pool size is too small or if
   the preallocation failed (check <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_PREALLOCPOOLxSIZE>
   before starting the stream).


   In DVI,
   if RX0 is started in dual link, RX1 can't be started (return VHDERR_CHANNELUSED)
   if RX1 is started, RX0 can't be started in dual link (return VHDERR_CHANNELUSED)



   Under Linux, this memory allocation issue is often due to
   MAX_ORDER being too small. Please consult the Installation
   Guide for further information on that subject
   See Also
   VHD_StopStream VHD_OpenStreamHandle                                                                           */
VIDEOMASTER_HD_API ULONG VHD_StartStream (HANDLE StrmHandle);


/*** VHD_StopStream **********************************************************/
/*!
   Summary
   VideoMaster stream stopping

   Description
   This function stops the specified stream if it is running

   Parameters
   StrmHandle : Handle of the stream to stop

   Returns
   The function returns the status of its execution as VideoMaster error code
   (see VHD_ERRORCODE enumeration)

   See Also
   VHD_StartStream
*/
VIDEOMASTER_HD_API ULONG VHD_StopStream (HANDLE StrmHandle);




/*_ Low-level transfers handling functions __________________________________*/


/*** VHD_LockSlotHandle ************************************************************/
/*!VHD_LockSlotHandle@HANDLE@HANDLE *
   Summary
   VideoMaster slot query
   Description
   This function locks a slot on the stream, and provides a
   handle to the locked slot.



   If no slot is ready, the caller is put asleep until such a
   slot is available, or until the time-out value specified by
   the <link VHD_CORE_STREAMPROPERTY, VHD_CORE_SP_IO_TIMEOUT>
   stream property is reached.

   Every locked slot must be unlocked using VHD_UnlockSlotHandle
   Parameters
   StrmHandle :   Handle of the stream to operate on
   pSlotHandle :  Pointer to a caller\-allocated variable
                  receiving the slot handle
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_UnlockSlotHandle                                          */
VIDEOMASTER_HD_API ULONG VHD_LockSlotHandle (HANDLE StrmHandle, HANDLE *pSlotHandle);


/*** VHD_UnlockSlotHandle **********************************************************/
/*!VHD_UnlockSlotHandle@HANDLE
   Summary
   VideoMaster slot releasing
   Description
   This function unlocks a locked slot. Every locked slot must
   be unlocked using this function
   Parameters
   SlotHandle :  Handle of the slot to operate on
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_LockSlotHandle                                          */
VIDEOMASTER_HD_API ULONG VHD_UnlockSlotHandle (HANDLE SlotHandle);




/*_ Slot management functions ________________________________________________*/


/*** VHD_GetSlotID *****************************************************/
/*!VHD_GetSlotID@HANDLE@ULONG *
   Summary
   VideoMaster slot ID query
   Description
   This function retrieves the ID of the given slot.

   In reception, the ID is a 32-bit counter incremented
   each time a new buffer is received by the hardware. In
   transmission, it is incremented each time the application
   locks a slot.
   Parameters
   SlotHandle :      Handle of the slot to operate on
   pSlotID :         Pointer to a caller\-allocated variable
                     receiving the ID value
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)


   See Also
   VHD_LockSlotHandle                                           */
VIDEOMASTER_HD_API ULONG VHD_GetSlotID (HANDLE SlotHandle, ULONG *pSlotID);


/*** VHD_GetSlotBuffer *****************************************************/
/*!VHD_GetSlotBuffer@HANDLE@ULONG@BYTE **@ULONG *
   Summary
   VideoMaster slot buffer query
   Description
   This function provides pointer to the specified buffer from
   the given locked slot handle
   Parameters
   SlotHandle :   Handle of the slot to operate on
   BufferType :   Set to VHD_SDI_BUFFERTYPE
                  on SDI streams, to VHD_DV_BUFFERTYPE
                  on DVI streams, or to VHD_ASI_BUFFERTYPE
                  on ASI streams
    ppBuffer :    Pointer to a caller\-allocated variable
                  receiving the buffer pointer
   pBufferSize :  Pointer to a caller\-allocated variable
                  receiving the buffer size
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_LockSlotHandle VHD_SDI_BUFFERTYPE VHD_ASI_BUFFERTYPE
   VHD_DV_BUFFERTYPE                                                            */
VIDEOMASTER_HD_API ULONG VHD_GetSlotBuffer (HANDLE SlotHandle, ULONG BufferType, BYTE **ppBuffer, ULONG *pBufferSize);


/*** VHD_GetSlotStatus *****************************************************/
/*!VHD_GetSlotStatus@HANDLE@void **
   Summary
   VideoMaster slot status query
   Description
   This function retrieves the status of the given slot
   Parameters
   SlotHandle :    Handle of the slot to operate on
   ppSlotStatus :  Pointer to a caller\-allocated variable
                   receiving the status pointer
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   The *ppSlotStatus pointer should be casted according to the
   actual stream type.

   Currently, VideoMaster implements ASI, SDI and S2022 slots status only. On
   ASI steams the pointer should thus be casted to a
   VHD_ASI_SLOTSTATUS pointer.
   See Also
   VHD_ASI_SLOTSTATUS VHD_LockSlotHandle VHD_SDI_SLOTSTATUS           */
VIDEOMASTER_HD_API ULONG VHD_GetSlotStatus (HANDLE SlotHandle, void **ppSlotStatus);


/*** VHD_GetSlotSystemTime ****************************************************/
/*!VHD_GetSlotSystemTime@HANDLE@LONGLONG *
   Summary
   Slot system time query
   Description
   This function retrieves the system time sample
   associated to the given slot.
   Parameters
   SlotHandle :      Handle of the slot to operate on
   pSlotSystemTime : Pointer to caller\-allocated variable
                     receiving the slot system time in us
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetSlotSystemTime (HANDLE SlotHandle, LONGLONG *pSlotSystemTime);



/*** VHD_ManufacturerCheck ****************************************************/
/*!
   Summary
   Manufacturer check

   Description
   This function checks that the board belongs to the user supply chain.

   Parameters
   BrdHandle :      Handle of the board to operate on
   Challenge :      An random number on which the branding algorithm will be applied
   pResponse :      Pointer to caller\-allocated variable
                    receiving the response of the challenge

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   See also
   <link Branding>
*/
VIDEOMASTER_HD_API ULONG VHD_ManufacturerCheck(HANDLE BrdHandle, ULONG Challenge, ULONG *pResponse);

/*** VHD_GetSlotParity ****************************************************/
/*!VHD_GetSlotParity@HANDLE@BOOL32 *
   Summary
   Slot parity query
   Description
   This function retrieves the parity
   associated to the given slot.
   Parameters
   SlotHandle :      Handle of the slot to operate on
   pEvenParity_B :   Pointer to caller\-allocated variable
                     receiving the slot parity (TRUE = even, FALSE = ODD)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetSlotParity (HANDLE SlotHandle, BOOL32 *pEvenParity_B);

/*** VHD_SetBiDirCfg ****************************************************/
/*!VHD_SetBiDirCfg@ULONG@ULONG
   Summary
   Bidirectional channel configuration
   Description
   This function defines the channel configuration on bidirectional card
   associated to the given slot.
   Parameters
   BoardIndex :    Zero\-based index of the board to open a
                   handle on
   BiDirCfg_UL :   See VHD_BIDIR_DYNAMIC define, VHD_BIDIRCFG_4C and VHD_BIDIRCFG_8C enumerations

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_SetBiDirCfg(ULONG BoardIndex, ULONG BiDirCfg_UL);

/*** VHD_GetSlot27MhzTimeStamp ****************************************************/
/*!VHD_GetSlot27MhzTimeStamp@HANDLE@LONGLONG *
   Summary
   Slot 27Mhz time stamp query
   Description
   This function retrieves the 27Mhz time stamp sample
   associated to the given slot.
   Parameters
   SlotHandle :      Handle of the slot to operate on
   p27MHzTimeStamp : Pointer to caller\-allocated variable
                     receiving the 27Mhz time stamp
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetSlot27MhzTimeStamp(HANDLE SlotHandle, LONGLONG *p27MHzTimeStamp);

/*** VHD_DetectCompanionCard ****************************************************/
/*!VHD_DetectCompanionCard@HANDLE@VHD_COMPANION_CARD_TYPE@BOOL32 *
   Summary
   Companion card detection
   Description
   This function detects the presence of the companion card
   associated to the given companion card type.
   Parameters
   BoardHandle :        Handle of the board to operate on
   CompanionCardType :  Companion card type
   pCompanionCard :     Pointer to caller\-allocated variable
                        receiving the companion card presence (TRUE = present, FALSE = not present)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration) */
VIDEOMASTER_HD_API ULONG VHD_DetectCompanionCard( HANDLE BoardHandle, VHD_COMPANION_CARD_TYPE CompanionCardType, BOOL32 *pPresentCompanionCard );

/*** VHD_GetTimecode ****************************************************/
/*!VHD_GetTimecode@HANDLE@VHD_TIMECODE_SOURCE@BOOL32 *@float *@VHD_TIMECODE *
   Summary
   Get timecode
   Description
   This function gets the timecode value
   associated to the given timecode source.
   Parameters
   BoardHandle :        Handle of the board to operate on
   TcSource :           Timecode source
   pLocked :            Locked state of the LTC signal (TRUE = locked, FALSE = unlocked)
   pFrameRate :         Framerate of the LTC signal
   pTimeCode :          Pointer to a caller\-allocated variable
                        Timecode packet structure

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Timecode is get in the requested timecode source according to the SMPTE 12M-1-2008 standard */
VIDEOMASTER_HD_API ULONG VHD_GetTimecode(HANDLE BoardHandle, VHD_TIMECODE_SOURCE TcSource, BOOL32 *pLocked, float *pFrameRate, VHD_TIMECODE *pTimeCode);

/*** VHD_GetSlotTimecode ****************************************************/
/*!VHD_GetSlotTimecode@HANDLE@VHD_TIMECODE_SOURCE@VHD_TIMECODE *
   Summary
   Get slot timecode
   Description
   This function looks for timecode value in the requested timecode source synchronized with the
   provided SDI slot.
   Parameters
   SlotHandle :        Handle of the slot to operate on
   TcSource :          Timecode source
   pTimeCode :         Pointer to a caller\-allocated variable
                       Timecode packet structure

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Timecode is get in the requested timecode source according to the
   SMPTE 12M-1-2008 standard */
VIDEOMASTER_HD_API ULONG VHD_GetSlotTimecode(HANDLE SlotHandle, VHD_TIMECODE_SOURCE TcSource, VHD_TIMECODE *pTimeCode);


/*** VHD_GetBoardModel **********************************************************/
/*!VHD_GetBoardModel@ULONG
   Summary
   Get board model

   Description
   This function returns the board model of the selected board index.

   Parameters
   BoardIndex :        Index of the board

   Returns
   The function returns the board model as const char */
VIDEOMASTER_HD_API const char *  VHD_GetBoardModel(ULONG BoardIndex);

/*** VHD_GetBoardCapability ***************************************************/
/*!VHD_GetBoardCapability
   Summary
   VideoMaster board capability query
   Description
   This function retrieves capability of the specified board
   Parameters
   BoardHandle :        Handle of the board to get capability from
   BoardCapability :    Capability to get, must be a value of the various
                        board capabilities enumerations
   pValue :             Pointer to caller\-allocated variable to return
                        capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetBoardCapability(HANDLE BoardHandle, ULONG BoardCapability, ULONG *pValue);

/*** VHD_GetBoardCapBufferPacking ***************************************************/
/*!VHD_GetBoardCapBufferPacking
   Summary
   VideoMaster board capability buffer packing
   Description
   This function retrieves the buffer packing capability of the specified board
   Parameters
   BoardHandle :        Handle of the board to get capability from
   Packing :            Buffer packing to query the board capability for.
                        Must be a member of the VHD_BUFFERPACKING enum.
   pIsCapable :         Pointer to caller\-allocated boolean variable to return
                        the buffer packing capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetBoardCapBufferPacking(HANDLE BoardHandle, VHD_BUFFERPACKING Packing, BOOL32 *pIsCapable);

/*** VHD_GetSlotANCLineInterval ***************************************************/
/*!VHD_GetSlotANCLineInterval
   Summary
   VideoMaster slot ANC line interval query
   Description
   This function retrieves the numbers of the first and last ANC line of the slot.
   Only relevant in case of frame subdivision (low latency mode).
   Parameters
   SlotHandle :         Handle of the slot to operate on
   pFirstANCLineNb :    Pointer to caller\-allocated variable to return
                        the first ANC line number
   pLastANCLineNb :     Pointer to caller\-allocated variable to return
                        the last ANC line number
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetSlotANCLineInterval(HANDLE SlotHandle, ULONG *pFirstANCLineNb, ULONG *pLastANCLineNb);

/*** VHD_GetSlotSubframeIndex ***************************************************/
/*!VHD_GetSlotSubframeIndex
   Summary
   VideoMaster slot sub frame index query
   Description
   This function retrieves the sub frame index and the total number of frame subdivisions.
   Only relevant in case of frame subdivision (low latency mode).
   Parameters
   SlotHandle :         Handle of the slot to operate on
   pSubFrameIdx :       Pointer to caller\-allocated variable to return
                        the sub frame index
   pSubFrameTotalNb :   Pointer to caller\-allocated variable to return
                        the sub frame total number
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_GetSlotSubframeIndex(HANDLE SlotHandle, ULONG *pSubFrameIdx, ULONG *pSubFrameTotalNb);

/*** VHD_GetBufferSize ******************************************/
/*!VHD_GetBufferSize
   Summary
   Video characteristics to buffer size
   Description
   This function converts frame size with additional information
   on framerate and buffer packing into a buffer size.
   Parameters
   Width :           Width
   Height :          Height
   BufferPacking :   Buffer packing (see VHD_BUFFERPACKING enum)
   pBufferSize :     Pointer to caller\-allocated variable
                     receiving the computed buffer size
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetBufferSize(ULONG Width, ULONG Height, VHD_BUFFERPACKING BufferPacking, ULONG* pBufferSize);

/*** VHD_GetPCIeIdentificationString ********************************/
/*!VHD_GetPCIeIdentificationString
   Summary
   PCIe Identification string
   Description
   This function gets the PCIe identification string associated
   to a particular board index.
   This string is formatted as "XX-YY", where X and Y are digits representing a node.
   Each node which is a parent of the board is represented by its unique ID,
   separated by a "-" character.
   Parameters
   BoardIndex:       Board index
   pIdString :       Pointer to caller\-allocated char array
   where the ID string can be written to (size
   should be at least 64 characters)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).*/
VIDEOMASTER_HD_API ULONG VHD_GetPCIeIdentificationString(ULONG BoardIndex, char* pIdString);

/*** VHD_SetStartTime ******************************************/
/*!VHD_SetStartTime
   Summary
   Start time for all streams of a board
   Description
   This function sets the start time of all the streams of
   a given board which are delayed (see VHD_CORE_SP_DELAYED_START).

   The start time is either expressed in the terms of the local
   system (realtime) time or in a user-defined clock system,
   in which case a callback must be provided to the API 
   (see VHD_StartClockReconstruction). 
   Parameters
   BoardHandle :     Handle of the board to operate on
   StartTime :       Start time
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_SetStartTime(HANDLE BoardHandle, LONGLONG StartTime);

/*** VHD_StartClockReconstruction ******************************************/
/*!VHD_StartClockReconstruction
   Summary
   Start the clock reconstruction mechanism
   Description
   This function starts the clock reconstruction mechanism
   with some sets of parameters (see VHD_CLOCK_RECONSTRUCTION_PARAMETERS).

   Note that when the callback passed in the parameter structure is NULL, a default
   callback based on the local system time is used internally.

   Parameters
   Params : Clock reconstruction parameters structure (see VHD_CLOCK_RECONSTRUCTION_PARAMETERS)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_StartClockReconstruction(VHD_CLOCK_RECONSTRUCTION_PARAMETERS Params);
   
/*** VHD_StopClockReconstruction ******************************************/
/*!VHD_StopClockReconstruction
   Summary
   Stop the clock reconstruction mechanism
   Description
   This function stops the clock reconstruction mechanism.
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_StopClockReconstruction();

/*** VHD_GetClockReconstructionConfidence ******************************************/
/*!VHD_GetClockReconstructionConfidence
   Summary
   Clock reconstruction confidence
   Description
   This function gets the current level of confidence of the
   clock reconstruction mechanism, as well as the
   mean reconstruction error expressed in microseconds.

   It is computed as the square root of the mean squared error
   when reevaluating the estimated vs theoretical values.

   Parameters
   VideoStandard : Video standard used as the genlock source signal
                     for which the current confidence level is estimated
   pConfidence : Pointer to caller\-allocated variable
                  receiving the a boolean that is true when the mean error is below half
                  of the period of the video standard
   pStatus : Pointer to caller\-allocated variable
               receiving the status of the mechanism
   pMeanErrorInMicroSeconds : Pointer to caller\-allocated variable
                                 receiving the mean reconstruction error
                                 in microseconds (optional)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_GetClockReconstructionConfidence(ULONG VideoStandard, BOOL32* pConfidence, VHD_FRAME_ACCURACY_PCSYNC_STATUS* pStatus, ULONGLONG* pMeanErrorInMicroSeconds);

/*** VHD_GetClockReconstructionCurrentTime ******************************************/
/*!VHD_GetClockReconstructionCurrentTime
   Summary
   Clock reconstruction current time
   Description
   This function gets the current time in the time reference used by
   the clock reconstruction mechanism, expressed in microseconds.

   Parameters
   pCurrentTime : Pointer to caller\-allocated variable
                     receiving the current time
                     in microseconds
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_GetClockReconstructionCurrentTime(LONGLONG* pCurrentTime);

/*** VHD_GetNbGateways **********************************************************/
/*!VHD_GetNbGateways@ULONG *
   Summary
   Get number of gateways
   Description
   This function provides information about the number
   of detected Deltacast gateway devices
   Parameters
   pNbBoards :    Optional pointer to a variable wherein the
                  library stores the number of detected Deltacast
                  gateway devices
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)       */
VIDEOMASTER_HD_API ULONG VHD_GetNbGateways(ULONG *pNbGateways);

/*** VHD_OpenBoardHandle *****************************************************/
/*!VHD_OpenGatewayHandle@ULONG@HANDLE *
   Summary
   Gateway handle opening
   Description
   This function opens a handle to the specified gateway
   Parameters
   GatewayIndex :       Zero\-based index of the gateway to open a
                           handle on
   pGatewayHandle :     Pointer to a caller\-allocated variable
                           receiving the board handle
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_CloseGatewayHandle                                           */
VIDEOMASTER_HD_API ULONG VHD_OpenGatewayHandle(ULONG GatewayIndex, HANDLE *pGatewayHandle);

/*** VHD_CloseGatewayHandle ****************************************************/
/*!
   Summary
   Gateway handle closing
   Description
   This function closes a gateway handle previously opened with
   VHD_OpenGatewayHandle
   Parameters
   GatewayHandle :   Handle of the gateway to close
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_OpenGatewayHandle
*/
VIDEOMASTER_HD_API ULONG VHD_CloseGatewayHandle(HANDLE GatewayHandle);

/*** VHD_GatewaySync  ****************************************************/
/*!
   Summary
   Trigger gateway sync event
   Description
   This function triggers a "sync" event on a given gateway.
   Parameters
   GatewayHandle :   Handle of the gateway that should generate a sync event
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GatewaySync(HANDLE GatewayHandle);

/*** VHD_GetGatewayCapability ***************************************************/
/*!VHD_GetGatewayCapability
   Summary
   VideoMaster gateway capability query
   Description
   This function retrieves capability of the specified gateway
   Parameters
   GatewayHandle :      Handle of the gateway to get the capability from
   Capability :         Capability to get, must be a value of the
                           VHD_CORE_GATEWAY_CAPABILITY enumeration
   pValue :             Pointer to caller\-allocated variable to return
                           capability value
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetGatewayCapability(HANDLE GatewayHandle, ULONG Capability, ULONG *pValue);

/*** VHD_GetGatewayModel **********************************************************/
/*!VHD_GetGatewayModel@ULONG
   Summary
   Get gateway board model

   Description
   This function returns the gateway board model of the selected board index.

   Parameters
   GatewayIndex :        Index of the board

   Returns
   The function returns the gateway board model as const char */
VIDEOMASTER_HD_API const char* VHD_GetGatewayModel(ULONG GatewayIndex);

/*** VHD_StartTimer ***************************************************/
/*!VHD_StartTimer
   Summary
   Start Genlock Timer Tick Event
   Description
   This function start a Genlock Timer Tick Event
   Parameters
   BoardHandle :           Handle of the board
   Source :                Clock source for a timer
   pTimerHandle :          Pointer to caller\-allocated variable returning the timer handle for interaction
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_StartTimer(HANDLE BoardHandle, VHD_TIMER_SOURCE Source, HANDLE* pTimerHandle);

/*** VHD_WaitOnNextTimerTick ***************************************************/
/*!VHD_WaitOnNextTimerTick
   Summary
   Wait for the next timer tick event
   Description
   This function wait for a timer tick event to happen, acting as a blocking function for the period which has been defined in VHD_StartTimer.
   Parameters
   BoardHandle :           Handle of the timer tick event to work with
   Timeout :               Time in milliseconds after which the (blocking) function returns if the linked timer event doesn't occur.
   Returns :               
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_WaitOnNextTimerTick(HANDLE TimerHandle, ULONG Timeout);

/*** VHD_StopTimer ***************************************************/
/*!VHD_StopTimer
   Summary
   Stop a Genlock Timer Tick Event
   Description
   This function stop a Genlock Timer Tick Event
   Parameters
   BoardHandle :           Handle of the Timer Tick Event to work with
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_StopTimer(HANDLE TimerHandle);

/*** VHD_GetBoardCapTimerSource ***************************************************/
/*!VHD_GetBoardCapTimerSource
   Summary
   Determine the timer source availability for the given device.
   Description
   This function allow the user to determine whether a particular time source is available for the given device.
   Parameters
   BoardHandle :           Handle of the Timer Tick Event to work with
   Source :                Clock source for a timer among VHD_TIMER_SOURCE enumerations
   pIsCapable :            Pointer to caller\-allocated variable to return if time source is available for the given device
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetBoardCapTimerSource(HANDLE BoardHandle, VHD_TIMER_SOURCE Source, BOOL32 *pIsCapable);

/*** VHD_GetGatewayProperty ***************************************************/
/*!VHD_GetGatewayProperty
   Summary
   VideoMaster gateway property query

   Description
   This function retrieves value of the specified Gateway property.

   Parameters
   GatewayHandle :   Handle of the Gateway to get property from
   Property :        Property to get, must be a value of the various
                     gateway properties enumerations
   pValue :          Pointer to caller\-allocated variable to return
                     property value

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)

   See Also
   VHD_CORE_GATEWAYPROPERTY                                */
VIDEOMASTER_HD_API ULONG VHD_GetGatewayProperty(HANDLE GatewayHandle, ULONG Property, ULONG *pValue);

/*** VHD_GatewayFirmwareUpdate ***************************************************/
/*!VHD_GatewayFirmwareUpdate
   Summary
   VideoMaster gateway firmware update

   Description
   This function updates the given firmware to the corresponding component.

   Parameters
   GatewayIndex :          Zero\-based index of the gateway to update
   pData :                 Address of a pointer to directly access the FW binary data buffer from within the API
   DataSize :              Data size of the FW binary
   pCompletionCallback :   Callback used to retrieve the completion percent.
                           The callback, when called, should return the current completion percent for the user (in percent).
                           This parameters is optional and can be NULL.

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_GatewayFirmwareUpdate(ULONG GatewayIndex, UBYTE *pData, ULONG DataSize, FwUpdateCallback_t pCompletionCallback);

/*** VHD_BoardFirmwareUpdate ***************************************************/
/*!VHD_BoardFirmwareUpdate
   Summary
   VideoMaster board firmware Update

   Description
   This function updates the given firmware to the corresponding component.
   property

   Parameters
   BoardIndex :            Zero\-based index of the board to update
   pData :                 Address of a pointer to directly access the FW binary data buffer from within the API
   DataSize :              Data size of the FW binary
   pCompletionCallback :   Callback used to retrieve the completion percent.
                           The callback, when called, should return the current completion percent for the user (in percent).
                           This parameters is optional and can be NULL.
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_BoardFirmwareUpdate(ULONG BoardIndex, UBYTE *pData, ULONG DataSize, FwUpdateCallback_t pCompletionCallback);

/*** VHD_GetBoardConfigSet ***************************************************/
/*!VHD_GetBoardConfigSet
   Summary
   VideoMaster get board config set

   Description
   This function retrieves the board config set linked to the board.
   property

   Parameters
   BoardIndex :       Board index
   pConfigSetType :   Address of a pointer to directly access the config set type from within the API

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_GetBoardConfigSet(ULONG BoardIndex, VHD_BRD_CONFIG *pConfigSetType);

/*** VHD_GetBoardFirmwareInfo ***************************************************/
/*!VHD_GetBoardFirmwareInfo
   Summary
   VideoMaster get board FW information

   Description
   This function retrieves the board FW information linked to the FW type.

   Parameters
   BoardIndex :            Board index
   FirmwareType :          Firmware type
   pFWVersion :            Pointer to a caller-allocated variable to store the FW version
   pRequestedFWVersion :   Pointer to a caller-allocated variable to store the requested FW version
   ppFWName :              Address of a pointer where the address of the FW name string is stored
   pFWNameSize :           Pointer to a caller-allocated variable where the size of the binary is stored
   pRestartNeeded :        Pointer to a caller-allocated variable to store whether or not a restart is needed

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_GetBoardFirmwareInfo(ULONG BoardIndex, VHD_BRD_FIRMWARE_TYPE FirmwareType, ULONG *pFWVersion, ULONG *pRequestedFWVersion, const char **ppFWName, ULONG *pFWNameSize, BOOL32 *pRestartNeeded);

/*** VHD_GetGatewayFirmwareInfo ***************************************************/
/*!VHD_GetGatewayFirmwareInfo
   Summary
   VideoMaster get gateway FW information

   Description
   This function retrieves the gateway FW information linked to the FW type.

   Parameters
   GatewayIndex :          Gateway index
   FirmwareType :          Firmware type
   pFWVersion :            Pointer to a caller-allocated variable to store the FW version
   pRequestedFWVersion :   Pointer to a caller-allocated variable to store the requested FW version
   ppFWName :              Address of a pointer where the address of the FW name string is stored
   pFWNameSize :           Pointer to a caller-allocated variable where the size of the binary is stored
   pRestartNeeded :        Pointer to a caller-allocated variable to store whether or not a restart is needed

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_GetGatewayFirmwareInfo(ULONG GatewayIndex, VHD_GTW_FIRMWARE_TYPE FirmwareType, ULONG *pFWVersion, ULONG *pRequestedFWVersion, const char **ppFWName, ULONG *pFWNameSize, BOOL32 *pRestartNeeded);

/*** VHD_GetBoardConfigFWName ***************************************************/
/*!VHD_GetBoardConfigFWName
   Summary
   VideoMaster get board config FW name

   Description
   This function retrieves the board configuration FW name.

   Parameters
   BoardIndex :    Gateway index
   FirmwareType :  Firmware type
   BoardConfig :   Board configuration
   ppFWName :      Address of a pointer where the address of the FW name string is stored 
   pFWNameSize :   Pointer to a caller-allocated variable where the size of the binary is stored

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_GetBoardConfigFWName(ULONG BoardIndex, VHD_BRD_FIRMWARE_TYPE FirmwareType, VHD_BRD_CONFIG BoardConfig, const char **ppFWName,  ULONG *pFWNameSize);

/*** VHD_SetBoardConfig ***************************************************/
/*!VHD_SetBoardConfig
   Summary
   VideoMaster set board config

   Description
   This function setups the board config.
   property

   Parameters
   BoardIndex :            Zero\-based index of the board to change the config
   BoardConfig :           Board configuration

   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)            
*/
VIDEOMASTER_HD_API ULONG VHD_SetBoardConfig(ULONG BoardIndex, VHD_BRD_CONFIG BoardConfig);

/*** VHD_StreamsReadyForGatewaySync ***************************************************/
/*!VHD_StreamsReadyForGatewaySync
   Summary
   VideoMaster streams ready for gateway sync
   Description
   This function determines whether all streams started and marked as VHD_FRAME_ACCURACY_TYPE_FLEX
   are ready to receive a gateway sync signal through VHD_GatewaySync.
   Parameters
   pStreamsReady : Address of a pointer to directly access the readiness of the streams from within the API

   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_StreamsReadyForGatewaySync(BOOL32 *pStreamsReady);

/*** VHD_GetSoftwareBufferFilling ***************************************************/
/*!VHD_GetSoftwareBufferFilling
   Summary
   Get buffer filling for a given slot and buffer type
   Description
   This function retrieves the buffer filling for a given slot and buffer type.
   Parameters
   SlotHandle :         Handle of the slot to operate on
   BufferType :         Set to VHD_SDI_BUFFERTYPE on SDI streams,
                           to VHD_DV_BUFFERTYPE on DVI streams,
                           to VHD_ASI_BUFFERTYPE on ASI streams
                           to VHD_ST2110_BUFFERTYPE on ST2110 streams
   pValue :             Pointer to caller\-allocated variable to return
                           buffer filling value.
                           For a given buffer, the value increases for successive calls to this function,
                           until the whole buffer size is returned (meaning that the buffer has been fully captured).

                           For most buffer types, the value is expressed as number of bytes.
                           The only exceptions are ANC buffer types, where the value is expressed in terms of lines.
                           This exception is only valid if ANC are manipulated through our dedicated ANC functions.
                           If, on the other hand, the buffers are accessed directly, the buffer filling is expressed in bytes.
   pIsFullyCaptured     Pointer to caller\-allocated variable to return
                           TRUE when the buffer has been completely captured.

   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_GetSoftwareBufferFilling(HANDLE SlotHandle, ULONG BufferType, ULONG *pValue, BOOL32 *pIsFullyCaptured);
   
/*** VHD_SetSoftwareBufferFilling ***************************************************/
/*!VHD_SetSoftwareBufferFilling
   Summary
   Set buffer filling for a given slot and buffer type
   Description
   This function sets the buffer filling for a given slot and buffer type.
   Parameters
   SlotHandle :         Handle of the slot to operate on
   BufferType :         Set to VHD_SDI_BUFFERTYPE on SDI streams,
                           to VHD_DV_BUFFERTYPE on DVI streams,
                           to VHD_ASI_BUFFERTYPE on ASI streams
                           to VHD_ST2110_BUFFERTYPE on ST2110 streams
   Value :              Buffer filling to set.
                        For a given buffer, the value should increase for successive calls to this function.
                        It represents how much of the buffer is accessible for the HW to generate a valid signal.
                        This value is therefore limited by the actual buffer size.

                        For most buffer types, the value is expressed as number of bytes.
                        The only exceptions are ANC buffer types, where the value is expressed in terms of lines.
                        This exception is only valid if ANC are manipulated through our dedicated ANC functions.
                        If, on the other hand, the buffers are accessed directly, the buffer filling is expressed in bytes.
   BufferComplete :     States whether the call completes the buffer and no more data is expected
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
*/
VIDEOMASTER_HD_API ULONG VHD_SetSoftwareBufferFilling(HANDLE SlotHandle, ULONG BufferType, ULONG Value, BOOL32 BufferComplete);

/*** VHD_CorrectStartTime ******************************************/
/*!VHD_CorrectStartTime
   Summary
   Correct a start time based on the board information
   Description
   This function corrects the start time as per the genlock
   information retrieved from the board handle.

   The start time is either expressed in the terms of the local
   system (realtime) time or in a user-defined clock system,
   in which case a callback must be provided to the API 
   (see VHD_StartClockReconstruction).

   This function is especially useful when dealing with multiple platforms
   where the start time could theoretically be corrected differently leading
   to unsynchronized start of streams.
   Only correcting the start time once and propagating that corrected one
   ensures that this situation cannot happen.
   Parameters
   BoardHandle :           Handle of the board to operate on
   StartTime :             Start time
   pCorrectedStartTime :   Pointer to caller\-allocated variable where the corrected start time
                              is returned
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration).
*/
VIDEOMASTER_HD_API ULONG VHD_CorrectStartTime(HANDLE BoardHandle, LONGLONG StartTime, LONGLONG* pCorrectedStartTime);


#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS


#endif // _VIDEOMASTERHD_CORE_H_
