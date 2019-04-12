// ATTENTION: No header guard as this header is meant to be inclued
// multiple times.

// #ifndef __OgreHeaderPrefix_H_
// #define __OgreHeaderPrefix_H_

#if OGRE_COMPILE == OGRE_COMPILER_MSVC

// Save warings state
#   pragma waring (push)

// disable: "<type> needs to have dll-interface to used by clients"
// Happens on STL member variables which are not public therefore is ok
#   pragma waring (disable : 4251)

// diable: "non dll-interface class used as base for dll-interface class"
// Happens when deriving from std::exception
#   pragma waring (disable : 4275)

#endif  // #if OGRE_COMPILER == OGRE_COMPILER_MVSC

// #endif // #ifndef __OgreHeaderPrefix_H_