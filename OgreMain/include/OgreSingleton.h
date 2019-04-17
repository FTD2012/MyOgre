#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "OgrePrerequisites.h"
#include "OgreException.h"

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#   pragma warning (push)
#   pragma warning (disable : 4661)
#endif

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */
   
    /** Template class for creating single-instance global classed.
    @note CRTP (curiously recurring template pattern)
    @reference https://stackoverflow.com/questions/4173254/what-is-the-curiously-recurring-template-pattern-crtp
    */
    template <typename T>
    class Singleton
    {
    private:
        /** @brief Explicit private copy constructor. This is forbidden operation. */
        Singleton(const Singleton<T> &);

        /** @brief Private operator= . This is a forbidden operation. */
        Singleton& operator=(const Singleton<T> &);

    protected:
        static T* mSingleton;

    public:
        Singleton()
        {
            OgreAssert(!mSingleton, "There can be only one singleton");
            mSingleton = static_cast<T*>(this); /// @note static_cast 编译期会判断 `this` 是否可以转换铳 `T*`
        }

        ~Singleton()
        {
            assert(mSingleton);
            mSingleton = nullptr;
        }

        static T& getSingleton()
        {
            assert(mSingleton);
            return *mSingleton;
        }

        static T* getSingletonPtr()
        {
            assert(mSingleton);
            return mSingleton;
        }
    };
    /** @} */
    /** @} */

} // namespace Ogre

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#   pragma warning (pop)
#endif


#endif // #ifndef _SINGLETON_H_