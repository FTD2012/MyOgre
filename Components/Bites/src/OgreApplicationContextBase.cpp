#include "OgreApplicationContextBase.h"

#include "OgreViewport.h"

#include "OgreRoot.h"
#include "OgreLogManager.h"

namespace OgreBites {

    ApplicationContextBase::ApplicationContextBase(const Ogre::String& appName)
    : mAppName(appName)
    {

    }

    ApplicationContextBase::~ApplicationContextBase()
    {

    }

    void ApplicationContextBase::initApp()
    {
        createRoot();
        if (!oneTimeConfig())
        {
            Ogre::LogManager::getSingletonPtr()->logMessage("One time config failed.");
            return;
        }

        setup();
    }

    void ApplicationContextBase::setup()
    {
        mRoot->initialise(false);
        createWindow(mAppName);

    }

    void ApplicationContextBase::createRoot()
    {
        Ogre::String pluginsPath;

        mRoot = OGRE_NEW Ogre::Root(pluginsPath);

#ifdef OGRE_STATIC_LIB
        mStaticPluginLoader.load();
#endif
    }

    bool ApplicationContextBase::oneTimeConfig()
    {
        if (!mRoot->restoreConfig())
            return false;
        return true;
    }

    NativeWindowPair ApplicationContextBase::createWindow(const Ogre::String& name, uint w, uint h, Ogre::NameValuePairList miscParams)
    {
        NativeWindowPair ret = {NULL, NULL};

        if (!mWindows.empty())
            miscParams["currentGLContext"] = "true";

        Ogre::RenderWindowDescription p;
        miscParams.insert(p.miscParam.begin(), p.miscParam.end());
        p.name = name;
        p.miscParam = miscParams;

        if (w > 0 && h > 0)
        {
            p.width = w;
            p.height = h;
        }

        ret.render = mRoot->createRenderWindow(p);

        mWindows.push_back(ret);

        return ret;
    }

}