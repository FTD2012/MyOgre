#ifndef __SceneManagerEnumerator_H_
#define __SceneManagerEnumerator_H_

#include "OgrePrerequisites.h"

#include "OgreSceneManager.h"
#include "OgreSingleton.h"
#include "OgreHeaderPrefix.h"

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup Scene
    *  @{
    */
    class _OgreExport SceneManagerEnumerator : public Singleton<SceneManagerEnumerator>, public SceneMgtAlloc
    {
    public:
        /// Scene manager instances, indexed by instance name.
        typedef std::map<String, SceneManager*> Instances;

    private:
        Instances mInstances;
        RenderSystem* mCurrentRenderSystem;

    public:
        SceneManagerEnumerator();
        ~SceneManagerEnumerator();


        /** Notifies all SceneManagers of the destination rendering system.
        */
        void setRenderSystem(RenderSystem* rs);

        /// @copydoc Singleton::getSingleton()
        static SceneManagerEnumerator& getSingleton(void);
        /// @copydoc Singleton::getSingleton()
        static SceneManagerEnumerator* getSingletonPtr(void);
    };

    /** @} */
    /** @} */
}

#include "OgreHeaderSuffix.h"

#endif  // ifndef __SceneManagerEnumerator_H_