#ifndef __FrameListener_H_
#define __FrameListener_H_

#include "OgrePrerequisites.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */
    struct FrameEvent
    {
        Real timeSinceLastEvent;
        Real timeSinceLastFrame;
    };

    class _OgreExport FrameListener
    {
    public:
        /** Called when a frame is about to begin rendering.
        @remarks
            This event happens before any targets have begun upating.
        @return
            True to go ahead, false to abort rendering and drop
            out of the rendering loop.
        */
        virtual bool frameStarted(const FrameEvent& event)
        {
            (void)event;
            return true;
        }

        /** Called after all the render targets have had their rendering commands
            issued, but before render windows have been asked to flip their
            buffers over.
        @remarks
            The usefulness of this event comes from the fact that rendering 
            commands are queued for the GPU to process. These can take a little
            while to finish, and so while that is happening the CPU can be doing
            useful things. Once the request to 'flip buffers' happens, the thread
            requesting it will block until the GPU is ready, which can waste CPU
            cycles. Therefore, it is often a good idea to use this callback to 
            perform per-frame processing. Of course because the frame's rendering
            commands have already been issued, any changes you make will only
            take effect from the next frame, but in most cases that's not noticeable.
        @return
            True to continue rendering, false to drop out of the rendering loop.
        */
        virtual bool frameRenderingQueued(const FrameEvent& event)
        {
            (void)event;
            return true;
        }

        /** Called just after a frame has been rendered.
        @remarks
            This event happens after all render targets have been fully updated
            and the buffers switched.
        @return
            True to continue with the next frame, false to drop out of the rendering loop.
        */
        virtual bool frameEnded(const FrameEvent& event)
        {
            (void)event;
            return true;
        }

        virtual ~FrameListener()
        {

        }
    };
    /** @} */
    /** @} */
}


#endif  // #ifndef __FrameListener_H_