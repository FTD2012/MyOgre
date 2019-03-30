#ifndef _Bitwise_H_
#define _Bitwise_H_

#include "OgrePrerequisites.h"

#ifndef __has_builtin
    // Compatibility with non-clang cimpilers
#   define __has_builtin(x) 0
#endif

namespace Ogre {
    /** \addtogroup Core
     *  @{
     */
    /** \addtogroup General
     *  @{
     */

    /** Class for manipulating bit patterns.
     */
    class Bitwise {

    public:

        /** Determins whether the number is power-of-two or not.
        @note
            0 and 1 are tread as power of two.
        */
        template<typename T>
        static OGRE_FORCE_INLINE bool isPO2(T n) {
            return (n & (n-1)) == 0;
        }
    };

    /** @} */
    /** @} */
}



#endif  // #ifndef _Bitwise_H_