#include "NDIModule.h"
#include "Processing.NDI.Lib.h"
#include <iostream>
#include <algorithm>

constexpr auto NDI_TIMEOUT = 1000;

/**
 * @brief NDIAudioSourceList default constructor.
 * 
 */
NDIAudioSourceList::NDIAudioSourceList()
	:	sourceCount(0),
		recvList(0){ NDIlib_initialize(); }

/**
 * @brief Destroy the NDIAudioSourceList::NDIAudioSourceList object
 * 
 */
NDIAudioSourceList::~NDIAudioSourceList()
{
	for (auto& i : recvList)
		NDIlib_recv_destroy(i);
	NDIlib_destroy();
}

/**
 * @brief try to search all NDI audio source available and let user select sources wanted.
 * 
 * type ip adresse of sources to select.
 * type end to confirm.
 * type "all" to select all sources available.
 * 
 */
bool NDIAudioSourceList::search()
{	
	//Create a NDI finder and find sources available.
	const NDIlib_find_create_t NDIFindCreateDesc;
	auto pNDIFind = NDIErrorCheck(NDIlib_find_create_v2(&NDIFindCreateDesc));
	uint32_t NDISourceNum = 0;
	const NDIlib_source_t* pSources = nullptr;
	bool found = false;
	while (!found)
	{
		NDIlib_find_wait_for_sources(pNDIFind, NDI_TIMEOUT);
		pSources = NDIlib_find_get_current_sources(pNDIFind, &NDISourceNum);
		found = true;
	}
	NDIErrorCheck(pSources);
	if (!NDISourceNum)	return false;

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
		auto pNDIRecv = NDIErrorCheck(NDIlib_recv_create_v3(&i));
		recvList.push_back(pNDIRecv);
	}
	NDIlib_find_destroy(pNDIFind);
	
	return true;
}

/**
 * @brief try to capture NDI AUDIO data from every NDI receiver in recvList.
 * 
 * @param queueList audioQueue objects that are used to stock audio data
 * @param PA_SAMPLE_RATE portaudio OUTPUT sample rate
 * @param PA_OUTPUT_CHANNELS portaudio OUTPUT channel numbers
 * @param bufferMax max buffer size allocated for audioQueue.(defined by user.)
 */
void NDIAudioSourceList::receiveAudio(		std::vector<audioQueue<float>>& queueList, 
									  const std::				uint32_t	PA_SAMPLE_RATE, 
									  const	std::				uint32_t	PA_OUTPUT_CHANNELS,
									  const std::				  size_t	bufferMax,
									  const std::				  size_t	bufferMin)
{
	for (auto i : recvList)
	{
		audioQueue<float> NDIdata(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, bufferMax, bufferMin);
		queueList.push_back(std::move(NDIdata));
	}
	
	while (true)
	{
		for (auto i = 0; i < recvList.size(); i++)
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
				
				queueList[i].push(audioDataNDI.p_data, audioDataNDI.no_samples, audioDataNDI.sample_rate);
				
				delete[] audioDataNDI.p_data;
			}
			else continue;
		}
	}
}
