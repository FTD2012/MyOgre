#ifndef __OgrePrerequisites_H_
#define __OgrePrerequisites_H_

/* Platform-specific stuff */
#include "OgrePlatform.h"

#include <string>
#include <memory>

namespace Ogre {




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