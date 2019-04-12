# Configure Components build

set(OGRE_COMP_LIB_TYPE ${OGRE_LIB_TYPE})

if (OGRE_BUILD_COMPONENT_BITES)
    message("OGRE_BUILD_COMPONENT_BITESdddd")
    add_subdirectory(Bites)
endif ()