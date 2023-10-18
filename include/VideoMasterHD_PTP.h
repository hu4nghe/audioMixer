/*! VideomasterHD_PTP.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : lr                             Date: 2018/10/05

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_PTP_H_
#define _VIDEOMASTERHD_PTP_H_

#include "VideoMasterHD_Core.h"

/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_PTP
*/

/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_PTP
*/

/*_ VHD_PTP_PORT_STATE _____________________________________________*/
/*!
   Summary
      PTP port state
   Description
      This enumeration lists all the possible states in which a PTP-enabled device can be.
   See Also
      <link VHD_GetPTPPortState>
*/
typedef enum _VHD_PTP_PORT_STATE
{
   VHD_PTP_PORT_STATE_INITIALIZING = 0,   /*! The device is initializing its PTP configuration */
   VHD_PTP_PORT_STATE_FAULTY,             /*! Faulty state */
   VHD_PTP_PORT_STATE_DISABLED,           /*! The PTP device capability is disabled */
   VHD_PTP_PORT_STATE_LISTENING,          /*! The device is listening for PTP synchronization messages */
   VHD_PTP_PORT_STATE_PREMASTER,          /*! The device is in a pre-master state */
   VHD_PTP_PORT_STATE_MASTER,             /*! The device is a PTP master */
   VHD_PTP_PORT_STATE_PASSIVE,            /*! Passive state */
   VHD_PTP_PORT_STATE_UNCALIBRATED,       /*! The device receives PTP synchronization messages and tries to lock on the master clock */
   VHD_PTP_PORT_STATE_SLAVE,     /*! The device is a slave of the PTP master clock */
   NB_VHD_PTP_PORT_STATE
}VHD_PTP_PORT_STATE;

/*_ VHD_PTP_PORT_STATE _____________________________________________*/
/*!
Summary
   PTP profile
Description
   This enumeration lists the different profiles that describe the
   dataset values used to configure PTP.
   These values can be retrieved via <link VHD_CreatePTPDSFromProfile>.
See Also
*/
typedef enum _VHD_PTP_PROFILE
{
   VHD_PTP_PROFILE_ST2059_2 = 0,    /*! ST2059-2 PTP profile */
   VHD_PTP_PROFILE_AES67,           /*! AES67 PTP profile */
   NB_VHD_PTP_PROFILE
}VHD_PTP_PROFILE;

/*_ VHD_PTP_PORT_STATE _____________________________________________*/
/*!
Summary
   PTP delay mechanism
Description
   This enumeration lists the different delay mechanisms that can be used
   by a PTP device to synchronize on the master clock.
See Also
   <link VHD_PTP_PORTDS>
*/
typedef enum _VHD_PTP_DELAYMECHANISM
{
   VHD_PTP_DELAYMECHANISM_E2E = 1,           /*! End-to-end PTP delay mechanism */
   VHD_PTP_DELAYMECHANISM_P2P = 2,           /*! Peer-to-peer delay mechanism */
   VHD_PTP_DELAYMECHANISM_DISABLED = 0xFE,   /*! Delay mechanism is disabled */
   NB_VHD_PTP_DELAYMECHANISM
}VHD_PTP_DELAYMECHANISM;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_PTP
*/

/*_ VHD_PTP_CLOCKQUALITY _______________________________________________________*/
/*!
Summary
   PTP clock quality
Description
   This structure holds the data that determine the PTP clock quality.
See Also
   <link VHD_PTP_DEFAULTDS>
*/
typedef struct _VHD_PTP_CLOCKQUALITY
{
   UBYTE ClockClass;                      /*! Clock class */
   UBYTE ClockAccuracy;                   /*! Clock accuracy */
   UWORD OffsetScaledLogVariance;         /*! Offset scaled log variance */
}VHD_PTP_CLOCKQUALITY;

/*_ VHD_PTP_DEFAULTDS _______________________________________________________*/
/*!
Summary
   PTP default dataset
Description
   This structure holds the necessary PTP default dataset
   variables used to affect the behavior of a PTP device.
See Also
   <link VHD_CreatePTPDSFromProfile>
*/
typedef struct _VHD_PTP_DEFAULTDS
{
   UWORD NumberPorts;                     /*! Number of ports */
   VHD_PTP_CLOCKQUALITY ClockQuality;     /*! Clock quality */
   UBYTE Priority1;                       /*! Priority 1 */
   UBYTE Priority2;                       /*! Priority 2 */
   UBYTE DomainNumber;                    /*! Domain number */
}VHD_PTP_DEFAULTDS;

/*_ VHD_PTP_PORTDS _______________________________________________________*/
/*!
Summary
   PTP port dataset
Description
   This structure holds the necessary PTP port dataset
   variables used to affect the behavior of a PTP device.
See Also
   <link VHD_CreatePTPDSFromProfile>
*/
typedef struct _VHD_PTP_PORTDS
{
   UWORD PortNumber;                      /*! Port number (read-only) */
   BYTE LogMinDelayReqInterval;           /*! Base-2 log of the minimum delay request interval */
   ULONG PeerMeanPathDelay_seconds;       /*! Current one-way propagation delay on the link for peer-to-peer delay mechanism */
   BYTE LogAnnounceInterval;              /*! Base-2 log of the mean announce interval */
   UBYTE AnnounceReceiptTimeout;          /*! Timeout on announce response */
   BYTE LogSyncInterval;                  /*! Base-2 log of the mean synchronization interval */
   VHD_PTP_DELAYMECHANISM DelayMechanism; /*! Delay mechanism (see <link VHD_PTP_DELAYMECHANISM>) */
   BYTE LogMinPdelayReqInterval;          /*! Base-2 log of the minimum p-delay request interval */
   UBYTE VersionNumber;                   /*! Version number */
}VHD_PTP_PORTDS;

/*_ VHD_PTP_CONFIGURATION _______________________________________________________*/
/*!
Summary
   PTP configuration
Description
   This structure holds the data used to correctly configure PTP on a device.
See Also
   <link VHD_CreatePTPDSFromProfile>, <link VHD_GetPTPConfiguration>, <link VHD_SetPTPConfiguration>
*/
typedef struct _VHD_PTP_CONFIGURATION
{
   ULONG MulticastAddr;                   /*! Multicast address on which the PTP messages are sent */
   BOOL32 SmpteMixedMode_B;               /*! Enables/disables SMPTE mixed mode */
   VHD_PTP_DEFAULTDS DefaultDS;           /*! Default dataset */
   VHD_PTP_PORTDS PortDS;                 /*! Port dataset */
}VHD_PTP_CONFIGURATION;

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif
   /*** VHD_GetPTPPortState ***************************************************/
   /*!VHD_GetPTPPortState
   Summary
      Gets PTP port state
   Description
      This function retrieves the current PTP state of the device.
   Parameters
      BoardHandle : Handle of the board
      pPTPPortState : Pointer to caller\-allocated variable to return
                        the PTP state
      pLocked : Pointer to caller\-allocated variable to return
                        the PTP locked state
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
   ULONG VIDEOMASTER_HD_API VHD_GetPTPPortState(HANDLE BoardHandle, VHD_PTP_PORT_STATE *pPTPPortState, BOOL32* pLocked);

   /*** VHD_GetPTPTime ***************************************************/
   /*!VHD_GetPTPTime
   Summary
      Gets PTP time
   Description
      This function retrieves the current PTP time.
   Parameters
      BoardHandle : Handle of the board
      pPTPTimeStamp_sec : Pointer to caller\-allocated variable to return
                           the PTP timestamp in seconds
      pPTPTimeStamp_nsec : Pointer to caller\-allocated variable to return
                              the nanosecond part of the PTP timestamp
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
   ULONG VIDEOMASTER_HD_API VHD_GetPTPTime(HANDLE BoardHandle, ULONG *pPTPTimeStamp_sec, ULONG *pPTPTimeStamp_nsec);

   /*** VHD_GetPTPOffset ***************************************************/
   /*!VHD_GetPTPOffset
   Summary
      Gets PTP offset
   Description
      This function retrieves the current offset the device clock is
      away from the master clock.
   Parameters
      BoardHandle : Handle of the board
      pPTPOffset_sec : Pointer to caller\-allocated variable to return
                        the PTP offset in seconds
      pPTPOffset_nsec : Pointer to caller\-allocated variable to return
                           the nanosecond part of the PTP offset
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
   ULONG VIDEOMASTER_HD_API VHD_GetPTPOffset(HANDLE BoardHandle, LONG *pPTPOffset_sec, LONG *pPTPOffset_nsec);

   /*** VHD_SetPTPConfiguration ***************************************************/
   /*!VHD_SetPTPConfiguration
   Summary
      Sets PTP configuration
   Description
      This functions sets the given PTP configuration on the device.
   Parameters
      BoardHandle : Handle of the board
      PTPConfiguration : PTP configuration to apply
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
   ULONG VIDEOMASTER_HD_API VHD_SetPTPConfiguration(HANDLE BoardHandle, VHD_PTP_CONFIGURATION PTPConfiguration);

   /*** VHD_GetPTPConfiguration ***************************************************/
   /*!VHD_GetPTPConfiguration
   Summary
      Gets current PTP configuration
   Description
      This function retrieves the current PTP configuration used by the device.
   Parameters
      BoardHandle : Handle of the board
      pPTPConfiguration : Pointer to caller\-allocated variable to return
                           the PTP configuration
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
   ULONG VIDEOMASTER_HD_API VHD_GetPTPConfiguration(HANDLE BoardHandle, VHD_PTP_CONFIGURATION *pPTPConfiguration);

   /*** VHD_CreatePTPDSFromProfile ***************************************************/
   /*!VHD_CreatePTPDSFromProfile
   Summary
      Creates PTP datasets
   Description
      This function creates the default and port datasets based on a given PTP profile.
   Parameters
      PTPProfile : PTP profile from which the datasets are defined
      pDefaultDS : Pointer to caller\-allocated variable to return
                     default dataset
      pPortDS : Pointer to caller\-allocated variable to return
                  port dataset
   Returns
      The function returns the status of its execution as
      VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   */
   ULONG VIDEOMASTER_HD_API VHD_CreatePTPDSFromProfile(VHD_PTP_PROFILE PTPProfile, VHD_PTP_DEFAULTDS *pDefaultDS, VHD_PTP_PORTDS *pPortDS);
   
#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS

#endif //_VIDEOMASTERHD_PTP_H_