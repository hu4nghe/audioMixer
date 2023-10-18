/*! VideomasterHD_Sdi_Vbi.h

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


#ifndef _VIDEOMASTERHD_SDI_VBI_H_
#define _VIDEOMASTERHD_SDI_VBI_H_

#ifdef __cplusplus
extern "C" {
#endif


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Vbi
*/


/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Vbi
*/


/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Vbi
*/






#ifndef EXCLUDE_API_FUNCTIONS

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Vbi
*/


/*** VHD_VbiDigitalize *******************************************************/
/*!VHD_VbiDigitalize
   <keywords VBI>
   
   Summary
   VBI line digitalization
   Description
   This function digitalizes the provided VBI line.
   
   It recovers the sequence of high and low levels (ones and
   zeros) carried on as a waveform within the provided line
   buffer, and presents them as a buffer of digital data bits
   (stored as bytes).
   Parameters
   pSourceLine :            Pointer to source video line buffer,
                            as provided by VHD_SlotVbiGetLine
   SourceLineSize :         Size, in bytes, of the source video
                            line buffer
   HdSdi :                  Boolean telling whether the buffer
                            contains HD SDI (TRUE) or SD SDI
                            (FALSE).
                            * HD SDI implies an interface
                              sampling frequency of 74.25 MHz and a
                              source buffer containing either Y or
                              C samples
                            * SD SDI implies an interface
                              sampling frequency of 13.5 MHz and a
                              source buffer containing interleaved
                              Y and C samples 
   DigitalBitrate :         Clock frequency, in Hz, of digital
                            signal to recover
   pDestBuffer :            Optional pointer to caller\-allocated
                            buffer receiving digitalized signal.
                            If NULL, then the function will
                            specify maximum needed buffer size
                            through pDestBufferSize argument
   pDestBufferSizeInBits :  Pointer to caller\-allocated variable
                            specifying size, in bits, of buffer
                            pointed by pDestBuffer, and updated
                            by the function with actual digital
                            data size, in bits
   Returns
   The function returns the status of its execution as a
   VideoMaster error code (see VHD_ERRORCODE enumeration in
   VideoMasterHD.h)
   Remarks
   The caller is responsible of properly allocating pDestBuffer
   buffer, whose size must be sufficient to store
   pDestBufferSizeInBits bits.
   
   
   
   Digitalized data are stored in their reception order, from
   most significant bit of first byte of buffer to least
   significant bit of last byte of buffer.
   
   
   
   \Example of storage on a 2-byte buffer of a couple of
   received bit sequences :
     * '1' will be stored as '0x80','0x00'
     * '0','1' will be stored as '0x40','0x00'
     * '1,1,1,1,1,1,1,1' will be stored as '0xFF','0x00'
     * '1,0,1,1,0,1,1,1,0,1,1,1,1' will be stored as
       '0xB7','0x78'
   
   See Also
   VHD_SlotVbiGetLine  
   */

#ifdef __cplusplus
VIDEOMASTER_HD_API ULONG VHD_VbiDigitalize (BYTE *pSourceLine, ULONG SourceLineSize, BOOL32 HdSdi, float DigitalBitrate, BYTE *pDestBuffer, ULONG *pDestBufferSizeInBits, BOOL32 VBI10Bits_B = FALSE);
#else
VIDEOMASTER_HD_API ULONG VHD_VbiDigitalize (BYTE *pSourceLine, ULONG SourceLineSize, BOOL32 HdSdi, float DigitalBitrate, BYTE *pDestBuffer, ULONG *pDestBufferSizeInBits, BOOL32 VBI10Bits_B);
#endif


#endif

#ifdef __cplusplus
}
#endif

#endif // _VIDEOMASTERHD_SDI_VBI_H_

