#ifndef NDI_MODULE_H
#define NDI_MODULE_H

#include "audioQueue.h"
#include "Processing.NDI.Lib.h"

//void NDIAudioReceive(std::vector<audioQueue<float>>& queueList, std::uint32_t PA_SAMPLE_RATE, std::uint32_t PA_OUTPUT_CHANNELS);

class NDIAudioSourceList
{
	public:
				NDIAudioSourceList		();
				NDIAudioSourceList		(const			  NDIAudioSourceList&	 other) = delete;
				NDIAudioSourceList		(				  NDIAudioSourceList&&   other) = delete;
			   ~NDIAudioSourceList		();
		bool	search					();
		void	receiveAudio			(		std::vector<audioQueue<float>>&  queue, 
										 const	std::				uint32_t	 PA_SAMPLE_RATE, 
										 const  std::				uint32_t	 PA_OUTPUT_CHANNELS,
										 const	std::				  size_t	 bufferMax);
		template<typename T>
		   T*	NDIErrorCheck		(							T*	 ptr);
	

	private : 
		std::uint32_t						sourceCount;
		std::vector<NDIlib_recv_instance_t> recvList;
};

#endif//NDI_MODUEL_H

template<typename T>
inline T* NDIAudioSourceList::NDIErrorCheck(T* ptr)
{
	if (!ptr)
	{
		std::print(stderr, "NDI Error: No source is found.\n");
		return nullptr;
	}
	else return ptr;
}
