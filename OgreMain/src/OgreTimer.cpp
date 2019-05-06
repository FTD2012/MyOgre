#include "OgreTimer.h"

using namespace std::chrono;

namespace Ogre {
    //--------------------------------------------------------------------------------
    Timer::Timer()
    {
        reset();
    }

    //--------------------------------------------------------------------------------
    void Timer::reset()
    {
        zeroClock = clock();
        start = steady_clock::now();
    }

    //--------------------------------------------------------------------------------
    unsigned long Timer::getMilliseconds()
    {
        auto now = steady_clock::now();
        return duration_cast<milliseconds>(now - start).count();
    }


    //--------------------------------------------------------------------------------
    unsigned long Timer::getMicroseconds()
    {
        auto now = steady_clock::now();
        return duration_cast<microseconds>(now - start).count();
    }

    //--------------------------------------------------------------------------------
    unsigned long Timer::getMillisecondsCPU()
    {
        clock_t newClock = clock();
        return (unsigned long)((float)(newClock-zeroClock) / ((float)CLOCKS_PER_SEC/1000.0));
    }

    //--------------------------------------------------------------------------------
    unsigned long Timer::getMicrosecondsCPU()
    {
        clock_t newClock = clock();
        return (unsigned long)((float)(newClock-zeroClock) / ((float)CLOCKS_PER_SEC/1000000.0));
    }
}