#include "OgreStableHeaders.h"
#include "OgreControllerManager.h"

namespace Ogre {
    //-----------------------------------------------------------------------
    template<> ControllerManager* Singleton<ControllerManager>::mSingleton = nullptr;
    ControllerManager* ControllerManager::getSingletonPtr()
    {
        return mSingleton;
    }
    ControllerManager& ControllerManager::getSingleton()
    {
        assert(mSingleton);  return *mSingleton;  
    }
}