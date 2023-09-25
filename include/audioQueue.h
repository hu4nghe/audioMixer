#ifndef AUDIO_QUEUE_H
#define AUDIO_QUEUE_H

#include <atomic>
#include <concepts>
#include <print>
#include <thread>
#include <vector>

#include "samplerate.h"
#include "sndfile.hh"

#include "queueBlocker.h"

template<typename T>
concept audioType = std::same_as<T, short> || std::same_as<T, float>;

template <audioType T>
class audioQueue 
{
    private :
 /* atomic?   Type           Name*/  

              std::vector<T> queue;

  std::atomic<std::  size_t> head;
  std::atomic<std::  size_t> tail;                
  std::atomic<std::  size_t> elementCount;
              std::uint32_t  audioSampleRate;
              std:: uint8_t  channelNum;
  std::atomic<std:: uint8_t> usage;

    public : 
  /*inline?   Return Type    Function            const? Argument Type    Argument               const? noexcept?     Implementation*/

                             audioQueue         ();
                             audioQueue         (const  std::uint32_t    sampleRate,
                                                 const  std:: uint8_t    channelNumbers,
                                                 const  std::  size_t    frames);
                             audioQueue         (const   audioQueue<T>   &other);
                             audioQueue         (        audioQueue<T>  &&other)                       noexcept;

                       bool  push               (const              T*   ptr, 
                                                 const  std::  size_t    frames,
                                                 const  std:: uint8_t    outputChannelNum,
                                                 const  std::uint32_t    outputSampleRate);
                       bool  pop                (                   T*  &ptr, 
                                                 const  std::  size_t    frames,
                                                 const           bool    mode);

    inline             void  setSampleRate      (const  std::uint32_t    sRate)                        noexcept     { audioSampleRate = sRate; }
    inline             void  setChannelNum      (const  std:: uint8_t    cNum )                        noexcept     { channelNum = cNum; }
                       void  setCapacity        (const  std::  size_t    newCapacity);                  

               
    inline    std::uint32_t  sampleRate         ()                                              const  noexcept     { return audioSampleRate; }
    inline    std:: uint8_t  channels           ()                                              const  noexcept     { return channelNum; }
    inline    std::  size_t  size               ()                                              const  noexcept     { return elementCount.load(); }
    inline             bool  empty              ()                                              const  noexcept     { return usage.load() == 0; }

    private :
                       bool  enqueue            (const              T    value);
                       bool  dequeue            (                   T   &value,
                                                 const           bool    mode);
                       void  clear              ();
                       void  usageRefresh       (); 
                       void  resample           (       std::vector<T>  &data,
                                                 const  std::  size_t    frames,
                                                 const  std::uint32_t    inputSampleRate);
                       void  channelConversion  (       std::vector<T>  &data,
                                                 const  std:: uint8_t    inputChannelNum);
                       
};

#pragma region Constructors
template<audioType T>
inline audioQueue<T>::audioQueue()
    :   queue(0),  
        audioSampleRate(0), 
        channelNum(0),
        head(0), 
        tail(0), 
        usage(0), 
        elementCount(0), {}

template<audioType T>
inline audioQueue<T>::audioQueue(const std::uint32_t sampleRate, 
                                 const std:: uint8_t channelNumbers, 
                                 const std::  size_t frames)
    :   queue(frames * channelNumbers),
        audioSampleRate(sampleRate), 
        channelNum(channelNumbers),
        head(0), 
        tail(0),
        usage(0),
        elementCount(0){}

template<audioType T>
inline audioQueue<T>::audioQueue(const audioQueue<T> &other)
{
   
    queue           = other.queue;
    head.           store(other.head.load());
    tail.           store(other.tail.load());
    elementCount.   store(other.elementCount.load());
    audioSampleRate = other.audioSampleRate;
    channelNum      = other.channelNum;
    usage.          store(other.usage.load());
}

template<audioType T>
inline audioQueue<T>::audioQueue(audioQueue<T> &&other) noexcept
{
    queue           = std::move(other.queue);
    head.           store(other.head.load());
    tail.           store(other.tail.load());
    elementCount.   store(other.elementCount.load());
    audioSampleRate = other.audioSampleRate;
    channelNum      = other.channelNum;
    usage.          store(other.usage.load());
}


#pragma endregion

#pragma region Private member functions
template<audioType T>
bool audioQueue<T>::enqueue(const T value)
{
    auto currentTail = tail.load(std::memory_order_relaxed);
    auto nextTail    = (currentTail + 1) % queue.size();

    if (nextTail == head.load(std::memory_order_acquire)) 
        return false; // Queue is full

    queue[currentTail] = value;
    tail        .store      (nextTail, std::memory_order_release);
    elementCount.fetch_add  (       1, std::memory_order_relaxed);
    return true;
}

template<audioType T>
bool audioQueue<T>::dequeue(         T &value, 
                            const bool  mode)
{
    auto currentHead =  head.load(std::memory_order_relaxed);

    if ( currentHead == tail.load(std::memory_order_acquire)) 
        return false; // Queue is empty

    if (!mode) value  = queue[currentHead];
    else       value += queue[currentHead];
    head        .store      ((currentHead + 1) % queue.size(), std::memory_order_release);
    elementCount.fetch_sub  (                               1, std::memory_order_relaxed);
    return true;
}

template<audioType T>
inline void audioQueue<T>::clear()
{
    head        .store(0);
    tail        .store(0);
    elementCount.store(0);
}

template<audioType T>
inline void audioQueue<T>::usageRefresh() 
{ 
    if (queue.size() == 0)
    {
        std::print("error : queue size is 0.\n");
        return;
    }
    auto newUsage = static_cast<double>(elementCount.load()) / queue.size() * 100.0;
    usage.store(static_cast<std::uint8_t>(newUsage)); 
    //std::print("usage : {}\n", usage.load()); 
}

template<audioType T>
void audioQueue<T>::resample(      std::vector<T> &data, 
                             const std::  size_t   frames, 
                             const std::uint32_t   inputSampleRate)
{
    const auto resampleRatio = static_cast<double>(audioSampleRate) / inputSampleRate;
    const auto newSize       = static_cast<size_t>(frames * channelNum * resampleRatio);
    std::vector<T> temp(newSize);

    SRC_STATE* srcState = src_new(SRC_SINC_BEST_QUALITY, static_cast<int>(channelNum), nullptr);

    SRC_DATA srcData;
    srcData.end_of_input  = true;
    srcData.data_in       = data.data();
    srcData.data_out      = temp.data();
    srcData.input_frames  = static_cast<long>(frames);
    srcData.output_frames = static_cast<int> (frames * resampleRatio);
    srcData.src_ratio     = resampleRatio;

    src_process(srcState, &srcData);
    src_delete(srcState);
    
    data = std::move(temp);
}

template<audioType T>
void audioQueue<T>::channelConversion(      std::vector<T> &data, 
                                      const std:: uint8_t   inputChannelNum){}
#pragma endregion

#pragma region Public APIs
template<audioType T>
bool audioQueue<T>::push(const             T* ptr, 
                         const std::  size_t  frames, 
                         const std:: uint8_t  inputChannelNum, 
                         const std::uint32_t  inputSampleRate)
{
    const bool needChannelConversion    = (inputChannelNum != channelNum);
    const bool needResample             = (inputSampleRate != audioSampleRate);
    const auto currentSize              = frames * inputChannelNum;

    std::vector<T> temp(ptr, ptr + currentSize);
    /*if (needChannelConversion)
        channelConversion(temp, ChannelNum);*/
    if (needResample)
        resample(temp, frames, inputSampleRate);

    const auto estimatedUsage = usage.load() + (temp.size() * 100 / queue.size());
    queueBlocker inputBlocker(1, 0.01, 0.001, 50);
    auto delayTime = - inputBlocker.delayCalculate(estimatedUsage);

    if (estimatedUsage >= 50) 
        std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));

    for (const auto i : temp)
    {
        if (!this->enqueue(i))
        {
            std::print(stderr,"push aborted, no enough space.\n");
            usageRefresh();
            return false;
        }
    }
    usageRefresh();
    return true;
}

template<audioType T>
bool audioQueue<T>::pop(                 T* &ptr, 
                         const std::size_t   frames,
                         const bool          mode)
{
    const auto size = frames * channelNum;
    const auto estimatedUsage = usage.load() >= (size * 100 / queue.size()) ? usage.load() - (size * 100 / queue.size()) : 0;
    
    queueBlocker inputBlocker(1, 0.01, 0.001, 50);
    auto delayTime = inputBlocker.delayCalculate(estimatedUsage);

    if (estimatedUsage <= 50) 
        std::this_thread::sleep_for(std::chrono::milliseconds(delayTime));

    for (auto i = 0; i < size; i++)
    {   
        if (!this->dequeue(ptr[i],mode)) 
        {
           std::print(stderr,"pop aborted, no enough element in queue.\n");
           usageRefresh();
           return false;
        }
    }
    usageRefresh();
    return true;
}

template<audioType T>
inline void audioQueue<T>::setCapacity(const std::size_t newCapacity) 
{   
    if (newCapacity == queue.size()) return;
    else
    {
        if (!this->empty()) this->clear();
        queue.resize(newCapacity);
    }
}
#pragma endregion

#endif// AUDIO_QUEUE_H