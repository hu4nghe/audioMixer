#ifndef DELTACAST_MODULE_H
#define DELTACAST_MODULE_H

#include <vector>

#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Dv.h"
#include "VideoMasterHD_Dv_Audio.h"
/*
class HDMIAudioStream
{
public:
	HDMIAudioStream();
   ~HDMIAudioStream();
	bool hardwareInfoCheck();
	bool videoStreamInfoCheck();
	void getAudioData(const int PA_SAMPLE_RATE, const int PA_OUTPUT_CHANNELS);

private:
	HANDLE boardHandle;
	HANDLE streamHandle;
	HANDLE slotHandle;
};*/
bool combineBYTETo24Bit(const std::uint8_t* sourceAudio,
	const std::size_t  sourceSize,
	std::int32_t* combined24bit);

void DeltaCastRecv(					std::vector<audioQueue<std::int32_t>>& queue,
							const	std::uint32_t	                PA_SAMPLE_RATE,
							const	std::uint32_t	                PA_OUTPUT_CHANNELS,
							const	std::uint32_t	                BUFFER_MAX,
							const	std::uint32_t	                BUFFER_MIN);

#endif