#ifndef AUDIOMIXER_H
#define AUDIOMIXER_H

class audioMixer
{
private:
    //input modules(optional)
    std::unique_ptr<NDIModule>                          ndi;
    std::unique_ptr<sndfileModule>                      sndFileModule;

    //output modules(obligatory)
    std::unique_ptr<portaudioModule>                    portaudio;
    std::function<int(const void*,
        void*,
        unsigned long,
        const PaStreamCallbackTimeInfo*,
        PaStreamCallbackFlags,
        void*)>                     PA_Callback;

    bool                                                NDIEnabled;
    bool                                                sndfileEnabled;

    /*Reserved for unfinished DeltaCast Module :
    std::unique_ptr<DeltaCastModule> deltaCastModule;
    bool DeltaCastEnabled;*/

    std::uint8_t outputChannels;
    std::size_t  outputsampleRate;
    std::size_t  PA_BufferSize;


public:
    audioMixer(const uint8_t     nbChannels,
        const size_t      sampleRate,
        const size_t      PA_framesPerBuffer,
        const bool        enableNDI,
        const bool        enableSndfile);

    ~audioMixer();

    bool startOutput()
    {
        PA_Callback = [this](const  void* inputBuffer,
            void* outputBuffer,
            unsigned long               framesPerBuffer,
            const  PaStreamCallbackTimeInfo* timeInfo,
            PaStreamCallbackFlags       statusFlags,
            void* userData) -> int
            {
                auto out = static_cast<int32_t*>(outputBuffer);
                //Set output buffer to zero by default to avoid noise when there is no input.
                memset(out, 0, sizeof(out) * framesPerBuffer);
                if (NDIEnabled)
                {
                    for (auto& currentAudioQueue : *(this->ndi).)
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
    }
};
#endif