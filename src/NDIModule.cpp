#include "NDIModule.h"
#include <iostream>
#include <algorithm>

constexpr auto NDI_TIMEOUT = 1000;
constexpr auto QUEUE_SIZE_MULTIPLIER = 2;

template <typename T>
inline T* NDIErrorCheck(T* ptr) { if (!ptr) { std::print("NDI Error: No source is found.\n"); exit(EXIT_FAILURE); } else { return ptr; } }

void func(std::vector<audioQueue<float>> &queueList, int PA_SAMPLE_RATE, int PA_OUTPUT_CHANNELS)
{
	NDIlib_initialize();
	const NDIlib_find_create_t NDIFindCreateDesc;
	auto pNDIFind = NDIErrorCheck(NDIlib_find_create_v2(&NDIFindCreateDesc));
	uint32_t NDISourceNum = 0;
	const NDIlib_source_t* pSources = nullptr;
	bool found = false;
	while (!found)
	{
		NDIlib_find_wait_for_sources(pNDIFind, NDI_TIMEOUT);
		pSources = NDIlib_find_get_current_sources(pNDIFind, &NDISourceNum);
		if (pSources->p_url_address == "192.168.0.200:5961") continue;
		else found = true;
	}
	NDIErrorCheck(pSources);
	std::print("NDI sources list:\n");
	for (std::size_t i = 0; i < NDISourceNum; i++)
		std::print("Source {}\nName : {}\nIP   : {}\n\n", i, pSources[i].p_ndi_name, pSources[i].p_url_address);

	std::vector<NDIlib_recv_create_v3_t> sourceList;
	bool sourceMatched = false;
	std::string url;
	
	std::print("Please enter the IP of the source that you want to connect to, enter end to confirm.\n");
	do
	{
		sourceMatched = false;
		std::cin >> url;
		if (url == "end")
		{
			std::print("Sources confimed.\n");
			break;
		}
		else
		{
			for (std::size_t i = 0; i < NDISourceNum; i++)
			{
				if (url == pSources[i].p_url_address)
				{
					NDIlib_recv_create_v3_t NDIRecvCreateDesc;
					NDIRecvCreateDesc.p_ndi_recv_name = pSources[i].p_ndi_name;
					NDIRecvCreateDesc.source_to_connect_to = pSources[i];
					std::print("{} selected.\n", pSources[i].p_ndi_name);
					sourceList.push_back(NDIRecvCreateDesc);
					sourceMatched = true;
				}
			}
		}
		if (!sourceMatched) std::print("Source do not exist! Please try again.\n");
	} while (true);
	std::vector<NDIlib_recv_instance_t> recvList;
	
	for (auto &i : sourceList)
	{
		auto pNDIRecv = NDIErrorCheck(NDIlib_recv_create_v3(&i));
		recvList.push_back(pNDIRecv);
		audioQueue<float> NDIdata(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, 0);
		queueList.push_back(std::move(NDIdata));
	}

	while (true)
	{
		for (auto i = 0; i < recvList.size();i++)
		{
			NDIlib_audio_frame_v2_t audioInput;
			auto type = NDIlib_recv_capture_v2(recvList[i], nullptr, &audioInput, nullptr,0);
			if (type == NDIlib_frame_type_none) continue;
			if (type == NDIlib_frame_type_audio)
			{
				const auto dataSize = static_cast<size_t>(audioInput.no_samples) * audioInput.no_channels;

				// Create a NDI audio object and convert it to interleaved float format.
				NDIlib_audio_frame_interleaved_32f_t audioDataNDI;
				audioDataNDI.p_data = new float[dataSize];
				NDIlib_util_audio_to_interleaved_32f_v2(&audioInput, &audioDataNDI);

				queueList[i].setCapacity(dataSize * QUEUE_SIZE_MULTIPLIER);
				queueList[i].push(audioDataNDI.p_data, audioDataNDI.no_samples, audioDataNDI.no_channels, audioDataNDI.sample_rate);

				delete[] audioDataNDI.p_data;
			}
			else continue;
		}
	}
	NDIlib_find_destroy(pNDIFind);
	for (auto &i : recvList)
	{
		NDIlib_recv_destroy(i);
	}
	NDIlib_destroy();
}
