#ifndef __OGRE_GLFWGLSupport_H_
#define __OGRE_GLFWGLSupport_H_

#include "OgreGLNativeSupport.h"


namespace Ogre {

    class GLFWGLSupport : public GLNativeSupport
    {
    public:
        GLFWGLSupport(int profile)
        : GLNativeSupport(profile)
        {

        }

        ~GLFWGLSupport()
        {

        }

        virtual RenderWindow* newWindow(const String &name, unsigned int width, unsigned int height,
                                        bool fullScreen, const NameValuePairList* miscParams = nullptr);

        void start();
        
        void stop();
    };
} // namespace Ogre



#endif  // #ifndef __OGRE_GLFWGLSupport_H_