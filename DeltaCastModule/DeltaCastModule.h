#ifndef DELTACAST_MODULE_H
#define DELTACAST_MODULE_H

#include <vector>

#include "VideoMasterHD_Core.h"
#include "VideoMasterHD_Dv.h"
#include "VideoMasterHD_Dv_Audio.h"

class HDMIAudioStream
{
public:
<<<<<<< HEAD
	HDMIAudioStream();
   ~HDMIAudioStream();
	bool hardwareInfoCheck();
	bool videoStreamInfoCheck();
	void getAudioData(const int PA_SAMPLE_RATE, const int PA_OUTPUT_CHANNELS);

private:
	HANDLE boardHandle;
	HANDLE streamHandle;
	HANDLE slotHandle;
};

=======

	HDMIAudioStreamList() = default;
	~HDMIAudioStreamList() = default;

	bool HDMICheck();
	bool HDMIAudioRecv(const int PA_SAMPLE_RATE, const int PA_OUTPUT_CHANNELS);
	
>>>>>>> 2b8ac42f9af21b6a69306f1a92c131c931f09683


private:

};
#endif