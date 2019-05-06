#include "OgreStableHeaders.h"

#include "OgreRenderSystem.h"

namespace Ogre {
    RenderSystem::Listener* RenderSystem::msSharedEventListener = nullptr;

    //-----------------------------------------------------------------------
    RenderSystem::RenderSystem()
    {

    }

    //-----------------------------------------------------------------------
    RenderSystem::~RenderSystem()
    {
        
    }

    //-----------------------------------------------------------------------
    void RenderSystem::_initialise()
    {
        
    }

    //-----------------------------------------------------------------------
    RenderSystem::Listener* RenderSystem::getSharedListener()
    {
        return msSharedEventListener;
    }

    //-----------------------------------------------------------------------
    void RenderSystem::shutdown()
    {
        
    }
}