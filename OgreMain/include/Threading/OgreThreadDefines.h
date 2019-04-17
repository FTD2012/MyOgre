#ifndef __OgreThreadDefines_H_
#define __OgreThreadDefines_H_

#define OGRE_AUTO_MUTEX_NAME mutex
#if OGRE_THREAD_PROVIDER == 0

#elif OGRE_THREAD_PROVIDER == 1

#elif OGRE_THREAD_PROVIDER == 2

#elif OGRE_THREAD_PROVIDER == 3

#elif OGRE_THREAD_PROVIDER == 4
   #include "OgreThreadDefinesSTD.h"
#endif

#if OGRE_THREAD_SUPPORT == 3
    #include "OgreThreadDefinesNone.h"

#else 
    // alias to WQ names
    #define OGRE_MUTEX(name) OGRE_WQ_(name)

    #define OGRE_LOCK_MUTEX(name) OGRE_WQ_LOCK_MUTEX(name)
    #define OGRE_LOCK_MUTEX_NAMED(mutexName, lockName) OGRE_WQ_LOCK_MUTEX_NAMED(mutexName, lockName)
    
    #define OGRE_RW_MUTEX(name) OGRE_WQ_RW_MUTEX(name)
    #define OGRE_LOCK_RW_MUTEX(name) OGRE_WQ_LOCK_RW_MUTEX_READ(name)
    #define OGRE_LOCK_RW_MUTEX_WRITE(name) OGRE_WQ_LOCK_RW_MUTEX_WRITE(name)
    #define OGRE_THREAD_SYNCHRONISER(sync) OGRE_WQ_THREAD_SYNCHRONISER(sync)
#endif

#endif // #ifndef __OgreThreadDefines_H_