#include "OgreGL3PlusRenderSystem.h"

#include "OgreLogManager.h"

#include "OgreGLUtil.h"

namespace Ogre {

    //-----------------------------------------------------------------------
    GL3PlusRenderSystem::GL3PlusRenderSystem()
    {
        LogManager::getSingleton().logMessage(getName() + " created.");
  
        mGLSupport = getGLSupport();

    }

    //-----------------------------------------------------------------------    
    GL3PlusRenderSystem::~GL3PlusRenderSystem()
    {
        if (mGLSupport)
            OGRE_DELETE mGLSupport;
    }

    //-----------------------------------------------------------------------
    const String& GL3PlusRenderSystem::getName() const
    {
        static String strName("OpenGL 3+ Rendering Subsystem");
        return strName;
    }

    //-----------------------------------------------------------------------
    void GL3PlusRenderSystem::_initialise()
    {
        RenderSystem::_initialise();
        mGLSupport->start();
    }

    //-----------------------------------------------------------------------
    RenderWindow* GL3PlusRenderSystem::_createRenderWindow(const String& name, unsigned int width, unsigned int height,
                                                           bool fullScreen, const NameValuePairList* miscParams)
    {
        RenderWindow* window = mGLSupport->newWindow(name, width, height, fullScreen, miscParams);

    }
}