#include "OgreLogManager.h"
// #include "OgreStringConverter.h"
#include "OgreGLFWGLSupport.h"
#include "OgreGLFWWindow.h"

#include "OgreGLUtil.h"

namespace Ogre {

    //-----------------------------------------------------------------------
    GLNativeSupport* getGLSupport(int profile)
    {
        return OGRE_NEW GLFWGLSupport(profile);
    }

    //-----------------------------------------------------------------------
    RenderWindow* GLFWGLSupport::newWindow(const String &name, unsigned int width, unsigned int height, bool fullScreen, const NameValuePairList* miscParams)
    {
        NameValuePairList params;
        if(miscParams)
            params = *miscParams;
        params["contextProfile"] = std::to_string(int(mContextProfile));

        LogManager::getSingletonPtr()->logMessage("Creating a GLFW Compatible Render System");
        GLFWWindow* window = OGRE_NEW GLFWWindow();
        window->create(name, width, height, fullScreen, &params);

        return window;
    }

    //-----------------------------------------------------------------------
    void GLFWGLSupport::start()
    {
	    LogManager::getSingleton().logMessage(
			"********************************************\n"
			"***  Starting Mac OS X OpenGL Subsystem  ***\n"
			"********************************************");
    }

    //-----------------------------------------------------------------------
    void GLFWGLSupport::stop()
    {
        LogManager::getSingleton().logMessage(
			"********************************************\n"
			"***  Stopping Mac OS X OpenGL Subsystem  ***\n"
			"********************************************");
    }
}