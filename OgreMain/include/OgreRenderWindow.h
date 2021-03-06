#ifndef __RenderWindow_H_
#define __RenderWindow_H_

#include "OgrePrerequisites.h"
#include "OgreRenderTarget.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup RenderSystem
    *  @{
    */

    class _OgreExport RenderWindow : public RenderTarget
    {
    protected:
        bool mIsFullScreen;
        bool mIsPrimary;

    public:
        RenderWindow();
    };



    /** @} */
    /** @} */
}   // namespace Ogre


#endif  // #ifndef __RenderWindow_H_