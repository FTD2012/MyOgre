#include "OgreApplicationContextBase.h"

#include "OgreViewport.h"

#include "OgreRoot.h"

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

        setup();
    }

    void ApplicationContextBase::setup()
    {

    }

    void ApplicationContextBase::createRoot()
    {
        Ogre::String pluginsPath;

        mRoot = OGRE_NEW Ogre::Root(pluginsPath);
    }

    void ApplicationContextBase::oneTimeConfig()
    {
        // if (!mRoot->get)
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

        



    }

}