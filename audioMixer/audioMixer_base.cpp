#include "audioMixer_base.h"
#include <xutility>

namespace fs = std::filesystem;

#pragma region NDIModule
bool NDIModule::NDISourceSearch()
{
	if (!activeStatus)
	{
		std::print("Error : NDI stream is not running!\n");
		return false;
	}

	constexpr auto NDI_TIMEOUT = 1000;
	//Create a NDI finder and find sources available.
	const NDIlib_find_create_t NDIFindCreateDesc;
	auto pNDIFind = NDIlib_find_create_v2(&NDIFindCreateDesc);
	if (pNDIFind == nullptr)
	{
		std::print("Fail to create NDI finder!\n");
		return false;
	}

	uint32_t NDISourceNum = 0;
	const NDIlib_source_t* pSources = nullptr;
	bool found = false;
	while (!found)
	{
		NDIlib_find_wait_for_sources(pNDIFind, NDI_TIMEOUT);
		pSources = NDIlib_find_get_current_sources(pNDIFind, &NDISourceNum);
		found = true;
	}
	if (!NDISourceNum || pNDIFind == nullptr)
		return false;

	//List all available sources.
	std::print("NDI sources list:\n");
	for (std::size_t i = 0; i < NDISourceNum; i++)
		std::print("Source {}\nName : {}\nIP   : {}\n\n", i, pSources[i].p_ndi_name, pSources[i].p_url_address);


	//let user select sources they want.
	std::vector<NDIlib_recv_create_v3_t> sourceList;
	bool sourceMatched = false;
	bool selectAll = false;
	std::string url;

	std::print("Please enter the IP of the source that you want to connect to, enter end to confirm.\n");
	do
	{
		sourceMatched = false;
		std::cin >> url;

		if (url == "all") selectAll = true;

		for (std::size_t i = 0; i < NDISourceNum; i++)
		{
			if (url == pSources[i].p_url_address || selectAll)
			{
				NDIlib_recv_create_v3_t NDIRecvCreateDesc;
				NDIRecvCreateDesc.p_ndi_recv_name = pSources[i].p_ndi_name;
				NDIRecvCreateDesc.source_to_connect_to = pSources[i];
				std::print("{} selected.\n", pSources[i].p_ndi_name);
				sourceList.push_back(NDIRecvCreateDesc);
				sourceMatched = true;
			}
		}
		if (url == "end" || selectAll)
		{
			std::print("Sources confimed.\n");
			break;
		}
		if (!sourceMatched) std::print("Source do not exist! Please try again.\n");
	} while (true);


	//for every source selected, create a NDI receiver for further operations.
	for (auto& i : sourceList)
	{
		auto pNDIRecv = NDIlib_recv_create_v3(&i);
		recvList.push_back(pNDIRecv);
	}
	NDIlib_find_destroy(pNDIFind);
	return true;
}

void NDIModule::NDIRecvAudio(audioQueue<float>& target)
{
	std::vector<audioQueue<float>> NDIQueues;
	NDIQueues.reserve(recvList.size() * target.max());
	for (auto i : recvList)
	{
		audioQueue<float> dataQueue(target.sampleRate(), target.channels(), target.max(), target.min());
		NDIQueues.push_back(std::move(dataQueue));
	}
	while (true)
	{
		for (auto &i : recvList)
		{
			NDIlib_audio_frame_v2_t audioInput;
			auto type = NDIlib_recv_capture_v2(recvList[i], nullptr, &audioInput, nullptr, 0);
			if (type == NDIlib_frame_type_audio)
			{
				const auto dataSize = static_cast<size_t>(audioInput.no_samples) * audioInput.no_channels;

				// Create a NDI audio object and convert it to interleaved float format.
				NDIlib_audio_frame_interleaved_32f_t audioDataNDI;
				audioDataNDI.p_data = new float[dataSize];
				NDIlib_util_audio_to_interleaved_32f_v2(&audioInput, &audioDataNDI);

				if (!target.push(audioDataNDI.p_data, audioDataNDI.no_samples, audioDataNDI.sample_rate, audioDataNDI.no_channels))
					std::print("No more space in the queue!\n");

				delete[] audioDataNDI.p_data;
			}
			else continue;
		}
	}
}
#pragma endregion

/*
#pragma region sndfileModule
void sndfileModule::selectAudioFile()
{
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
				std::print("Sound file seletcted : {}.\n", filePath.filename().string());
				pathList.push_back(filePath);
			}
			else
			{
				std::print("Error : No such file or dictory.\n");
				continue;
			}
		}

	} while (true);
}

void sndfileModule::readAudioFile(	const std::uint32_t PA_SAMPLE_RATE, 
									const std::uint32_t PA_OUTPUT_CHANNELS, 
									const std::uint32_t BUFFER_MAX, 
									const std::uint32_t BUFFER_MIN)
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

		audioQueue<float> sndQueue(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, BUFFER_MAX, BUFFER_MIN);
		sndQueue.push(temp, i.frames(), i.samplerate(), i.channels());
		delete[] temp;

		SNDData.push_back(std::move(sndQueue));
	}
	return;
}
#pragma endregion*/

#pragma region audioMixer
int audioMixer::portAudioOutputCallback(const void*							inputBuffer, 
											  void*							outputBuffer, 
											  unsigned long					framesPerBuffer, 
										const PaStreamCallbackTimeInfo*		timeInfo, 
											  PaStreamCallbackFlags			statusFlags)
{
		auto out = static_cast<float*>(outputBuffer);
		//Set output buffer to zero by default to avoid noise when there is no input.
		memset(out, 0, sizeof(out) * framesPerBuffer);

		outputAudioQueue.pop(out, framesPerBuffer, true);
		return paContinue;

}

audioMixer::audioMixer(const std::uint8_t	nbChannels,
					   const std::size_t	sampleRate, 
					   const std::size_t	max, 
					   const std::size_t	min, 
					   const bool			enableNDI, 
					   const bool			enableSndfile) : 
	outputAudioQueue(sampleRate,nbChannels,max,min),
	NDIEnabled		(enableNDI),
	sndfileEnabled	(enableSndfile),
	PaStreamOut		(nullptr)
{
	PAErrorCheck(Pa_Initialize());
	PAErrorCheck(Pa_OpenDefaultStream(&PaStreamOut,
									   0,			//no input
									   nbChannels,
									   paFloat32,	//32bit float
									   sampleRate,
									   128,
									  &audioMixer::PA_Callback,
									   this));
	if (NDIEnabled)
	{
		if (!NDI)
		{
			NDI = std::make_unique<NDIModule>();
			NDI->start();
		}
	}
	else NDI = nullptr;

	if (sndfileEnabled)
	{
		if (!sndfile)
		{
			sndfile = std::make_unique<sndfileModule>();
			sndfile->start();
		}
	}
	else sndfile = nullptr;
}

audioMixer::~audioMixer()
{
	if (NDI)
	{
		NDI->stop();
		NDI.release();
	}
	if (sndfile)
	{
		sndfile->stop();
		sndfile.release();
	}
	if (Pa_IsStreamActive(PaStreamOut))
		PAErrorCheck(Pa_StopStream(PaStreamOut));

	PAErrorCheck(Pa_CloseStream(PaStreamOut));
	PAErrorCheck(Pa_Terminate());
}
void audioMixer::PaStart()
{
	if (Pa_IsStreamStopped(PaStreamOut))
		Pa_StartStream(PaStreamOut);
	std::print("PortAudio is active.\n");
}
void audioMixer::PaStop()
{
	if (Pa_IsStreamActive(PaStreamOut))
		Pa_StopStream(PaStreamOut);
	std::print("PortAudio is stopped.\n");
}
#pragma endregion