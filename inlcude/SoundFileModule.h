#ifndef SOUNDFILE_MODULE_H
#define SOUNDFILE_MODULE_H

#include "sndfile.hh"
#include "audioQueue.h"

void sndfileReceive(std::vector<audioQueue<float>>& queueList, int PA_SAMPLE_RATE, int PA_OUTPUT_CHANNELS);

#endif