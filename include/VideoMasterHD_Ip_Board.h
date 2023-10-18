
/*! VideomasterHD_IP_Board.h

    Copyright (c) 2015, DELTACAST. All rights reserved.

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


#ifndef _VIDEOMASTERHD_IP_BOARD_H_
#define _VIDEOMASTERHD_IP_BOARD_H_

#include "VideoMasterHD_Core.h"

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Ip_Board
*/

#define VHD_IP_LLDP_PARAM_OPTIONAL_TLV_VALUE_SIZE 512
#define VHD_IP_LLDP_PARAM_CHASSIS_ID_SIZE 255
#define VHD_IP_LLDP_PARAM_PORT_ID_SIZE 255


/*_ VideomasterHD_Ip_Board RX FILTERING MASK __________________________________*/

   /*! Filtering bit masks. These constants define filtering bit masks for the VHD_IP_BRD_SP_FILTERING_MASK, VHD_IP_BRD_SP_FILTERING_MASK_AUDIO and VHD_IP_BRD_SP_FILTERING_MASK_ANC board stream properties */

#define VHD_IP_FILTER_UDP_PORT_DEST       0x01  /*! IP filtering is done on UDP port destination */
#define VHD_IP_FILTER_IP_ADDR_DEST        0x02  /*! IP filtering is done on IP address destination */
#define VHD_IP_FILTER_UDP_PORT_SRC        0x04  /*! IP filtering is done on UDP port source */
#define VHD_IP_FILTER_IP_ADDR_SRC         0x08  /*! IP filtering is done on IP address source */
#define VHD_IP_FILTER_RTP_PAYLOAD_TYPE    0x10  /*! IP filtering is done on RTP payload type */

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Ip_Board
*/


/*_ VHD_IP_BRD_BOARDPROPERTY _______________________________________________*/
/*!
   Summary
   VideoMaster IP board properties
   Description
   The VHD_IP_BRD_BOARDPROPERTY enumeration lists all the board
   properties available on IP cards.
   
   These values are used as indexes for VHD_GetBoardProperty and
   VHD_SetBoardProperty functions calls.
   See Also
   VHD_GetBoardProperty VHD_SetBoardProperty                     */
typedef enum _VHD_IP_BRD_BOARDPROPERTY
{
   VHD_IP_BRD_BP_S2022_6_SUPPORT=ENUMBASE_IP_BRD,        /*! Support of SMPTE 2022-6 protocol - Read only*/ 
   VHD_IP_BRD_BP_RX0_UDP_PORT,                           /*! RX0 UDP port used for packet filtering */ 
   VHD_IP_BRD_BP_RX0_SPS_UDP_PORT,                       /*! RX0 Seamless Protection Switching UDP port used for packet filtering */ 
   VHD_IP_BRD_BP_RX0_SSRC,                               /*! RX0 SSRC used for packet filtering */ 
   VHD_IP_BRD_BP_RX1_UDP_PORT,                           /*! RX1 UDP port used for packet filtering */ 
   VHD_IP_BRD_BP_RX1_SPS_UDP_PORT,                       /*! RX1 Seamless Protection Switching UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX1_SSRC,                               /*! RX1 SSRC used for packet filtering */ 
   VHD_IP_BRD_BP_RX2_UDP_PORT,                           /*! RX2 UDP port used for packet filtering */ 
   VHD_IP_BRD_BP_RX2_SPS_UDP_PORT,                       /*! RX2 Seamless Protection Switching UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX2_SSRC,                               /*! RX2 SSRC used for packet filtering */ 
   VHD_IP_BRD_BP_ARP_TIMEOUT,                            /*! Timeout value in ms used for ARP communications (default is 0ms) */
   VHD_IP_BRD_BP_RX0_AUDIO_UDP_PORT,                     /*! RX0 AUDIO UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX0_AUDIO_SSRC,                         /*! RX0 AUDIO SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX0_ANC_UDP_PORT,                       /*! RX0 ANC UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX0_ANC_SSRC,                           /*! RX0 ANC SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX1_AUDIO_UDP_PORT,                     /*! RX1 AUDIO UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX1_AUDIO_SSRC,                         /*! RX1 AUDIO SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX1_ANC_UDP_PORT,                       /*! RX1 ANC UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX1_ANC_SSRC,                           /*! RX1 ANC SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX2_AUDIO_UDP_PORT,                     /*! RX2 AUDIO UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX2_AUDIO_SSRC,                         /*! RX2 AUDIO SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX2_ANC_UDP_PORT,                       /*! RX2 ANC UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX2_ANC_SSRC,                           /*! RX2 ANC SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX3_UDP_PORT,                           /*! RX3 UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX3_SPS_UDP_PORT,                       /*! RX3 Seamless Protection Switching UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX3_SSRC,                               /*! RX3 SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX3_AUDIO_UDP_PORT,                     /*! RX3 AUDIO UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX3_AUDIO_SSRC,                         /*! RX3 AUDIO SSRC used for packet filtering */
   VHD_IP_BRD_BP_RX3_ANC_UDP_PORT,                       /*! RX3 ANC UDP port used for packet filtering */
   VHD_IP_BRD_BP_RX3_ANC_SSRC,                           /*! RX3 ANC SSRC used for packet filtering */
   VHD_IP_BRD_BP_ST2110_SUPPORT,                         /*! Support of SMPTE 2110 protocol - Read only*/
   VHD_IP_BRD_BP_IGMP_REPORT_VERSION,                    /*! IGMP report version */
   VHD_IP_BRD_BP_RX0_SPS_AUDIO_UDP_PORT,                 /*! RX0 Seamless Protection Switching UDP port used for audio packet filtering */
   VHD_IP_BRD_BP_RX0_SPS_ANC_UDP_PORT,                   /*! RX0 Seamless Protection Switching UDP port used for ANC packet filtering */
   VHD_IP_BRD_BP_RX1_SPS_AUDIO_UDP_PORT,                 /*! RX1 Seamless Protection Switching UDP port used for audio packet filtering */
   VHD_IP_BRD_BP_RX1_SPS_ANC_UDP_PORT,                   /*! RX1 Seamless Protection Switching UDP port used for ANC packet filtering */
   VHD_IP_BRD_BP_RX2_SPS_AUDIO_UDP_PORT,                 /*! RX2 Seamless Protection Switching UDP port used for audio packet filtering */
   VHD_IP_BRD_BP_RX2_SPS_ANC_UDP_PORT,                   /*! RX2 Seamless Protection Switching UDP port used for ANC packet filtering */
   VHD_IP_BRD_BP_RX3_SPS_AUDIO_UDP_PORT,                 /*! RX3 Seamless Protection Switching UDP port used for audio packet filtering */
   VHD_IP_BRD_BP_RX3_SPS_ANC_UDP_PORT,                   /*! RX3 Seamless Protection Switching UDP port used for ANC packet filtering */
   NB_VHD_IP_BRD_BOARDPROPERTY
}VHD_IP_BRD_BOARDPROPERTY;

/*_ VHD_IP_BRD_ETHERNETPORTPROPERTY _______________________________________________*/
/*!
   Summary
   VideoMaster IP ethernet port properties
   Description
   The VHD_IP_BRD_ETHERNETPORTPROPERTY enumeration lists all the
   properties for ethernet ports available on IP cards.
   
   These values are used as indexes for VHD_GetEthernetPortProperty and
   VHD_SetEthernetPortProperty functions calls.
   See Also
   VHD_GetEthernetPortProperty VHD_SetEthernetPortProperty                     */
typedef enum _VHD_IP_BRD_ETHERNETPORTPROPERTY
{
   VHD_IP_BRD_EP_FACTORY_MAC_ADDR_LSW,    /*! Factory MAC address (32 least significant bits) - Read only*/ 
   VHD_IP_BRD_EP_FACTORY_MAC_ADDR_MSW,    /*! Factory MAC address (32 most significant bits) - Read only*/ 
   VHD_IP_BRD_EP_CUSTOM_MAC_ADDR_LSW,     /*! Custom MAC address (32 least significant bits) - Only effective when the VHD_IP_EP_CUSTOM_MAC_ADDR_MSW is set */
   VHD_IP_BRD_EP_CUSTOM_MAC_ADDR_MSW,     /*! Custom MAC address (32 most significant bits) - Previously set VHD_IP_EP_CUSTOM_MAC_ADDR_LSW will be effective */
   VHD_IP_BRD_EP_USE_CUSTOM_MAC_ADDR,     /*! If TRUE, the custom MAC address will be used in place of the factory MAC address (default is FALSE) */
   VHD_IP_BRD_EP_IP_ADDR,                 /*! Local IP address */ 
   VHD_IP_BRD_EP_PACKET_COUNT,            /*! Number of IP packet received */ 
   VHD_IP_BRD_EP_PACKET_ERROR,            /*! Number of erroneous IP packet received */ 
   VHD_IP_BRD_EP_SUBNET_MASK,             /*! Local subnet mask */
   VHD_IP_BRD_EP_GATEWAY_ADDR,            /*! Local gateway address */
   NB_VHD_IP_BRD_ETHERNETPORTPROPERTY
}VHD_IP_BRD_ETHERNETPORTPROPERTY;

/*_ VHD_IP_BRD_ETHERNETPORT _______________________________________________*/
/*!
   Summary
   VideoMaster IP ethernet port list
   Description
   The VHD_IP_BRD_ETHERNETPORT enumeration lists all the
   ethernet ports available on IP cards.
   
   These values are used as indexes for VHD_GetEthernetPortProperty and
   VHD_SetEthernetPortProperty functions calls.
   See Also
   VHD_GetEthernetPortProperty VHD_SetEthernetPortProperty                     */
typedef enum _VHD_IP_BRD_ETHERNETPORT
{
   VHD_IP_BRD_ETHERNETPORT_ETH_0,   /*! Ethernet physical port 0 */
   VHD_IP_BRD_ETHERNETPORT_ETH_1,   /*! Ethernet physical port 1 */
   NB_VHD_IP_BRD_ETHERNETPORT
}VHD_IP_BRD_ETHERNETPORT;

/*_ VHD_IP_BRD_STREAMPROPERTY _______________________________________________*/
/*!
   Summary
   VideoMaster IP stream properties
   Description
   The VHD_IP_BRD_STREAMPROPERTY enumeration lists all the stream
   properties available on IP cards.
   
   These values are used as indexes for VHD_GetStreamProperty and
   VHD_SetStreamProperty functions calls.
   See Also
   VHD_GetStreamProperty VHD_SetStreamProperty                     */
typedef enum _VHD_IP_BRD_STREAMPROPERTY
{
   VHD_IP_BRD_SP_TTL=ENUMBASE_IP_BRD,        /*! Packet Time to Live value (default is 64) */ 
   VHD_IP_BRD_SP_TOS,                        /*! Packet Type of Service (default is 160 - Differentiated Services Codepoint: Class Selector 5) */
   VHD_IP_BRD_SP_MAC_DST_LSW,                /*! Packet MAC destination (32 least significant bits) */  
   VHD_IP_BRD_SP_MAC_DST_MSW,                /*! Packet MAC destination (32 mostsignificant bits) */ 
   VHD_IP_BRD_SP_IP_DST,                     /*! Packet IP destination (TX), also used for packet filtering (RX) */ 
   VHD_IP_BRD_SP_UDP_PORT_DST,               /*! Packet UDP port destination */ 
   VHD_IP_BRD_SP_UDP_PORT_SRC,               /*! Packet UDP port source (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_TTL,                    /*! Seamless Protection Switching packet Time to Live value (default is 64) */
   VHD_IP_BRD_SP_SPS_TOS,                    /*! Seamless Protection Switching packet Type of Service (default is 160 - Differentiated Services Codepoint: Class Selector 5) */
   VHD_IP_BRD_SP_SPS_MAC_DST_LSW,            /*! Seamless Protection Switching packet MAC destination (32 least significant bits) */
   VHD_IP_BRD_SP_SPS_MAC_DST_MSW,            /*! Seamless Protection Switching packet MAC destination (32 most significant bits) */ 
   VHD_IP_BRD_SP_SPS_IP_DST,                 /*! Seamless Protection Switching packet IP destination, also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_UDP_PORT_DST,           /*! Seamless Protection Switching packet UDP port destination */
   VHD_IP_BRD_SP_SPS_UDP_PORT_SRC,           /*! Seamless Protection Switching packet UDP port source, also used for packet filtering (RX) */ 
   VHD_IP_BRD_SP_PIT_MAX,                    /*! Maximum time between two received packets (ns)*/ 
   VHD_IP_BRD_SP_SSRC,                       /*! Packet SSRC */
   VHD_IP_BRD_SP_DATAGRAM_COUNT,             /*! Number of received or transmitted datagram packet */
   VHD_IP_BRD_SP_AUDIO_UDP_PORT_DST,         /*! Packet AUDIO UDP port destination */
   VHD_IP_BRD_SP_AUDIO_UDP_PORT_SRC,         /*! Packet AUDIO UDP port source (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_ANC_UDP_PORT_DST,           /*! Packet ANC UDP port destination */
   VHD_IP_BRD_SP_ANC_UDP_PORT_SRC,           /*! Packet ANC UDP port source (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_AUDIO_SSRC,                 /*! Packet AUDIO SSRC */
   VHD_IP_BRD_SP_ANC_SSRC,                   /*! Packet ANC SSRC */
   VHD_IP_BRD_SP_VIDEO_RTP_PAYLOAD_TYPE,     /*! Video RTP Payload Type (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_AUDIO_RTP_PAYLOAD_TYPE,     /*! Audio RTP Payload Type (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_ANC_RTP_PAYLOAD_TYPE,       /*! ANC RTP Payload Type (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_AUDIO_DATAGRAM_COUNT,       /*! Number of received or transmitted audio datagram packet */
   VHD_IP_BRD_SP_AUDIO_PIT_MAX,              /*! Maximum time between two received audio packets (ns)*/
   VHD_IP_BRD_SP_AUDIO_IP_DST,               /*! AUDIO IP destination used for packet filtering (RX only) */
   VHD_IP_BRD_SP_ANC_IP_DST,                 /*! ANC IP destination used for packet filtering (RX only) */
   VHD_IP_BRD_SP_IP_SRC,                     /*! IP source used for packet filtering (RX only) */
   VHD_IP_BRD_SP_AUDIO_IP_SRC,               /*! AUDIO IP source used for packet filtering (RX only) */
   VHD_IP_BRD_SP_ANC_IP_SRC,                 /*! ANC IP source used for packet filtering (RX only) */
   VHD_IP_BRD_SP_FILTERING_MASK,             /*! Used to setup packet filtering mask (RX only) */
   VHD_IP_BRD_SP_FILTERING_MASK_AUDIO,       /*! Used to setup packet filtering mask for audio (RX only) */
   VHD_IP_BRD_SP_FILTERING_MASK_ANC,         /*! Used to setup packet filtering mask for ANC (RX only) */
   VHD_IP_BRD_SP_SPS_AUDIO_UDP_PORT_DST,     /*! Seamless Protection Switching packet audio UDP port destination */
   VHD_IP_BRD_SP_SPS_AUDIO_UDP_PORT_SRC,     /*! Seamless Protection Switching Packet audio UDP port source (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_ANC_UDP_PORT_DST,       /*! Seamless Protection Switching packet ANC UDP port destination */
   VHD_IP_BRD_SP_SPS_ANC_UDP_PORT_SRC,       /*! Seamless Protection Switching Packet ANC UDP port source (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_VIDEO_RTP_PAYLOAD_TYPE, /*! Seamless Protection Switching video RTP Payload Type (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_AUDIO_RTP_PAYLOAD_TYPE, /*! Seamless Protection Switching audio RTP Payload Type (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_ANC_RTP_PAYLOAD_TYPE,   /*! Seamless Protection Switching ANC RTP Payload Type (TX), also used for packet filtering (RX) */
   VHD_IP_BRD_SP_SPS_AUDIO_IP_DST,           /*! Seamless Protection Switching IP destination used for packet filtering (RX only) */
   VHD_IP_BRD_SP_SPS_ANC_IP_DST,             /*! Seamless Protection Switching IP destination used for packet filtering (RX only) */
   VHD_IP_BRD_SP_SPS_IP_SRC,                 /*! Seamless Protection Switching IP source used for packet filtering (RX only) */
   VHD_IP_BRD_SP_SPS_AUDIO_IP_SRC,           /*! Seamless Protection Switching audio IP source used for packet filtering (RX only) */
   VHD_IP_BRD_SP_SPS_ANC_IP_SRC,             /*! Seamless Protection Switching ANC packet IP source used for packet filtering (RX only) */
   VHD_IP_BRD_SP_SPS_FILTERING_MASK,         /*! Used to setup Seamless Protection Switching packet filtering mask (RX only) */
   VHD_IP_BRD_SP_SPS_FILTERING_MASK_AUDIO,   /*! Used to setup Seamless Protection Switching packet filtering mask for audio (RX only) */
   VHD_IP_BRD_SP_SPS_FILTERING_MASK_ANC,     /*! Used to setup Seamless Protection Switching packet filtering mask for ANC (RX only) */
   VHD_IP_BRD_SP_SPS_ENABLED,                /*! Used to activate the Seamless Protection Switching (default to FALSE for ST2110. Read-only and defaults to TRUE for ST2022) */
   VHD_IP_BRD_SP_SPS_PIT_MAX,                /*! Maximum time between two received SPS packets (ns)*/
   VHD_IP_BRD_SP_SPS_AUDIO_PIT_MAX,          /*! Maximum time between two received SPS audio packets (ns)*/
   VHD_IP_BRD_SP_SPS_ANC_PIT_MAX,            /*! Maximum time between two received SPS ANC packets (ns)*/
   VHD_IP_BRD_SP_ANC_PIT_MAX,                /*! Maximum time between two received ANC packets (ns)*/
   VHD_IP_BRD_SP_SPS_DATAGRAM_COUNT,         /*! Number of received or transmitted SPS datagram packet */
   VHD_IP_BRD_SP_SPS_AUDIO_DATAGRAM_COUNT,   /*! Number of received or transmitted SPS audio datagram packet */
   VHD_IP_BRD_SP_SPS_ANC_DATAGRAM_COUNT,     /*! Number of received or transmitted SPS ANC datagram packet */
   VHD_IP_BRD_SP_ANC_DATAGRAM_COUNT,         /*! Number of received or transmitted ANC datagram packet */
   NB_VHD_IP_BRD_STREAMPROPERTY
}VHD_IP_BRD_STREAMPROPERTY ;

/* Compatibility defines to match with old names */
#define VHD_IP_BRD_SP_JITTER_MAX    VHD_IP_BRD_SP_PIT_MAX

/*_ VHD_IP_BOARD_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster IP board capability
  Description
  The VHD_IP_BOARD_CAPABILITY enumeration lists all the available IP board capabilities
   
  These values are used in VHD_GetBoardCapability function
  See Also
  <link VHD_GetBoardCapability>
*/
typedef enum _VHD_IP_BOARD_CAPABILITY { 
   VHD_IP_BOARD_CAP_ST2022_6 = ENUMBASE_IP_BRD,          /*! Return true if the board supports SMPTE 2022-6 protocol handling feature*/
   VHD_IP_BOARD_CAP_ST2022_5,                            /*! Return true if the board supports SMPTE 2022-5 protocol handling feature*/
   VHD_IP_BOARD_CAP_ST2022_7,                            /*! Return true if the board supports SMPTE 2022-7 protocol handling feature*/
   VHD_IP_BOARD_CAP_ARP_IGMP,                            /*! Return true if the board supports ARP and IGMP protocols handling feature*/
   VHD_IP_BOARD_CAP_ST2110_10,                           /*! Return true if the board supports SMPTE 2110-10 protocol handling feature*/
   VHD_IP_BOARD_CAP_ST2110_20,                           /*! Return true if the board supports SMPTE 2110-20 protocol handling feature*/
   VHD_IP_BOARD_CAP_ST2110_30,                           /*! Return true if the board supports SMPTE 2110-30 protocol handling feature*/
   VHD_IP_BOARD_CAP_ST2110_40,                           /*! Return true if the board supports SMPTE 2110-40 protocol handling feature*/
   VHD_IP_BOARD_CAP_SPS,                                 /*! Return true if the board supports Seamless Protection Switching*/
   VHD_IP_BOARD_CAP_NUMBER_OF_ETHERNET_PORTS,            /*! Return the number of ethernet ports on board */
   VHD_IP_BOARD_CAP_PTP,                                 /*! Return true if the board supports Precision Time Protocol */
   VHD_IP_BOARD_CAP_ST2110_30_ONBOARDBUFFER_SAMPLE_DEPTH, /*! Maximum number of bytes that can be buffered on board without any overflow */
   VHD_IP_BOARD_CAP_DHCP,                                /*! Return true if the board supports DHCP protocol */
   VHD_IP_BOARD_CAP_IGMPv3,                              /*! Return true if the board supports the version 3 of IGMP protocol */
   VHD_IP_BOARD_CAP_LLDP,                                /*! Return true if the board supports LLDP Protocol */
   NB_VHD_IP_BOARD_CAPABILITY
}VHD_IP_BOARD_CAPABILITY;

/*_ VHD_IP_BRD_FILTERMODEMULTICAST _______________________________________________*/
/*!
   Summary
   VideoMaster Multicast filter mode
   Description
   The VHD_IP_BRD_FILTERMODEMULTICAST enumeration lists the
   available filter mode for Multicast on IP boards.

   These values are used as indexes for VHD_SetMulticastFilterMode function calls.
   */
typedef enum _VHD_IP_BRD_FILTERMODEMULTICAST
{
   VHD_IP_BRD_FILTERMODEMULTICAST_EXCLUDE,   /*! Filter mode exclude */
   VHD_IP_BRD_FILTERMODEMULTICAST_INCLUDE,   /*! Filter mode include */
   NB_VHD_IP_BRD_FILTERMODEMULTICAST
}VHD_IP_BRD_FILTERMODEMULTICAST;

/*_ VHD_IP_BRD_IGMP_VERSION _______________________________________________*/
/*!
   Summary
   VideoMaster IGMP Report version
   Description
   The VHD_IP_BRD_IGMP_VERSION enumeration lists the
   available IGMP Report version for Multicast on IP boards.

   These values are used as indexes for VHD_SetMulticastReportVersion function calls.
   */
typedef enum _VHD_IP_BRD_IGMP_VERSION
{
   VHD_IP_BRD_IGMP_VERSION_V2,         /*! IGMP protocol version 2 */
   VHD_IP_BRD_IGMP_VERSION_V3,         /*! IGMP protocol version 3 (default) */
   VHD_IP_BRD_IGMP_VERSION_V2_AND_V3,  /*! IGMP protocol version 2 and 3 */
   NB_VHD_IP_BRD_IGMP_VERSION
}VHD_IP_BRD_IGMP_VERSION;

/*_ VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE _______________________________________________*/
/*!
   Summary
   VideoMaster LLDP MAC address modes
   Description
   The VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE enumeration lists the
   available LLDP MAC address modes on IP boards.

   These values are used as indexes for VHD_EnableLLDP function calls.         */
typedef enum _VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE
{
   VHD_IP_BRD_LLDP_MAC_ADDRESS_NEAREST_BRIDGE,            /*! Nearest bridge: destination MAC address 01:80:C2:00:00:0E */
   VHD_IP_BRD_LLDP_MAC_ADDRESS_NEAREST_NON_TPMR_BRIDGE,   /*! Nearest non TPMR bridge: destination MAC address 01:80:C2:00:00:03 */
   VHD_IP_BRD_LLDP_MAC_ADDRESS_NEAREST_CUSTOMER_BRIDGE,   /*! Nearest customer bridge: destination MAC address 01:80:C2:00:00:00 */
   NB_VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE
}VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE;

/*_ VHD_IP_BRD_LLDP_TLV_OPTIONAL_NAMES _______________________________________________*/
/*!
   Summary
   VideoMaster LLDP TLV Optionals names
   Description
   The VHD_IP_BRD_LLDP_TLV_OPTIONAL_NAMES enumeration lists the
   available LLDP optionals TLV names on IP boards.

   These values are used as indexes for VHD_EnableLLDP function calls.
   Ref. to IEEE Std 802.1AB™ */

typedef enum _VHD_IP_BRD_LLDP_TLV_OPTIONAL_NAMES
{
   VHD_IP_BRD_LLDP_TLV_OPTIONAL_PORT_DESCRIPTION = 4,    /*! Port Description TLV allows network management to advertise the IEEE 802 LAN station’s port description */
   VHD_IP_BRD_LLDP_TLV_OPTIONAL_SYSTEM_NAME,             /*! The System Name TLV allows network management to advertise the system’s assigned name */
   VHD_IP_BRD_LLDP_TLV_OPTIONAL_SYSTEM_DESCRIPTION,      /*! The System Description TLV allows network management to advertise the system’s description */
   VHD_IP_BRD_LLDP_TLV_OPTIONAL_SYSTEM_CAPABILITIES,     /*! The System Capabilities TLV is an optional TLV that identifies the primary function(s) of the system and whether or not these primary functions are enabled */
   VHD_IP_BRD_LLDP_TLV_OPTIONAL_MANAGEMENT_ADDRESS,      /*! The Management Address TLV identifies an address associated with the local LLDP agent that may be used to reach higher layer entities to assist discovery by network management */
   NB_VHD_IP_BRD_LLDP_TLV_OPTIONAL_NAMES
}VHD_IP_BRD_LLDP_TLV_OPTIONAL_NAMES;

/*_VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_NAMES _______________________________________________*/
/*!
   Summary
   VideoMaster LLDP TLV Chassis_ID subtyte names
   Description
   The VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_NAMES enumeration lists the
   available LLDP TLV Chassis_ID subtyte names on IP boards.

   These values are used as indexes for VHD_EnableLLDP function calls.
   Ref. to IEEE Std 802.1AB™ */

typedef enum _VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE
{
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_CHASSIS_COMPONENT = 1,     /*! EntPhysicalAlias when entPhysClass has a value of chassis(3) (IETF RFC 2737) */
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_INTERFACE_ALIAS,           /*! IfAlias (IETF RFC 2863) */
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_PORT_COMPONENT,            /*! EntPhysicalAlias when entPhysicalClass has a value port(10) or backplane(4) (IETF RFC 2737) */
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_MAC_ADDRESS,               /*! MAC address (IEEE Std 802-2001) */
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_NETWORK_ADDRESS,           /*! Octet string that identifies a particular network address family and an associated network address that are encoded in network octet order */
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_INTERFACE_NAME,            /*! ifName (IETF RFC 2863) */
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE_LOCALLY_ASSIGNED,          /*! local is an alpha-numeric string and is locally assigned */
   NB_VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE
}VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE;

/*_VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_NAMES _______________________________________________*/
/*!
   Summary
   VideoMaster LLDP TLV Port_ID subtyte names
   Description
   The VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_NAMES enumeration lists the
   available LLDP TLV Port_ID subtyte names on IP boards.

   These values are used as indexes for VHD_EnableLLDP function calls.
   Ref. to IEEE Std 802.1AB™ */

typedef enum _VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE
{
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_INTERFACE_ALIAS = 1,    /*! ifAlias (IETF RFC 2863) */
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_PORT_COMPONENT,         /*! entPhysicalAlias when entPhysicalClass has a value port(10 or ‘backplane(4) (IETF RFC 2737) */
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_MAC_ADDRESS,            /*! MAC address (IEEE Std 802-2001) */
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_NETWORK_ADDRESS,        /*! Octet string that identifies a particular network address family and an associated network address that are encoded in network octet order */
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_INTERFACE_NAME,         /*! ifName (IETF RFC 2863)*/
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_AGENT_CIRCUIT_ID,       /*! Agent circuit ID (IETF RFC 3046) */
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE_LOCALLY_ASSIGNED,       /*! local is an alpha-numeric string and is locally assigned */
   NB_VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE
}VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Ip_Board
*/

/*_ VHD_IP_DHCP_PARAMETERS _____________________________________________*/
/*!
Summary
VideoMaster DHCP parameters
*/
typedef struct _VHD_IP_DHCP_STATUS
{
   BOOL32 Enable;                            /*! Indicates if the DHCP protocol is enabled */
   BOOL32 IPValid;                           /*! Indicates if the IP address which has been attributed is valid or not */
} VHD_IP_DHCP_STATUS;


/*!
Summary
VideoMaster LLDP Chassis ID TLV fields parameters
Please refer to LLDP Standard (802.1AB-2016), mostly for the byte ordering which depends of the subtype
MAC and IP address must be encoded in network octet order
Ref. to IEEE Std 802.1AB™ */
typedef struct _VHD_IP_LLDP_CHASSIS_ID_TLV
{
   VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE Subtype;          /*! Chassis ID subtype field shall contain an VHD_IP_BRD_LLDP_TLV_CHASSIS_ID_SUBTYPE value indicating the type of component being referenced by the chassis ID field */
   USHORT Length;                                           /*! Chassis ID TLV information string length field shall indicate the length, in octets, of the (chassis ID subtype + chassis ID) fields. 1 <= n <= 255 */
   UBYTE pChassisID[VHD_IP_LLDP_PARAM_CHASSIS_ID_SIZE];     /*! Chassis_ID TLV information string data */
} VHD_IP_LLDP_CHASSIS_ID_TLV;

/*!
Summary
VideoMaster LLDP Port ID TLV fields parameters  
Please refer to LLDP Standard (802.1AB-2016), mostly for the byte ordering which depends of the subtype
MAC and IP address must be encoded in network octet order 
Ref. to IEEE Std 802.1AB™ */
typedef struct _VHD_IP_LLDP_PORT_ID_TLV
{
   VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE Subtype;       /*! Port_ID TLV field shall contain an VHD_IP_BRD_LLDP_TLV_PORT_ID_SUBTYPE value indicating the type of component being referenced by the port ID field */
   USHORT Length;                                     /*! Port ID TLV information string length field shall indicate the length, in octets, of the (port ID subtype + port ID) fields. 1 <= n <= 255 */
   UBYTE pPortID[VHD_IP_LLDP_PARAM_PORT_ID_SIZE];     /*! Port_ID TLV information string data */
} VHD_IP_LLDP_PORT_ID_TLV;


/*!
Summary
VideoMaster mandatory LLDP parameters
Ref. to IEEE Std 802.1AB™ */
typedef struct _VHD_IP_LLDP_MANDATORY_TLV
{
   VHD_IP_LLDP_CHASSIS_ID_TLV Chassis_ID;       /*! Chassis ID TLV is a mandatory TLV that identifies the chassis containing the IEEE 802 LAN station associated with the transmitting LLDP agent. */
   VHD_IP_LLDP_PORT_ID_TLV Port_ID;             /*! Port ID TLV is a mandatory TLV that identifies the port component of the MSAP identifier associated with the transmitting LLDP agent. */
   USHORT TimeToLive;                           /*! The Time To Live TLV indicates the number of seconds that the recipient LLDP agent is to regard the information associated with this MSAP identifier to be valid. Shall contain an integer value in the range 0 <= t <= 65535 seconds */
} VHD_IP_LLDP_MANDATORY_TLV;

/*!
Summary
VideoMaster optionals LLDP parameters
Ref. to IEEE Std 802.1AB™ */
typedef struct _VHD_IP_LLDP_OPTIONAL_TLV
{
   UBYTE Type;                                                 /*! Optional TLV type: used to identifies the specific TLV */
   USHORT Length;                                              /*! Optional TLV length field: shall contain the length of the information string (pValue), in octets */
   UBYTE pValue[VHD_IP_LLDP_PARAM_OPTIONAL_TLV_VALUE_SIZE];    /*! Optional TLV information string data */
} VHD_IP_LLDP_OPTIONAL_TLV;

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Ip_Board
*/

/*** VHD_SetEthernetPortProperty ****************************************************/
/*!VHD_SetEthernetPortProperty@HANDLE@VHD_IP_BRD_ETHERNETPORT@VHD_IP_BRD_ETHERNETPORTPROPERTY@ULONG
   Summary
   Ethernet port property configuration
   Description
   This function configures the value of the specified ethernet port
   property
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:         Ethernet port of the board to set property on,
                     must be a value of the VHD_IP_BRD_ETHERNETPORT list
   EthernetPortProperty :   Property to set, must be a value of the VHD_IP_BRD_ETHERNETPORTPROPERTY list
   Value :               Property value to configure
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT VHD_IP_BRD_ETHERNETPORTPROPERTY
   VHD_GetEthernetPortProperty                                         */
VIDEOMASTER_HD_API ULONG VHD_SetEthernetPortProperty (HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, VHD_IP_BRD_ETHERNETPORTPROPERTY Property, ULONG Value);

/*** VHD_GetEthernetPortProperty ****************************************************/
/*!VHD_GetEthernetPortProperty@HANDLE@VHD_IP_BRD_ETHERNETPORT@VHD_IP_BRD_ETHERNETPORTPROPERTY@ULONG *
   Summary
   Ethernet port property query
   Description
   This function retrieves the value of the specified ethernet port
   property
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:         Ethernet port of the board to set property on,
                     must be a value of the VHD_IP_BRD_ETHERNETPORT list
   EthernetPortProperty :   Property to set, must be a value of the VHD_IP_BRD_ETHERNETPORTPROPERTY list
   pValue :               Pointer to caller\-allocated variable to return
                     property value
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT VHD_IP_BRD_ETHERNETPORTPROPERTY
   VHD_SetEthernetPortProperty                                         */
VIDEOMASTER_HD_API ULONG VHD_GetEthernetPortProperty (HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, VHD_IP_BRD_ETHERNETPORTPROPERTY Property, ULONG *pValue);

/*** VHD_JoinMulticastGroup ****************************************************/
/*!VHD_JoinMulticastGroup@HANDLE@VHD_IP_BRD_ETHERNETPORT@ULONG
   Summary
   Join multicast group
   Description
   This function engage IGMP protocol to join the specified multicast group on the specified ethernet port.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:         Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   GroupAddr :            Address of the multicast group to join
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_BRD_BP_NETWORK_TIMEOUT                                         */
VIDEOMASTER_HD_API ULONG VHD_JoinMulticastGroup(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, ULONG GroupAddr);

/*** VHD_LeaveMulticastGroup ****************************************************/
/*!VHD_LeaveMulticastGroup@HANDLE@VHD_IP_BRD_ETHERNETPORT@ULONG
   Summary
   Leave multicast group
   Description
   This function engages IGMP protocol to leave the specified multicast group on the specified ethernet port.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:         Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   GroupAddr :            Address of the multicast group to leave
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_BRD_BP_NETWORK_TIMEOUT                                         */
VIDEOMASTER_HD_API ULONG VHD_LeaveMulticastGroup(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, ULONG GroupAddr);

/*** VHD_AddMulticastSource ****************************************************/
/*!VHD_AddMulticastSource@HANDLE@VHD_IP_BRD_ETHERNETPORT@ULONG@ULONG
   Summary
   Add a multicast source 
   Description
   This function engages IGMP protocol to add the specified multicast source on the specified ethernet port and group.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   GroupAddr :            Address of the multicast group which the source will be added
   SourceAddr :           Address of the multicast source to add
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_BRD_BP_NETWORK_TIMEOUT */
VIDEOMASTER_HD_API ULONG VHD_AddMulticastSource(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, ULONG GroupAddr, ULONG SourceAddr);

/*** VHD_RemoveMulticastSource ****************************************************/
/*!VHD_RemoveMulticastSource@HANDLE@VHD_IP_BRD_ETHERNETPORT@ULONG@ULONG
   Summary
   Remove a multicast source
   Description
   This function engages IGMP protocol to remove the specified multicast source on the specified ethernet port and group.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   GroupAddr :            Address of the multicast group which the source will be removed
   SourceAddr :           Address of the multicast source to remove
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT */
VIDEOMASTER_HD_API ULONG VHD_RemoveMulticastSource(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, ULONG GroupAddr, ULONG SourceAddr);

/*** VHD_SetMulticastFilterMode ****************************************************/
/*!VHD_SetMulticastFilterMode@HANDLE@VHD_IP_BRD_ETHERNETPORT@ULONG@VHD_IP_BRD_FILTERMODEMULTICAST
   Summary
   Set the multicast filter mode
   Description
   This function engages IGMP protocol to set the specified multicast filter mode.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   GroupAddr :            Address of the multicast group which is concern by the change
   FilterMode :           Filter mode selection : include or exclude
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_BRD_FILTERMODEMULTICAST */
VIDEOMASTER_HD_API ULONG VHD_SetMulticastFilterMode(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, ULONG GroupAddr, VHD_IP_BRD_FILTERMODEMULTICAST FilterMode);

/*** VHD_SetMulticastVersion ****************************************************/
/*!VHD_SetMulticastVersion@HANDLE@VHD_IP_BRD_IGMP_VERSION
   Summary
   Set the multicast report version
   Description
   This function sets the specified multicast version report to be use (IGMv3 by default).
   Parameters
   BrdHandle :             Handle of the board to set property on
   Version :               Version of the IGMP report
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_IGMP_VERSION */
VIDEOMASTER_HD_API ULONG VHD_SetMulticastVersion(HANDLE BrdHandle, VHD_IP_BRD_IGMP_VERSION Version);

/*** VHD_GetMulticastVersion ****************************************************/
/*!VHD_GetMulticastVersion@HANDLE@VHD_IP_BRD_IGMP_VERSION*
   Summary
   Get the multicast report version
   Description
   This function gets the multicast version report which is used by the board (IGMv3 by default).
   Parameters
   BrdHandle :             Handle of the board to set property on
   pVersion :              Pointer to stock the version of the IGMP report 
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_IGMP_VERSION */
VIDEOMASTER_HD_API ULONG VHD_GetMulticastVersion(HANDLE BrdHandle, VHD_IP_BRD_IGMP_VERSION* pVersion);

/*** VHD_EnableDHCP ****************************************************/
/*!VHD_EnableDHCP@HANDLE@VHD_IP_BRD_ETHERNETPORT
   Summary
   Enable the DHCP protocol
   Description
   This function enables the DHCP protocol on the specified board handle.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT */
VIDEOMASTER_HD_API ULONG VHD_EnableDHCP(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort);

/*** VHD_DisableDHCP ****************************************************/
/*!VHD_DisableDHCP@HANDLE@VHD_IP_BRD_ETHERNETPORT
   Summary
   Disable the DHCP protocol
   Description
   This function disables the DHCP protocol on the specified board handle.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT */
VIDEOMASTER_HD_API ULONG VHD_DisableDHCP(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort);

/*** VHD_GetDHCPStatus ****************************************************/
/*!VHD_GetDHCPStatus@HANDLE@VHD_IP_BRD_ETHERNETPORT@VHD_IP_DHCP_STATUS*
   Summary
   Get the DHCP status
   Description
   This function returns a VHD_IP_DHCP_STATUS structure with the DHCP stateand the validity of the IP address if one has been attributed.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   pStatus :               VHD_IP_DHCP_STATUS structure pointer
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_DHCP_STATUS */
VIDEOMASTER_HD_API ULONG VHD_GetDHCPStatus(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, VHD_IP_DHCP_STATUS* pStatus);

/*** VHD_EnableLLDP ****************************************************/
/*!VHD_EnableLLDP@HANDLE@VHD_IP_BRD_ETHERNETPORT@VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE@VHD_IP_LLDP_MANDATORY_TLV@VHD_IP_LLDP_OPTIONAL_TLV*@UBYTE
   Summary
   Enable the LLDP protocol
   Description
   This function enables the LLDP protocol on the specified board handle.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   MAC_AddressMode :      MAC address modes which determines the scope of propagation of LLDP packets
   within a bridged LAN. Must be a value of the VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE list.
   MandatoryTLV :         Structure containing LLDP mandatory fields
   pOptionalsTLV_Array :  Structures array containing LLDP optionals fields
   NumberOfOptionalsTLV : Number of optionals field to be added
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE
   VHD_IP_LLDP_MANDATORY_TLV
   VHD_IP_LLDP_OPTIONAL_TLV  */
VIDEOMASTER_HD_API ULONG VHD_EnableLLDP(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, VHD_IP_BRD_LLDP_MAC_ADDRESS_MODE MAC_AddressMode, VHD_IP_LLDP_MANDATORY_TLV MandatoryTLV, VHD_IP_LLDP_OPTIONAL_TLV* pOptionalsTLV_Array, UBYTE NumberOfOptionalsTLV);

/*** VHD_DisableLLDP ****************************************************/
/*!VHD_DisableLLDP@HANDLE@VHD_IP_BRD_ETHERNETPORT@VHD_IP_LLDP_MANDATORY_TLV
   Summary
   Disable the LLDP protocol
   Description
   This function disables the LLDP protocol on the specified board handle.
   Parameters
   BrdHandle :            Handle of the board to set property on
   EthernetPort:          Ethernet port of the board to set property on,
   must be a value of the VHD_IP_BRD_ETHERNETPORT list
   MandatoryTLV :         Structure containing LLDP mandatory fields
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   See Also
   VHD_IP_BRD_ETHERNETPORT
   VHD_IP_LLDP_MANDATORY_TLV */
VIDEOMASTER_HD_API ULONG VHD_DisableLLDP(HANDLE BrdHandle, VHD_IP_BRD_ETHERNETPORT EthernetPort, VHD_IP_LLDP_MANDATORY_TLV MandatoryTLV);

#ifdef __cplusplus
}
#endif

#endif // EXCLUDE_API_FUNCTIONS

#endif // _VIDEOMASTERHD_IP_BOARD_H_

