#ifndef NDI_MODULE_H
#define NDI_MODULE_H

#include "audioQueue.h"
#include "Processing.NDI.Lib.h"

class NDIAudioSourceList
{
	public:
				NDIAudioSourceList		();
				//any copy or move of NDIAudioSourceList object is not possible! 
				NDIAudioSourceList		(const			  NDIAudioSourceList&	 other) = delete;
				NDIAudioSourceList		(				  NDIAudioSourceList&&   other) = delete;
			   ~NDIAudioSourceList		();
		bool	search					();
		void	receiveAudio			(		std::vector<audioQueue<float>>&  queue, 
										 const	std::				uint32_t	 PA_SAMPLE_RATE, 
										 const  std::				uint32_t	 PA_OUTPUT_CHANNELS,
										 const	std::				  size_t	 bufferMax,
										 const  std::				  size_t	 bufferMin);
		template<typename T>
		   T*	NDIErrorCheck			(								   T*	 ptr);
	

	private : 
		std::uint32_t						sourceCount;
		std::vector<NDIlib_recv_instance_t> recvList;
};

#endif//NDI_MODUEL_H

/**
 * @brief NDI error checker
 * 
 * return nullptr if a operation is failed
 * return pointer itself if operation is successed.
 * 
 * @tparam T audio data type.
 * @param ptr NDI object pointer
 * @return T* ptr itself
 */
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
