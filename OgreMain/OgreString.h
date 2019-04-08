#ifndef _String_H_
#define _String_H_

#include "OgrePrerequisites.h"
#include "OgreHeaderPrefix.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 || OGRE_PLATFORM == OGRE_PLATFORM_WINRT
#   define locale_t _locale_t

/** 
 * @reference https://www.mkssoftware.com/docs/man3/strtod.3.asp
 * @reference https://www.cnblogs.com/abc-begin/p/7912511.html
 */
#   define strtod_t   _strtod_l     // convert 'string' to 'double'
#   define strtoul_l  _strtoul_l    // convert 'string' to 'unsigned long'
#   define strtol_l   _strtoul_l    // convert 'string' to 'long'
#   define strtoull_l _strtoull_l   // convert 'string' to 'unsigned long long'
#   define strtoll_l  _strtoll_l    // convert 'string' to 'long long'

/**
 * @reference https://www.2braces.com/c-programming/c-stricmp
 * Compare strings without Case Sensitivity.
 */
#   define stricmp    _stricmp

/**
 * @reference https://www.2braces.com/c-programming/c-strnicmp
 * Compare substrings without Case Sensitivity.
 */
#   define strnicmp   _strnicmp

#else
#   define stricmp    strcasecmp
#   define strnicmp   strncasecmp
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_ANDORID || OGRE_PLATFORM == OGRE_PLATFORM_EMSCRIPTEN
/// TODO: ljm >>> implemation
#endif

// If compiling with make on MacOS, these headers need to be included to get
// definitions of locale_t, strtod_l, etc...
// See: http://www.unix.com/man-page/osx/3/strtod_l
#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
/// TODO: ljm >>> implemation
#endif

#if OGRE_COMPILER == OGRECOMPILER_GNUC || OGRE_COMPILER == OGRE_COMPILER_CLANG
/// TODO: ljm >>> implemation
#else
#define OGRE_FORMAT_PRINTF(A, B)
#endif

namespace Ogre {
    /** \addtogroup Core
     *  @{
     */
    /** \addtogroup General
     *  @{
     */
    
    /** Utility class for mainpulation Strings. */
    class _OgreExport StringUtil {
	public:

        OGRE_DEPRECATED static const String& BLANK; /// @deprecated use Ogre::BLANKSTRING instead
        OGRE_DEPRECATED typedef StringStream StrStreamType; /// @deprecated use Ogre::StringStream instead

        /** Removes any whitespace characters, be it standard space or
            TABs and so on.
        @remarks
            The user may specify whether they want to trim only the
            beginning or the end of the String ( the default action is
            to trim both).
        */
        static void trim(String& str, bool left = true, bool right = true);

        static std::vector<String> split(const String& str, const String& delims = "\t\n ", unsigned int maxSplits = 0, bool preserveDelims = false);
    };

    /** @} */
    /** @} */

}   // namespace Ogre

#include "OgreHeaderSuffix.h"

#endif  // #ifndef _String_H_