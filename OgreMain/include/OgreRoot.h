#ifndef __ROOT__
#define __ROOT__

#include "OgrePrerequisites.h"
#include "OgreSceneManagerEnumerator.h"

#include <exception>
#include "OgreHeaderPrefix.h"

namespace Ogre {

    typedef std::vector<RenderSystem*> RenderSystemList;

    /** The root class of the Ogre System.
     @remarks
        The Ogre::Root class represents a starting point for the client
        application. From here, the application can gain access to the
        fundamentals of the system, namely the rendering systems
        available, management of saved configurations, logging, and
        access to other classes in the system. Acts as a hub from which
        all other objects may be reached. An instance of Root must be
        created before any other Ogre operations are called. Once an
        instance has been created, the same instance is accessible
        throughout the life of that object by using Root::getSingleton
        (as a reference) or Root::getSingletonPtr (as a pointer).
    */
    class _OgreExport Root : public Singleton<Root>, public RootAlloc
    {
        friend class RenderSystem;
    protected:
        RenderSystemList mRenderers;
        RenderSystem* mActiveRenderer;

        // ordered in reverse destruction sequence
        std::unique_ptr<LogManager> mLogManager;

        std::unique_ptr<Timer> mTimer;

        std::unique_ptr<ControllerManager> mControllerManager;
        std::unique_ptr<SceneManagerEnumerator> mSceneManagerEnum;

        RenderWindow* mAutoWindow;

    public:
        typedef std::vector<Plugin*> PluginInstanceList;

    protected:
        /// List of Plugin instances registered
        PluginInstanceList mPlugins;

        /// Whether root is initialised
        bool mIsInitialised;
    
    public:
        Root(const String& pluginFileName = "plugins.cfg",
             const String& configFileName = "ogre.cfg",
             const String& logFileName = "Ogre.log");
        ~Root();


        /** @copydoc RenderSystem::_createRenderWindow
        */
        RenderWindow* createRenderWindow(const String& name, uint width, uint height, bool fullScreen, const NameValuePairList* miscParams = 0);
        RenderWindow* createRenderWindow(const RenderWindowDescription& desc)
        {
            return createRenderWindow(desc.name, desc.width, desc.height, desc.useFullScreen, &desc.miscParam);
        }

        /** Install a new plugin.
        @remarks
            This installs a new extension to OGRE. The plugin itself may be loaded
            from a DLL / DSO, or it might be statically linked into your own 
            application. Either way, something has to call this method to get
            it registered and functioning. You should only call this method directly
            if your plugin is not in a DLL that could otherwise be loaded with 
            loadPlugin, since the DLL function dllStartPlugin should call this
            method when the DLL is loaded. 
        */
        void installPlugin(Plugin* plugin);

        /** Checks for saved video/sound/etc settings
        @remarks
            This method checks to see if there is a valid saved configuration
            from a previous run. If there is, the state of the system will
            be restored to that configuration.

        @return
            If a valid configuration was found, <b>true</b> is returned.
        @par
            If there is no saved configuration, or if the system failed
            with the last config settings, <b>false</b> is returned.
        */
        bool restoreConfig();

        /** Adds a new rendering subsystem to the list of available renderers.
        @remarks
            Intended for use by advanced users and plugin writers only!
            Calling this method with a pointer to a valid RenderSystem
            (subclass) adds a rendering API implementation to the list of
            available ones. Typical examples would be an OpenGL
            implementation and a Direct3D implementation.
        @note
            <br>This should usually be called from the dllStartPlugin()
            function of an extension plug-in.
        */
        void addRenderSystem(RenderSystem* newRend);

        /** Retrieve a list of the available render systems.
        @remarks
            Retrieves a pointer to the list of available renderers as a
            list of RenderSystem subclasses. Can be used to build a
            custom settings dialog.
        */
        const RenderSystemList& getAvailableRenderers();

        /** Retrieve a pointer to the render system by the given name.
        @param name
            Name of the render system intend to retrieve.
        @return
            A pointer to the render system, <b>NULL</b> if no found.
        */
        RenderSystem* getRenderSystemByName(const String& name);

        /** Sets the rendering subsystem to be used.
        @remarks
            This method indicates to OGRE which rendering system is to be
            used (e.g. Direct3D, OpenGL etc).
        @par
            This method is also called by render systems if they are
            initialised directly.
        @param
            system Pointer to the render system to use.
        @see
            RenderSystem
        */
        void setRenderSystem(RenderSystem* system);

        /** Retrieve a pointer to the currently selected render system.
        */
        RenderSystem* getRenderSystem();

        /** Initialises the render.
        @remarks
            This method can only be called after a renderer has been
            selected with Root::setRenderSystem, and it will initialise
            the selected rendering system ready for use.
        @param autoCreateWindow
            If true, a rendering window will automatically be created 
            (saving a call to Root::createRenderWindow). The window will be
            created based on the options currently set on the render system.
        @return
            A pointer to the automatically created window, if requested,
            otherwise <b>NULL</b>
        */
        RenderWindow* initialise(bool autoCreateWindwo, const String& windowTitle = "OGRE Render Window", const String& customCapabilitiesConfig = BLANKSTRING);

        static Root& getSingleton();
        static Root* getSingletonPtr();
    };




}


#include "OgreHeaderSuffix.h"

#endif  // #ifndef __ROOT__