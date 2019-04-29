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

    

        

        return nullptr;
    }

    //-----------------------------------------------------------------------
    void Root::addRenderSystem(RenderSystem* newRend)
    {
        mRenderers.push_back(newRend);
    }
}