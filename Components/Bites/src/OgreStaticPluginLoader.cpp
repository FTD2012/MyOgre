#include "OgreStaticPluginLoader.h"
#include "OgreBuildSettings.h"
#include "OgreRoot.h"
#include "OgrePlugin.h"

#ifdef OGRE_BUILD_RENDERSYSTEM_GL3PLUS
#   define OGRE_STATIC_GL3Plus
#endif

// headers

#ifdef OGRE_STATIC_GL3Plus
#include "OgreGL3PlusPlugin.h"
#endif

namespace OgreBites {
    void StaticPluginLoader::load()
    {
#ifdef OGRE_STATIC_GL3Plus
        mPlugins.push_back(OGRE_NEW Ogre::GL3PlusPlugin());
#endif

        Ogre::Root* root = Ogre::Root::getSingletonPtr();
        for (size_t i = 0; i < mPlugins.size(); i++)
        {
            root->installPlugin(mPlugins[i]);
        }
    

    }

}
