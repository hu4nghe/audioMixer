#include <csignal>
#include <iostream>
#include "NDIModule.h" 
#include "portaudio.h"
#include "audioQueue.h"
#include "SoundFileModule.h"

#pragma region System signal handler
/**
 * @brief A system signal handler allows to quit with Crtl + C
 * 
 * Let exit_loop = true if a system signal is received.
 */
static std::atomic<bool> exit_loop(false);
static void sigIntHandler(int) {exit_loop = true;}
#pragma endregion

#pragma region Global constants and variables
constexpr auto PA_SAMPLE_RATE				= 48000;
constexpr auto PA_BUFFER_SIZE				= 512;
constexpr auto PA_INPUT_CHANNELS			= 0;
constexpr auto PA_OUTPUT_CHANNELS			= 2;
constexpr auto PA_FORMAT					= paFloat32;
std::vector<audioQueue<float>> NDIdata;
std::vector<audioQueue<float>> SNDdata;
#pragma endregion

/**
 * @brief Error checker PortAudio library.
 * 
 * Exit with failure in case of error.
 */
inline void  PAErrorCheck (PaError err){if ( err){ std::print("PortAudio error : {}.\n", Pa_GetErrorText(err)); exit(EXIT_FAILURE);}}

#pragma region NDI Inout
void NDIAudioTread()
{
	NDIAudioReceive(NDIdata, PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS);
}
#pragma endregion

#pragma region Sndfile Input
void sndfileRead()
{
	//sndfileReceive(SNDdata,PA_SAMPLE_RATE, PA_OUTPUT_CHANNELS);
}
#pragma endregion

#pragma region PA output
static int portAudioOutputCallback(	const	void*						inputBuffer,
											void*						outputBuffer,
											unsigned long				framesPerBuffer,
									const	PaStreamCallbackTimeInfo*	timeInfo,
											PaStreamCallbackFlags		statusFlags,
											void*						UserData)
{
	auto out = static_cast<float*>(outputBuffer);
	memset(out, 0, sizeof(out) * framesPerBuffer);
	auto outputDelay = 0;
	for (auto& i : NDIdata)
	{
		outputDelay = i.getoutputDelay() > outputDelay ? i.getoutputDelay() : outputDelay;
		if (!i.empty()) i.pop(out, framesPerBuffer, true);
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(outputDelay)));
	std::print("{}\n", outputDelay);
	return paContinue;
}

void portAudioOutputThread()
{
	std::signal(SIGINT, sigIntHandler);

	PaStream* streamOut;
	PAErrorCheck(Pa_OpenDefaultStream( &streamOut,				// PortAudio Stream
										PA_INPUT_CHANNELS,				
										PA_OUTPUT_CHANNELS,				
										PA_FORMAT,						
										PA_SAMPLE_RATE,					
										PA_BUFFER_SIZE,					
										portAudioOutputCallback,// Callback function called
										nullptr));				// No user data passed

	while (!exit_loop)
	{
		if (NDIdata.empty()) Pa_StopStream(streamOut);
		if (!NDIdata.empty()) Pa_StartStream(streamOut);
	}

	PAErrorCheck(Pa_StopStream(streamOut));
	PAErrorCheck(Pa_CloseStream(streamOut));
}
#pragma endregion
int main()
{
	PAErrorCheck(Pa_Initialize());
	std::thread ndiThread(NDIAudioTread);
	//::thread sndfile(sndfileRead);
	std::thread portaudio(portAudioOutputThread);

	ndiThread.detach();
	//sndfile.detach();
	portaudio.join();
	PAErrorCheck(Pa_Terminate());
	return 0;
}