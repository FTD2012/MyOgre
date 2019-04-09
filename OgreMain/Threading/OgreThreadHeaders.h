#ifndef __OgreThreadHeaders_H_
#define __OgreThreadHeaders_H_

#if !defined(NOMINMAX) && defined(_MSC_VER)
#   define NOMINMAX // required to stop window.h messing up std::min
#endif

#if OGRE_THREAD_PROVIDER == 1

#elif OGRE_THREAD_PROVIDER == 2

#elif OGRE_THREAD_PROVIDER == 3

#elif OGRE_THREAD_PROVIDER == 4
    #include "OgreThreadHeadersSTD.h"
#endif

#include "OgreThreadDefines.h"

#endif  // #ifndef __OgreThreadHeaders_H_