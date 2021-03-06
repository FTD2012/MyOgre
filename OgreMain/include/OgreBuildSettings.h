#ifndef __Custom_Config_H_
#define __Custom_Config_H_

// Define ogre version
#define OGRE_VERSION_MAGOR 1
#define OGRE_VERSION_MINOR 12
#define OGRE_VERSION_PATCH 0
#define OGRE_VERSION_SUFFIX ""
#define OGRE_VERSION_NAME "Rhagorthua"

#define OGRE_STATIC_LIB
#define OGRE_DEBUG_MODE 1

/**  There are three modes for resource lookup.
0 - LEGACY - search in all groups twice - for case sensitive and insensitive lookup.
1 - PEDANTIC(adj.卖弄学问的，迂腐的) - require an explicit resource group. Case sensitive lookup.
2 - STRICT - search in default group if not specified otherwise. Case sensitive lookup.
*/
#define OGRE_RESOURCEMANAGER_STRICT 2

/* #define OGRE_BUILD_RENDERSYSTEM_D3D9 */
/* #define OGRE_BUILD_RENDERSYSTEM_D3D11 */
/* #define OGRE_BUILD_RENDERSYSTEM_GL */
#define OGRE_BUILD_RENDERSYSTEM_GL3PLUS
/* #define OGRE_BUILD_RENDERSYSTEM_GLES2 */
#define OGRE_BUILD_PLUGIN_BSP
#define OGRE_BUILD_PLUGIN_OCTREE
#define OGRE_BUILD_PLUGIN_PCZ
#define OGRE_BUILD_PLUGIN_PFX
/* #define OGRE_BUILD_PLUGIN_CG */
#define OGRE_BUILD_PLUGIN_STBI
/* #define OGRE_BUILD_PLUGIN_FREEIMAGE */
#define OGRE_BUILD_COMPONENT_PAGING
#define OGRE_BUILD_COMPONENT_MESHLODGENERATOR
#define OGRE_BUILD_COMPONENT_TERRAIN
#define OGRE_BUILD_COMPONENT_VOLUME
#define OGRE_BUILD_COMPONENT_PROPERTY
#define OGRE_BUILD_COMPONENT_OVERLAY
#define OGRE_BUILD_COMPONENT_RTSHADERSYSTEM
#define OGRE_BUILD_COMPONENT_HLMS

#define OGRE_CONFIG_LITTLE_ENDIAN
/* #undef OGRE_CONFIG_BIG_ENDIAN */

/** If set to 1, Real is typedef'ed to double. Otherwise, Real is typedef'ed to float.
    Setting this allows you to perform mathematical operations in the CPU (Quaternion, Vector3 etc)
	with more precision, but bear in mind that the GPU still operates in single-precision mode.
*/
#define OGRE_DOUBLE_PRECISION 0

#define OGRE_NODE_INHERIT_TRANSFORM 0

/** There are three modes for handling asserts in OGRE:
0 - STANDARD - Standard asserts in debug build, nothing in release builds.
1 - RELEASE_EXCEPTIONS - Standard asserts in debug builds, exceptions in release build.
2 - EXCEPTIONS - Exceptions in debug builds, exceptions in release builds.
*/
#define OGRE_ASSERT_MODE 1

/** Support for multithreading, there are three options.
0 - No support for threading.
1 - Thread support for background loading, by both loading and constructing resources
    in a background thread. Resource management and SharedPrt handling becomes
	thread-safe, and resources may be completely loaded in the background.
	The places where threading is available are clearly
	marked, you should assume stat is NOT thread safe unless otherwise
	stated in relation to this flag.
2 - Thread support for background resource preparation. This means that resource
	data can streamed into memory in the background, but the final resource
	construction (including RenderSystem dependencies) is still done in the primary
	thread. Has a lower synchronisation primitive overhead the full threading
	while still allowing the major blocking aspects of resource management (I/O)
	to be done in the background.
3 - No synchronisation primitive overhead. WorkQuene is threaded.
*/
#define OGRE_THREAD_SUPPORT 3

/** Provider for threading functionality, there are 4 options.
0 - No support for threading.
1 - Boost libraries provide threading functionality.
2 - Poco libraries provide threading functionality.
3 - TBB library provides threading functionality.
4 - Standard library provides threading functionality. (requires complier support)
*/
#define OGRE_THREAD_PROVIDER 4

#define OGRE_NO_MESHLOD 0

/** Disables use of the internal image codec for loading DDS(Direct Draw Surface - using in DirectX) files. */
#define OGRE_NO_DDS_CODEC 0

/** Disables use of the internal image codec for loading PVRTC files. */
#define OGRE_NO_PVRTC_CODEC 1

/** Disables use of the internal image codec for loading ETC files. */
#define OGRE_NO_ECT_CODEC 0

/** Disables use of the internal image codec for loading ASTC(using in Unity) files. */
#define OGRE_NO_ASTC_CODEC 1

/** Disables use of the ZIP archive support. WARING: Disabling this will make the samples unusable. */
#define OGER_NO_ZIP_ARCHIVE 0

#define OGRE_NO_VIEWPORT_ORIENTATIONMODE 1

#define OGRE_NOT_TBB_SCHEDULER 0

/** If set to 1. profiling code will be included in the application. When you
    are deploying your application you will probably want to set this to 0.
*/
#define OGRE_PROFILING 0

#define OGRE_NO_QUADBUFFER_STEREO 1

#define OGRE_BITES_HAVE_SDL 1

#endif	// #ifndef __Custom_Config_H_
