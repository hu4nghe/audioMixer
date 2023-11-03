#ifndef NDI_RECV_MODULE_H
#define NDI_RECV_MODULE_H

#include <print>

#include "audio_base.h"
#include "audioQueue.h"
#include "Processing.NDI.Lib.h"

class NDIFinder
{
	NDIlib_find_instance_t finder;
public:
	NDIFinder() 
	{
		NDIlib_find_create_t finderConfig;
		finder = NDIlib_find_create_v2(&finderConfig);
		if (finder == nullptr)
			throw std::logic_error("Failed to create NDI finder !");
	};
	NDIFinder(const bool  showLocalSources, 
			  const char* pGroups)
	{
		NDIlib_find_create_t finderConfig;
		finderConfig.show_local_sources = showLocalSources;
		finderConfig.p_groups = pGroups;
		finderConfig.p_extra_ips = nullptr;//deprecated feature

		finder = NDIlib_find_create_v2(&finderConfig);
		if (finder == nullptr)
			throw std::logic_error("Failed to create NDI finder !");
	}

	~NDIFinder() { NDIlib_find_destroy(finder); }
};

class NDIModule : public audioMixerModule_base
{
private:
    bool                                active;
    std::uint32_t						sourceCount;
    std::vector<NDIlib_recv_instance_t> recvList;
public:

    NDIModule()
        :   sourceCount(0),
            recvList(0),
            active(false) {}
   ~NDIModule() = default;

    void start()	override
    {
		if (!NDIlib_initialize()) throw std::logic_error("Cannot run NDI.");
		else
		{
			std::print("NDI Module is activated.\n");
			active = true;
		}
    }
    void stop()		override
    {
        for (auto& i : recvList)
        {
            NDIlib_recv_destroy(i);
        }

        NDIlib_destroy();
        std::print("NDI Module is stopped.\n");
        active = false;
    }
    bool isActive() override { return active; }

    /**
    * @brief try to search all NDI audio source available and let user select sources wanted.
    *
    * type ip adresse of sources to select.
    * type end to confirm.
    * type "all" to select all sources available.
    *
    * @return true  if at least 1 NDI source is found,
    * @return false if failed to search NDI sources.
    *
    */
    void NDISourceSearch();
    /**
    * @brief try to capture NDI AUDIO data from every NDI receiver in recvList.
    *
    */
    void NDIRecvAudio(audioQueue<float>& target);


};

void NDIModule::NDISourceSearch()
{
	if (!active)
		throw std::logic_error("NDI lib is not running !");

	constexpr auto timeout = 1000;
	//Create a NDI finder and find sources available.
	NDIFinder audioFinder();

	const NDIlib_find_create_t finderConfig;
	auto pNDIFind = NDIlib_find_create_v2(&finderConfig);
	if (pNDIFind == nullptr)
		throw std::logic_error("NDI lib is not running !");

	uint32_t NDISourceNum = 0;
	const NDIlib_source_t* pSources = nullptr;
	bool found = false;
	while (!found)
	{
		NDIlib_find_wait_for_sources(pNDIFind, timeout);
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
		for (auto& i : recvList)
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

#endif//NDI_RECV_MODULE_H