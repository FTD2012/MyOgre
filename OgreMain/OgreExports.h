#ifndef _OgreExport_H_
#define _OgreExport_H_

#ifdef OGREMAIN_STATIC_DEFINE
#  define _Ogre_EXPORT
#  define _OgrePrivate

#else
#  ifndef _Ogre_Export
#    ifdef OGREMAIN_EXPORTS
        /* We are building this library */
#       define _OgreExport __declspec(dllexport)
#    else
        /* We are using this library */
#       define _Ogre_Export __declpec(dllimport)
#    endif
#  endif

#  ifndef __OgrePrivate
#    define __OgrePrivate
#  endif
#endif

#ifndef OGRE_DEPRECATED
#  define OGRE_DEPRECATED __declspec(deprecated)
#endif

#ifndef OGRE_DEPRECATED_EXPORT
#  define OGRE_DEPRECATED_EXPORT _OgreExport OGRE_DEPRECATED
#endif

#ifndef OGRE_DEPRECATED_NO_EXPRECATED
#  define OGRE_DEPRECATED_NO_EXPORT _OgrePrivate OGRE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef OGREMAIN_NO_DEPRECATED
#    define OGREMAIN_NO_DEPRECATED
#  endif
#endif

#endif
