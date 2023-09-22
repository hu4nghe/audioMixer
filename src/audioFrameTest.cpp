/*
#include <print>
#include "audioFrame.h"
#include "sndfile.hh"

int main() 
{

}
*/




*/





















/*

	std::print("start\n");
	
	audioQueue<float> a;
	audioQueue<float> b;

	a.sndfileRead("C:/Users/Modulo/Desktop/Nouveau dossier/Music/Rachmaninov- Music For 2 Pianos, Vladimir Ashekenazy & André Previn/Rachmaninov- Music For 2 Pianos [Disc 1]/Rachmaninov- Suite #1 For 2 Pianos, Op. 5, 'Fantaisie-Tableaux' - 1. Bacarolle- Allegretto.wav");
	return 0;
	*/









/* 

static std::atomic<bool> exit_loop(false);
static void sigIntHandler(int) { exit_loop = true; }

inline void  PAErrorCheck(PaError err) { if (err) { std::print("PortAudio error : {}.\n", Pa_GetErrorText(err)); exit(EXIT_FAILURE); } }
audioQueue<float> MicroInput(0);
constexpr auto QUEUE_SIZE_MULTIPLIER = 1.8;

static int portAudioInputCallback(const void*						inputBuffer,
										void*						outputBuffer,
										unsigned long				framesPerBuffer,
								  const PaStreamCallbackTimeInfo*	timeInfo,
										PaStreamCallbackFlags		statusFlags,
										void* UserData)
{
	audioQueue<float> a(0);

	a.setCapacity(10);
	a.setChannelNum(8);
	std::vector<float> data{ 1.0,2.0,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
	a.push(data.data(), data.size(), 2, 0);

	return 0;


}