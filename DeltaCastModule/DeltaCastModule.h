#ifndef DELTACAST_MODULE_H
#define DELTACAST_MODULE_H

#include <vector>

#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Dv.h"
#include "VideoMasterHD_Dv_Audio.h"

class HDMIAudioStreamList
{
public:

	HDMIAudioStreamList() = default;
	~HDMIAudioStreamList() = default;

	bool HDMICheck();
	bool HDMIAudioRecv(const int PA_SAMPLE_RATE, const int PA_OUTPUT_CHANNELS);
	


private:

};
#endif