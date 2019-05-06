#ifndef __ApplicationContextBase_H_
#define __ApplicationContextBase_H_

#include "OgreBitesPrerequisites.h"
#include "OgreBuildSettings.h"
#include "OgreLogManager.h"

#include "OgreFrameListener.h"
#include "OgreStaticPluginLoader.h"

// forward declarations
extern "C" struct GLFWwindow;

/** \addtogroup Optional Optional Components
*  @{
*/
/** \defgroup Bites Bites
* reusable utilities for rapid prototyping
*  @{
*/

namespace OgreBites {

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
    typedef ANativeWindow NativeWindowType;
#else
    typedef GLFWwindow NativeWindowType;
#endif

    // Link between a render window and a platform specific window
    struct NativeWindowPair
    {
        Ogre::RenderWindow* render;
        NativeWindowType* native;
    };

    class _OgreBitesExport ApplicationContextBase : public Ogre::FrameListener
    {
    protected:
        Ogre::Root* mRoot;
        StaticPluginLoader mStaticPluginLoader;

        Ogre::String mAppName;

        typedef std::vector<NativeWindowPair> WindowList;
        WindowList mWindows;

    public:
        explicit ApplicationContextBase(const Ogre::String& appName = "MyOgre3D");
        virtual ~ApplicationContextBase();

        Ogre::Root* getRoot() const {
            return mRoot;
        }

        // This function initializes the render system and resources.
        void initApp();


        // Set up the context after configuration.
        virtual void setup();

        // Create the OGRE root.
        virtual void createRoot();

        /** Configures the startup settings for OGRE. [I use the config dialog here,
        but you can also] restore from a config file. Note that this only happens
        when you start the context, and not when you reset it.
        */
        virtual bool oneTimeConfig();

        // Create a new render window.
        virtual NativeWindowPair createWindow(const Ogre::String& name, uint w = 800, uint = 600, Ogre::NameValuePairList miscParams = Ogre::NameValuePairList());

    };


    
}


/** @} */
/** @} */

#endif  // #ifndef __ApplicationContextBase_H_