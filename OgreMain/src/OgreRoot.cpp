#include "OgreStableHeaders.h"

#include "OgreControllerManager.h"
#include "OgrePlugin.h"
#include "OgreTimer.h"

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

        // Create SceneManager enumerator (note - will be managed by singleton)
        mSceneManagerEnum.reset(new SceneManagerEnumerator());

        mTimer.reset(new Timer());

        // Cant't create managers until initialised
        mControllerManager = nullptr;

    }

    //-----------------------------------------------------------------------
    Root::~Root()
    {

    }

    //-----------------------------------------------------------------------
    bool Root::restoreConfig()
    {
        String renderSystem = "OpenGL 3+ Rendering Subsystem";
        RenderSystem* rs = getRenderSystemByName(renderSystem);

        if (!rs)
            return false;

        String err = rs->validateConfigOptions();
        if (err.length() > 0)
            return false;

        setRenderSystem(rs);

        return true;
    }


    //-----------------------------------------------------------------------
    RenderWindow* Root::createRenderWindow(const String& name, uint width, uint height, bool fullScreen, const NameValuePairList* miscParams)
    {
        if (!mIsInitialised)
        {

        }

        if (!mActiveRenderer)
        {

        }

        RenderWindow* ret;
        ret = mActiveRenderer->_createRenderWindow(name, width, height, fullScreen, miscParams);

        return ret;
    }

    //-----------------------------------------------------------------------
    void Root::installPlugin(Plugin* plugin)
    {
        LogManager::getSingletonPtr()->logMessage("Installing plugin: " + plugin->getName());

        mPlugins.push_back(plugin);
        plugin->install();

        /// DOUBT: ljm >>> can if remove?
        if (mIsInitialised)
        {
            plugin->initialise();
        }

        LogManager::getSingleton().logMessage("Plugin successfully installed");
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

        if (mSceneManagerEnum)
            mSceneManagerEnum->setRenderSystem(system);
        
        if (RenderSystem::Listener* ls = RenderSystem::getSharedListener())
            ls->eventOccurred("RenderSystemChanged");
    }

    //-----------------------------------------------------------------------
    void Root::addRenderSystem(RenderSystem* newRend)
    {
        mRenderers.push_back(newRend);
    }

    //-----------------------------------------------------------------------
    RenderWindow* Root::initialise(bool autoCreateWindow, const String& windowTitle, const String& customCapabilitiesConfig)
    {
        // if (!mActiveRenderer)
        OgreAssert(mActiveRenderer, "Cannot initialise - no render");

        if (!mControllerManager)
            mControllerManager.reset(new ControllerManager());

        mActiveRenderer->_initialise();

        if (autoCreateWindow)
        {

        }

        mTimer->reset();
        
        mIsInitialised = true;

        return mAutoWindow;
    }
}