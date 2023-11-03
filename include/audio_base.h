#ifndef AUDIO_BASE_H
#define AUDIO_BASE_H

#include <concepts>
#include <format>
#include <string>
#include <iostream>
#include <limits>
#include <type_traits>

template <int bitDepth>
class audioType 
{
public:
    using dataType = std::conditional_t<bitDepth == 16, short,
                     std::conditional_t<bitDepth == 20  ||
                                        bitDepth == 24, int,
                     std::conditional_t<bitDepth == 32, float, void>>>;
    static_assert(!std::is_same_v<dataType, void>, "Unsupported Bit Depth");

                audioType   ()              : value(0)      {}
                audioType   (dataType val)  : value(val)    { checkValue(); }

    audioType&  operator=   (const dataType& val)           { value = val; checkValue(); return *this;}
    operator    dataType    ()                      const   { return value; }

private:

    dataType value;

    void checkValue() const 
    {
        std::string errorMsg = std::format("Value out of range for {} bit.\n", bitDepth);
        if constexpr (bitDepth == 16)
        {
            if (value < std::numeric_limits<dataType>::min() || value > std::numeric_limits<dataType>::max())
                throw std::out_of_range(errorMsg);
        }

        else if constexpr (bitDepth == 20)
        {
            if (value < -524288 || value > 524287)
                throw std::out_of_range(errorMsg);
        }
        else if constexpr (bitDepth == 24)
        {
            if (value < -8388608 || value > 8388607)
                throw std::out_of_range(errorMsg);
        }
        else
        {
            if (value < -1 || value > 1)
                throw std::out_of_range(errorMsg);
        }
        
    }
};

class audioMixerModule_base
{
public:

    //any copy or move of a Module is NOT possible!
    audioMixerModule_base(const audioMixerModule_base& other) = delete;
    audioMixerModule_base(audioMixerModule_base&& other) = delete;

    virtual void    start   () = 0;
    virtual void    stop    () = 0;
    virtual bool    isActive() = 0;
    virtual        ~audioMixerModule_base() {}
protected:
    audioMixerModule_base   () = default;
};

#endif//AUDIO_BASE_H