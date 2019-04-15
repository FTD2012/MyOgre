#include "OgreStableHeaders.h"
#include "OgreRenderTarget.h"

namespace Ogre
{
    unsigned int RenderTarget::getWidth(void) const
    {
        return mWidth;
    }

    unsigned int RenderTarget::getHeight(void) const
    {
        return mHeight;
    }

} // namespace Ogre
