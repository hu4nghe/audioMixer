#ifndef NDI_MODULE_H
#define NDI_MODULE_H

#include "audioQueue.h"

void NDIAudioReceive(std::vector<audioQueue<float>>& queueList, int PA_SAMPLE_RATE, int PA_OUTPUT_CHANNELS);

#endif//NDI_MODUEL_H