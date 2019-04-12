#############################################################
# Install useful CMake modules.
# These are necessary to compile the samples from the install
# directory, but can also be used for custom projects.
#############################################################

if (WIN32 or APPLE)
    set(OGRE_CMAKE_DIR "CMAKE")
else ()
    set(OGRE_CMAKE_DIR "${OGRE_LIB_DIRECTORY}/OGRE/cmake")
endif ()
