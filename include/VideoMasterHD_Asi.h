/*! VideomasterHD_Asi.h

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


#ifndef _VIDEOMASTERHD_ASI_H_
#define _VIDEOMASTERHD_ASI_H_


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Asi
*/

#define VHD_MAXNB_PIDFILTER 256 /*! Maximum amount of PID filtered per input stream */

   /*! Clock status bit masks. These constants define status bit masks for the VHD_ASI_BP_CLK_STATUS board properties */
#define VHD_ASI_CLKSTS_INVALID      0x00000001  /*!VHD_ASI_CLKSTS_INVALID
                                                   Invalid reference clock                                   */


   /*! RX channel status bit masks. These constants define status bit masks for the VHD_CORE_BP_RXx_STATUS board properties */
#define VHD_ASI_RXSTS_BITRATE_FAIL  0x00000004  /*!VHD_ASI_RXSTS_BITRATE_FAIL
                                                   RX channel bitrate failure indicator. This bit is set to '1'
                                                   in <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_RXi_STATUS>
                                                   board properties when the difference between the incoming
                                                   bitrate and the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_BITRATE>
                                                   is bigger than the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_ALLOWED_BR_DEV>. */
#define VHD_ASI_RXSTS_FRAMING_ERR 0x00000008  /*!VHD_ASI_RXSTS_FRAMING_ERR
                                                 RX channel framing error indicator. This bit is set to '1' in
                                                 <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_RXi_STATUS> board
                                                 properties when the MPEG sync_byte (0x47) doesn't repeat
                                                 every 188 byte (or 204 according to the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_PACKET_TYPE>). */


   /*! TX channel status bit masks. These constants define status bit masks for the VHD_CORE_BP_RXx_STATUS board properties */
#define VHD_ASI_TXSTS_BITRATE_FAIL  0x00000004  /*!VHD_ASI_TXSTS_BITRATE_FAIL
                                                   TX channel bitrate failure indicator. This bit is set to '1'
                                                   in <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_TXi_STATUS>
                                                   board properties when the difference between the incoming
                                                   source bitrate and the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_BITRATE>
                                                   is bigger than the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_ALLOWED_BR_DEV>. */
#define VHD_ASI_TXSTS_FRAMING_ERR 0x00000008  /*!VHD_ASI_TXSTS_FRAMING_ERR
                                                 TX channel framing error indicator. This bit is set to '1' in
                                                 <link VHD_CORE_BOARDPROPERTY, VHD_CORE_BP_TXi_STATUS> board
                                                 properties when the sync byte (0x47) doesn't repeat every 188
                                                 byte (or 204 according to the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_PACKET_TYPE>). */

/*_ VideomasterHD_Asi DATA TYPE __________________________________________________*/
/*! Data types bit masks. These constants define data type bit masks for the VHD_CORE_SP_MUTED_DATA_MASK stream property */
#define VHD_ASI_DATA_TS           0x00000001  /*! Transport stream data */

#define VHD_ASI_BITRATE_HIGHPRECISION_FACTOR    1000000  /*!VHD_ASI_BITRATE_HIGHPRECISION_FACTOR
                                                            Multiplicative factor between high-precision bitrate and standard-precision bitrate.
                                                            It expresses the fact that up to 6 decimals are considered for high-precision bitrates.
                                                            Since properties are encoded with unsigned integers, this constant allows one to
                                                            define a floating point bitrate and multiply it by this value to get a high-precision
                                                            bitrate ready to be set.
                                                            <link VHD_ASI_SP_BITRATE_HIGH_PRECISION_MSB, VHD_ASI_SP_BITRATE_HIGH_PRECISION_LSB>
                                                            */


/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Asi
*/

/*_ VHD_ASI_BOARDPROPERTY ______________________________________________*/
/*!
Summary
VideoMaster ASI boards properties

Description
The VHD_ASI_BOARDPROPERTY enumeration lists all the available ASI
board properties.

These values are used as indexes for VHD_GetBoardProperty and 
VHD_SetBoardProperty functions calls.

See Also
VHD_GetBoardProperty
VHD_SetBoardProperty
*/
typedef enum _VHD_ASI_BOARDPROPERTY
{
   VHD_ASI_BP_CLK_SOURCE =ENUMBASE_ASI,            /*!_VHD_ASI_BOARDPROPERTY::VHD_ASI_BP_CLK_SOURCE
                                                      Board clock source selection (see VHD_ASI_CLOCKSOURCE),
                                                      default is VHD_ASI_CLK_SRC_LOCAL. */
   VHD_ASI_BP_EXT1_SOURCE_DEPRECATED,                         /*!_VHD_ASI_BOARDPROPERTY::VHD_ASI_BP_EXT1_SOURCE
                                                      Board output external connector source selection (see VHD_ASI_EXT1SOURCE),
                                                      default is VHD_ASI_EXT1SRC_NONE. */
   VHD_ASI_BP_CLK_STATUS,                          /*!_VHD_ASI_BOARDPROPERTY::VHD_ASI_BP_CLK_STATUS
                                                      Clock status (see VHD_ASI_CLKSTS_xxx). */
   VHD_ASI_BP_EXTCLK1_ENABLE,                      /*!_VHD_ASI_BOARDPROPERTY::VHD_ASI_BP_EXTCLK1_ENABLE
                                                      External clock 1 control (TRUE = enable, FALSE = disable),
                                                      default is FALSE. */
   VHD_ASI_BP_ACTIVE_LOOPBACK_0,                   /*!_VHD_ASI_BOARDPROPERTY::VHD_ASI_BP_ACTIVE_LOOPBACK_0
                                                      RX0-TX0 active loopback control (TRUE = enable, FALSE = disable) 
                                                      default is FALSE. */
   NB_VHD_ASI_BOARDPROPERTIES
} VHD_ASI_BOARDPROPERTY;

#define VHD_ASI_BP_EXT1_SOURCE     VHD_ASI_BP_EXT1_SOURCE_DEPRECATED  /*! Backward compatibility */       


/*_ VHD_ASI_STREAMPROPERTY ______________________________________________*/
/*!
Summary
VideoMaster ASI streams properties

Description
The VHD_ASI_STREAMPROPERTY enumeration lists all the available ASI
stream properties.

These values are used as indexes for VHD_GetStreamProperty and 
VHD_SetStreamProperty functions calls.

See Also
VHD_GetStreamProperty
VHD_SetStreamProperty
*/
typedef enum _VHD_ASI_STREAMPROPERTY
{
   VHD_ASI_SP_PACKET_TYPE=ENUMBASE_ASI,         /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_PACKET_TYPE
                                                   When written, this property configures the type of TS packets
                                                   and operation on that stream, taken from the
                                                   VHD_ASI_TSPACKETTYPE enumeration (default is VHD_ASI_PKT_188).
                                                   
                                                   When read on a reception stream, it provides the actual
                                                   incoming packet type                                        */
   VHD_ASI_SP_BUFFER_SIZE,                      /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BUFFER_SIZE
                                                   Specifies the buffer size (in bytes). This size must be a
                                                   multiple of the ASI packet size which depends on the
                                                   VHD_ASI_SP_PACKET_TYPE and the VHD_ASI_SP_RX_TIMESTAMP
                                                   properties, hence 188 or 204 bytes, plus 8 bytes if RX time
                                                   stamping is enabled. There is no such restriction on a
                                                   VHD_ASI_PKT_RAW stream. 

                                                   The size must be a multiple of 64 bytes on the DELTA-asi. 
                                                  
                                                   Minimum buffer size is 0x800, maximum is 0x800000 for a DELTA-mixed 
                                                   asi and 0x100000 for a DELTA-asi, default is 0x800.
                                                   
                                                   You should note that the buffer size will have a big
                                                   influence on the latency and performances. A big buffer size
                                                   will increase latency. A small buffer size will decrease
                                                   performances because DMA transfer overhead. You should take
                                                   into account the bitrate to compute the appropriate
                                                   trade-off.  */
   VHD_ASI_SP_BITRATE,                          /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BITRATE
                                                   When written, this property specifies the bitrate to output
                                                   on a transmission stream, if using its local bitrate
                                                   generator. This bitrate value is expressed in units of bps
                                                   (bits per second), and may range from 100 kbps to 214 Mbps.
                                                   On reception streams, this field may be optionally used to
                                                   program a reference value for incoming bitrate estimation
                                                   (default is 100000).
                                                   
                                                   When read on reception streams, it provides the actual
                                                   incoming bitrate. On transmission streams, it monitors the
                                                   incoming source bitrate if <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_TX_BITRATE_SRC>
                                                   is not <link VHD_ASI_BITRATESOURCE, VHD_ASI_BR_SRC_LOCAL>   */
   VHD_ASI_SP_TX_BITRATE_SRC,                   /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_TX_BITRATE_SRC
                                                   Specifies the bitrate source to use on a transmission stream,
                                                   taken from the VHD_ASI_BITRATESOURCE enumeration. Unused on
                                                   reception streams (default is VHD_ASI_BR_SRC_LOCAL)         */
   VHD_ASI_SP_BACKUP_BITRATE,                   /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BACKUP_BITRATE
                                                   For TX streams, enable/disable automatic switching to a
                                                   backup bitrate generator in case of a non-local bitrate
                                                   source failure, ie. when the difference between the incoming
                                                   source bitrate and the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_BITRATE>
                                                   is bigger than the programmed <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_ALLOWED_BITRATE_DEV>
                                                   (default is FALSE)
                                                   Unused on reception streams                                 */
   VHD_ASI_SP_BITRATE_INT_PERIOD,               /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BITRATE_INT_PERIOD
                                                   Bitrate monitor integration period, chosen from the VHD_ASI_BRINTPERIOD enumeration.
                                                   (default is VHD_ASI_INTPER_100)                             */
   VHD_ASI_SP_ALLOWED_BITRATE_DEV,              /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_ALLOWED_BITRATE_DEV
                                                   Maximum allowed bitrate deviation, given in bps. See <link Bitrate Monitoring>
                                                   topic for details.
                                                   ( minimum is 0, maximum is 100000000, default is 100000000)       */
   VHD_ASI_SP_RX_TIMESTAMP,                     /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_RX_TIMESTAMP
                                                   TRUE to enable packet time stamping on reception stream,
                                                   FALSE to disable it. Unused on transmission streams.
                                                   (default is FALSE)                                          */
   VHD_ASI_SP_SYNCHRONOUS_SLAVING_DEPRECATED,   /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_SYNCHRONOUS_SLAVING
                                                    Deprecated */
   VHD_ASI_SP_BYTE_MODE,                        /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BYTE_MODE
                                                   On transmission streams, specifies the transmission mode. 
                                                   If TRUE, the stream transmits in byte mode. 
                                                   If FALSE, the stream transmits in packet mode.
                                                   On reception streams, auto-detect the reception mode.
                                                   If TRUE, the stream is in byte mode.
                                                   If FALSE, the stream is in packet mode. */
   VHD_ASI_SP_POLARITY,                         /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_POLARITY
                                                   Defines the polarity of the reception <link VHD_ASI_POLARITY> */
   VHD_ASI_SP_BITRATE_HIGH_PRECISION_MSB,       /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BITRATE_HIGH_PRECISION_MSB
                                                   When written, this property specifies the most-significant bits
                                                   of the high-precision bitrate to output
                                                   on a transmission stream, if using its local bitrate
                                                   generator. This combined bitrate value is expressed in millionth of units of bps
                                                   (bits per second), and may range from 100 kbps to 214 Mbps.
                                                   On reception streams, this field may be optionally used to
                                                   program a reference value for incoming bitrate estimation
                                                   (default is 100000).

                                                   Application has to configure the VHD_ASI_SP_BITRATE_HIGH_PRECISION_LSB
                                                   first and then the VHD_ASI_SP_BITRATE_HIGH_PRECISION_MSB.
                                                   
                                                   When read on reception streams, it provides the actual
                                                   incoming bitrate. On transmission streams, it monitors the
                                                   incoming source bitrate if <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_TX_BITRATE_SRC>
                                                   is not <link VHD_ASI_BITRATESOURCE, VHD_ASI_BR_SRC_LOCAL>   */
   VHD_ASI_SP_BITRATE_HIGH_PRECISION_LSB,       /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_BITRATE_HIGH_PRECISION_LSB
                                                   When written, this property specifies the least-significant bits
                                                   of the high-precision bitrate to output
                                                   on a transmission stream, if using its local bitrate
                                                   generator. The combined bitrate value is expressed in millionth of units of bps
                                                   (bits per second), and may range from 100 kbps to 214 Mbps.
                                                   On reception streams, this field may be optionally used to
                                                   program a reference value for incoming bitrate estimation
                                                   (default is 100000).

                                                   Application has to configure the VHD_ASI_SP_BITRATE_HIGH_PRECISION_LSB
                                                   first and then the VHD_ASI_SP_BITRATE_HIGH_PRECISION_MSB.
                                                   
                                                   When read on reception streams, it provides the actual
                                                   incoming bitrate. On transmission streams, it monitors the
                                                   incoming source bitrate if <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_TX_BITRATE_SRC>
                                                   is not <link VHD_ASI_BITRATESOURCE, VHD_ASI_BR_SRC_LOCAL>   */
   VHD_ASI_SP_USE_LOCAL_CLK,                       /*!_VHD_ASI_STREAMPROPERTY::VHD_ASI_SP_USE_LOCAL_CLK
                                                   TRUE to enable the stream to use the 27MHz ASI local clock source,
                                                   FALSE to use the SDI genlock circuitry. only available on mixed type channels.
                                                   (default is FALSE)                                          */
   NB_VHD_ASI_STREAMPROPERTIES
} VHD_ASI_STREAMPROPERTY;

#define VHD_ASI_SP_SYNCHRONOUS_SLAVING     VHD_ASI_SP_SYNCHRONOUS_SLAVING_DEPRECATED  /*! Backward compatibility */       


/*_ VHD_ASI_STREAMPROCMODE ________________________________________*/
/*!
Summary
VideoMaster ASI streams processing modes

Description
The VHD_ASI_STREAMPROCMODE enumeration lists all the ASI stream 
processing modes.

These values are used during VHD_OpenStreamHandle function calls.

See Also
VHD_OpenStreamHandle
*/
typedef enum _VHD_ASI_STREAMPROCMODE
{
   VHD_ASI_STPROC_DEFAULT=ENUMBASE_ASI,         /*! Default ASI processing */
   NB_VHD_ASI_STREAMPROCMODE                    
} VHD_ASI_STREAMPROCMODE;

/*_ VHD_ASI_BUFFERTYPE ________________________________________*/
/*!
   Summary
   VideoMaster ASI buffer type
   Description
   The VHD_ASI_BUFFERTYPE enumeration lists all the ASI buffer
   types.
   
   These values are used during VHD_GetSlotBuffer function
   calls.
   See Also
   VHD_GetSlotBuffer
   Remarks
   Currently, only one buffer type is available     
   */

typedef enum _VHD_ASI_BUFFERTYPE
{
   VHD_ASI_BT_TS = 0,             /*! ASI transport stream buffer type */
   NB_VHD_ASI_BUFFERTYPE
} VHD_ASI_BUFFERTYPE;


/*_ VHD_ASI_BITRATESOURCE _____________________________________________*/
/*!
   Summary
   Videomaster ASI bitrate source
   Description
   The VHD_ASI_BITRATESOURCE enumeration lists all supported
   bitrate sources used in <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_TX_BITRATE_SRC>
   stream property.
   Remarks
   The bitrate source selection is particularly useful to slave
   one transmission stream to a incoming ASI bitrate.
   See Also
   <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_TX_BITRATE_SRC>                         */
typedef enum _VHD_ASI_BITRATESOURCE
{
   VHD_ASI_BR_SRC_LOCAL = 0,                 /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL
                                                Selects the local bitrate generator */
   VHD_ASI_BR_SRC_RX0,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_RX0
                                                Selects the RX0 ASI channel bitrate. */
   VHD_ASI_BR_SRC_RX1,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_RX1
                                                Selects the RX1 ASI channel bitrate. */
   VHD_ASI_BR_SRC_EXT0,                      /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_EXT0
                                                Selects the EXT0 bitrate.*/
   VHD_ASI_BR_SRC_RX2,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL
                                                Selects the RX2 ASI channel bitrate. */
   VHD_ASI_BR_SRC_RX3,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL
                                                Selects the RX3 ASI channel bitrate. */
   VHD_ASI_BR_SRC_RX4,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the RX4 ASI channel bitrate. */
   VHD_ASI_BR_SRC_RX5,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the RX5 ASI channel bitrate. */
   VHD_ASI_BR_SRC_RX6,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the RX6 ASI channel bitrate. */
   VHD_ASI_BR_SRC_RX7,                       /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the RX7 ASI channel bitrate. */
   VHD_ASI_BR_SRC_GPIO_0,                    /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the GPIO 0 as ASI channel bitrate. */
   VHD_ASI_BR_SRC_GPIO_1,                    /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the GPIO 1 as ASI channel bitrate. */
   VHD_ASI_BR_SRC_GPIO_2,                    /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the GPIO 2 as ASI channel bitrate. */
   VHD_ASI_BR_SRC_GPIO_3,                    /*!_VHD_ASI_BITRATESOURCE::VHD_ASI_BR_SRC_LOCAL 
                                                Selects the GPIO 3 as ASI channel bitrate. */
   NB_VHD_ASI_BITRATESOURCE
} VHD_ASI_BITRATESOURCE;


/*_ VHD_ASI_CLOCKSOURCE _____________________________________________*/
/*!
   Summary
   Videomaster ASI clock source
   Description
   The VHD_ASI_CLOCKSOURCE enumeration defines values that are used to specify 
   a TX channel 27 MHz reference clock source on the DELTA-asi board. 

   When the selected clock is not VHD_ASI_CLKSRC_LOCAL, an onboard clock 
   monitoring circuitry will be provided with an automatic switch 
   to/from a local backup clock in case of failure/recovery of the selected 
   clock source. 

   This enumeration is used in <link VHD_ASI_BOARDPROPERTY, VHD_ASI_BP_CLK_SOURCE> 
   board property to select the board reference clock. 
   
   See Also
   <link VHD_ASI_BOARDPROPERTY, VHD_ASI_BP_CLK_SOURCE>                         */
typedef enum _VHD_ASI_CLOCKSOURCE
{
   VHD_ASI_CLKSRC_LOCAL,            /*! Selects the local clock. */
   VHD_ASI_CLKSRC_RX0,              /*! Retrieves clock from RX0 channel. */
   VHD_ASI_CLKSRC_RX1,              /*! Retrieves clock from RX1 channel. */
   VHD_ASI_CLKSRC_EXT0,             /*! Retrieves clock from ext0 connector. */
   VHD_ASI_CLKSRC_RX2,              /*! Retrieves clock from RX2 channel. */
   VHD_ASI_CLKSRC_RX3,              /*! Retrieves clock from RX3 channel. */
   VHD_ASI_CLKSRC_RX4,              /*! Retrieves clock from RX4 channel. */
   VHD_ASI_CLKSRC_RX5,              /*! Retrieves clock from RX5 channel. */
   VHD_ASI_CLKSRC_RX6,              /*! Retrieves clock from RX6 channel. */
   VHD_ASI_CLKSRC_RX7,              /*! Retrieves clock from RX7 channel. */
   NB_VHD_ASI_CLOCKSOURCE
}VHD_ASI_CLOCKSOURCE;

/*_ VHD_ASI_EXT1SOURCE _____________________________________________*/
/*!
Summary
Videomaster ASI supported ext1 source.
Description
The VHD_ASI_EXT1SOURCE enumeration lists all supported
ext1 connector sources used in <link VHD_ASI_BOARDPROPERTY, VHD_ASI_BP_EXT1_SOURCE>
board property.
See Also
<link VHD_ASI_BOARDPROPERTY, VHD_ASI_BP_EXT1_SOURCE>                         */
typedef enum _VHD_ASI_EXT1SOURCE
{
	VHD_ASI_EXT1SRC_NONE,             /*! No output on EXT1 (line in tristate) */
	VHD_ASI_EXT1SRC_CLK,              /*! Output selected board 27MHz reference on EXT1 */
	VHD_ASI_EXT1SRC_RX0_BR,           /*! Output RX0 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX1_BR,           /*! Output RX1 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX2_BR,           /*! Output RX2 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX3_BR,           /*! Output RX3 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX4_BR,           /*! Output RX4 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX5_BR,           /*! Output RX5 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX6_BR,           /*! Output RX6 incoming bitrate on EXT1. The channel must be running */
	VHD_ASI_EXT1SRC_RX7_BR,           /*! Output RX7 incoming bitrate on EXT1. The channel must be running */
	NB_VHD_ASI_EXT1SOURCE
}VHD_ASI_EXT1SOURCE_DEPRECATED;

#define VHD_ASI_EXT1SOURCE     VHD_ASI_EXT1SOURCE_DEPRECATED  /*! Backward compatibility */       


/*_ VHD_ASI_TSPACKETTYPE _______________________________________________________*/
/*!
   Summary
   Videomaster ASI transport stream packet type
   Description
   The VHD_ASI_TSPACKETTYPE enumeration lists all supported
   transport stream packet type used in VHD_ASI_SP_PACKET_TYPE
   stream property.
   Remarks
   Although the MPEG-2 standard specified 188-bytes long TS
   packets, some DVB streams may extend this packet size to
   204-byte to carry forward error correction data (FEC).
   
   It is important to note that the DELTACAST boards do not
   manage FEC, but may configure their re-framing engines and
   acquisition modes to support these packet sizes.
   
   
   
   Thus, on ASI reception streams :
   
     * When a value of VHD_ASI_PKT_188 or VHD_ASI_PKT_204 is
       chosen, the framing check will be performed on the desired
       size, and packets of that length will be transmitted to the
       caller
     * When the VHD_ASI_PKT_204d188 value is chosen, the framing
       check will be performed on a 204&#45;byte basis, while only
       the 188 first bytes of each packet will be transmitted to the
       caller
     * The VHD_ASI_PKT_188e204 value is forbidden
     * When the VHD_ASI_PKT_RAW value is chosen, no framing
       check will be performed on incoming data, and thus all the
       received bytes will be transmitted to the caller
   
   And, on ASI transmission streams :
   
     * When a value of VHD_ASI_PKT_188 or VHD_ASI_PKT_204 is
       chosen, the framing check will be performed on the desired
       size, which is also the length of the packets transmitted by
       the caller
     * When the VHD_ASI_PKT_204d188 value is chosen, the caller
       will supply 204&#45;byte packets to StreamMaster, but only
       the 188 first bytes of each one will be transmitted
     * When the VHD_ASI_PKT_188e204 value is chosen, the framing
       check will be performed on a 188&#45;byte basis, but the
       on&#45;board transmitter will adjust its timings to let room
       for 16 additional bytes in the signal
     * When the VHD_ASI_PKT_RAW value is chosen, no framing
       check will be performed, and all the bytes will be
       transmitted
   See Also
   <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_PACKET_TYPE>             */
typedef enum _VHD_ASI_TSPACKETTYPE
{
   VHD_ASI_PKT_188 = 0,                       /*! 188-byte TS packets */
   VHD_ASI_PKT_188e204,                       /*! 188-byte TS packets, extended to 204 bytes */
   VHD_ASI_PKT_204,                           /*! 204-byte TS packets */
   VHD_ASI_PKT_204d188,                       /*! 204-byte TS packets, stripped down to 188 bytes */
   VHD_ASI_PKT_RAW,                           /*! Specifies raw data mode (no re-framing) */
   NB_VHD_ASI_TSPACKETTYPE
} VHD_ASI_TSPACKETTYPE;



/*_ VHD_ASI_BRINTPERIOD ____________________________________________*/
/*!
   Summary
   Videomaster ASI bitrate integration period
   Description
   The VHD_ASI_BRINTPERIOD enumeration lists all supported
   bitrate integration period used in VHD_ASI_SP_BR_INT_PERIOD
   stream property.
   Remarks
   The bitrate monitor is used on ASI reception streams to
   estimate the incoming bitrate.
   
   When programming the bitrate integration period, one should
   take care of the bitrate the channel will run. In fact,
   programming a one second integration period over a stream at
   100 Mbps will overflow the hardware bitrate monitor. It is
   thus advised to use small integration periods when the
   bitrate goes too high, and reserve large integration periods
   for low-bitrate use cases.
   See Also
   <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_BR_INT_PERIOD>      */
typedef enum _VHD_ASI_BRINTPERIOD
{
   VHD_ASI_INTPER_1 = 0,              /*! 1 msec integration period */
   VHD_ASI_INTPER_10,                 /*! 10 msec integration period */
   VHD_ASI_INTPER_100,                /*! 100 msec integration period */
   VHD_ASI_INTPER_1000,               /*! 1000 msec integration period */
   NB_VHD_ASI_BRINTPERIOD
} VHD_ASI_BRINTPERIOD;

/*_ VHD_ASI_BOARD_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster ASI board capability
  Description
  The VHD_ASI_BOARD_CAPABILITY enumeration lists all the available ASI board capabilities
   
  These values are used in VHD_GetBoardCapability function
  See Also
  <link VHD_GetBoardCapability>
*/
typedef enum _VHD_ASI_BOARD_CAPABILITY
{
   VHD_ASI_BOARD_CAP_EXT_CLK_SRC = ENUMBASE_ASI,         /*! Return true if the board supports external clock source handling feature*/
   VHD_ASI_BOARD_CAP_BITRATE_MAX,                        /*! Returns the maximum bit rate supported by the board */
   VHD_ASI_BOARD_CAP_BYTE_VS_PACKET_MODE_SEL,            /*! Returns TRUE if the board support byte and packet modes. See <link VHD_ASI_SP_BYTE_MODE>  */
   VHD_ASI_BOARD_CAP_POLARITY,                           /*! Returns TRUE if the board support polarity configuration. See <link VHD_ASI_SP_POLARITY> */
   VHD_ASI_BOARD_CAP_ONLINE_HIGH_PRECISION_TX_BITRATE,   /*! Returns TRUE if the board supports setting online high precision bitrate for a transmission stream. */
   VHD_ASI_BOARD_CAP_LOCAL_CLK,                          /*! Returns TRUE if the board supports setting local clock source. See <link VHD_ASI_SP_USE_LOCAL_CLK> */
   NB_VHD_ASI_BOARD_CAPABILITY
}VHD_ASI_BOARD_CAPABILITY;


/*_ VHD_ASI_POLARITY _____________________________________________*/
/*!
  Summary
  VideoMaster ASI polarity
  Description
  The VHD_ASI_POLARITY enumeration lists all the available ASI 
  polarities.
  See Also
  <link VHD_ASI_STREAMPROPERTY, VHD_ASI_SP_POLARITY>
*/
typedef enum _VHD_ASI_POLARITY
{
   VHD_ASI_POL_NORMAL,    /*! Normal polarity */
   VHD_ASI_POL_INVERTED,  /*! Inverted polarity */
   VHD_ASI_POL_AUTO,      /*! Auto detection of the incoming polarity */
   NB_VHD_ASI_POLARITY
}VHD_ASI_POLARITY;


/*_ VHD_GPIOMUX _____________________________________________*/
/*!
   Summary
   VideoMaster ASI GPIO mux
   Description
   The VHD_GPIOMUX enumeration lists all the available
   configuration for the GPIO mux.
   See Also
   <link External Connector Configuration> <link VHD_SetGPIOMux@HANDLE@UBYTE@VHD_GPIOMUX, VHD_SetGPIOMux>
   <link VHD_GetGPIOMux@HANDLE@UBYTE@VHD_GPIOMUX *, VHD_GetGPIOMux>                                       */
typedef enum _VHD_GPIOMUX
{
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX0, /*! Configure GPIO mux to output ASI bitrate from RX0 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX1, /*! Configure GPIO mux to output ASI bitrate from RX1 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX2, /*! Configure GPIO mux to output ASI bitrate from RX2 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX3, /*! Configure GPIO mux to output ASI bitrate from RX3 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX4, /*! Configure GPIO mux to output ASI bitrate from RX4 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX5, /*! Configure GPIO mux to output ASI bitrate from RX5 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX6, /*! Configure GPIO mux to output ASI bitrate from RX6 */
   VHD_GPIOMUX_OUTPUT_ASI_BR_RX7, /*! Configure GPIO mux to output ASI bitrate from RX7 */
   VHD_GPIOMUX_OUTPUT,            /*! Configure GPIO mux as custom output */
   VHD_GPIOMUX_INPUT,             /*! Configure GPIO mux as input */
   NB_VHD_GPIOMUX
}VHD_GPIOMUX;




/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Asi
*/

/*_ VHD_ASI_TIMESTAMP _______________________________________________________*/
/*!
Summary
STC and MPEG-2 timestamp structure

Description
The VHD_ASI_TIMESTAMP structure defines an MPEG-2 time value.

The VHD_GetSTC function uses this structure to return the on-board STC.

Remarks
A timestamp value is composed of a base and an extension. The
base is expressed in units of the period of 1/300 times the
system clock frequency (thus 90 KHz), while the extension is
directly encoded in units of the system clock frequency (27
MHz).

To recover the complete timestamp value from these fields,
the following formula is applied:

TimeStamp = Base x 300 + Extension

See Also
VHD_GetSTC                                                   
*/
typedef struct _VHD_ASI_TIMESTAMP
{
   BYTE           Base32;              /*! Contains the 33-rd bit (highest bit) of the timestamp base */
   ULONG          Base0_31;            /*! Contains the 32 lower bits of the timestamp base */
   WORD           Ext0_8;              /*! Contains the timestamp extension (9 bits) */
} VHD_ASI_TIMESTAMP;


/*_ VHD_ASI_SLOTSTATUS _______________________________________________________*/
/*!
   Summary
   ASI slot status structure
   Description
   The VHD_ASI_SLOTSTATUS structure is used to report the status
   of an ASI slot.
   See Also
   VHD_GetSlotStatus
*/
typedef struct _VHD_ASI_SLOTSTATUS
{
   ULONG          StatusSize;             /*! The size, in bytes, of this data structure. Set this member to sizeof(VHD_ASI_SLOTSTATUS) before calling the VHD_GetSlotStatus function. */
   BOOL32         FramingError;           /*!_VHD_ASI_SLOTSTATUS::FramingError
                                             TRUE if a framing error occurred in this slot. A framing
                                             error is encoutered if the Transport Stream sync_byte (47h)
                                             is not found every 188 (204) bytes                          */
} VHD_ASI_SLOTSTATUS;





#ifndef EXCLUDE_API_FUNCTIONS


#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Asi
*/



/*** VHD_GetSTC *****************************************************/
/*!VHD_GetSTC@HANDLE@VHD_ASI_TIMESTAMP *
   Summary
   Videomaster STC query
   Description
   The VHD_GetSTC function provides the current STC (System Time
   Clock) value on the specified board.
   Parameters
   BrdHandle :  Handle of the board to operate on
   pSTC :       Pointer to a user\-allocated VHD_ASI_TIMESTAMP
                structure, wherein Videomaster copies the STC
                value
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_ASI_TIMESTAMP                                             */
VIDEOMASTER_HD_API ULONG VHD_GetSTC (HANDLE BrdHandle, VHD_ASI_TIMESTAMP *pSTC);


/*** VHD_SetPIDFilter *****************************************************/
/*!VHD_SetPIDFilter@HANDLE@int
   Summary
   PID filter configuration
   Description
   This function configures the PID which must be captured on a
   ASI reception stream.
   
   It must be called before starting the capture using
   VHD_StartStream.
   
   The PID filter configuration remains active until the stream
   handle is closed using VHD_CloseStreamHandle, or until it is
   re-configured by calling this function again.
   
   If called with a NULL filter pointer, then the reception PID
   filter is disabled and all TS packets are captured.
   Parameters
   StrmHandle :   Handle of the stream to work on
   pPIDFilters :  Array of integers defining the PID to capture.
                  To capture less than VHD_MAXNB_PIDFILTER lines,
                  simply reset all other entries to \-1 or NULL
                  to disable PID filtering
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)       */
VIDEOMASTER_HD_API ULONG VHD_SetPIDFilter (HANDLE StrmHandle, int pPIDFilters[VHD_MAXNB_PIDFILTER]);

/*** VHD_SetGPIOMux *****************************************************/
/*!VHD_SetGPIOMux@HANDLE@UBYTE@VHD_GPIOMUX
   Summary
   VideoMaster GPIO mux configuration
   Description
   This function defines the mux configuration of the GPIO
   associated with the index
   Parameters
   BrdHandle :  Handle of the board to operate on
   GPIOIdx :    Zero\-based index of the GPIO to handle
   GPIOMux :    Configuration to set to the GPIO (see
                VHD_GPIOMUX)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   <link External Connector Configuration> <link VHD_GPIOMUX> */
VIDEOMASTER_HD_API ULONG VHD_SetGPIOMux(HANDLE BrdHandle, UBYTE GPIOIdx, VHD_GPIOMUX GPIOMux);

/*** VHD_GetGPIOMux *****************************************************/
/*!VHD_GetGPIOMux@HANDLE@UBYTE@VHD_GPIOMUX *
   Summary
   VideoMaster GPIO mux configuration query
   Description
   This function gets the mux configuration of the GPIO
   associated with the index
   Parameters
   BrdHandle :  Handle of the board to operate on
   GPIOIdx :    Zero\-based index of the GPIO to handle
   GPIOMux :    Pointer to caller\-allocated variable to return
                the configuration of the GPIO (see VHD_GPIOMUX)
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   <link External Connector Configuration> <link VHD_GPIOMUX>   */
VIDEOMASTER_HD_API ULONG VHD_GetGPIOMux(HANDLE BrdHandle, UBYTE GPIOIdx, VHD_GPIOMUX *pGPIOMux);

/*** VHD_SetGPIO *****************************************************/
/*!VHD_SetGPIO@HANDLE@UBYTE@ULONG
   Summary
   VideoMaster GPIO value
   Description
   This function defines the value of the GPIO associated with
   the index
   Parameters
   BrdHandle :  Handle of the board to operate on
   GPIOIdx :    Zero\-based index of the GPIO to handle
   Value :      Value to set to the GPIO
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   <link External Connector Configuration>                     */
VIDEOMASTER_HD_API ULONG VHD_SetGPIO(HANDLE BrdHandle, UBYTE GPIOIdx,  ULONG Value);

/*** VHD_GetGPIO *****************************************************/
/*!VHD_GetGPIO@HANDLE@UBYTE@ULONG *
   Summary
   VideoMaster GPIO value query
   Description
   This function gets the value of the GPIO associated with the
   index
   Parameters
   BrdHandle :  Handle of the board to operate on
   GPIOIdx :    Zero\-based index of the GPIO to handle
   pValue :     Pointer to caller\-allocated variable to return the
                value of the GPIO
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   <link External Connector Configuration>                          */
VIDEOMASTER_HD_API ULONG VHD_GetGPIO(HANDLE BrdHandle, UBYTE GPIOIdx,  ULONG *pValue);

#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_ASI_H_
