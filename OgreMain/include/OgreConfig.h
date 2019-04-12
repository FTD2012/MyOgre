#ifndef __Config_H_
#define __Config_H_

#include "OgreBuildSettings.h"

/** If set to >0, OGRE will always 'think' that the graphics card only has the
    number of texture units specified. Very useful for testing multipass fallback.
*/
#define OGRE_PRETEND_TEXTURE_UNITS 0

/** Define number of texture coordinate sets allowed per vertex.
*/
#define OGRE_MAX_TEXTURE_COORDS_SETS 8

/** Define max number of texture layers allowed per pass on any card
*/
#define OGRE_MAX_TEXTURE_LAYERS 16

/** Define max number of lights allowed per pass.
*/
#define OGRE_MAX_SIMULANEOUS_LIGHTS 8

/** Define max number of blending weights allowed per vertex.
*/
#define OGRE_MAX_BLEND_WEIGHTS 4

/** Define max number of the multiple render targets (MRTs) to render to at once.
*/
#define OGRE_MAX_MULITPLE_RENDER_TARGETS 8

#endif	// #ifndef __Config_H_