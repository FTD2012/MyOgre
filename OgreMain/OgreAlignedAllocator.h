#ifndef __AlignedAllocator_H_
#define __AlignedAllocator_H_

#include <cstdlib>
#include "OgrePlatform.h"

namespace Ogre {
    /** \addtogroup Core
     *  @{
     */
    /** \addtogroup General
     *  @{
     */

    /** Class to provide aligned memory allocate functionality.
    @remarks
        All SIMD processing are friendly with aligned memory. and some SIMD routines
        are designed for working with aligned memory only. If the data are intended yo
        use SIMD processing, it's need to be aligned for better performance boost.
        In additional, most time cache boundary aligned data also lead to better
        performance even if didn't used SIMD processing. So this class providess a couple
        of functions for allocate aligned memory.
    @par
        Anyways, in general, you don't need to use this class directly, Ogre internally
        will take care with most SIMD and cache friendly optimisation if possible.
    @par
        This isn't a "one-step" optimsiation, there are a lot of underlying work to
        achieve performance boost. If you don't know what are you doing or what there
        are going, just ignore this class.
    @note
        This class intended to use by advanced user only.
    */
    class _OgreExport AlignedMemory {

	public:

        /** Allocate memory with given alignment.
        @param size
            The size of memory need to allocate.
        @param alignment
            The alignment of result pointer, must be power of two
            and in range [1, 128]
        @return
            The allocated memory pointer.
        @par
            onfailure, exception will be throw.
        */
        static DECL_MALLOC void* allocate(size_t size, size_t alignment);

        /** Allocate memory with default platform dependent alignment.
        @remarks
            The default alignment depend on target machine, this function
            guarantee aligned memory according with SIMD processing and 
            cache boundary friendly.
        @param size
            The size of memory need to allocate.
        @return
            The allocated memory pointer.
        @par
            on failure, exception will be throw.
        */
        static DECL_MALLOC void* allocate(size_t size);

        /** Deallocate memory that allocated by this class.
        @param p
            Pointer to the memory allocated by this class or <b>NULL</b> pointer.
        @par
            on <b>NULL</b> pointer, nothing happen.
        */
        static void deallocate(void* p);
    };

    /// STL compatible wrapper for @ref AlignedMemory.
    template<typename T, size_t Alignment>
    struct AlignedAllocator : public std::allocator<T> {
        AlignedAllocator() : std::allocator<T>() {}

        template<class U>
        AlignedAllocator(const AlignedAllocator<U, Alignment>& other) {};

        template<class Other>
        struct rebind {
            using other = AlignedAllocator<Other, Alignment>;
        };

        T* allocate(size_t n) {
            return static_cast<T*>(AlignedMemory::allocate(n * sizeof(T), Alignment));
        }

        T* allocate(size_t n, const void* hint) { // deprecated in C++17
            return static_cast<T*>(AlignedMemory::allocate(n * sizeof(T), Alignment));
        }

        void deallocate(T* p, size_t /*n*/) {
            AlignedMemory::deallocate(p);
        }

    };

    /** @} */
    /** @} */
}



#endif  // #ifndef __AlignedAllocator_H_