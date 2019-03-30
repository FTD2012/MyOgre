#ifndef __Common_H_
#define __Common_H_

#include "OgreHeaderPrefix.h"
#include "OgrePrerequisites.h"  /// DOUBE: ljm >>> maybe do not need ref this file

namespace Ogre {

    typedef _StringBase String;

    /// Constant black string, useful for returning by ret where local does not exist
    const String BLANKSTRING;

}

#include "OgreHeaderSuffix.h"

#endif  // ifndef __Common_H_