#ifndef __GL3PlusPlugin_H_
#define __GL3PlusPlugin_H_

#include "OgrePlugin.h"

namespace Ogre {
    class GL3PlusRenderSystem;

    /** Plugin instance for GL3Plus Manager
    */
    class GL3PlusPlugin : public Plugin
    {
    protected:
        GL3PlusRenderSystem* mRenderSystem;

    public:
        GL3PlusPlugin();

        const String& getName() const;

        void install();

        void initialise();

        void shutdown();

        void uninstall();
    }


}

#endif  // #ifndef __GL3PlusPlugin_H_