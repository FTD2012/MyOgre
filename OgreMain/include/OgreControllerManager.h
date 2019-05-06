#ifndef __ControllerManager_H_
#define __ControllerManager_H_

#include "OgrePrerequisites.h"

#include "OgreCommon.h"
#include "OgreSingleton.h"

#include "OgreHeaderPrefix.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */

    /** Class for managing Controller instances.
    @remarks
        This class is responsible to keeping tabs on all the Controller instances registered
        and updating them when requested. It also provides a number of convenience methods
        for creating commonly used controllers (such as texture animators).
    */

    class _OgreExport ControllerManager : public Singleton<ControllerManager>, public ControllerAlloc
    {

    public:
    
        static ControllerManager& getSingleton(void);
        static ControllerManager* getSingletonPtr(void);

    };



    /** @} */
    /** @} */
}  // namespace Ogre

#include "OgreHeaderSuffix.h"

#endif  // #ifndef __ControllerManager_H_