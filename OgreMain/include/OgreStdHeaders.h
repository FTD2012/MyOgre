#ifndef __StdHeaders_H_
#define __StdHeaders_H_

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdarg>
#include <cmath>

// STL containers
#include <vector>
#include <map>
#include <string>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

// STL algorithms & functions
#include <algorithm>
#include <functional>
#include <limits>

// C++ Stream stuff
#include <fstream>
#include <iosfwd>
#include <sstream>

#include <atomic>

extern "C" {
#   include <sys/types.h>
#   include <sys/stat.h>
}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT
#   undef min
#   undef max
#   if defined( __MINGW3___ )
#       include <unistd.h>
#   endif
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_LINUX || OGRE_PLATFORM == OGRE_PLATFORM_ANDROID || OGRE_PLATFORM == OGRE_PLATFORM_EMSCRIPTEN
extern "C" {
#   include <unistd.h>
#   include <dlfcn.h>
}
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE || OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
extern "C" {
#   include <unistd.h>
#   include <sys/param.h>
#   include <CoreFoundation/CoreFoundation.h>
}
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_EMSCRIPTEN
#   include <emscripten/emscripten.h>
#endif

#endif  // #ifndef __StdHeaders_H_