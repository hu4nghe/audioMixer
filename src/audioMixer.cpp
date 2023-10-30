#include <csignal>
#include <iostream>

#include "NDIModule.h" 
#include "SoundFileModule.h"
#include "portaudio.h"
#include "audioQueue.h"
#include "DeltaCastModule.h"

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
constexpr auto PA_BUFFER_SIZE				= 128;
constexpr auto PA_INPUT_CHANNELS			= 0;		
constexpr auto PA_OUTPUT_CHANNELS			= 2;
constexpr auto PA_FORMAT					= paInt24;

std::size_t PA_SAMPLE_RATE			= 44100;
std::size_t AUDIOQUEUE_BUFFER_MAX	= 441000;
std::size_t AUDIOQUEUE_BUFFER_MIN	= 4410;

std::vector<audioQueue<float>> NDIdata;
std::vector<audioQueue<float>> SNDdata;
std::vector<audioQueue<std::int32_t>> DeltaCastData;

std::atomic<bool> NDIselectReady(false);
#pragma endregion

#pragma region NDI Input
/**
 * @brief Thread that capture audio input from NDI sources.
 * 
 */
void NDIAudioTread()
{
	std::signal(SIGINT, sigIntHandler);

	NDIAudioSourceList ndiSources;
	
	while (!ndiSources.search()) 
	{
		std::print("no source found ! type any key to serach again\n");
		std::cin.get();
	}
	NDIselectReady.store(true, std::memory_order_release);
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
	std::signal(SIGINT, sigIntHandler);
	sndfileInputList sndfileList;
	sndfileList.selectAudioFile	();
	sndfileList.readAudioFile(SNDdata,
							  PA_SAMPLE_RATE,
							  PA_OUTPUT_CHANNELS,
							  AUDIOQUEUE_BUFFER_MAX,
							  AUDIOQUEUE_BUFFER_MIN);

}
#pragma endregion

#pragma region DeltaCast input
void DeltaCastThread()
{
	DeltaCastRecv(	DeltaCastData,
					PA_SAMPLE_RATE,
					PA_OUTPUT_CHANNELS,
					AUDIOQUEUE_BUFFER_MAX,
				AUDIOQUEUE_BUFFER_MIN);
	
	return;

}
#pragma endregion

#pragma region PortAudio
void PAConfig()
{
	std::print("Configuration :\nplease enter output sample rate:(in Hz)\n");
	std::cin >> PA_SAMPLE_RATE;

	std::size_t timeMax;
	std::print("please enter the max buffer size(in ms)\n");
	std::cin >> timeMax;
	timeMax /= 1000;

	AUDIOQUEUE_BUFFER_MAX = timeMax * PA_SAMPLE_RATE * PA_OUTPUT_CHANNELS;

	std::size_t timeMin;
	std::print("please enter the min buffer size(in ms)\n");
	std::cin >> timeMin;
	timeMin /= 1000;
	AUDIOQUEUE_BUFFER_MIN = timeMin * PA_SAMPLE_RATE * PA_OUTPUT_CHANNELS;
}

/**
 * @brief Error checker PortAudio library.
 *
 * In case of error, print error message and exit with failure.
 *
 * @param err PaError type error code.
 */
inline void  PAErrorCheck(PaError err)
{
	if (err)
	{
		std::print("PortAudio error : {}.\n", Pa_GetErrorText(err));
		exit(EXIT_FAILURE);
	}
}

static int portAudioOutputCallback( const	                    void* inputBuffer,
																void* outputBuffer,
													   unsigned long  framesPerBuffer,
									const	PaStreamCallbackTimeInfo* timeInfo,
											   PaStreamCallbackFlags  statusFlags,
																void* UserData)
{
	auto out = static_cast<int32_t*>(outputBuffer);
	//Set output buffer to zero by default to avoid noise when there is no input.
	memset(out, 0, sizeof(out) * framesPerBuffer);
	//for every audioQueue in the list
	/*
	for (auto& currentAudioQueue : NDIdata)
	{
		if (currentAudioQueue.pop(out, framesPerBuffer, true))//pop in addition mode, return true if successefully poped.
		{
			auto samplePlayedPerSecond = static_cast<uint64_t>(currentAudioQueue.sampleRate()) * currentAudioQueue.channels();
			std::print("{}  samples	|	{}  ms.\n",
					   currentAudioQueue.size(),
					   currentAudioQueue.size() / samplePlayedPerSecond);
		}
		else
			std::print("Min buffer size reached, add more audio data to continue!\n");
	}*/
	for (auto& currentAudioQueue : DeltaCastData)
	{
		currentAudioQueue.pop(out, framesPerBuffer, false);
	}
	return paContinue;
}

void PAOutputThread()
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
	Pa_StartStream(streamOut);
	bool PaActiveFlag = true;
	while (!exit_loop)
	{
		char ch = getchar();
		if (ch == ' ')
		{
			if (PaActiveFlag)
			{
				Pa_StopStream(streamOut);
				std::print("Portaudio Status : Stopped.\n");
			}
			else
			{
				Pa_StartStream(streamOut);
				std::print("Portaudio Status : Active. \n");
			}

			PaActiveFlag = !PaActiveFlag;
		}

	}
	PAErrorCheck(Pa_StopStream(streamOut));
	PAErrorCheck(Pa_CloseStream(streamOut));
	PAErrorCheck(Pa_Terminate());
}
#pragma endregion

int main()
{	
	PAConfig();

	//std::thread ndiThread(NDIAudioTread);
	std::thread portaudio(PAOutputThread);
	std::thread deltaCast(DeltaCastThread);

	//ndiThread.join();
	portaudio.join();
	deltaCast.join();
	return 0;
}