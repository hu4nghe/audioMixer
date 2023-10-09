#include <csignal>
#include <iostream>

#include "NDIModule.h" 
#include "SoundFileModule.h"
#include "portaudio.h"
#include "audioQueue.h"

#pragma region System signal handler
/**
 * @brief A system signal handler allows to quit with Crtl + C
 * 
 * Let exit_loop = true if a system signal is received.
 */
static std::atomic<bool> exit_loop(false);
static void sigIntHandler(int) { exit_loop = true; }
#pragma endregion

#pragma region Global constants and variables
constexpr auto PA_SAMPLE_RATE				= 44100;	//portaudio output sample rate
constexpr auto PA_BUFFER_SIZE				= 441;		//portaudio frames per buffer
constexpr auto PA_INPUT_CHANNELS			= 0;		
constexpr auto PA_OUTPUT_CHANNELS			= 2;
constexpr auto PA_FORMAT					= paFloat32;
//constexpr auto AUDIOQUEUE_BUFFER_MAX		= 441000;	//Default buffer size : 10s for 44.1 KHz

int AUDIOQUEUE_BUFFER_MAX = 0;
int AUDIOQUEUE_BUFFER_MIN = 0;

std::vector<audioQueue<float>> NDIdata;
std::vector<audioQueue<float>> SNDdata;
#pragma endregion

/**
 * @brief Error checker PortAudio library.
 * 
 * In case of error, print error message and exit with failure. 
 * 
 * @param err PaError type error code.
 */
inline void  PAErrorCheck (PaError err)
{ 
	if (err)
	{ 
		std::print("PortAudio error : {}.\n", Pa_GetErrorText(err)); 
		exit(EXIT_FAILURE);
	} 
}
/**
 * @brief unfinished channel management function
 * 
*/
void channelAdaption(int originalChannel, int outputChannel)
{

}

#pragma region NDI Inout
/**
 * @brief Thread that capture audio input from NDI sources.
 * 
 */
void NDIAudioTread()
{
	NDIAudioSourceList ndiSources;
	
	while (!ndiSources.search()) 
	{
		std::print("no source found ! type any key to serach again\n");
		std::cin.get();
	}

	ndiSources.receiveAudio(NDIdata, 
							PA_SAMPLE_RATE, 
							PA_OUTPUT_CHANNELS, 
							AUDIOQUEUE_BUFFER_MAX,
							AUDIOQUEUE_BUFFER_MIN);
}
#pragma endregion

#pragma region Sndfile Input
void sndfileRead()
{
	sndfileInputList sndfileList;
	sndfileList.selectAudioFile	();
	sndfileList.readAudioFile(SNDdata,
							  PA_SAMPLE_RATE,
							  PA_OUTPUT_CHANNELS);

}
#pragma endregion

#pragma region PA output
static int portAudioOutputCallback(	const	                    void*	inputBuffer,
											                    void*	outputBuffer,
											           unsigned long	framesPerBuffer,
									const	PaStreamCallbackTimeInfo*	timeInfo,
											   PaStreamCallbackFlags	statusFlags,
											                    void*	UserData)
{
	auto out = static_cast<float*>(outputBuffer);
	//Set output buffer to zero by default to avoid noise when there is no input.
	memset(out, 0, sizeof(out) * framesPerBuffer);
	//for every audioQueue in the list
	for (auto& i : NDIdata)
		i.pop(out, framesPerBuffer, true);//mode : true for addition, false for override.

	return paContinue;
}

bool isAudioQueueVecEmpty(std::vector<audioQueue<float>>& vec)
{
	for (const auto i : vec)
	{
		if (!i.empty()) return false;
	}
	return true;
}

void portAudioOutputThread()
{
	std::signal(SIGINT, sigIntHandler);

	PAErrorCheck(Pa_Initialize());
	PaStream* streamOut;
	//initialize portaudio stream using default devices.
	PAErrorCheck(Pa_OpenDefaultStream( &streamOut,
										PA_INPUT_CHANNELS,				
										PA_OUTPUT_CHANNELS,				
										PA_FORMAT,						
										PA_SAMPLE_RATE,					
										PA_BUFFER_SIZE,					
										portAudioOutputCallback,
										nullptr));
	
	//lambda to check if all audioQueue is empty.
	//if yes, pause the portaudio and wait for new datas to restart it.
	auto isAudioQueueVecEmpty = [](const std::vector<audioQueue<float>>& vec) 
	{
		return std::all_of(vec.begin(), vec.end(), [](const audioQueue<float>& i) { return i.empty(); });
	};

	while (!exit_loop)
	{
		if ( isAudioQueueVecEmpty(NDIdata)) Pa_StopStream (streamOut);
		if (!isAudioQueueVecEmpty(NDIdata)) Pa_StartStream(streamOut);
	}
	
	//clean up
	PAErrorCheck(Pa_StopStream(streamOut));
	PAErrorCheck(Pa_CloseStream(streamOut));
	PAErrorCheck(Pa_Terminate());
}
#pragma endregion



int main()
{
	std::print("Configuration audio queue :\nplease enter the max buffer size(in sample number)\n");
	std::cin >> AUDIOQUEUE_BUFFER_MAX;
	if (AUDIOQUEUE_BUFFER_MAX == 0) std::print("Error : Max buffer size equals to zero !\n");
	std::print("please enter the min numbers of samples in the buffer(in sample number)\n");
	std::cin >> AUDIOQUEUE_BUFFER_MIN;
	


	std::thread ndiThread(NDIAudioTread);
	//std::thread sndfile(sndfileRead);
	std::thread portaudio(portAudioOutputThread);

	ndiThread.	join();
	//sndfile.	join();
	portaudio.	join();
	return 0;
}