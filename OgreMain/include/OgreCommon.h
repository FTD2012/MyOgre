#ifndef __Common_H_
#define __Common_H_

#include "OgreHeaderPrefix.h"
#include "OgrePrerequisites.h"  /// DOUBE: ljm >>> maybe do not need ref this file

namespace Ogre {

    typedef _StringBase String;

    /// Constant black string, useful for returning by ret where local does not exist
    const String BLANKSTRING;

    /// Name / value parameter pair (first = name, second = value)
    typedef std::map<String, String> NameValuePairList;

    /// Render window creation parameters.
    struct RenderWindowDescription
    {
        String              name;
        uint                width;
        uint                height;
        bool                useFullScreen;
        NameValuePairList   miscParam;
    };
}

#include "OgreHeaderSuffix.h"

#endif  // ifndef __Common_H_