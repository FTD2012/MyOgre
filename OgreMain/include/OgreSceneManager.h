#ifndef __SceneManager_H_
#define __SceneManager_H_

#include "OgrePrerequisites.h"

#include "OgreCommon.h"

#include "OgreHeaderPrefix.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup Scene
    *  @{
    */

    class _OgreExport SceneManager : public SceneMgtAlloc
    {
    public:

    protected:

        /// Instance Name
        String mName;

        /// The rendering system to send the scene to.
        RenderSystem* mDestRenderSystem;
    protected:

        struct _OgreExport ShadowRenderer
        {
            ShadowRenderer(SceneManager* owner);
            ~ShadowRenderer();

            RenderSystem* mDestRenderSystem;
        } mShadowRenderer;

    public:

    protected:

    public:
        SceneManager(const String& name);

        virtual ~SceneManager();

        /** Notifies the scene manager of its destination render system
        @remarks
            Called automatically by RenderSystem::addSceneManager
            this method simply notifies the manager of the render
            system to which its output must be directed.
        @param sys 
            Pointer to the RenderSystem subclass to be used as a render target.
        */
        void _setDestinationRenderSystem(RenderSystem* sys);
    };

    /** @} */
    /** @} */
}  // namespace Ogre

#include "OgreHeaderSuffix.h"

#endif  // #ifndef __SceneManager_H_