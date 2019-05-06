#ifndef __OgreGLUtil_H_
#define __OgreGLUtil_H_

#include "OgreGLNativeSupport.h"

namespace Ogre {
    _OgreGLExport GLNativeSupport* getGLSupport(int profile = GLNativeSupport::CONTEXT_CORE);
}

#endif  // #ifndef __OgreGLUtil_H_