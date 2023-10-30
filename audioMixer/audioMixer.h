/*#include <csignal>
#include <iostream>

#include "NDIModule.h" 
#include "SoundFileModule.h"
#include "portaudio.h"
#include "audioQueue.h"

template <audioType T>
class audioMixer
{
public:
	audioMixer();
private : 
	std::vector<audioQueue<T>> NDISources;
	std::vector<audioQueue<T>> SNDDataSources;
	std::vector<audioQueue<T>> DeltaCastSources;
	std::vector<audioQueue<T>> MicroSources;
	
	std::size_t 
};*