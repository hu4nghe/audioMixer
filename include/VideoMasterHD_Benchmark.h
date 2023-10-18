/*! VideomasterHD_Benchmark.h

    Copyright (c) 2009, DELTACAST. All rights reserved.

    THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
    KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR
    PURPOSE.

  Project : Videomaster

  Package :

  Company : DELTACAST

  Author  : lr                             Date: 2018/09/12

  Purpose :

*/

#ifndef _VIDEOMASTERHD_BENCHMARK_H_
#define _VIDEOMASTERHD_BENCHMARK_H_

/*_ VHD_PCIEBENCHMARK_DIRECTION _____________________________________________*/
/*!
   Summary
   VideoMaster PCIe benchmark transfer direction type
   Description
   The VHD_PCIEBENCHMARK_DIRECTION enumeration lists all the available
   DMA transfer directions used in benchmarking functions
   
   See Also
   <link VHD_PCIeBenchmark, VHD_StartContinuousPCIeBenchmark, VHD_ValidateBoardUsage>
*/
typedef enum _VHD_PCIEBENCHMARK_DIRECTION
{
   VHD_UNIDIRECTIONAL_BENCHMARK_RX,               /*! RX transfer direction */
   VHD_FULLDUPLEX_BENCHMARK_RX,   /*! RX and TX transfer directions, considering RX for measurement */
   VHD_UNIDIRECTIONAL_BENCHMARK_TX,               /*! TX transfer direction */
   VHD_FULLDUPLEX_BENCHMARK_TX,   /*! RX and TX transfer directions, considering TX for measurement */
   NB_VHD_PCIEBENCHMARK_DIRECTION
}VHD_PCIEBENCHMARK_DIRECTION;

/*_ STRUCTURES _______________________________________________________________
//
// This section defines the different structures used by VideomasterHD_Core
*/

/*_ VHD_PCIE_BENCHMARK_MEASURE _______________________________________________________*/
/*!
   Summary
   PCIe bandwidth measurement
   Description
   The VHD_PCIE_BENCHMARK_MEASURE structure holds different measure
   on the available PCIe bandwidth.
   Available channel percentage represents the potential number of channels
   available to transfer the desired buffer size at a given rate.
   For instance, a percentage of 350% means at least 3 channels plus some margin.

   See Also
   <link VHD_PCIeBenchmark, VHD_StartContinuousPCIeBenchmark, VHD_ValidateBoardUsage>
*/
typedef struct _VHD_PCIE_BENCHMARK_MEASURE
{
   VHD_PCIEBENCHMARK_DIRECTION Direction_E;         /*! Direction of transfer */
   ULONG MinimumPercentage_UL;                     /*! Minimum available channel percentage */
   ULONG MaximumPercentage_UL;                     /*! Maximum available channel percentage */
   ULONG AveragePercentage_UL;                     /*! Average available channel percentage */
} VHD_PCIE_BENCHMARK_MEASURE;

/*_ VHD_PCIE_BENCHMARK_CHANNEL_USAGE _______________________________________________________*/
/*!
   Summary
   PCIe bandwidth measurement
   Description
   The VHD_PCIE_BENCHMARK_CHANNEL_USAGE structure holds information on a setup for a channel on
   which PCIe benchmarking is performed.

   See Also
   <link VHD_PCIE_BENCHMARK_BOARD_USAGE, VHD_ValidateBoardUsage>
*/
typedef struct _VHD_PCIE_BENCHMARK_CHANNEL_USAGE
{
   ULONG DmaBufferSize;                         /*!  Size of the DMA buffer */
   ULONG Framerate;                             /*!  Framerate at which the buffer would be sent */
   VHD_PCIEBENCHMARK_DIRECTION Direction;       /*!  Direction of transfer */
}VHD_PCIE_BENCHMARK_CHANNEL_USAGE;

/*_ VHD_PCIE_BENCHMARK_BOARD_USAGE _______________________________________________________*/
/*!
   Summary
   PCIe bandwidth measurement
   Description
   The VHD_PCIE_BENCHMARK_BOARD_USAGE structure holds information on a setup for a board on
   which PCIe benchmarking is performed.

   See Also
   <link VHD_PCIE_BENCHMARK_SETUP, VHD_ValidateBoardUsage>
*/
typedef struct _VHD_PCIE_BENCHMARK_BOARD_USAGE
{
   ULONG BoardIndex;                                  /*!  Index of the board to benchmark on */
   VHD_PCIE_BENCHMARK_CHANNEL_USAGE *pChannelUsage;   /*!  Array of channel usages */
   ULONG NbChannelUsage;                              /*!  Number of channel usages */
}VHD_PCIE_BENCHMARK_BOARD_USAGE;

/*_ VHD_PCIE_BENCHMARK_SETUP _______________________________________________________*/
/*!
   Summary
   PCIe full benchmark setup
   Description
   The VHD_PCIE_BENCHMARK_SETUP structure holds information on a
   complete setup for some boards to perform PCIe benchmarking.
   See Also
   <link VHD_ValidateBoardUsage>                                   */
typedef struct _VHD_PCIE_BENCHMARK_SETUP
{
   VHD_PCIE_BENCHMARK_BOARD_USAGE *pBoardUsage; /*!  Array of board usages */
   ULONG NbBoardUsage;                          /*!  Number of board usages */
   ULONG Duration;                              /*!  Duration of the benchmark (expressed in seconds) */
   ULONG NbPasses;                              /*!  Number of passes */
   ULONG NbLoopsPerPass;                        /*!  Number of loops per pass */
}VHD_PCIE_BENCHMARK_SETUP;


typedef void(*PCIE_BENCHMARK_CALLBACK)(VHD_PCIE_BENCHMARK_MEASURE);
typedef void(*VALIDATE_BOARD_USAGE_PROGRESSION_CALLBACK)(ULONG);

#ifndef EXCLUDE_API_FUNCTIONS


#ifdef __cplusplus
extern "C" {
#endif

/*_ API FUNCTIONS ____________________________________________________________
//
// This section defines the different API functions exported by VideomasterHD_Benchmark
*/

/*** VHD_PCIeBenchmark ***************************************************/
/*!VHD_PCIeBenchmark
   Summary
   VideoMaster PCIe benchmark
   Description
   This function estimates the PCIe bandwidth in terms of available channel percentage. 
   Parameters
   BrdHandle :       Handle of the board to operate on
   Direction :       Direction of the transfer (see VHD_PCIEBENCHMARK_DIRECTION enum)
   BufferSize :      Size of the buffer
   Framerate :       Framerate at which the buffer would be sent
   NbPasses :        Number of passes
   NbLoopsPerPass:   Number of loop per pass
   pMeasurement :     Pointer to caller\-allocated variable to return
                        the measurements (see VHD_PCIE_BENCHMARK_MEASURE structure)
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_PCIeBenchmark(HANDLE BrdHandle, VHD_PCIEBENCHMARK_DIRECTION Direction, ULONG BufferSize, ULONG Framerate, ULONG NbPasses, ULONG NbLoopsPerPass, VHD_PCIE_BENCHMARK_MEASURE* pMeasurement);

/*** VHD_StartContinuousPCIeBenchmark ***************************************************/
/*!VHD_StartContinuousPCIeBenchmark
   Summary
   VideoMaster PCIe benchmark (threaded)
   Description
   This function starts a continuous PCIe bandwidth benchmarking.
   It can be stopped via the function VHD_StopContinuousPCIeBenchmark.
   Parameters
   BrdHandle :       Handle of the board to operate on
   ThreadHandle :    Pointer to a caller\-allocated variable
                         receiving the thread handle
   Direction :       Direction of the transfer (see VHD_PCIEBENCHMARK_DIRECTION enum)
   BufferSize :      Size of the buffer
   Framerate :       Framerate at which the buffer would be sent
   NbPasses :        Number of passes
   NbLoopsPerPass :  Number of loop per pass
   Callback :        User-provided function through which intermediate
                        measurements are returned
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_StartContinuousPCIeBenchmark(HANDLE BrdHandle, HANDLE* pThreadHandle, VHD_PCIEBENCHMARK_DIRECTION Direction, ULONG BufferSize, ULONG Framerate, ULONG NbPasses, ULONG NbLoopsPerPass, PCIE_BENCHMARK_CALLBACK Callback);

/*** VHD_StopContinuousPCIeBenchmark ***************************************************/
/*!VHD_StopContinuousPCIeBenchmark
   Summary
   VideoMaster PCIe benchmark (threaded)
   Description
   This function stops the previously started continuous PCIe bandwidth benchmarking.
   It has to follow a call to the function VHD_StartContinuousPCIeBenchmark to be relevant.
   Parameters
   BrdHandle :    Handle of the board to operate on
   ThreadHandle : Handle of the thread to stop   
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_StopContinuousPCIeBenchmark(HANDLE BrdHandle, HANDLE ThreadHandle);

/*** VHD_ValidateBoardUsage ***************************************************/
/*!VHD_ValidateBoardUsage
   Summary
   Validate board usage through PCIe benchmark
   Description
   This functions takes a complete board usage setup as input and
   tries to measure the minimum, average and maximum available channel percentage in RX and/or TX.

   If the setup does not contain any RX (resp. TX) channel setups, then the parameter pRxMeasures (resp. pTxMeasures)
   can be omitted (set to NULL).
   Should both parameters be non-NULL but only one direction is effectively measured, the other parameter will
   see its "direction" variable set to NB_VHD_PCIEBENCHMARK_DIRECTION (see VHD_PCIEBENCHMARK_DIRECTION enumeration)
   as a way to tell that no measurement had to be done on that direction.
   Parameters
   Setup :        Benchmarking setup (see VHD_PCIE_BENCHMARK_SETUP)
   pRxMeasures :  Pointer to a caller\-allocated variable
                     receiving the computed RX measures
   pTxMeasures :  Pointer to a caller\-allocated variable
                     receiving the computed TX measures
   Callback :     User-provided function through which progression is returned
   Returns
   The function returns the status of its execution as
   VideoMasterHD error code (see VHD_ERRORCODE enumeration)      */
VIDEOMASTER_HD_API ULONG VHD_ValidateBoardUsage(VHD_PCIE_BENCHMARK_SETUP Setup, VHD_PCIE_BENCHMARK_MEASURE* pRxMeasures, VHD_PCIE_BENCHMARK_MEASURE* pTxMeasures, VALIDATE_BOARD_USAGE_PROGRESSION_CALLBACK Callback);

#ifdef __cplusplus
}
#endif

#endif //EXCLUDE_API_FUNCTIONS


#endif // _VIDEOMASTERHD_BENCHMARK_H_
