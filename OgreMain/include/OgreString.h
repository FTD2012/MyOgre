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

        /** Returns a StringVector that contains all the substrings delimited
            by characters in the passed <code>delims</code> argument.
        @param str
        @param delims
            A list of the delimiter characters to split by
        @param maxSplits
            The maxium number of splits to perform(0 for unlimited splits). If this
            paramters is > 0, the splitting process will stop after this many splits,
            left to right.
        @param preserveDelims
            Flag to determine if delimiters should be saved as substrings.
        */
        static std::vector<String> split(const String& str, const String& delims = "\t\n ", unsigned int maxSplits = 0, bool preserveDelims = false);

        ///TODO: ljm >>> tokenise

        /** Lower-cases all the characters in the string.
         */
        static void toLowerCase(String& str);

        /** Upper-cases all the characters in the string.
        */
        static void toUpperCase(String& str);

        /** Upper-cases the first letter of each word.
        */
        static void toTitleCase(String& str);

        /** Returns whether the string begins with the pattern passed in.
        @param str
        @param pattern
            The pattern to compare with.
        @param lowerCase
         */
        static bool startWith(const String& str, const String& pattern, bool lowerCase);

        /** Returns whether the string ends with the pattern passed in.
        @param str
        @param pattern
            The pattern to compare with
        @param lowerCase
            If true, the end of the string will be lower cased before
            comparsion, pattern should also be in lower case.
        */
        static bool endWith(const String& str, const String& pattern, bool lowerCase = true);

        /** Method for standardising paths - use forward slashes only, end with slash.
        */
        static String standardisePath(const String& str);

        /// TODO: ljm >>> implemation normalizeFilePath
        
        /** Method for spliting a fully qualified filename into the base name and path.
        @remarks
            Path is standardised as in standardisePath.
        */
        static void splitFileName(const String& qualifiedName,
                                  String& outBasename, String& outPath);

        /** Method for spliting a filename into the base name and extension
        */
        static void splitBaseFileName(const String& fullName,
                                      String& outBasename, String& outExtention);

        /// TODO: ljm >>> implemation match

        static String replaceAll(const String& source, const String& replaceWhat, const String& replaceWithWhat);
    };

    /** @} */
    /** @} */

}   // namespace Ogre

#include "OgreHeaderSuffix.h"

#endif  // #ifndef _String_H_