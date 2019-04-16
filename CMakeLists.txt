######################################################################
# OGRE BUILD SYSTEM
# Welcome to the CMake build system for OGRE.
# This is the main file where we prepare the general build environment
# and provide build configuration options.
######################################################################

cmake_minimum_required(VERSION 3.3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)



# Use relative paths
# This seems mostly to reduce path size for command-line limits on windows
if (WIN32)
    set(CMAKE_USE_RELATIVE_PATHS true)
    set(CMAKE_SUPPRESS_REGENERATION true)
endif()

if (APPLE AND NOT ANDROID)
    set(CMAKE_SIZEOF_VOID_P 4)
    set(CMAKE_XCODE_ATTRIBUTE_GCC_VERSION "com.apple.compilers.llvm.clang.1_0")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")

endif ()

project(OGRE VERSION 1.12.0)

# extra version info
set(OGRE_VERSION_SUFFIX "")
set(OGRE_VERSION_NAME "Rhagorthua")

# legacy defines
set(OGRE_SOVERSION ${OGRE_VERSION})
set(OGRE_VERSION_DASH_SEPARATED "${OGRE_VERSION_MAJOR}-${OGRE_VERSION_MINOR}-${OGRE_VERSION_PATCH}")

# include necessary submodules
set(CMAKE_MODULE_PATH 
    "${PROJECT_SOURCE_DIR}/CMake"
    "${PROJECT_SOURCE_DIR}/CMake/Utils"
    "${PROJECT_SOURCE_DIR}/CMake/Packages"
)

include(CMakeDependentOption)
include(MacroLogFeature)
include(OgreConfigTargets)
set(OGRE_WORK_DIR "${PROJECT_BINARY_DIR}")



#####################################################################
# Set up the basic build environment
#####################################################################

# Add OgreMain include path
if (APPLE_IOS)
    set(OGRE_STATIC TRUE)
endif ()

# definitions for samples
set(OGRE_LIBRARIES OgreMain)

# Find dependencies
include(Dependencies)



######################################################################
# Provide user options to customise the build process
######################################################################
cmake_dependent_option(OGRE_BUILD_WINDOW_ALL_PLATFORM "Build Window with GLFW" TRUE "GLFW_FOUND" FALSE)

cmake_dependent_option(OGRE_BUILD_RENDERSYSTEM_GL "Build OpenGL RenderSystem" TRUE "OPENGL_FOUND;NOT APPLE_IOS;NOT WINDOWS_STORE;NOT WINDOWS_PHONE" FALSE)

cmake_dependent_option(OGRE_BUILD_COMPONENT_OVERLAY "Build Overlay component" TRUE "FREETYPE_FOUND" FALSE)
cmake_dependent_option(OGRE_BUILD_COMPONENT_BITES "Build OgreBites component" TRUE "OGRE_BUILD_COMPONENT_OVERLAY" FALSE)

cmake_dependent_option(OGRE_BUILD_SAMPLES "Build Ogre demos" TRUE "OGRE_BUILD_COMPONENT_OVERLAY;OGRE_BUILD_COMPONENT_BITES" FALSE)
message("OGRE_BUILD_WINDOW_ALL_PLATFORM = " ${OGRE_BUILD_WINDOW_ALL_PLATFORM})
###################################################################
# configure global build settings based on selected build options
###################################################################


###################################################################
# disable way too common compiler warnings on project level
###################################################################

##################################################################
# Now setup targets
##################################################################

# Setup testlib
####
# @waring
# Don't use this include, use target_include_directories instead in libs
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/testLib/include)
####
add_subdirectory(testLib)

# Setup external
add_subdirectory(external)

# Setup RenderSystems
add_subdirectory(RenderSystems)

# Setup OgreMain project
add_subdirectory(OgreMain)

# Setup Components
add_subdirectory(Components)


# Setup samples
add_subdirectory(Samples)