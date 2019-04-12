############################################################
# Paging optional component
############################################################

if (OGRE_STATIC)


endif ()

# define header and source files for the library

file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

if (ANDROID OR EMSCRIPTEN OR APPLE_IOS OR WINDOWS_STORE OR WINDOWS_PHONE)

elseif (WIN32)


elseif (APPLE)
    set(RESOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/misc/ogrelogo.png")
    source_group(Resources FILES ${RESOURCE_FILES})
    set(DEPENDENCIES ${DEPENDENCIES} "-framework Cocoa")
elseif (UNIX)

endif ()

# setup target
add_library(OgreBites ${OGRE_COMP_LIBTYPE} ${HEADER_FILES} ${SOURCES})
set_target_properties(OgreBites PROPERTIES VERSION ${OGRE_SOVERSION} SOVERSION ${OGRE_SOVERSION})
target_link_libraries(OgreBites PUBLIC OgreMain)
target_include_directories(OgreBites PUBLIC 
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
  $<INSTALL_INTERFACE:include/OGRE/Bites>)