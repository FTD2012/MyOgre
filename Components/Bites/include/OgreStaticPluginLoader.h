#ifndef __StaticPluginLoader_H_
#define __StaticPluginLoader_H_

#include "OgreBitesPrerequisites.h"
#include "OgrePrerequisites.h"

namespace OgreBites {

    /** Utility class for loading the plugins statically.

        When loading plugins statically, you are limited to loading plugins
        that are known about at compile time. This class will load all built
        plugins based on OgreBuildSettings.h
    */
    class _OgreBitesExport StaticPluginLoader
    {
    private:
        std::vector<Ogre::Plugin*> mPlugins;

    public:
        void load();

        void unload();
    };
}


#endif  // #ifndef __StaticPluginLoader_H_