#include <csignal>
#include <iostream>
#include <functional>

#include "Processing.NDI.Lib.h"
#include "SoundFileModule.h"
#include "portaudio.h"
#include "audioQueue.h"
#include <vector>

class audioMixerModule_base
{
public:
    //any copy or move of a Module is NOT possible! 
    audioMixerModule_base(const audioMixerModule_base&  other) = delete;
    audioMixerModule_base(      audioMixerModule_base&& other) = delete;

	virtual void    start                () = 0;
	virtual void    stop                 () = 0;
    virtual bool    isActive             () = 0;
	virtual        ~audioMixerModule_base() {}
protected :
    audioMixerModule_base() = default;
};

class NDIModule : public audioMixerModule_base 
{
public:
	
    NDIModule() 
        :   sourceCount (0), 
            recvList    (0),
            activeStatus(false){}

   ~NDIModule() = default;

    void start   () override 
	{
        NDIlib_initialize();
		std::print("NDI Module is activated.\n");
        activeStatus = true;
	}

	void stop    () override 
	{
        for (auto& i : recvList)
        {
            NDIlib_recv_destroy(i);
        }

        NDIlib_destroy();
        std::print("NDI Module is stopped.\n");
        activeStatus = false;
	}

    bool isActive() override { return activeStatus; }

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
    bool NDISourceSearch();

    /**
    * @brief try to capture NDI AUDIO data from every NDI receiver in recvList.
    *
    * @param queueList audioQueue objects that are used to stock audio data
    * @param PA_SAMPLE_RATE portaudio OUTPUT sample rate
    * @param PA_OUTPUT_CHANNELS portaudio OUTPUT channel numbers
    * @param bufferMax max buffer size allocated for audioQueue.(defined by user.)
    */
    void NDIRecvAudio(const	 std::uint32_t	    PA_SAMPLE_RATE,
                      const  std::uint32_t	    PA_OUTPUT_CHANNELS,
                      const	 std::size_t	        bufferMax,
                      const  std::size_t	        bufferMin);
private :
    bool                                activeStatus;
    std::uint32_t						sourceCount;
    std::vector<NDIlib_recv_instance_t> recvList;
    std::vector<audioQueue<float>>      NDIdata;
    
};

class sndfileModule : public audioMixerModule_base
{
public:
    sndfileModule() : pathList(0){}

    ~sndfileModule() = default;

    void start()        override 
    {
        std::cout << "sndfile Module is activated." << std::endl;
    }

    void stop()         override 
    {
        std::cout << "sndfile Module is stopped." << std::endl;
    }

    bool isActive()     override { return true; }
    
    void	selectAudioFile();
    void	readAudioFile(const	std::uint32_t		PA_SAMPLE_RATE,
                          const std::uint32_t		PA_OUTPUT_CHANNELS,
                          const std::uint32_t		BUFFER_MAX,
                          const	std::uint32_t		BUFFER_MIN);
private:
    std::vector<fs::path>           pathList;
    std::vector<audioQueue<float>>  SNDData;
};

class audioMixer 
{
    friend class NDIModule;
    friend class sndfileModule;

private:
    //input modules(optional) : 
     
    //NDI 
    std::unique_ptr<NDIModule>      NDI;
    bool                            NDIEnabled;

    //libsndfile
    std::unique_ptr<sndfileModule>  sndfile;
    bool                            sndfileEnabled;

    //portaudio stream
    PaStream*                       PaStreamOut;
    audioQueue<float>               outputAudioQueue;
public:
    audioMixer() = default;
    audioMixer(const std::uint8_t   nbChannels, 
               const std::size_t    sampleRate, 
               const std::size_t    max,
               const std::size_t    min,
               const bool           enableNDI, 
               const bool           enableSndfile);

    ~audioMixer();
};


















/*
bool startOutput()
    {
        PA_Callback = [this](const  void*                       inputBuffer,
                                void*                       outputBuffer,
                                unsigned long               framesPerBuffer,
                         const  PaStreamCallbackTimeInfo*   timeInfo,
                                PaStreamCallbackFlags       statusFlags,
                                void*                       userData) -> int
            {
                auto out = static_cast<int32_t*>(outputBuffer);
                //Set output buffer to zero by default to avoid noise when there is no input.
                memset(out, 0, sizeof(out) * framesPerBuffer);
                if (NDIEnabled)
                {
                    for (auto& currentAudioQueue : *(this->NDI).)
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
                    }
                }
                return 0;
            };
        portaudio = std::make_unique<portaudioModule>(nbChannels, sampleRate, PA_BufferSize, );
        portaudio->start();
    }*/