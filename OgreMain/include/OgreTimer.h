#ifndef __OGRE_TIMER_H_
#define __OGRE_TIMER_H_

#include "OgrePrerequisites.h"
#include <chrono>

namespace Ogre {
    class _OgreExport Timer : public TimerAlloc
    {
    private:
        std::chrono::steady_clock::time_point start;
        clock_t zeroClock;

    public:
        Timer();

        void reset();

        /** Returns milliseconds since initialisation or last reset. */
        unsigned long getMilliseconds();

        /** Returns miscroseconds since initialisation or last reset. */
        unsigned long getMicroseconds();

        /** Returns milliseconds since initialisation or last reset, only CPU time measured */  
        unsigned long getMillisecondsCPU();

        /** Returns microseconds since initialisation or last reset, only CPU time measured */  
        unsigned long getMicrosecondsCPU();
    };


}

#endif  // #ifndef __OGRE_TIMER_H_