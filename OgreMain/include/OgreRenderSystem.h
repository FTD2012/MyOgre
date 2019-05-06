#ifndef __RenderSystem_H_
#define __RenderSystem_H_

#include "OgrePrerequisites.h"

#include "OgreHeaderPrefix.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup RenderSystem
    *  @{
    */

    class _OgreExport RenderSystem : public RenderSysAlloc
    {
    public:
        RenderSystem();
        virtual ~RenderSystem();

        virtual const String& getName() const = 0;

        /** Validates the options set for the rendering system, returning a message if there are problems.
        */
        virtual String validateConfigOptions() = 0;

        /** Start up the render using the default render system.
            Called by Root::setRenderSystem. Shouldn't really be called
            directly, although this can be done if the app want s to.
        */
        virtual void _initialise();

        /** Shutdown the renderer and cleanup resources.
        */
        virtual void shutdown();

        /** Creates a new rendering window.
        */
        virtual RenderWindow* _createRenderWindow(const String& name, unsigned int width, unsigned int height, bool fullScreen, const NameValuePairList* miscParams = 0) = 0;

        /** Defines a listener on the custom events that this render system
            can raise.
        @see
            RenderSystem::addListener
        */
        class _OgreExport Listener
        {
        public:
            Listener() {}
            virtual ~Listener() {}
            
            /** A rendersystem-specific event occurred.
            @param eventName
                The name of the event which has occurred
            @param parameters
                A list of parameters that may belong to this event,
                may be null if there are no parameters.
            */
            virtual void eventOccurred(const String& eventName, const NameValuePairList* parameters = nullptr) = 0;
        };

        /** Retrieve a pointer to the current shared render system listener.
        */
        static Listener* getSharedListener();
        
    protected:

        static Listener* msSharedEventListener;

    };

    /** @} */
    /** @} */
}

#include "OgreHeaderSuffix.h"

#endif  // #ifndef __RenderSystem_H_