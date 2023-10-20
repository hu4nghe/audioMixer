#include <print>
#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Dv.h"
#include "VideoMasterHD_Dv_Audio.h"
#include "DeltaCastModule.h"

HDMIAudioStream::HDMIAudioStream()
{
					boardHandle		= nullptr;
					streamHandle	= nullptr;
					slotHandle		= nullptr;
	unsigned long	result			= 0;
	unsigned long	DllVersion		= 0;
	unsigned long	nbBoards		= 0;
	unsigned long	boardType		= 0;
	bool			isHdmiBoard		= false;

	result = VHD_GetApiInfo(&DllVersion, &nbBoards);
	if (result == VHDERR_NOERROR && nbBoards > 0)
	{
		if (VHD_OpenBoardHandle(0, &boardHandle, NULL, 0) == VHDERR_NOERROR)
		{
			VHD_GetBoardProperty(boardHandle, VHD_CORE_BP_BOARD_TYPE, &boardType);
			isHdmiBoard = ((boardType == VHD_BOARDTYPE_HDMI) ||
				(boardType == VHD_BOARDTYPE_HDMI20) ||
				(boardType == VHD_BOARDTYPE_FLEX_HMI) ||
				(boardType == VHD_BOARDTYPE_MIXEDINTERFACE));
		}
	}
	else
	{
		std::print("Error : Cannot query VideoMaster information.\n");
	}

}

HDMIAudioStream::~HDMIAudioStream()
{

	VHD_CloseStreamHandle(streamHandle);
	VHD_CloseBoardHandle(boardHandle);
}

bool HDMIAudioStream::hardwareInfoCheck()
{
	unsigned long result		= 0;
	unsigned long DllVersion	= 0;
	unsigned long nbBoards		= 0;
	unsigned long boardType		= 0;
	bool          isHdmiBoard	= false;

	result = VHD_GetApiInfo(&DllVersion, &nbBoards);
	if (result == VHDERR_NOERROR && nbBoards > 0)
	{
		if (VHD_OpenBoardHandle(0, &boardHandle, NULL, 0) == VHDERR_NOERROR)
		{
			VHD_GetBoardProperty(boardHandle, VHD_CORE_BP_BOARD_TYPE, &boardType);
			isHdmiBoard = (	(boardType == VHD_BOARDTYPE_HDMI)		|| 
							(boardType == VHD_BOARDTYPE_HDMI20)		|| 
							(boardType == VHD_BOARDTYPE_FLEX_HMI)	|| 
							(boardType == VHD_BOARDTYPE_MIXEDINTERFACE));
			if (isHdmiBoard)
			{
				result = VHD_SetStreamProperty(streamHandle, VHD_DV_SP_MODE, VHD_DV_MODE_HDMI);
			}
			
			return isHdmiBoard;
		}
	}
	else
	{
		std::print("Error : Cannot query VideoMaster information.\n");
		return false;
	}
}

bool HDMIAudioStream::videoStreamInfocheck()
{
	unsigned long	result = 0;
	


	return false;
}

void HDMIAudioStream::getAudioData(const int PA_SAMPLE_RATE, const int PA_OUTPUT_CHANNELS)
{
}

/*
bool HDMIValidityCheck()
{
	ULONG SDKVer = 0;
	ULONG boardNumber = 0;
	ULONG boardType = 0;
	HANDLE streamHandle = nullptr;
	VHD_DV_MODE DvMode = NB_VHD_DV_MODES;
		if (VHD_GetApiInfo(&SDKVer, &boardNumber) == VHDERR_NOERROR)
		{
			if (boardNumber > 0)
			{
				HANDLE boardHandle = nullptr;
				if (VHD_OpenBoardHandle(0, &boardHandle, NULL, 0) == VHDERR_NOERROR)
				{
					VHD_GetBoardProperty(boardHandle, VHD_CORE_BP_BOARD_TYPE, &boardType);
					bool HDMI = ((boardType == VHD_BOARDTYPE_HDMI) ||
						(boardType == VHD_BOARDTYPE_HDMI20));
					if (HDMI)
					{
						if (VHD_OpenStreamHandle(boardHandle, VHD_ST_RX0, HDMI ? VHD_DV_STPROC_JOINED : VHD_DV_STPROC_DEFAULT, NULL, &streamHandle, NULL) == VHDERR_NOERROR)
						{
							if (VHD_SetStreamProperty(streamHandle, VHD_DV_SP_MODE, VHD_DV_MODE_HDMI) == VHDERR_NOERROR)
							{
								while (DvMode != VHD_DV_MODE_HDMI || Result != VHDERR_NOERROR)
								{
									VHD_GetStreamProperty(streamHandle, VHD_DV_SP_MODE, (ULONG*)&DvMode);
								}

							}

						}

					}
				}
			}
		}
	return false;
}*/