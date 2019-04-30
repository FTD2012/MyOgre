#include "OgreStableHeaders.h"

namespace Ogre {
    //-----------------------------------------------------------------------
    template<> Root* Singleton<Root>::mSingleton = nullptr;
    Root* Root::getSingletonPtr()
    {
        return mSingleton;
    }
    Root& Root::getSingleton()
    {
        assert(mSingleton);
        return *mSingleton;
    }

    //-----------------------------------------------------------------------
    Root::Root(const String& pluginFileName, const String& configFileName, const String& logFileName)
    : mActiveRenderer(nullptr)
    {
        if (!LogManager::getSingletonPtr())
        {
            mLogManager.reset(new LogManager());
            mLogManager->createLog(logFileName, true, true);
        }
    }

    //-----------------------------------------------------------------------
    Root::~Root()
    {

    }

    //-----------------------------------------------------------------------
    bool Root::restoreConfig()
    {
        String renderSystem = "";
        RenderSystem* rs = getRenderSystemByName(renderSystem);

        if (!rs)
            return false;

        

    }


    //-----------------------------------------------------------------------
    RenderWindow* Root::createWindow(const String& name, uint width, uint height, bool fullScreen, const NameValuePairList* miscParams)
    {

    }

    //-----------------------------------------------------------------------
    const RenderSystemList& Root::getAvailableRenderers()
    {
        return mRenderers;
    }

    //-----------------------------------------------------------------------
    RenderSystem* Root::getRenderSystemByName(const String& name)
    {
        if (name.empty())
            return nullptr;

        RenderSystemList::const_iterator pRend;
        for (pRend = getAvailableRenderers().begin(); pRend != getAvailableRenderers().end(); ++pRend)
        {
            RenderSystem* rs = *pRend;
            if (rs->getName() == name)
                return rs;
        }

        return nullptr;
    }

    //-----------------------------------------------------------------------
    void Root::setRenderSystem(RenderSystem* system)
    {
        if (mActiveRenderer && mActiveRenderer != system)
            mActiveRenderer->shutdown();

        mActiveRenderer = system;

        

    }

    //-----------------------------------------------------------------------
    void Root::addRenderSystem(RenderSystem* newRend)
    {
        mRenderers.push_back(newRend);
    }
}