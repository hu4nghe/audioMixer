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
 * @tparam T audio data type : 32bit float(-1,1) or 16bit short(-32767,32768).
 */
template<typename T>
concept audioType = std::same_as<T, short> || std::same_as<T, float>;

template <audioType T>
class audioQueue 
{
    private :
                                                                            std::vector<T>   queue;

                                                                std::atomic<std::  size_t>   head;
                                                                std::atomic<std::  size_t>   tail;                
                                                                std::atomic<std::  size_t>   elementCount;
                                                                            std::  size_t    bufferMin;
                                                                            std::uint32_t    outputSampleRate;
                                                                            std:: uint8_t    outputNbChannel;
                                                        
                                                        
                                
    public : 
                                                 audioQueue         ();
                                                 audioQueue         (const  std::uint32_t    sampleRate,
                                                                     const  std:: uint8_t    channelNumbers,
                                                                     const  std::  size_t    bufferMax,
                                                                     const  std::  size_t    bufferMin);
                                                 audioQueue         (const   audioQueue<T>&  other);
                                                 audioQueue         (        audioQueue<T>&& other)                        noexcept;
                             
                                           bool  push               (const              T*   data,
                                                                     const  std::  size_t    frames,
                                                                     const  std::uint32_t    inputSampleRate,
                                                                     const  std:: uint8_t    inputNbChannel);

                                           bool  pop                (                   T*&  data,
                                                                     const  std::  size_t    frames,
                                                                     const           bool    mode);

                        inline             void  setSampleRate      (const  std::uint32_t    newSampleRate)                noexcept     { outputSampleRate = newSampleRate; }
                        inline             void  setChannelNum      (const  std:: uint8_t    newChannelNum )               noexcept     { outputNbChannel  = newChannelNum; }
                                           void  setCapacity        (const  std::  size_t    newCapacity);
                        inline             void  setMinBuffer       (const  std::  size_t    newMinBuffer)                 noexcept     { bufferMin        = newMinBuffer;  }

    [[nodiscard]]       inline             bool  empty              ()                                              const  noexcept     { return  elementCount.load() == 0; }
    [[nodiscard]]       inline    std::  size_t  size               ()                                              const  noexcept     { return  elementCount.load();      }
    [[nodiscard]]       inline    std:: uint8_t  channels           ()                                              const  noexcept     { return  outputNbChannel;          }
    [[nodiscard]]       inline    std::uint32_t  sampleRate         ()                                              const  noexcept     { return  outputSampleRate;         }
                        inline    std::vector<T> getvec             ()                                                                  { return  queue;                    }

    private :
    [[nodiscard]]                          bool  enqueue            (const              T    value);
    [[nodiscard]]                          bool  dequeue            (                   T&   value,
                                                                     const           bool    mode);
                                           void  clear              ();
                                           void  resample           (       std::vector<T>&  data,
                                                                     const  std::  size_t    frames,
                                                                     const  std::uint32_t    inputSampleRate,
                                                                     const  std:: uint8_t    inputNbChannel);
                                 std::vector<T>  channelConvert     (const  std::vector<T>&  data,
                                                                     const  std:: uint8_t    originalNbChannel,
                                                                     const  std:: uint8_t    targetNbChannel);
};

#pragma region Constructors
/**
 * @brief Default constructor.
 * 
 * @tparam T 
 */
template<audioType T>
audioQueue<T>::audioQueue()
    :   queue            (0),  
        outputSampleRate (0), 
        outputNbChannel       (0),
        head             (0), 
        tail             (0), 
        elementCount     (0),
        bufferMin        (0){}

/**
 * @brief Construct a new audioQueue<T>::audioQueue object with following arguments : 
 * 
 * @tparam T audio data type.
 * @param sampleRate OUTPUT samplerate that you want.
 * @param channelNumbers OUTPUT channels that you want.
 * @param bufferMax the max size of buffer, in sample numbers.
 */
template<audioType T>
audioQueue<T>::audioQueue              (const std::uint32_t    sampleRate, 
                                        const std:: uint8_t    channelNumbers, 
                                        const std::  size_t    bufferMax,
                                        const std::  size_t    bufferMin)
    :   queue            (bufferMax * channelNumbers),
        outputSampleRate (sampleRate), 
        outputNbChannel       (channelNumbers),
        head             (0), 
        tail             (0),
        elementCount     (0),
        bufferMin        (bufferMin){}

/**
 * @brief Copy constructor
 * 
 * @tparam T audio data type.
 * @param other audioQueue object to copy
 */
template<audioType T>
audioQueue<T>::audioQueue              (const  audioQueue<T>&  other)
    :
        queue            (other.queue),
        head             (other.head.load()),
        tail             (other.tail.load()),
        elementCount     (other.elementCount.load()),
        outputSampleRate (other.outputSampleRate),
        outputNbChannel       (other.outputNbChannel),
        bufferMin        (other.bufferMin){}

/**
 * @brief Move constructor
 * 
 * @tparam T audio data type.
 * @param other audioQueue object to move
 */
template<audioType T>
audioQueue<T>::audioQueue              (       audioQueue<T>&& other) noexcept
    :
        queue            (std::move(other.queue)),
        head             (other.head.load()),
        tail             (other.tail.load()),
        elementCount     (other.elementCount.load()),
        outputSampleRate (other.outputSampleRate),
        outputNbChannel       (other.outputNbChannel),
        bufferMin        (other.bufferMin){}


#pragma endregion

#pragma region Private member functions

/**
 * @brief enqueue operation, push one element into the audio queue.
 * 
 * use release - aquire model to ensure a sychornized-with relation between differnt therad.
 * 
 * @tparam T audio data type
 * @param value data to push.
 * @return true push successed.
 * @return false push failed.
 */
template<audioType T>
bool audioQueue<T>::enqueue            (const             T    value)
{
    auto currentTail = tail.load(std::memory_order_relaxed);
    auto    nextTail = (currentTail + 1) % queue.size(); //calculate next tail in circular queue.

    if (nextTail == head.load(std::memory_order_acquire)) 
        return false; // Queue is full
     
    queue[currentTail] = value;

    tail        .store    (nextTail, std::memory_order_release);
    elementCount.fetch_add(       1, std::memory_order_relaxed);
    return true;
}

/**
 * @brief dequeue operation, pop one element from the head of the queue.
 * 
 * use release - aquire model to ensure a sychornized-with relation between differnt therad.
 * 
 * @tparam T 
 * @param value the target variable for pop output.
 * @param mode true : do a addition that add poped element to value;
 *             false : do a replacement that replace the origingal element in value.
 * @return true if pop successed.
 * @return false if pop failed.
 */
template<audioType T>
bool audioQueue<T>::dequeue            (                  T&   value, 
                                        const          bool    mode)
{
    auto currentHead =  head.load(std::memory_order_relaxed);
    auto    nextHead = (currentHead + 1) % queue.size();//calculate next head in circular queue.

    if ( currentHead == tail.load(std::memory_order_acquire)) 
        return false; // Queue is empty

    if (!mode) value  = queue[currentHead];//cover mode.
    else       value += queue[currentHead];//addition mode.

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

/**
 * @brief resample a slice of audio using libsamplerate. 
 * 
 * @tparam T audio data type used
 * @param data input vector
 * @param frames input frames
 * @param inputSampleRate original sample rate
 */
template<audioType T>
void audioQueue<T>::resample           (      std::vector<T>  &data, 
                                        const std::  size_t    frames, 
                                        const std::uint32_t    inputSampleRate,
                                        const std:: uint8_t    inputNbChannel)
{
    const auto resampleRatio = static_cast<double>(outputSampleRate) / inputSampleRate;
    const auto newSize       = static_cast<size_t>(frames * outputNbChannel * resampleRatio);//ид modifier
    std::vector<T> temp(newSize);//new vector for resampling output.

    SRC_STATE* srcState = src_new(SRC_SINC_BEST_QUALITY, static_cast<int>(outputNbChannel), nullptr);//ид modifier

    SRC_DATA srcData;
    srcData.end_of_input  = true;
    srcData.data_in       = data.data();
    srcData.data_out      = temp.data();
    srcData.input_frames  = static_cast<long>(frames);
    srcData.output_frames = static_cast<int> (frames * resampleRatio);
    srcData.src_ratio     = resampleRatio;

    src_process(srcState, &srcData);
    src_delete (srcState);

    data = std::move(temp); //temp is moved and becomes deprecated to save costs.
}
template<audioType T>
std::vector<T> audioQueue<T>::channelConvert(
                                        const  std::vector<T>& data,
                                        const  std::uint8_t    originalNbChannel,
                                        const  std::uint8_t    targetNbChannel)
{
    auto frames         = data.size() / originalNbChannel;
    auto validNbChannel = std::min(originalNbChannel, targetNbChannel);

    std::vector<T> convertedData(frames * targetNbChannel, 0.0f);
    for (auto i = 0; i < frames; i++)
    {
        for (auto j = 0; j < validNbChannel; j++)
        {
            convertedData[i * targetNbChannel + j] = data[i * originalNbChannel + j];
        }
    }
    return convertedData;
}
#pragma endregion

#pragma region Public API
/**
 * @brief To push a numbers of samples into the buffer queue.
 * 
 * @tparam T audio data type.
 * @param  data input audio array.
 * @param  frames number of samples.
 * @param  inputSampleRate INPUT sample rate of original data.
 * @return true if push successed
 * @return false if push failed due to no enough space.
 */
template<audioType T>
bool audioQueue<T>::push               (const             T*   data, 
                                        const std::  size_t    frames, 
                                        const std::uint32_t    inputSampleRate,
                                        const std:: uint8_t    inputNbChannel)
{
    const auto currentSize  = frames * inputNbChannel;    
    std::vector<T> temp(data, data + currentSize);
    std::print("creation temp no souci\n\n");
    if (inputSampleRate != outputSampleRate) 
        resample(temp, frames, inputSampleRate,inputNbChannel);
    std::print("check resampling pas de souci\n\n");
    for (const auto &i : temp)
    {
        if (!this->enqueue(i))
            return false;
    }
    std::print("push pas de souci\n\n");
    return true;
}
/**
 * @brief To pop a number of samples out of buffer queue
 * 
 * @tparam T audio data type.
 * @param  data target output array.
 * @param  frames numbers of frames wanted.
 * @param  mode true  = addition mode, adds audio data to array.
 *              flase = cover mode, which will covers the original data in array.
 * @return true if pop successed.
 * @return false if pop failed or partially failed due to no enough samples in buffer.
 */
template<audioType T>
bool audioQueue<T>::pop                (                  T*&  data, 
                                        const std::  size_t    frames,
                                        const          bool    mode)
{
    if (elementCount.load(std::memory_order_acquire) < bufferMin)
        return false;

    const auto size = frames * outputNbChannel;
    for (auto i = 0; i < size; i++)
    {     
        if (!this->dequeue(data[i],mode)) 
        {
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