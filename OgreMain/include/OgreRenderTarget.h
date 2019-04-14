#ifndef __RenderTarget_H_
#define __RenderTarget_H_

#include "OgrePrerequisites.h"

// #include "OgrePixelFormat.h" /// TODO: ljm >>> implemation
#include "OgreHeaderPrefix.h"

/* Define the number of priority groups for the render system's render targets. */
#ifndef OGRE_NUM_RENDERTARGET_GROUPS
#   define OGRE_NUM_RENDERTARGET_GROUPS 10
#   define OGRE_DEFAULT_RT_GROUP 4
#   define OGRE_REND_TO_TEX_RT_GROUP 2
#endif

namespace Ogre {

    /** \addtogroup Core
    * @{
    */
    /** \addtogroups RenderSystem
    * @{
    */
    /** A 'canvas' which can receive the results of a rendering operation.
    @remarks
        The a abstract class defines a common root to all targets of rendering operations.
        A render target could be a window on a screen, or another offscreen surface like a
        texture or bump map etc.
    @note bump map
        凹凸贴图
    @reference https://www.cnblogs.com/decode1234/p/6862436.html
    */

    class _OgreExport RenderTarget : public RenderSysAlloc
    {
    public:

    protected:
        /// The name of this target
        String mName;
        /// The priority of the render target.
        uchar mPriority;

        uint32 mWidth;
        uint32 mHeight;
        uint32 mColourDepth;
        uint16 mDepthBufferPoolId;
        


   };


    /** @} */
    /** @} */

}   // namespace Ogre






#include "OgreHeaderSuffix.h"

/** @} */
/** @} */

#endif  // #ifndef __RenderTarget_H_