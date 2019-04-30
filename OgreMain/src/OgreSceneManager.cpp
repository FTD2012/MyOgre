#include "OgreStableHeaders.h"

#include <cstdio>


namespace Ogre {
    //-----------------------------------------------------------------------
    SceneManager::SceneManager(const String& name)
    : mName(name)
    , mDestRenderSystem(nullptr)
    , mShadowRenderer(this)
    {

    }


    //-----------------------------------------------------------------------
    void SceneManager::_setDestinationRenderSystem(RenderSystem* sys)
    {
        mDestRenderSystem = sys;
        mShadowRenderer.mDestRenderSystem = sys;

        if (sys)
        {
            
        }
    }

}
