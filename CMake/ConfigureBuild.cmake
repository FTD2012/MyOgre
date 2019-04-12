#######################################################################
# This file takes care of configuring Ogre to build with the settings
# given in CMake. It creates the necessary config.h file and will
# also prepare package files for pkg-config and CMake.
#######################################################################

# ensure debug mode
string(TOLOWER "${CMAKE_BUILD_TYPE}" BUILD_TYPE_LOWER)
if (${CAMKE_BUILD_TYPE} STREQUAL "debug")
    set(OGRE_DEBUG_MODE 1)
endif()


if (APPLE_IOS)
    set(OGRE_SET_BUILDPLATFORM_APPLE_IOS 1)
    set(OGRE_STATIC TRUE)
    set(OGRE_STATIC_LIB TRUE)
    set(OGRE_CONFIG_ENABLE_PVRTC TRUE)
endif ()

# should we build static libs?
if (OGRE_STATIC)
    set(OGRE_LIB_TYPE STATIC)
else ()
    set(OGRE_LIB_TYPE SHARED)
endif ()