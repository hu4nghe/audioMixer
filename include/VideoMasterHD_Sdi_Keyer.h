/*! VideomasterHD_Sdi_Keyer.h

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


#ifndef _VIDEOMASTERHD_SDI_KEYER_H_
#define _VIDEOMASTERHD_SDI_KEYER_H_


/*_ CONSTANTS ________________________________________________________________
//
// This section defines the different constants used by VideomasterHD_Keyer
*/


/*! RX channel status bit masks. These constants define status bit masks for the VHD_CORE_BP_RXx_STATUS and  board properties */
#define VHD_KEYER_RXSTS_MISALIGNED  0x00000010  /*! RX channel misalignment indicator. This bit is set to '1' when the incoming signal is too far enough from the reference clock */



/*_ ENUMERATIONS _____________________________________________________________
//
// This section defines the different enumerations used by VideomasterHD_Keyer
*/

/*_ VHD_KEYER_BOARDPROPERTY _______________________________________________*/
/*!
Summary
   Hardware keyer board properties
Description
The VHD_KEYER_BOARDPROPERTY enumeration lists all the available keyer
board properties.

These values are used as indexes for VHD_GetBoardProperty and 
VHD_SetBoardProperty functions calls

See Also
VHD_GetBoardProperty
VHD_SetBoardProperty
*/

typedef enum _VHD_KEYER_BOARDPROPERTY
{
   VHD_KEYER_BP_ENABLE_0 = ENUMBASE_KEYER,           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ENABLE_0
                                                      Hardware keyer enable (default is FALSE)                          */
   VHD_KEYER_BP_INPUT_A_0,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_A_0
                                                      Keyer first input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX0                        */
   VHD_KEYER_BP_INPUT_B_0,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_B_0
                                                      Keyer second input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX0                        */
   VHD_KEYER_BP_INPUT_K_0,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_K_0
                                                      Keyer key input selection (see VHD_KEYERINPUT),
                                                      default is VHD_KINPUT_RX0                                         */
   VHD_KEYER_BP_VIDEOOUTPUT_TX_0,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_VIDEOOUTPUT_TX_0
                                                      TX0 connector video output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_KEYER                    */
   VHD_KEYER_BP_VIDEOOUTPUT_TX_1,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_VIDEOOUTPUT_TX_1
                                                      TX1 connector video output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_TEST                     */
   VHD_KEYER_BP_ANCOUTPUT_TX_0,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOUTPUT_TX_0
                                                      TX0 connector ancillary data output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_TEST                     */
   VHD_KEYER_BP_ANCOUTPUT_TX_1,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOUTPUT_TX_1
                                                      TX1 connector ancillary data output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_TEST                     */
   VHD_KEYER_BP_BLENDING_TYPE_0,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_BLENDING_TYPE_0
                                                      Alpha blending type (see VHD_KEYERBLENDINGTYPE),
                                                      default is VHD_BLENDING_MULTIPLICATIVE                            */
   VHD_KEYER_BP_ALPHACLIP_MIN_0,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MIN_0
                                                      Minimum value for alpha clipping (default is 0)                   */
   VHD_KEYER_BP_ALPHACLIP_MAX_0,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MAX_0
                                                      Maximum value for alpha clipping (default is 1020)                */
   VHD_KEYER_BP_ALPHABLEND_FACTOR_0,                 /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHABLEND_FACTOR_0
                                                      Global alpha blending factor (default is 0)                       */
   VHD_KEYER_BP_INVERT_KEY_0,                        /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INVERT_KEY_0
                                                      Alpha blending inversion (default is FALSE)                       */
   VHD_KEYER_BP_RX_GENLOCK_OFFSET_0_DEPRECATED,      /*!This value is now deprecated and replaced by 
                                                      VHD_SDI_BP_RX0_GENLOCK_OFFSET                                    */
   VHD_KEYER_BP_RX_GENLOCK_OFFSET_1_DEPRECATED,      /*!This value is now deprecated and replaced by 
                                                      VHD_SDI_BP_RX1_GENLOCK_OFFSET                                    */
   VHD_KEYER_BP_RX_BLACK_0,                          /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_RX_BLACK_0
                                                      RX0 signal is replaced by a black video signal (default is FALSE) */
   VHD_KEYER_BP_RX_BLACK_1,                          /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_RX_BLACK_1
                                                      RX1 signal is replaced by a black video signal (default is FALSE) */
   VHD_KEYER_BP_KCOMPRESSOR_0,                       /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_KCOMPRESSOR_0
                                                      Hardware key compressor enable (default is FALSE)                 */
   VHD_KEYER_BP_ANCOVERRIDE_TX_0,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOVERRIDE_TX_0
                                                      TX0 connector ancillary data output source priority
                                                      (see VHD_KEYERANCOVERRIDE), default is VHD_ANCOVERRIDE_STATICMODE */
   VHD_KEYER_BP_ANCOVERRIDE_TX_1,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOVERRIDE_TX_1
                                                      TX1 connector ancillary data output source priority
                                                      (see VHD_KEYERANCOVERRIDE), default is VHD_ANCOVERRIDE_STATICMODE */
   VHD_KEYER_BP_LUMACLIP_MIN_0,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MIN_0
                                                      Lower 10-bit luma value on keyer SDI output (default is 64)       */
   VHD_KEYER_BP_LUMACLIP_MAX_0,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MAX_0
                                                      Higher 10-bit luma value on keyer SDI output (default is 940)     */
   VHD_KEYER_BP_CHROMACLIP_MIN_0,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MIN_0
                                                      Lower 10-bit chroma value on keyer SDI output (default is 64)     */
   VHD_KEYER_BP_CHROMACLIP_MAX_0,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MAX_0
                                                      Higher 10-bit chroma value on keyer SDI output (default is 960)   */
   VHD_KEYER_BP_ENABLE_1,                            /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ENABLE_1
                                                      hardware keyer enable (default is FALSE)                          */
   VHD_KEYER_BP_INPUT_A_1,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_A_1
                                                      Keyer first input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX1                        */
   VHD_KEYER_BP_INPUT_B_1,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_B_1
                                                      Keyer second input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX1                        */
   VHD_KEYER_BP_INPUT_K_1,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_K_1
                                                      Keyer key input selection (see VHD_KEYERINPUT),
                                                      default is VHD_KINPUT_RX1                                         */
   VHD_KEYER_BP_BLENDING_TYPE_1,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_BLENDING_TYPE_1
                                                      Alpha blending type (see VHD_KEYERBLENDINGTYPE),
                                                      default is VHD_BLENDING_MULTIPLICATIVE                            */
   VHD_KEYER_BP_ALPHACLIP_MIN_1,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MIN_1
                                                      Minimum value for alpha clipping (default is 0)                   */
   VHD_KEYER_BP_ALPHACLIP_MAX_1,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MAX_1
                                                      Maximum value for alpha clipping (default is 1020)                */
   VHD_KEYER_BP_ALPHABLEND_FACTOR_1,                 /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHABLEND_FACTOR_1
                                                      Global alpha blending factor (default is 0)                       */
   VHD_KEYER_BP_INVERT_KEY_1,                        /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INVERT_KEY_1
                                                      Alpha blending inversion (default is FALSE)                       */
   VHD_KEYER_BP_KCOMPRESSOR_1,                       /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_KCOMPRESSOR_1
                                                      Hardware key compressor enable (default is FALSE)                 */
   VHD_KEYER_BP_LUMACLIP_MIN_1,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MIN_1
                                                      Lower 10-bit luma value on keyer SDI output (default is 64)       */
   VHD_KEYER_BP_LUMACLIP_MAX_1,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MAX_1
                                                      Higher 10-bit luma value on keyer SDI output (default is 940)     */
   VHD_KEYER_BP_CHROMACLIP_MIN_1,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MIN_1
                                                      Lower 10-bit chroma value on keyer SDI output (default is 64)     */
   VHD_KEYER_BP_CHROMACLIP_MAX_1,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MAX_1
                                                      Higher 10-bit chroma value on keyer SDI output (default is 960)   */
   VHD_KEYER_BP_ENABLE_2,                            /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ENABLE_2
                                                      hardware keyer enable (default is FALSE)                          */
   VHD_KEYER_BP_INPUT_A_2,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_A_2
                                                      Keyer first input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX2                        */
   VHD_KEYER_BP_INPUT_B_2,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_B_2
                                                      Keyer second input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX2                        */
   VHD_KEYER_BP_INPUT_K_2,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_K_2
                                                      Keyer key input selection (see VHD_KEYERINPUT),
                                                      default is VHD_KINPUT_RX2                                         */
   VHD_KEYER_BP_VIDEOOUTPUT_TX_2,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_VIDEOOUTPUT_TX_2
                                                      TX2 connector video output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_KEYER                    */
   VHD_KEYER_BP_ANCOUTPUT_TX_2,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOUTPUT_TX_2
                                                      TX2 connector ancillary data output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_TEST                     */
   VHD_KEYER_BP_BLENDING_TYPE_2,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_BLENDING_TYPE_2
                                                      Alpha blending type (see VHD_KEYERBLENDINGTYPE),
                                                      default is VHD_BLENDING_MULTIPLICATIVE                            */
   VHD_KEYER_BP_ALPHACLIP_MIN_2,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MIN_2
                                                      Minimum value for alpha clipping (default is 0)                   */
   VHD_KEYER_BP_ALPHACLIP_MAX_2,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MAX_2
                                                      Maximum value for alpha clipping (default is 1020)                */
   VHD_KEYER_BP_ALPHABLEND_FACTOR_2,                 /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHABLEND_FACTOR_2
                                                      Global alpha blending factor (default is 0)                       */
   VHD_KEYER_BP_INVERT_KEY_2,                        /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INVERT_KEY_2
                                                      Alpha blending inversion (default is FALSE)                       */
   VHD_KEYER_BP_RX_GENLOCK_OFFSET_2_DEPRECATED,      /*!This value is now deprecated and replaced by 
                                                      VHD_SDI_BP_RX2_GENLOCK_OFFSET                                    */
   VHD_KEYER_BP_RX_BLACK_2,                          /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_RX_BLACK_2
                                                      RX2 signal is replaced by a black video signal (default is FALSE) */
   VHD_KEYER_BP_KCOMPRESSOR_2,                       /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_KCOMPRESSOR_2
                                                      hardware key compressor enable (default is FALSE)                 */
   VHD_KEYER_BP_ANCOVERRIDE_TX_2,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOVERRIDE_TX_2
                                                      TX2 connector ancillary data output source priority
                                                      (see VHD_KEYERANCOVERRIDE), default is VHD_ANCOVERRIDE_STATICMODE */
   VHD_KEYER_BP_LUMACLIP_MIN_2,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MIN_2
                                                      Lower 10-bit luma value on keyer SDI output (default is 64)       */
   VHD_KEYER_BP_LUMACLIP_MAX_2,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MAX_2
                                                      Higher 10-bit luma value on keyer SDI output (default is 940)     */
   VHD_KEYER_BP_CHROMACLIP_MIN_2,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MIN_2
                                                      Lower 10-bit chroma value on keyer SDI output (default is 64)     */
   VHD_KEYER_BP_CHROMACLIP_MAX_2,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MAX_2
                                                      Higher 10-bit chroma value on keyer SDI output (default is 960)   */
   VHD_KEYER_BP_ENABLE_3,                            /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ENABLE_3
                                                      Hardware keyer enable (default is FALSE)                          */
   VHD_KEYER_BP_INPUT_A_3,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_A_3
                                                      Keyer first input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX3                        */
   VHD_KEYER_BP_INPUT_B_3,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_B_3
                                                      Keyer second input selection (see
                                                      VHD_KEYERINPUT), default is VHD_KINPUT_RX3                        */
   VHD_KEYER_BP_INPUT_K_3,                           /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_K_3
                                                      Keyer key input selection (see VHD_KEYERINPUT),
                                                      default is VHD_KINPUT_RX3                                         */
   VHD_KEYER_BP_VIDEOOUTPUT_TX_3,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_VIDEOOUTPUT_TX_3
                                                      TX3 connector video output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_KEYER                    */
   VHD_KEYER_BP_ANCOUTPUT_TX_3,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOUTPUT_TX_3
                                                      TX3 connector ancillary data output source (see
                                                      VHD_KEYEROUTPUT), default is VHD_KOUTPUT_TEST                     */
   VHD_KEYER_BP_BLENDING_TYPE_3,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_BLENDING_TYPE_3
                                                      Alpha blending type (see VHD_KEYERBLENDINGTYPE),
                                                      default is VHD_BLENDING_MULTIPLICATIVE                            */
   VHD_KEYER_BP_ALPHACLIP_MIN_3,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MIN_3
                                                      Minimum value for alpha clipping (default is 0)                   */
   VHD_KEYER_BP_ALPHACLIP_MAX_3,                     /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHACLIP_MAX_3
                                                      Maximum value for alpha clipping (default is 1020)                */
   VHD_KEYER_BP_ALPHABLEND_FACTOR_3,                 /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ALPHABLEND_FACTOR_3
                                                      Global alpha blending factor (default is 0)                       */
   VHD_KEYER_BP_INVERT_KEY_3,                        /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INVERT_KEY_3
                                                      Alpha blending inversion (default is FALSE)                       */
   VHD_KEYER_BP_RX_GENLOCK_OFFSET_3_DEPRECATED,      /*!This value is now deprecated and replaced by 
                                                      VHD_SDI_BP_RX3_GENLOCK_OFFSET                                    */
   VHD_KEYER_BP_RX_BLACK_3,                          /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_RX_BLACK_3
                                                      RX3 signal is replaced by a black video signal (default is FALSE) */
   VHD_KEYER_BP_KCOMPRESSOR_3,                       /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_KCOMPRESSOR_3
                                                      Hardware key compressor enable (default is FALSE)                 */
   VHD_KEYER_BP_ANCOVERRIDE_TX_3,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_ANCOVERRIDE_TX_3
                                                      TX3 connector ancillary data output source priority
                                                      (see VHD_KEYERANCOVERRIDE), default is VHD_ANCOVERRIDE_STATICMODE */
   VHD_KEYER_BP_LUMACLIP_MIN_3,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MIN_3
                                                      Lower 10-bit luma value on keyer SDI output (default is 64)       */
   VHD_KEYER_BP_LUMACLIP_MAX_3,                      /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_LUMACLIP_MAX_3
                                                      Higher 10-bit luma value on keyer SDI output (default is 940)     */
   VHD_KEYER_BP_CHROMACLIP_MIN_3,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MIN_3
                                                      Lower 10-bit chroma value on keyer SDI output (default is 64)     */
   VHD_KEYER_BP_CHROMACLIP_MAX_3,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_CHROMACLIP_MAX_3
                                                      Higher 10-bit chroma value on keyer SDI output (default is 960)   */
   VHD_KEYER_BP_INPUT_FALLBACK_0,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_FALLBACK_0
                                                      Activate input fallback for keyer 0 (default is FALSE, INPUT_FALLBACK disabled),
                                                      see documentation for further information  */
   VHD_KEYER_BP_INPUT_FALLBACK_1,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_FALLBACK_1
                                                      Activate input fallback for keyer 1 (default is FALSE, INPUT_FALLBACK disabled),
                                                      see documentation for further information  */
   VHD_KEYER_BP_INPUT_FALLBACK_2,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_FALLBACK_2
                                                      Activate input fallback for keyer 2 (default is FALSE, INPUT_FALLBACK disabled),
                                                      see documentation for further information  */
   VHD_KEYER_BP_INPUT_FALLBACK_3,                    /*!_VHD_KEYERPROPERTY::VHD_KEYER_BP_INPUT_FALLBACK_3
                                                      Activate input fallback for keyer 3 (default is FALSE, INPUT_FALLBACK disabled),
                                                      see documentation for further information  */
   NB_VHD_KEYER_BOARDPROPERTIES
} VHD_KEYER_BOARDPROPERTY;

#define VHD_KEYER_BP_ENABLE                  VHD_KEYER_BP_ENABLE_0                        /*! Backward compatibility */                                        
#define VHD_KEYER_BP_INPUT_A                 VHD_KEYER_BP_INPUT_A_0                       /*! Backward compatibility */                                                 
#define VHD_KEYER_BP_INPUT_B                 VHD_KEYER_BP_INPUT_B_0                       /*! Backward compatibility */                 
#define VHD_KEYER_BP_INPUT_K                 VHD_KEYER_BP_INPUT_K_0                       /*! Backward compatibility */                  
#define VHD_KEYER_BP_VIDEOOUTPUT_TX0         VHD_KEYER_BP_VIDEOOUTPUT_TX_0                /*! Backward compatibility */          
#define VHD_KEYER_BP_VIDEOOUTPUT_TX1         VHD_KEYER_BP_VIDEOOUTPUT_TX_1                /*! Backward compatibility */          
#define VHD_KEYER_BP_ANCOUTPUT_TX0           VHD_KEYER_BP_ANCOUTPUT_TX_0                  /*! Backward compatibility */            
#define VHD_KEYER_BP_ANCOUTPUT_TX1           VHD_KEYER_BP_ANCOUTPUT_TX_1                  /*! Backward compatibility */            
#define VHD_KEYER_BP_BLENDING_TYPE           VHD_KEYER_BP_BLENDING_TYPE_0                 /*! Backward compatibility */           
#define VHD_KEYER_BP_ALPHACLIP_MIN           VHD_KEYER_BP_ALPHACLIP_MIN_0                 /*! Backward compatibility */            
#define VHD_KEYER_BP_ALPHACLIP_MAX           VHD_KEYER_BP_ALPHACLIP_MAX_0                 /*! Backward compatibility */            
#define VHD_KEYER_BP_ALPHABLEND_FACTOR       VHD_KEYER_BP_ALPHABLEND_FACTOR_0             /*! Backward compatibility */        
#define VHD_KEYER_BP_INVERT_KEY              VHD_KEYER_BP_INVERT_KEY_0                    /*! Backward compatibility */      
#define VHD_KEYER_BP_RX_GENLOCK_OFFSET_0     VHD_KEYER_BP_RX_GENLOCK_OFFSET_0_DEPRECATED  /*! Backward compatibility */       
#define VHD_KEYER_BP_RX_GENLOCK_OFFSET_1     VHD_KEYER_BP_RX_GENLOCK_OFFSET_1_DEPRECATED  /*! Backward compatibility */   
#define VHD_KEYER_BP_RX_GENLOCK_OFFSET_2     VHD_KEYER_BP_RX_GENLOCK_OFFSET_2_DEPRECATED  /*! Backward compatibility */       
#define VHD_KEYER_BP_RX_GENLOCK_OFFSET_3     VHD_KEYER_BP_RX_GENLOCK_OFFSET_3_DEPRECATED  /*! Backward compatibility */  
#define VHD_KEYER_BP_RX0_GENLOCK_OFFSET      VHD_KEYER_BP_RX_GENLOCK_OFFSET_0_DEPRECATED  /*! Backward compatibility */       
#define VHD_KEYER_BP_RX1_GENLOCK_OFFSET      VHD_KEYER_BP_RX_GENLOCK_OFFSET_1_DEPRECATED  /*! Backward compatibility */       
#define VHD_KEYER_BP_RX0_BLACK               VHD_KEYER_BP_RX_BLACK_0                      /*! Backward compatibility */                
#define VHD_KEYER_BP_RX1_BLACK               VHD_KEYER_BP_RX_BLACK_1                      /*! Backward compatibility */                
#define VHD_KEYER_BP_KCOMPRESSOR             VHD_KEYER_BP_KCOMPRESSOR_0                   /*! Backward compatibility */              
#define VHD_KEYER_BP_ANCOVERRIDE_TX0         VHD_KEYER_BP_ANCOVERRIDE_TX_0                /*! Backward compatibility */          
#define VHD_KEYER_BP_ANCOVERRIDE_TX1         VHD_KEYER_BP_ANCOVERRIDE_TX_1                /*! Backward compatibility */          
#define VHD_KEYER_BP_LUMACLIP_MIN            VHD_KEYER_BP_LUMACLIP_MIN_0                  /*! Backward compatibility */             
#define VHD_KEYER_BP_LUMACLIP_MAX            VHD_KEYER_BP_LUMACLIP_MAX_0                  /*! Backward compatibility */             
#define VHD_KEYER_BP_CHROMACLIP_MIN          VHD_KEYER_BP_CHROMACLIP_MIN_0                /*! Backward compatibility */            
#define VHD_KEYER_BP_CHROMACLIP_MAX          VHD_KEYER_BP_CHROMACLIP_MAX_0                /*! Backward compatibility */


/*_ VHD_KEYERINPUT ___________________________________________________*/
/*!
   Summary
   Hardware keyer inputs
   Description
   The VHD_KEYERINPUT enumeration lists all supported keyer
   \input sources used in <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_INPUT_A>,
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_INPUT_B> and <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_INPUT_K>
   keyer properties
   See Also
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_INPUT_A> <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_INPUT_B>
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_INPUT_K>                                                      */
typedef enum _VHD_KEYERINPUT
{
   VHD_KINPUT_RX0 = 0,         /*! Selects RX0 signal as input */
   VHD_KINPUT_RX1,             /*! Selects RX1 signal as input */
   VHD_KINPUT_TX0,             /*! Selects TX0 PC stream as input */
   VHD_KINPUT_TX1,             /*! Selects TX1 PC stream as input */
   VHD_KINPUT_RX2,             /*! Selects RX2 signal as input */
   VHD_KINPUT_RX3,             /*! Selects RX3 signal as input */
   VHD_KINPUT_TX2,             /*! Selects TX2 PC stream as input */
   VHD_KINPUT_TX3,             /*! Selects TX3 PC stream as input */
   VHD_KINPUT_RX0_HW_PROCESS,  /*! Selects RX0 HW process stream as input */
   VHD_KINPUT_RX1_HW_PROCESS,  /*! Selects RX1 HW process stream as input */
   VHD_KINPUT_RX2_HW_PROCESS,  /*! Selects RX2 HW process stream as input */
   VHD_KINPUT_RX3_HW_PROCESS,  /*! Selects RX3 HW process stream as input */
   NB_VHD_KEYERINPUTS
} VHD_KEYERINPUT;




/*_ VHD_KEYEROUTPUT __________________________________________________*/
/*!
   Summary
   Hardware keyer outputs
   Description
   The VHD_KEYEROUTPUT enumeration lists all supported keyer
   \output types to forward on TX connectors. They are used in <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_VIDEOOUTPUT_TX0>,
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_VIDEOOUTPUT_TX1>,
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOUTPUT_TX0>
   and <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOUTPUT_TX1>
   keyer properties
   See Also
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_VIDEOOUTPUT_TX0> <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_VIDEOOUTPUT_TX1>
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOUTPUT_TX0> <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOUTPUT_TX1>     */

typedef enum _VHD_KEYEROUTPUT
{
   VHD_KOUTPUT_TEST = 0,       /*! Selects green video frame (or no ANC output on TX connector) */
   VHD_KOUTPUT_RX0,            /*! Forward RX0 signal to physical TX connector (or send RX0 ANC to TX connector) */
   VHD_KOUTPUT_RX1,            /*! Forward RX1 signal to physical TX connector (or send RX1 ANC to TX connector) */
   VHD_KOUTPUT_TX0_FILL,       /*! Send TX0 PC stream to physical TX connector (or send TX0 ANC to TX connector) */
   VHD_KOUTPUT_TX1_FILL,       /*! Send TX1 PC stream to physical TX connector (or send TX1 ANC to TX connector) */
   VHD_KOUTPUT_TX0_KEY,        /*! Send alpha component of TX0 PC stream to physical TX connector (only available for video) */
   VHD_KOUTPUT_KEYER,          /*! Select on-board keyer output (only available for video) */
   VHD_KOUTPUT_TX0_4444_KEY,   /*! Send alpha component and chrominances of TX0 PC stream to physical TX connector. Used to emit 4:4:4:4 YUVK (only available for video) */
   VHD_KOUTPUT_RX2,            /*! Forward RX2 signal to physical TX connector (or send RX2 ANC to TX connector) */
   VHD_KOUTPUT_RX3,            /*! Forward RX3 signal to physical TX connector (or send RX3 ANC to TX connector) */
   VHD_KOUTPUT_TX2_FILL,       /*! Send TX2 PC stream to physical TX connector (or send TX2 ANC to TX connector) */
   VHD_KOUTPUT_TX3_FILL,       /*! Send TX3 PC stream to physical TX connector (or send TX3 ANC to TX connector) */
   VHD_KOUTPUT_TX2_KEY,        /*! Send alpha component of TX2 PC stream to physical TX connector (only available for video) */
   VHD_KOUTPUT_RX0_HW_PROCESS, /*! Forward RX0 HW process signal to physical TX connector (or send RX0 HW process ANC to TX connector) */
   VHD_KOUTPUT_RX1_HW_PROCESS, /*! Forward RX1 HW process signal to physical TX connector (or send RX1 HW process ANC to TX connector) */
   VHD_KOUTPUT_RX2_HW_PROCESS, /*! Forward RX2 HW process signal to physical TX connector (or send RX2 HW process ANC to TX connector) */
   VHD_KOUTPUT_RX3_HW_PROCESS, /*! Forward RX3 HW process signal to physical TX connector (or send RX3 HW process ANC to TX connector) */
   NB_VHD_KEYEROUTPUTS
} VHD_KEYEROUTPUT;



/*_ VHD_KEYERBLENDINGTYPE _____________________________________*/
/*!
   Summary
   Hardware keyer alpha blending types
   Description
   The VHD_KEYERBLENDINGTYPE enumeration lists all supported
   keyer alpha blending types used in <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_BLENDING_TYPE>
   keyer property
   See Also
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_BLENDING_TYPE>                                    */

typedef enum _VHD_KEYERBLENDINGTYPE
{
   VHD_BLENDING_MULTIPLICATIVE = 0, /*! Selects multiplicative alpha blending (default) */
   VHD_BLENDING_ADDITIVE,           /*! Select additive alpha blending */
   NB_VHD_KEYERBLENDINGTYPES
} VHD_KEYERBLENDINGTYPE;

/*_ VHD_KEYERANCOVERRIDE _____________________________________*/
/*!
   Summary
   ANC output muxes priority
   Description
   The VHD_KEYERANCOVERRIDE enumeration lists all supported
   ANC override priority for <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOVERRIDE_TX0> and <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOVERRIDE_TX1>
   See Also
   <link VHD_KEYER_BOARDPROPERTY, VHD_KEYER_BP_ANCOVERRIDE_TX0>                                    */

typedef enum _VHD_KEYERANCOVERRIDE
{
   VHD_ANCOVERRIDE_STATICMODE = 0,              /*! ANC/VBI will be taken only from the selected source (default) */
   VHD_ANCOVERRIDE_PRIORITY_ON_TX0,             /*! ANC/VBI will be taken from the selected source except for zones where content is provided
                                                    using the VHD_ST_TX0 stream (running joined or disjoined_anc mode) */
   VHD_ANCOVERRIDE_PRIORITY_ON_TX1,             /*! ANC/VBI will be taken from the selected source except for zones where content is provided
                                                    using the VHD_ST_TX1 stream (running joined or disjoined_anc mode) */
   VHD_ANCOVERRIDE_PRIORITY_ON_TX0_THEN_TX1,    /*! ANC/VBI will be taken from the selected source except for zones where content is provided
                                                    using the VHD_ST_TX0 or VHD_ST_TX1 stream (with priority on TX0 over TX1 on aper-zone basis) */
   VHD_ANCOVERRIDE_PRIORITY_ON_TX2,             /*! ANC/VBI will be taken from the selected source except for zones where content is provided
                                                    using the VHD_ST_TX2 stream (running joined or disjoined_anc mode) */
   VHD_ANCOVERRIDE_PRIORITY_ON_TX3,             /*! ANC/VBI will be taken from the selected source except for zones where content is provided
                                                    using the VHD_ST_TX3 stream (running joined or disjoined_anc mode) */
   VHD_ANCOVERRIDE_PRIORITY_ON_TX2_THEN_TX3,    /*! ANC/VBI will be taken from the selected source except for zones where content is provided
                                                    using the VHD_ST_TX2 or VHD_ST_TX3 stream (with priority on TX2 over TX3 on aper-zone basis) */
   NB_VHD_KEYERANCOVERRIDE
} VHD_KEYERANCOVERRIDE;

/*_ VHD_KEYER_BOARD_CAPABILITY _____________________________________________*/
/*!
  Summary
  VideoMaster SDI keyer board capability
  Description
  The VHD_KEYER_BOARD_CAPABILITY enumeration lists all the available SDI keyer board capabilities
   
  These values are used in VHD_GetBoardCapability function
  See Also
  <link VHD_GetBoardCapability>
*/
typedef enum _VHD_KEYER_BOARD_CAPABILITY
{
   VHD_KEYER_BOARD_CAP_KEYER = ENUMBASE_KEYER,        /*! Return the number of keyer available on the board*/                    
   VHD_KEYER_BOARD_CAP_ADVANCED_INPUT_CONFIG,         /*! Return true if the board supports advanced input configuration handling feature*/
   VHD_KEYER_BOARD_CAP_ADVANCED_OUTPUT_CONFIG,        /*! Return true if the board supports advanced output configuration handling feature*/
   VHD_KEYER_BOARD_CAP_CSC,                           /*! Return true if the board supports color space conversion handling feature*/
   VHD_KEYER_BOARD_CAP_INPUT_FALLBACK,                /*! Return true if the board supports input fallback handling feature*/
   NB_VHD_KEYER_BOARD_CAPABILITY
}VHD_KEYER_BOARD_CAPABILITY;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Keyer
*/

#ifndef EXCLUDE_API_FUNCTIONS

#ifdef __cplusplus
extern "C" {
#endif


/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Keyer
*/
#ifdef __cplusplus
}
#endif

#endif

#endif // _VIDEOMASTERHD_SDI_KEYER_H_
