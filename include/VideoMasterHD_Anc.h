/*! VideomasterHD_Anc.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package : 

  Company : DELTACAST

  Author  : lr                             Date: 2018/10/29

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_ANC_H_
#define _VIDEOMASTERHD_ANC_H_



/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Anc
*/


/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Anc
*/

/*_ VHD_SAMPLETYPE ____________________________________________*/
/*!
   Summary
   VideoMaster ANC sample stream types
   Description
   The VHD_SAMPLETYPE enumeration lists the two available video
   \sample types (Y and C).
   
   It is used to define streams to look for ANC and VBI data in.
   
   These values are used during VHD_SlotAnc* and VHD_SlotVbi*
   function calls.
   See Also
   VHD_SlotAncGetNbPackets VHD_SlotAncGetPacket VHD_SlotAncInsertPacket
   VHD_SlotVbiGetLine VHD_SlotVbiInsertLine                             */

typedef enum _VHD_SAMPLETYPE
{
   VHD_SAMPLE_Y = 0,                /*! Luma ancillary data stream */
   VHD_SAMPLE_C,                    /*! Chroma ancillary data stream, or SD ANC/VBI stream */
   VHD_SAMPLE_Y_2,                  /*! Second luma ancillary data stream (only in stereoscopic and 4K modes)*/
   VHD_SAMPLE_C_2,                  /*! Second chroma ancillary data stream, or SD ANC/VBI stream (only in stereoscopic and 4K modes)*/
   VHD_SAMPLE_Y_3,                  /*! Third luma ancillary data stream (only in 4k mode)*/
   VHD_SAMPLE_C_3,                  /*! Third chroma ancillary data stream, or SD ANC/VBI stream (only in 4k mode)*/
   VHD_SAMPLE_Y_4,                  /*! Fourth luma ancillary data stream (only in 4k mode)*/
   VHD_SAMPLE_C_4,                  /*! Fourth chroma ancillary data stream, or SD ANC/VBI stream (only in 4k mode)*/
   VHD_SAMPLE_Y_B,                  /*! Additional luna ancillary data stream (only in dual-link modes) */
   VHD_SAMPLE_C_B,                  /*! Additional chroma ancillary data streamm, or SD ANC/VBI stream (only in dual-link modes) */
   VHD_SAMPLE_Y_2_B,                /*! Additional second luma ancillary data stream (only in stereoscopic and 4K modes + dual-link modes ) */
   VHD_SAMPLE_C_2_B,                /*! Additional second chroma ancillary data streamm, or SD ANC/VBI stream (only in stereoscopic and 4K modes + dual-link modes ) */
   VHD_SAMPLE_Y_3_B,                /*! Additional third luma ancillary data stream (only in 4K modes + dual-link modes ) */
   VHD_SAMPLE_C_3_B,                /*! Additional third chroma ancillary data streamm, or SD ANC/VBI stream (only in 4K modes + dual-link modes ) */
   VHD_SAMPLE_Y_4_B,                /*! Additional fourth luma ancillary data stream (only in 4K modes + dual-link modes ) */
   VHD_SAMPLE_C_4_B,                /*! Additional fourth chroma ancillary data streamm, or SD ANC/VBI stream (only in 4K modes + dual-link modes ) */
   VHD_SAMPLE_Y_5,                  /*! Additional fifth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_5,                  /*! Additional fifth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_5_B,                /*! Additional fifth luma ancillary data stream (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_C_5_B,                /*! Additional fifth chroma ancillary data streamm (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_Y_6,                  /*! Additional sixth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_6,                  /*! Additional sixth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_6_B,                /*! Additional sixth luma ancillary data stream (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_C_6_B,                /*! Additional sixth chroma ancillary data streamm (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_Y_7,                  /*! Additional seventh luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_7,                  /*! Additional seventh chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_7_B,                /*! Additional seventh luma ancillary data stream (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_C_7_B,                /*! Additional seventh chroma ancillary data streamm (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_Y_8,                  /*! Additional eighth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_8,                  /*! Additional eighth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_8_B,                /*! Additional eighth luma ancillary data stream (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_C_8_B,                /*! Additional eighth chroma ancillary data streamm (only in 8K modes + dual-link modes) */
   VHD_SAMPLE_Y_9,                  /*! Additional ninth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_9,                  /*! Additional ninth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_10,                 /*! Additional tenth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_10,                 /*! Additional tenth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_11,                 /*! Additional eleventh luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_11,                 /*! Additional eleventh chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_12,                 /*! Additional twelfth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_12,                 /*! Additional twelfth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_13,                 /*! Additional thirteenth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_13,                 /*! Additional thirteenth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_14,                 /*! Additional fourteenth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_14,                 /*! Additional fourteenth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_15,                 /*! Additional fifteenth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_15,                 /*! Additional fifteenth chroma ancillary data streamm (only in 8K modes) */
   VHD_SAMPLE_Y_16,                 /*! Additional sixteenth luma ancillary data stream (only in 8K modes) */
   VHD_SAMPLE_C_16,                 /*! Additional sixteenth chroma ancillary data streamm (only in 8K modes) */
   NB_VHD_SAMPLETYPES
} VHD_SAMPLETYPE;

/*!VHD_SAMPLE_Y_AND_C
Setting the SampleStream value in VHD_TIMECODEINFO structure with the VHD_SlotExtractTimecode function to VHD_SAMPLE_Y_AND_C on reception streams result in looking for timecode in both Y and C streams */
#define VHD_SAMPLE_Y_AND_C  (VHD_SAMPLETYPE)(-1)


/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Anc
*/

/*_ VHD_ANCPACKET ___________________________________________________*/
/*!
   Summary
   Ancillary data packet
   Description
   The VHD_ANCPACKET structure abstracts an ancillary data
   packet. This structure is used by the VHD_SlotAncGetPacket
   and VHD_SlotAncInsertPacket API functions.
   See Also
   VHD_SlotAncGetPacket VHD_SlotAncInsertPacket               */

typedef struct _VHD_ANCPACKET
{
   BYTE  DataID;              /*! 8 LSB of ANC packet Data ID field */
   union
   {
      BYTE  DataBlockNumber;  /*! 8 LSB of ANC packet Data Block Number field (Type 1 packets) */
      BYTE  SecondaryDataID;  /*! 8 LSB of ANC packet Secondary Data ID field (Type 2 packets) */
   };									/*! */
   BYTE  DataCount;           /*! Number of User Data words in this packet */
   WORD *pUserDataWords;      /*! Pointer to ANC packet User Data Words */
   BOOL32  InHANC;              /*! TRUE if this packet concerns horizontal blanking space, FALSE if located in horizontal active space. Please note that this only concerns packets of VANC space since during active lines, ANC are only allowed during horizontal blanking */
} VHD_ANCPACKET;

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Anc
*/

/*_ Ancillary data buffers navigation functions _____________________________*/


/*** VHD_SlotAncGetNbPackets *****************************************************/
/*!VHD_SlotAncGetNbPackets@HANDLE@int@VHD_SAMPLETYPE@int *
   Summary
   Number of ancillary data packets on a line query
   Description
   This function gives the number of ancillary data packets
   found on the specified line number of the provided SDI slot.
   
   The concerned stream must be of processing mode including
   ancillary data handling
   Parameters
   SlotHandle :     Handle of the slot to work on
   LineNumber :     Video line number to get count from (1..N,
                    with N depending on the standard)
   AncStream :      Specifies if working on Y or C ancillary data
                    stream (in SD, only C stream is used)
   pNbAncPackets :  Pointer to caller\-allocated variable
                    receiving the ancillary data packets count
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   When working in SD, the AncStream argument value must be
   VHD_SAMPLE_C, since Y and C samples are multiplexed together
   to carry on ancillary data packets
   See Also
   VHD_LockSlotHandle VHD_SlotAncGetPacket                        */
ULONG VIDEOMASTER_HD_API VHD_SlotAncGetNbPackets (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE AncStream, int *pNbAncPackets);


/*** VHD_SlotAncGetPacket ********************************************************/
/*!VHD_SlotAncGetPacket@HANDLE@int@VHD_SAMPLETYPE@int@VHD_ANCPACKET **
   Summary
   Ancillary data packet retrieval
   Description
   This function provides the specified ancillary data packet
   regarding the provided SDI slot.
   
   The concerned stream must be of processing mode including
   ancillary data handling
   Parameters
   SlotHandle :   Handle of the slot to work on
   LineNumber :   Video line number to get packet from (1..N,
                  with N depending on the standard)
   AncStream :    Specifies if working on Y or C ancillary data
                  stream (in SD, only C stream is used)
   PacketIndex :  Index (zero\-based) of the packet to retrieve
   ppAncPacket :  Pointer receiving a pointer to allocated ANC
                  packet structure
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   When working in SD, the AncStream argument value must be
   VHD_SAMPLE_C, since Y and C samples are multiplexed together
   to carry on ancillary data packets.
   
   In RX-modify-TX streams, you can freely update the content of
   the packet, but you cannot change its size. To replace this
   packet with a packet of different size, remove this one and
   allocate a new one
   See Also
   VHD_LockSlotHandle VHD_SlotAncGetNbPackets VHD_ANCPACKET      */
ULONG VIDEOMASTER_HD_API VHD_SlotAncGetPacket (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE AncStream, int PacketIndex, VHD_ANCPACKET **ppAncPacket);


/*** VHD_SlotAncAllocatePacket ***************************************************/
/*!VHD_SlotAncAllocatePacket@HANDLE@BYTE@VHD_ANCPACKET **
   Summary
   Ancillary data packet allocation
   Description
   This function allocates memory for a new ancillary data
   packet. The allocated memory is attached to a SDI slot
   
   The concerned stream must be of processing mode including
   ancillary data handling
   Parameters
   SlotHandle :   Handle of the slot to work on
   DataCount :    Number of User Data Words to allocate
   ppAncPacket :  Pointer receiving a pointer to allocated ANC
                  packet structure
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   Once a new packet has been allocated and properly filled in,
   it may be inserted on a specific video line using the
   VHD_SlotAncInsertPacket function.
   
   Allocated memory is automatically released by VideoMaster
   once the ancillary data slot is unlocked.
   
   User data words of allocated packets are all reset to zero by
   this function.
   
   
   
   Although the allocated packet will contain DataCount user
   data words, the caller may freely set the actual DataCount
   field of the packet structure to a value less or equal to it
   in before subsequent call to VHD_SlotAncInsertPacket
   See Also
   VHD_SlotAncInsertPacket VHD_ANCPACKET                         */
ULONG VIDEOMASTER_HD_API VHD_SlotAncAllocatePacket (HANDLE SlotHandle, BYTE DataCount, VHD_ANCPACKET **ppAncPacket);


/*** VHD_SlotAncInsertPacket *****************************************************/
/*!VHD_SlotAncInsertPacket@HANDLE@int@VHD_SAMPLETYPE@int@VHD_ANCPACKET *
   Summary
   Ancillary data packet insertion
   Description
   This function inserts the given ancillary data packet at the
   specified line within the provided SDI slot.
   
   The concerned stream must be of processing mode including
   ancillary data handling
   Parameters
   SlotHandle :   Handle of the slot to work on
   LineNumber :   Video line number to insert packet on (1..N,
                  with N depending on the standard)
   AncStream :    Specifies if working on Y or C ancillary data
                  stream (in SD, only C stream is used)
   PacketIndex :  Position (zero\-based) to put this packet at
                  (\-1 to insert at last location)
   pAncPacket :   Pointer to ancillary data packet to insert
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   When working in SD, the AncStream argument is ignored, since
   Y and C samples are multiplexed together to carry on
   ancillary data packets.
   
   Packet insertion automatically release allocated packet, so
   that the pAncPacket pointer cannot be re-used without any
   call to VHD_SlotAncAllocatePacket.
   
   
   
   When inserting a packet on a line already containing
   ancillary data, the PacketIndex argument let you decide where
   to place the new packet.
   
   It is related to other packets already present in the same
   zone as the packet to insert, that is in HANC space or in
   active part of the line.
   
   
   
   For example, if a line already contains packets A,B and C in
   HANC space, inserting a new HANC packet N at location 1 will
   give the following result : A,N,B,C
   See Also
   VHD_SlotAncAllocatePacket VHD_ANCPACKET                       */
ULONG VIDEOMASTER_HD_API VHD_SlotAncInsertPacket (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE AncStream, int PacketIndex, VHD_ANCPACKET *pAncPacket);


/*** VHD_SlotAncRemovePacket *****************************************************/
/*!VHD_SlotAncRemovePacket@HANDLE@int@VHD_SAMPLETYPE@int@BOOL32
   Summary
   Ancillary data packet removal
   Description
   This function remove the specified ancillary data packet from
   the specified line on the provided SDI slot.
   
   The concerned stream must be of processing mode including
   ancillary data handling
   Parameters
   SlotHandle :   Handle of the slot to work on
   LineNumber :   Video line number to remove packet from (1..N,
                  with N depending on the standard)
   AncStream :    Specifies if working on Y or C ancillary data
                  stream (in SD, only C stream is used)
   PacketIndex :  Position (zero\-based) of the packet to remove
                  (\-1 to remove all packets from line)
   InHANC :       Specifies if PacketIndex is related to HANC
                  zone or to active line zone. If PacketIndex is
                  \-1, then this argument is ignored and the
                  whole ANC line is erased
   Returns
   The function returns the status of its execution as
   VideoMaster error code (see VHD_ERRORCODE enumeration)
   Remarks
   When working in SD, the AncStream argument is ignored, since
   Y and C samples are multiplexed together to carry on
   ancillary data packets
   See Also
   VHD_LockSlotHandle VHD_SlotAncGetNbPackets                    */
ULONG VIDEOMASTER_HD_API VHD_SlotAncRemovePacket (HANDLE SlotHandle, int LineNumber, VHD_SAMPLETYPE AncStream, int PacketIndex, BOOL32 InHANC);


#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_ANC_H_
