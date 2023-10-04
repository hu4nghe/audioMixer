#include "SoundFileModule.h"
#include <string>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

void sndfileReceive(std::vector<audioQueue<float>>&queueList, int PA_SAMPLE_RATE, int PA_OUTPUT_CHANNELS)
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
				std::print("File do not exist! Please try again.\n");
				continue;
			}
			else
			{
				std::print("Sound file seletcted : {}.\n", filePath.filename().string());
				pathList.push_back(std::move(filePath));
			}

		}
		 
	} while (true);

	std::vector<SndfileHandle> fileHandleList;
	for (auto &i : pathList)
	{
		SndfileHandle sndFile(i.string());
		fileHandleList.push_back(std::move(sndFile));
	}

	for (auto &i : fileHandleList)
	{
		const size_t bufferSize = i.frames() * i.channels() + 100;
		float* temp = new float[bufferSize];
		i.read(temp, bufferSize);

		audioQueue<float> sndQueue(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, bufferSize);
		sndQueue.push(temp, i.frames(), i.samplerate());
		delete[] temp;

		queueList.push_back(std::move(sndQueue));		
	}
	return;
}
