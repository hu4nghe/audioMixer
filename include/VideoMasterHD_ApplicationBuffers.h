/*! VideomasterHD_ApplicationBuffers.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : VideomasterHD

  Package : 

  Company : DELTACAST

  Author  : gt                             Date: 2009/06/26

  Purpose : 

*/


#ifndef _VIDEOMASTERHD_APPLICATIONBUFFERS_H_
#define _VIDEOMASTERHD_APPLICATIONBUFFERS_H_


#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Sdi
*/


/*** VHD_InitApplicationBuffers ***************************************************/
/*!
   Summary
   Enables and initializes "application buffers" mechanism. 
   
   Description
   The "application buffers" mechanism allows the user application to provide its own
   buffers to transfer data to or from the card. Without this mechanism, the 
   buffers are allocated inside the VHD_StartStream function. 

   Parameters
   StreamHandle (IN) : Handle of the stream

   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   Remarks
   This function must be called after configuring the stream (ie. setting
   off-line properties) and before calling VHD_StartStream.
   Enabling "application buffers" mechanism forces the slaved transfer scheme.
   "application buffers" mechanism is not available on a RXmTX stream.
   
   See Also
   VHD_GetApplicationBuffersSize
   VHD_CreateSlot
   VHD_DestroySlot
   VHD_QueueOutSlot
   VHD_QueueInSlot
   VHD_WaitSlotSent
   VHD_WaitSlotFilled
   VHD_SetSlotParity
*/
VIDEOMASTER_HD_API ULONG VHD_InitApplicationBuffers(HANDLE StreamHandle);

/*** VHD_GetApplicationBuffersSize ***************************************************/
/*!
   Summary
   Get application buffers size
   
   Description
   This function returns the buffers size required for each buffer type that the user
   has to allocate when using the "application buffers" mechanism. 
   
  
   Parameters
   StreamHandle (IN): Handle of the stream
   BufferType (IN): Set to VHD_SDI_BUFFERTYPE
                     on SDI streams, to VHD_DV_BUFFERTYPE
                     on DVI streams, or to VHD_ASI_BUFFERTYPE
                     on ASI streams
   pBufferSize (OUT): Pointer to a caller-allocated variable 
                      receiving the size of this buffer type.
					
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   VHD_GetApplicationBuffersSize must be called after VHD_InitApplicationBuffers.

 
   See Also
   VHD_InitApplicationBuffers      
   VHD_CreateSlot   
*/
VIDEOMASTER_HD_API ULONG VHD_GetApplicationBuffersSize (HANDLE StreamHandle, ULONG BufferType, ULONG *pBufferSize);


/*** VHD_CreateSlot ***************************************************/
/*!
   Summary
   Slot creation
   
   Description
   This function creates a slot based on application buffers. An application 
   buffer address must be aligned on 4096-byte border.
   
  
   Parameters
   StreamHandle (IN): Handle of the stream
   ppBuffer (IN): Table containing user buffers pointers for
				  each buffer type. The table size must be equal to 
				  NB_VHD_xxx_BUFFERTYPE, where 'xxx' depends on 
				  the stream processing mode. The buffers size to allocate
				  can be known thanks to VHD_GetApplicationBuffersSize
   pSlot (OUT): Pointer to a user variable receiving the slot handle
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   VHD_CreateSlot must be called after VHD_InitApplicationBuffers.
   VHD_CreateSlot locks the provided buffer into physical memory. 

 
   See Also
   VHD_InitApplicationBuffers  
   VHD_GetApplicationBuffersSize
   VHD_DestroySlot
   VHD_QueueOutSlot
   VHD_QueueInSlot
*/
VIDEOMASTER_HD_API ULONG VHD_CreateSlot (HANDLE StreamHandle, BYTE *ppBuffer[], HANDLE *pSlot);

/*** VHD_DestroySlot ***************************************************/
/*!
   Summary
   Slot destruction
   
   Description
   This function destroys a slot previously created with VHD_CreateSlot. 
   
   
   Parameters
   SlotHandle (IN): Handle of the slot
   
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   This function unlocks application buffers from physical memory. Unused 
   application buffers should be unlocked to free physical memory.
   The corresponding slot cannot be currently present in the buffer queue. 
   Buffers are removed from the FIFO on VHD_WaitSlotFilled for a
   reception stream. For transmission streams,
   buffers are removed from the FIFO on VHD_WaitSlotSent.
   VHD_DestroySlot is internally called during VHD_StopStream call for 
   undestroyed slots.

 
   See Also
   VHD_CreateSlot
   VHD_WaitSlotSent
   VHD_WaitSlotFilled
*/
VIDEOMASTER_HD_API ULONG VHD_DestroySlot (HANDLE SlotHandle);


/*** VHD_SetSlotParity ***************************************************/
/*!
   Summary
   Set slot parity
   
   Description
   This function set the parity of a TX slot
   
   
   Parameters
   SlotHandle (IN): Handle of the slot
   EvenParity (IN): Even parity of the slot
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   This function is only available with the "application buffers" mechanism
   on a transmission stream in field mode.

 
   See Also
   VHD_GetSlotParity
*/
VIDEOMASTER_HD_API ULONG VHD_SetSlotParity (HANDLE SlotHandle, BOOL32 EvenParity);

/*** VHD_QueueOutSlot ***************************************************/
/*!
   Summary
   Queue a slot for sending
   
   Description
   When using "application buffers" mechanism, this function allow the user
   to queue a buffer for sending.  
  
   Parameters
   SlotHandle (IN): Handle of the slot
  
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   The FIFO can contains up to 32 buffers. The current number of buffer present in
   the output FIFO is known by reading VHD_CORE_SP_BUFFERQUEUE_FILLING property. 
   Buffers are removed from the FIFO on a successfull call to VHD_WaitSlotSent.
   Consumed buffers can be re-added to the buffer with a new call to VHD_QueueOutSlot. 
  
 
   See Also
   VHD_CreateSlot
   VHD_QueueOutSlot
*/
VIDEOMASTER_HD_API ULONG VHD_QueueOutSlot (HANDLE SlotHandle);

/*** VHD_QueueInSlot ***************************************************/
/*!
   Summary
   Queue a slot for receiving
   
   Description
   When using "application buffers" mechanism, this function allows the user
   to queue a buffer for receiving. The user has to add buffers to the buffer 
   queue before calling VHD_WaitSlotFilled. Buffers are returned by 
   VHD_WaitSlotFilled in the same order that they are added by VHD_QueueInSlot
   
   Parameters
   SlotHandle (IN): Handle of the slot
  
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   The FIFO can contains up to 32 buffers. The current number of buffer present in
   the input FIFO is known by reading VHD_CORE_SP_BUFFERQUEUE_DEPTH property. 
   VHD_CORE_SP_BUFFERQUEUE_FILLING property informs about the number of buffer of 
   the buffer queue that are filled with received data.
   Buffers are removed from the FIFO on a successfull call to VHD_WaitSlotFilled.
   Consumed buffers can be re-added to the buffer with a new call to VHD_QueueInSlot. 
  
 
   See Also
   VHD_CreateSlot
   VHD_QueueInSlot
*/
VIDEOMASTER_HD_API ULONG VHD_QueueInSlot (HANDLE SlotHandle);

/*** VHD_WaitSlotSent ***************************************************/
/*!
   Summary
   Wait a slot to be sent

   
   Description  
   This function returns a pointer to the slot that has been sent to the card.
   
  
   Parameters
   StreamHandle (IN): Handle of the stream
   *pSlotHandle (OUT): pointer to the sent slot handle
   Timeout (IN): Timeout value in ms
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   Remarks
   This function is only available for transmission streams.
   
   See Also
   VHD_CreateSlot
   VHD_QueueOutSlot
*/
VIDEOMASTER_HD_API ULONG VHD_WaitSlotSent(HANDLE StreamHandle, HANDLE *pSlotHandle, ULONG Timeout);


/*** VHD_WaitSlotFilled ***************************************************/
/*!
   Summary
   Wait a filled slot 

   
   Description  
   This function returns a pointer to the slot that has been filled by the card.
  
   Parameters
   StreamHandle (IN): Handle of the stream
   *pSlotHandle (OUT): pointer to the filled slot handle
   Timeout (IN): Timeout value in ms
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   Remarks
   This function is only available for reception streams.
   
   See Also
   VHD_CreateSlot
   VHD_QueueInSlot
*/
VIDEOMASTER_HD_API ULONG VHD_WaitSlotFilled(HANDLE StreamHandle, HANDLE *pSlotHandle, ULONG Timeout);

/*** VHD_SetSlotSubframeIndex ***************************************************/
/*!
   Summary
   Set slot sub frame index
   
   Description
   This function set the sub frame index of a TX slot
   
   
   Parameters
   SlotHandle (IN): Handle of the slot
   SubFrameIdx (IN): Sub frame index of the slot
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   This function is only available with the "application buffers" mechanism
   on a transmission stream in field mode.

   See Also
   VHD_GetSlotSubframeIndex
*/
VIDEOMASTER_HD_API ULONG VHD_SetSlotSubframeIndex(HANDLE SlotHandle, ULONG SubFrameIdx);


/*** VHD_TerminateSlot ***************************************************/
/*!
   Summary
   Terminates processing of a particular slot
   
   Description
   This function terminates the processing of a slot, which lets one to queue another slot.
   Without this function, the slot that is queued is always the same as the one that was retrieved
   through VHD_WaitSlotSent.
   
   
   Parameters
   SlotHandle (IN): Handle of the slot
   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)
   
   
   Remarks
   This function is only available with the "application buffers" mechanism
   on a transmission stream and when ULL is activated.

   See Also
   VHD_WaitSlotSent
*/
VIDEOMASTER_HD_API ULONG VHD_TerminateSlot(HANDLE SlotHandle);


#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_APPLICATIONBUFFERS_H_
