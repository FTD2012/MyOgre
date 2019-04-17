#ifndef __Exception_H_
#define __Exception_H_

#include "OgrePrerequisites.h"
#include "OgreString.h"
#include <exception>
#include "OgreHeaderPrefix.h"

// Check for OGRE assert mode

// RELEASE_EXCEPTIONS mode
#if OGRE_ASSERT_MODE == 1
#   if OGRE_DEBUG_MODE
#       define OgreAssert( a, b ) assert( (a) && (b) )
#   else
// #       define OgreAssert( a, b ) OGRE_EXCEP_2( Ogre::Exception::ERR_RT_ASSERTION_FAILED, (b) )  /// TODO: ljm >>> implemtation
#   endif

// EXCEPTIONS mode
#elif OGRE_ASSERT_MODE == 2
// #       define OgreAssert( a, b ) OGRE_EXCEP_2( Ogre::Exception::ERR_RT_ASSERTION_FAILED, (b) )  /// TODO: ljm >>> implemtation

// STANDARD mode
#else
/** Checks a condition at runtime and throws exception/ aborts if it fails.
 *
 * The macros OgreAssert (and OgreAssertDbg) evaluate the specified expression.
 * If it is 0, OgreAssert raises an error (see Ogre::RuntimeAssertionException) in Release configuration
 * and aborts in Debug configuration.
 * The macro OgreAssert checks the condition in both Debug and Release configurations
 * while OgreAssertDbg is only retained in the Debug configuration.
 *
 * To always abort instead of throwing an exception or disabling OgreAssert in Release configuration altogether,
 * set OGRE_ASSERT_MODE in CMake accordingly.
 */
#   define OgreAssert( expr, mesg ) assert( (expr) && (mesg) )
#endif

#if OGRE_DEUBG_MODE
#   define OgreAssertDbg( a, b ) OgreAssert( a, b )
#else
#   define OgreAssertDbg( a, b )
#endif

namespace Ogre {
    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */

    /** @} */
    /** @} */
} // Namespace Ogre

#include "OgreHeaderSuffix.h"

#endif // #ifndef __Exception_H_