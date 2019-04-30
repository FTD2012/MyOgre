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

        /** Shutdown the renderer and cleanup resources.
        */
        virtual void shutdown();

    };

    /** @} */
    /** @} */
}

#include "OgreHeaderSuffix.h"

#endif  // #ifndef __RenderSystem_H_