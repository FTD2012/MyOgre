#ifndef __MemoryAllocatorConfig_H_
#define __MemoryAllocatorConfig_H_

#include "OgreAlignedAllocator.h"

namespace Ogre {

    /** \addtogroup Core
    *  @{
    */
    /** \addtogroup General
    *  @{
    */

   enum MemoryCategory
   {
       /// General purpose
       MEMCATEGORY_GENERAL = 0,
       /// Geometry held in main memory
       MEMCATEGORY_GEOMETRY = 1,
       /// Animation data like tracks, bone matrices
       MEMCATEGORY_ANIMATION = 2,
       /// Nodes, control data
       MEMCATEGORY_SCENE_CONTROL = 3,
       /// Scene object instances
       MEMCATEGORY_SCENE_OBJECTS = 4,
       /// Other resources
       MEMCATEGORY_RESOURCE = 5,
       /// Scripting
       MEMCATEGORY_SCRIPTING = 6,
       /// Rendersystem structures
       MEMCATEGORY_RENDERSYS = 7,

       /// sentinel value, do not use
       MEMCATEGORY_COUNT = 8
   };

    /** @} */
    /** @} */
}

namespace Ogre {
    class AllocPolicy {};
    // this is a template, mainly so swig does not pick it up
    template<int Category = MEMCATEGORY_GENERAL> class AllocatedObject {};

    // Useful shorcuts
    typedef AllocPolicy RenderSysAllocPolicy;

    // Now defines all the base classed for each allocation
    typedef AllocatedObject<> GeneralAllocatedObject;
    typedef AllocatedObject<> RenderSysAllocatedObject;

    // Pef-class allocators defined here
    // NOTE: small, non-virtural classes should not subeclass an allocator
    // the virtual function table could double their size and make them less efficient
    // use primitive or STL allocators / deallocators for those

    typedef GeneralAllocatedObject      LogAlloc;

    typedef RenderSysAllocatedObject    RenderSysAlloc;
    typedef GeneralAllocatedObject      RootAlloc;

}



/** \addtogroup Core
*  @{
*/
/** \addtogroup General
*  @{
*/

// new / delete for classes deriving from AllocatedObject (alignment determined by per-class policy)
#   define OGRE_NEW new
#   define OGRE_DELETE delete

/** @} */
/** @} */


#endif  // #ifndef __MemoryAllocattorConfig_H_