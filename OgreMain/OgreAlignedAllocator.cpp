#include "OgreStableHeaders.h" /// TODO: ljm >>> implemation
#include "OgrePlatformInformation.h" /// TODO: ljm >>> implemation


/** 
 * |__2__|3|_________5__________|__6__|
 * ^       ^
 * 1       4
 * 
 * 1 -> Pointer to start of the block allocated by new.
 * 2 -> Gap used to get 4 aligned on given glinment.
 * 3 -> Byte offset between 1 and 4.
 * 4 -> Point to the start of data block.
 * 5 -> Data block.
 * 6 -> Wated memory at rear of data block.
 */
namespace Ogre {

	//---------------------------------------------------------------------
    void* AlignedMemory::allocate(size_t size, size_t alignment)
    {
        assert(0 < alignment && alignment <= 128 && Bitwise::isPO2(alignment));

        unsigned char* p = new unsigned char[size + alignment];
        size_t offset = alignment - (sizeof(p) & (alignment-1));

        unsigned char* result = p + offset;

        return result;
    }

	//---------------------------------------------------------------------
    void* AlignedMemory::allocate(size_t size) 
    {
        return allocate(size, OGRE_SIMD_ALIGNMENT);
    }

	//---------------------------------------------------------------------
    void AlignedMemory::deallocate(void* p) 
    {
        if (p)
        {
            unsigned char* mem = (unsigned char*)p;
            mem = mem - mem[-1];
            delete [] mem;
        }
    }
    
}