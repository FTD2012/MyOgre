#include "OgreGL3PlusPlugin.h"
#include "OgreRoot.h"
#include "OgreGL3PlusRenderSystem.h"

namespace Ogre {
    const String sPluginName = "GL 3+ RenderSystem";

    //-----------------------------------------------------------------------
    GL3PlusPlugin::GL3PlusPlugin()
    : mRenderSystem(nullptr)
    {

    }

    //-----------------------------------------------------------------------
    const String& GL3PlusPlugin::getName() const
    {
        return sPluginName;
    }

    //-----------------------------------------------------------------------
    void GL3PlusPlugin::install()
    {
        mRenderSystem = OGRE_NEW GL3PlusRenderSystem();
        Root::getSingletonPtr()->addRenderSystem(mRenderSystem);
    }

    //-----------------------------------------------------------------------
    void GL3PlusPlugin::initialise()
    {
        // nothing to do
    }
    
    //-----------------------------------------------------------------------
    void GL3PlusPlugin::shutdown()
    {
        // nothing to do
    }
    
    //-----------------------------------------------------------------------
    void GL3PlusPlugin::uninstall()
    {
        OGRE_DELETE mRenderSystem;
        mRenderSystem = nullptr;
    }

}