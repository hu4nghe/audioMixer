#ifndef AUDIO_QUEUE_H
#define AUDIO_QUEUE_H

#include <atomic>
#include <concepts>
#include <print>
#include <vector>

#include "samplerate.h"

#include "queueBlocker.h"

template<typename T>
concept audioType = std::same_as<T, short> || std::same_as<T, float>;

template <audioType T>
class audioQueue 
{
    private :
 
    inline   static                                     std::uint32_t   queueCount = 0;

                                                        std::vector<T>  queue;

                                            std::atomic<std::  size_t>  head;
                                            std::atomic<std::  size_t>  tail;                
                                            std::atomic<std::  size_t>  elementCount;

                                                        std::uint32_t   audioSampleRate;
    
                                                        std:: uint8_t   channelNum;
                                                        std:: uint8_t   bufferMin;
                                            std::atomic<std:: uint8_t>  usage;
                                                        
                                
    public : 
  /*inline    Return Type    Function            const  Argument Type    Argument               const  noexcept      Implementation*/

                             audioQueue         ();
                             audioQueue         (const  std::uint32_t    sampleRate,
                                                 const  std:: uint8_t    channelNumbers              ,
                                                 const  std::  size_t    frames);
                             audioQueue         (const   audioQueue<T>  &other);
                             audioQueue         (        audioQueue<T> &&other)                        noexcept;
                            ~audioQueue         ()                                                                  { queueCount--; }

                       bool  push               (const              T*   ptr, 
                                                 const  std::  size_t    frames,
                                                 const  std:: uint8_t  inputChannelNum,
                                                 const  std::uint32_t  inputSampleRate);
                       bool  pop                (                   T*  &ptr, 
                                                 const  std::  size_t    frames,
                                                 const           bool    mode);

    inline             void  setSampleRate      (const  std::uint32_t    newSampleRate)                noexcept     { audioSampleRate = newSampleRate; }
    inline             void  setChannelNum      (const  std:: uint8_t    newChannelNum )               noexcept     { channelNum      = newChannelNum; }
                       void  setCapacity        (const  std::  size_t    newCapacity);                  

    inline             bool  empty              ()                                              const               { return usage.load() == 0; }
    inline    std::  size_t  size               ()                                              const               { return elementCount.load(); }
    inline    std:: uint8_t  channels           ()                                              const               { return channelNum; }
    inline    std::uint32_t  sampleRate         ()                                              const               { return audioSampleRate; }

    static    std::uint32_t  getCount           ()                                                     noexcept     { return queueCount; }

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
    :   queue           (0),  
        audioSampleRate (0), 
        channelNum      (0),
        head            (0), 
        tail            (0), 
        usage           (0), 
        elementCount    (0),
        bufferMin       (0) { queueCount ++; }

template<audioType T>
inline audioQueue<T>::audioQueue(const std::uint32_t sampleRate, 
                                 const std:: uint8_t channelNumbers, 
                                 const std::  size_t frames)
    :   queue           (frames * channelNumbers),
        audioSampleRate (sampleRate), 
        channelNum      (channelNumbers),
        head            (0), 
        tail            (0),
        usage           (0),
        elementCount    (0),
        bufferMin       (0) { queueCount++; }

template<audioType T>
inline audioQueue<T>::audioQueue(const audioQueue<T>& other)
    :
        queue           (other.queue),
        head            (other.head.load()),
        tail            (other.tail.load()),
        elementCount    (other.elementCount.load()),
        audioSampleRate (other.audioSampleRate),
        channelNum      (other.channelNum),
        usage           (other.usage.load()),
        bufferMin       (other.bufferMin) { queueCount++; }

template<audioType T>
inline audioQueue<T>::audioQueue(audioQueue<T> &&other) noexcept
    :
        queue           (std::move(other.queue)),
        head            (other.head.load()),
        tail            (other.tail.load()),
        elementCount    (other.elementCount.load()),
        audioSampleRate (other.audioSampleRate),
        channelNum      (other.channelNum),
        usage           (other.usage.load()),
        bufferMin       (other.bufferMin){ queueCount++; }


#pragma endregion

#pragma region Private member functions
template<audioType T>
bool audioQueue<T>::enqueue(const T value)
{
    auto currentTail = tail.load(std::memory_order_release);
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
    auto currentHead =  head.load(std::memory_order_release);

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
        return;
    auto newUsage = static_cast<double>(elementCount.load()) / queue.size() * 100.0;
    usage.store(static_cast<std::uint8_t>(newUsage)); 
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
    src_delete (srcState);

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
    queueBlocker inputBlocker(0.1, 0.1, 0.01, 50);
    const auto delayCoefficient = 0.5 / queueCount;
    auto delayTime = static_cast<int>(delayCoefficient * inputBlocker.delayCalculate(estimatedUsage));
    if (delayTime < 0)
    {
        if(-delayTime > inputDelay.load())
            inputDelay.store(-delayTime);
    }
    else
    {
        if (delayTime > outputDelay.load())
            outputDelay.store(delayTime);
    }

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
    queueBlocker inputBlocker(0.1, 0.01, 0.01, 50);
    const auto delayCoefficient = 4 / queueCount;
    auto delayTime = static_cast<int>(delayCoefficient * inputBlocker.delayCalculate(estimatedUsage));
    if (delayTime < 0)  outputDelay.store(-delayTime);
    else                outputDelay.store( delayTime); 

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
        if (!this->empty()) 
            this->clear();
        queue.resize(newCapacity);
    }
}
#pragma endregion

#endif// AUDIO_QUEUE_H