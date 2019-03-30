#include <time.h>
#include "OgrePlatform.h"
#include <iostream>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#include "OgreString.h"

#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS

#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID

#endif