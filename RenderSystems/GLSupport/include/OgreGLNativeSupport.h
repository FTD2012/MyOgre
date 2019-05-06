#ifndef __GLNativeSupport_H_
#define __GLNativeSupport_H_

#include "OgreGLSupportPrerequisites.h"

#include "OgreGLRenderSystemCommon.h"

namespace Ogre {
    /** \addtogroup RenderSystems RenderSystems
    *  @{
    */
    /** \defgroup GLSupport GLSupport
    * provides OpenGL Context creation using GLX, WGL, EGL, Cocoa
    *  @{
    */
    class _OgreGLExport GLNativeSupport
    {
    public:

        enum ContextProfile
        {
            CONTEXT_CORE = 1,
            CONTEXT_COMPATIBILITY = 2,
            CONTEXT_ES = 4
        };



    protected:
        ContextProfile mContextProfile;

    public:

        GLNativeSupport(int profile)
        : mContextProfile(ContextProfile(profile))
        {

        }

        virtual ~GLNativeSupport()
        {

        }

        virtual RenderWindow* newWindow(const String &name, unsigned int width, unsigned int height,
                                        bool fullScreen, const NameValuePairList *miscParams = 0) = 0;

        virtual void start() = 0;

        virtual void stop() = 0;
    };
    /** @} */
    /** @} */
}

#endif  // #ifndef __GLNativeSupport_H_