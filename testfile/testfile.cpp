#include <iostream>
#include <chrono>
#include <thread>
#include "queueBlocker.h"

class testQueue
{
private : 
    std::size_t runTime;
    std::size_t inputCount;
    std::size_t outputCount;

public :
    testQueue() = default;
    void push()
    {

        std::this_thread::sleep_for(std::chrono::seconds(10));
    }
    void pop()
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
};
