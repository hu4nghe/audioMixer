#ifndef AUDIO_QUEUE_H
#define AUDIO_QUEUE_H

#include <atomic>
#include <concepts>
#include <print>
#include <vector>

#include "samplerate.h"

/**
 * @brief 
 * 
 * @tparam T the audio format used : float(-1,1) or short(-32767,32768).
 */
template<typename T>
concept audioType = std::same_as<T, short> || std::same_as<T, float>;

template <audioType T>
class audioQueue 
{
    private :
 
    inline   static                                     std::uint32_t    queueCount = 0;

                                                        std::vector<T>   queue;

                                            std::atomic<std::  size_t>   head;
                                            std::atomic<std::  size_t>   tail;                
                                            std::atomic<std::  size_t>   elementCount;

                                                        std::uint32_t    outputSampleRate;
    
                                                        std:: uint8_t    channelNum;
                                                        std:: uint8_t    bufferMin;
                                                        
                                
    public : 
                             audioQueue         ();
                             audioQueue         (const  std::uint32_t    sampleRate,
                                                 const  std:: uint8_t    channelNumbers,
                                                 const  std::  size_t    bufferMax);
                             audioQueue         (const   audioQueue<T>&  other);
                             audioQueue         (        audioQueue<T>&& other)                        noexcept;
                            ~audioQueue         ()                                                     noexcept     { queueCount--; }

                       bool  push               (const              T*   ptr,
                                                 const  std::  size_t    frames,
                                                 const  std::uint32_t    inputSampleRate);
                       bool  pop                (                   T*&  ptr,
                                                 const  std::  size_t    frames,
                                                 const           bool    mode);

    inline             void  setSampleRate      (const  std::uint32_t    newSampleRate)                noexcept     { outputSampleRate = newSampleRate; }
    inline             void  setChannelNum      (const  std:: uint8_t    newChannelNum )               noexcept     { channelNum       = newChannelNum; }
                       void  setCapacity        (const  std::  size_t    newCapacity);

    inline             bool  empty              ()                                              const  noexcept     { return !elementCount.load(); }
    inline    std::  size_t  size               ()                                              const  noexcept     { return elementCount.load(); }
    inline    std:: uint8_t  channels           ()                                              const  noexcept     { return channelNum; }
    inline    std::uint32_t  sampleRate         ()                                              const  noexcept     { return outputSampleRate; }
    static    std::uint32_t  getCount           ()                                                     noexcept     { return queueCount; }

    private :
                       bool  enqueue            (const              T    value);
                       bool  dequeue            (                   T&   value,
                                                 const           bool    mode);
                       void  clear              ();
                       void  resample           (       std::vector<T>&  data,
                                                 const  std::  size_t    frames,
                                                 const  std::uint32_t    inputSampleRate);
};

#pragma region Constructors
template<audioType T>
audioQueue<T>::audioQueue()
    :   queue            (0),  
        outputSampleRate (0), 
        channelNum       (0),
        head             (0), 
        tail             (0), 
        elementCount     (0),
        bufferMin        (0) 
        { queueCount++; }

/**
 * @brief Construct a new audio Queue<T>::audio Queue object with following arguments : 
 * 
 * @tparam T the audio format used.
 * @param sampleRate OUTPUT samplerate that you want.
 * @param channelNumbers OUTPUT channels that you want.
 * @param bufferMax the max size of buffer, in sample numbers.
 */
template<audioType T>
audioQueue<T>::audioQueue              (const std::uint32_t    sampleRate, 
                                        const std:: uint8_t    channelNumbers, 
                                        const std::  size_t    bufferMax)
    :   queue            (bufferMax * channelNumbers),
        outputSampleRate (sampleRate), 
        channelNum       (channelNumbers),
        head             (0), 
        tail             (0),
        elementCount     (0),
        bufferMin        (0) 
        { queueCount++; }

/**
 * @brief Copy constructor
 * 
 * @tparam T the audio format used.
 * @param other 
 */
template<audioType T>
audioQueue<T>::audioQueue              (const  audioQueue<T>&  other)
    :
        queue            (other.queue),
        head             (other.head.load()),
        tail             (other.tail.load()),
        elementCount     (other.elementCount.load()),
        outputSampleRate (other.outputSampleRate),
        channelNum       (other.channelNum),
        bufferMin        (other.bufferMin) 
        { queueCount++; }

/**
 * @brief Move constructor
 * 
 * @tparam T T the audio format used.
 * @param other 
 */
template<audioType T>
audioQueue<T>::audioQueue              (       audioQueue<T>&& other) noexcept
    :
        queue            (std::move(other.queue)),
        head             (other.head.load()),
        tail             (other.tail.load()),
        elementCount     (other.elementCount.load()),
        outputSampleRate (other.outputSampleRate),
        channelNum       (other.channelNum),
        bufferMin        (other.bufferMin)
        { queueCount++; }


#pragma endregion

#pragma region Private member functions
template<audioType T>
bool audioQueue<T>::enqueue            (const             T    value)
{
    auto currentTail = tail.load(std::memory_order_acquire);
    auto    nextTail = (currentTail + 1) % queue.size();

    if (nextTail == head.load(std::memory_order_acquire)) 
        return false; // Queue is full
     
    queue[currentTail] = value;

    tail        .store    (nextTail, std::memory_order_release);
    elementCount.fetch_add(       1, std::memory_order_relaxed);
    return true;
}

template<audioType T>
bool audioQueue<T>::dequeue            (                  T&   value, 
                                        const          bool    mode)
{
    auto currentHead =  head.load(std::memory_order_acquire);
    auto    nextHead = (currentHead + 1) % queue.size();

    if ( currentHead == tail.load(std::memory_order_acquire)) 
        return false; // Queue is empty

    if (!mode) value  = queue[currentHead];
    else       value += queue[currentHead];

    head        .store    (nextHead, std::memory_order_release);
    elementCount.fetch_sub(       1, std::memory_order_relaxed);
    return true;
}

template<audioType T>
void audioQueue<T>::clear              ()
{
    head        .store(0);
    tail        .store(0);
    elementCount.store(0);
}

template<audioType T>
void audioQueue<T>::resample           (      std::vector<T>  &data, 
                                        const std::  size_t    frames, 
                                        const std::uint32_t    inputSampleRate)
{
    const auto resampleRatio = static_cast<double>(outputSampleRate) / inputSampleRate;
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
#pragma endregion

#pragma region Public APIs
/**
 * @brief To push a numbers of samples into the buffer queue.
 * 
 * @tparam T the audio format used.
 * @param ptr input audio array.
 * @param frames number of samples.
 * @param inputSampleRate INPUT sample rate of original data.
 * @return true if push successed
 * @return false if push failed due to no enough space.
 */
template<audioType T>
bool audioQueue<T>::push               (const             T*   ptr, 
                                        const std::  size_t    frames, 
                                        const std::uint32_t    inputSampleRate)
{
    //check the input sample rate with expected output samplerate
    const bool needResample = (inputSampleRate != outputSampleRate);
    const auto currentSize  = frames * channelNum;

    //create a temporary vector for resampleing.
    
    std::vector<T> temp(ptr, ptr + currentSize);

    if (needResample) resample(temp, frames, inputSampleRate);
    
    for (const auto i : temp)
    {
        if (!this->enqueue(i))
        {
            std::print("push error\n");
            return false;
        }
    }
    return true;
}
/**
 * @brief To pop a number of samples out of buffer queue
 * 
 * @tparam T the audio format used.
 * @param ptr target output array.
 * @param frames numbers of frames wanted.
 * @param mode true  = addition mode, adds audio data to array.
 *             flase = cover mode, which will covers the original data in array.
 * @return true if pop successed.
 * @return false if pop failed or partially failed due to no enough samples in buffer.
 */
template<audioType T>
bool audioQueue<T>::pop                (                  T*&  ptr, 
                                        const std::  size_t    frames,
                                        const          bool    mode)
{
    if (this->queue.empty()) 
        return false;

    //calculate sample number
    const auto size = frames * channelNum;
    for (auto i = 0; i < size; i++)
    {   
        if (!this->dequeue(ptr[i],mode)) 
        {
            std::print("pop error\n");
            return false;
        }
    }
    return true;
}

/**
 * @brief To change max buffer size of audio queue.
 * 
 * warning : this operation will clear all datas in the buffer queue ! 
 * only use it when you don't want to play current audio anymore.
 * 
 * @tparam T 
 * @param newCapacity new queue capacity wanted.
 */
template<audioType T>
void audioQueue<T>::setCapacity        (const std::  size_t    newCapacity) 
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