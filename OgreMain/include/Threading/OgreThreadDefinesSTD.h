#ifndef __OgreThreadDefinesSTD_H_
#define __OgreThreadDefinesSTD_H_

#if OGRE_THREAD_SUPPORT != 3
#define OGRE_LOCK_AUTO_MUTEX std::unique_lock<std::recursive_mutex> ogreAutoMutexLock(OGRE_AUTO_MUTEX_NAME)
#endif




#endif  // __OgreThreadDefinesSTD_H_
