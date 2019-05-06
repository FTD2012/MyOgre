#ifndef __OgreGLRenderSystemCommon_H_
#define __OgreGLRenderSystemCommon_H_

#include "OgreGLSupportPrerequisites.h"

#include "OgreRenderSystem.h"
#include "OgreRenderWindow.h"

namespace Ogre {

    class GLNativeSupport;

    class _OgreGLExport GLRenderSystemCommon : public RenderSystem
    {
    protected:
        GLNativeSupport* mGLSupport;

    public:
        String validateConfigOptions() { return BLANKSTRING; }

    };
}




#endif  // #ifndef __OgreGLRenderSystemCommon_H_
