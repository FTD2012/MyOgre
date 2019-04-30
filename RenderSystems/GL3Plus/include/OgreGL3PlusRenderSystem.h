#ifndef __GL3PlusRenderSystem_H__
#define __GL3PlusRenderSystem_H__

#include "OgreGL3PlusPrerequisites.h"

#include "OgreGLRenderSystemCommon.h"

namespace Ogre {
    /** \addtogroup RenderSystems RenderSystems
    *  @{
    */
    /** \defgroup GL3Plus GL3Plus
    * Implementation of GL 3 as a rendering system.
    *  @{
    */
    class _OgreGL3PlusExport GL3PlusRenderSystem : public GLRenderSystemCommon
    {
    private:

    public:
        GL3PlusRenderSystem();
        ~GL3PlusRenderSystem();

        // ----------------------------------
        // Overridden RenderSystem functions
        // ----------------------------------

        const String& getName() const;

    };

    /** @} */
    /** @} */
}


#endif   // #ifndef __GL3PlusRenderSystem_H__