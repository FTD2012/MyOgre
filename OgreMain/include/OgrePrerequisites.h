#ifndef __OgrePrerequisites_H_
#define __OgrePrerequisites_H_

// Platform-specific stuff
#include "OgrePlatform.h"

#include <string>
#include <memory>

namespace Ogre {
#define OGRE_VERSION    ((OGRE_VERSION_MAJOR << 16) | (OGRE_VERSION_MINOR << 8) | OGRE_VERSION_PATCH)

// define the real number values to be used
// default to use 'float' unless precompiler option set
#if OGRE_DOUBLE_PRECISION == 1
    /** Software floating point type.
    @note Not valid as a pointer to GPU buffers / parameters
    */
    typedef double Real;
#else
    /** Software floating point type.
    @note Not valid as a pointer to GPU buffers / parameters
    */
    typedef float Real;
#endif

   typedef unsigned char uchar;
   typedef unsigned short ushort;
   typedef unsigned int uint;
   typedef unsigned long ulong;

    // Pre-declare classed
    // Allows use of pointers in header files without including individual .h
    // so decreases dependencies between files
    class ControllerManager;

    class Plugin;
    class RenderSystem;
    class RenderWindow;
    class Root;
    class LogManager;

    class Timer;
}

/**
 * Include all the standard header *after* all the configuration
 * settings have been made.
 */
#include "OgreStdHeaders.h"
#include "OgreMemoryAllocatorConfig.h"

namespace Ogre {
    typedef std::string _StringBase;
    typedef std::basic_stringstream<char, std::char_traits<char>, std::allocator<char> > _StringStreamBase;

    typedef _StringBase String;
    typedef _StringStreamBase StringStream;
    typedef StringStream stringstream;
}

#endif  // #ifndef __OgrePrerequisites_H_