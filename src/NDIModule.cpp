﻿#include "NDIModule.h"
#include <iostream>

constexpr auto NDI_TIMEOUT = 1000;
constexpr auto QUEUE_SIZE_MULTIPLIER = 10;

template <typename T>
inline T* NDIErrorCheck(T* ptr) { if (!ptr) { std::print("NDI Error: No source is found.\n"); exit(EXIT_FAILURE); } else { return ptr; } }

void func(std::vector<audioQueue<float>> &queueList, int PA_SAMPLE_RATE, int PA_OUTPUT_CHANNELS)
{
	NDIlib_initialize();
	const NDIlib_find_create_t NDIFindCreateDesc;
	auto pNDIFind = NDIErrorCheck(NDIlib_find_create_v2(&NDIFindCreateDesc));
	uint32_t NDISourceNum = 0;
	const NDIlib_source_t* pSources = nullptr;
	while (!NDISourceNum)
	{
		NDIlib_find_wait_for_sources(pNDIFind, NDI_TIMEOUT);
		pSources = NDIlib_find_get_current_sources(pNDIFind, &NDISourceNum);
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
	}
	while (true)
	{
		//for (auto &i : recvList)
		//{
			NDIlib_audio_frame_v2_t audioInput;
			if (NDIlib_recv_capture_v2(recvList[0], nullptr, &audioInput, nullptr, NDI_TIMEOUT) == NDIlib_frame_type_audio)
			{
				const auto dataSize = static_cast<size_t>(audioInput.no_samples) * audioInput.no_channels;

				// Create a NDI audio object and convert it to interleaved float format.
				NDIlib_audio_frame_interleaved_32f_t audioDataNDI;
				audioDataNDI.p_data = new float[dataSize];
				NDIlib_util_audio_to_interleaved_32f_v2(&audioInput, &audioDataNDI);
				NDIlib_recv_free_audio_v2(recvList[0], &audioInput);
				
				audioQueue<float> NDIdata(PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS, static_cast<std::size_t>(audioInput.no_samples * QUEUE_SIZE_MULTIPLIER));
				NDIdata.push(audioDataNDI.p_data, audioDataNDI.no_samples, audioDataNDI.no_channels, audioDataNDI.sample_rate);
				queueList.push_back(NDIdata);
				delete[] audioDataNDI.p_data;
			}
		//}
	}
	NDIlib_find_destroy(pNDIFind);
	for (auto &i : recvList)
	{
		NDIlib_recv_destroy(i);
	}
	NDIlib_destroy();
}
