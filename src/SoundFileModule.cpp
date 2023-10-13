#include "SoundFileModule.h"
#include <string>
#include <iostream>


void sndfileInputList::selectAudioFile()
{
	std::vector<fs::path> pathList;
	std::print("Sndfile: Please enter the path of the sound file, enter end to confirm.");
	std::string filePathStr;
	do
	{
		std::getline(std::cin >> std::ws, filePathStr);
		if (filePathStr == "end")
		{
			std::print("Sound files confimed.\n");
			break;
		}
		else
		{
			fs::path filePath(filePathStr);
			if (fs::exists(filePath))
			{
				std::print("Error : No such file or dictory.\n");
				continue;
			}
			else
			{
				std::print("Sound file seletcted : {}.\n", filePath.filename().string());
				pathList.push_back(std::move(filePath));
			}

		}

	} while (true);
}

void sndfileInputList::readAudioFile	(		std::vector<audioQueue<float>>& queue, 
										 const	std::				uint32_t	PA_SAMPLE_RATE, 
										 const  std::				uint32_t	PA_OUTPUT_CHANNELS,
										 const  std::				uint32_t	BUFFER_MAX,
										 const	std::				uint32_t	BUFFER_MIN)
{

	std::vector<SndfileHandle> fileHandleList;
	for (auto& i : pathList)
	{
		SndfileHandle sndFile(i.string());
		fileHandleList.push_back(sndFile);
	}

	for (auto& i : fileHandleList)
	{
		const size_t bufferSize = i.frames() * i.channels() + 100;
		float* temp = new float[bufferSize];
		i.read(temp, bufferSize);

		audioQueue<float> sndQueue(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, BUFFER_MAX,BUFFER_MIN);
		sndQueue.push(temp, i.frames(), i.samplerate());
		delete[] temp;

		queue.push_back(std::move(sndQueue));
	}
	return;
}
