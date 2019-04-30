#include "OgreStableHeaders.h"
#include "OgreSceneManagerEnumerator.h"

namespace Ogre {
    //-----------------------------------------------------------------------
    template<> SceneManagerEnumerator* Singleton<SceneManagerEnumerator>::mSingleton = nullptr;
    SceneManagerEnumerator* SceneManagerEnumerator::getSingletonPtr(void)
    {
        return mSingleton;
    }
    SceneManagerEnumerator& SceneManagerEnumerator::getSingleton(void)
    {  
        assert( mSingleton );  return ( *mSingleton );  
    }

    //-----------------------------------------------------------------------
    SceneManagerEnumerator::SceneManagerEnumerator()
    : mCurrentRenderSystem(nullptr)
    {

    }

    //-----------------------------------------------------------------------
    SceneManagerEnumerator::~SceneManagerEnumerator()
    {

    }

    //-----------------------------------------------------------------------
    void SceneManagerEnumerator::setRenderSystem(RenderSystem* rs)
    {
        mCurrentRenderSystem = rs;
        for (Instances::iterator i = mInstances.begin(); i != mInstances.end(); ++i)
        {
            i->second->_setDestinationRenderSystem(rs);
        }
    }


}