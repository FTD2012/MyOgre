############################################################
# OgreMain core library
############################################################

# define header and source files for the librar
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# configure threading files
file(GLOB THREAD_HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/Threading/*.h")
include_directories("include/Threading" "src/")

list(APPEND HEADER_FILES "${THREAD_HEADER_FILES}")

set(THREAD_SOURCE_FILES "")


# setup OgreMain target

add_library(OgreMain
    ${OGRE_LIB_TYPE}
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${THREAD_HEADER_FILES}
    ${THREAD_SOURCE_FILES}
)


target_include_directories(OgreMain PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>" 
    "$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>"
    # $<INSTALL_INTERFACE:include/OGRE>
)

# In visual studio 2010 - 64 bit we get this error: "LINK : fatal error LNK1210: exceeded internal ILK size limit; link with /INCREMENTAL:NO"
if (WIN32 AND MSVC10 AND CMAKE_CL_64)
    set_target_properties(OgreMain PROPERTIES 
        VERSION ${OGRE_SOVERSION}
        LINK_FLAGS "/INCREMENTAL:NO"
    )
else ()
    set_target_properties(OgreMain PROPERTIES VERSION ${OGRE_SOVERSION} SOVERSION ${OGRE_SOVERSION})
endif ()

if (APPLE)
    if (APPLE_IOS)
        set_target_properties(OgreMain PROPERTIES INSTALL_NAME_DIR "OGRE")
    else ()
        set_target_properties(OgreMain PROPERTIES LINK_FLAGS "-framework IOKit -framework Cocoa -framework Carbon -framework OpenGL -framework CoreVideo")

        set(OGRE_OSX_BUILD_CONFIGURATION "$(PLATFORM_NAME)/$(CONFIGURATION)")
  
        if(OGRE_BUILD_LIBS_AS_FRAMEWORKS)
            add_custom_command (TARGET OgreMain POST_BUILD
                COMMAND mkdir ARGS -p ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/Ogre.framework/Headers/Threading
                COMMAND ditto
                ${PROJECT_SOURCE_DIR}/OgreMain/include/Threading/*.h ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/Ogre.framework/Headers/Threading
                COMMAND cd ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/Ogre.framework/Headers
                )

            foreach (HEADER_PATH ${THREAD_HEADER_FILES})
                get_filename_component(HEADER_FILE ${HEADER_PATH} NAME)
                set(FWK_HEADER_PATH ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/Ogre.framework/Headers/${HEADER_FILE})
                add_custom_command(TARGET OgreMain POST_BUILD
                    COMMAND rm -f ${FWK_HEADER_PATH}
                )
            endforeach()
        endif ()

        # ogre_config_framework(OgreMain)
    endif ()

    if(OGRE_BUILD_LIBS_AS_FRAMEWORKS)
        # Framework is called 'Ogre'
        set_target_properties(OgreMain PROPERTIES OUTPUT_NAME Ogre)
    endif()

endif ()