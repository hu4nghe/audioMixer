#ifndef SOUNDFILE_MODULE_H
#define SOUNDFILE_MODULE_H

#include "sndfile.hh"
#include "audioQueue.h"
#include <filesystem>

namespace fs = std::filesystem;
/*
void sndfileReceive(std::vector<audioQueue<float>>& queueList, int PA_SAMPLE_RATE, int PA_OUTPUT_CHANNELS);
*/
class sndfileInputList
{
	public:

				sndfileInputList		()													= default;
				sndfileInputList		(const	sndfileInputList&					other)	= delete;
				sndfileInputList		(		sndfileInputList&&					other)	= delete;
			   ~sndfileInputList		()													= default;

		void	selectAudioFile			();
		void	readAudioFile			(		std::vector<audioQueue<float>>&		queue,
										 const	std::				uint32_t		PA_SAMPLE_RATE,
										 const  std::				uint32_t		PA_OUTPUT_CHANNELS);
	private:
		std::vector<fs::path> pathList;
};


#endif