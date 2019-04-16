# Configure Smaples build

file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp")

# Get the list of configured samples
get_property(OGRE_SAMPLES_LIST GLOBAL PROPERTY "OGRE_SAMPLES_LIST")

# if (APPLE_IOS)
#     set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/src/SampleBrowser.cpp PROPERTIES COMPILE_FLAGS "-x objective-c++")
# endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if (ANDROID)

else ()
    add_executable(SampleBrowser ${HEADER_FILES} ${SOURCE_FILES} ${RESOURCE_FILES})
endif ()

target_link_libraries(SampleBrowser OgreMain OgreBites OgreGLSupport OgreTestLib OgreGLSupport)


# configure SampleBrowser build

ogre_config_common(SampleBrowser)

if (APPLE)
    set_source_files_properties(${CMAKE_CURRENT_SOURCE_DIR}/src/SampleBrowser.cpp PROPERTIES COMPILE_FLAGS "-x objective-c++")

    # On OS X, create .app bundle
    set_property(TARGET SampleBrowser PROPERTY MACOSX_BUNDLE TRUE)
	set_property(TARGET SampleBrowser PROPERTY MACOSX_BUNDLE_ICON_FILE SampleBrowser_OSX.icns)
	set_property(TARGET SampleBrowser PROPERTY MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/Samples/Common/misc/Info.plist)
	set(MACOSX_BUNDLE_GUI_IDENTIFIER "org.ogre3d.\${PRODUCT_NAME:rfc1034identifier}")
    set_target_properties(SampleBrowser PROPERTIES XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")

    if (APPLE_IOS)

    else ()
        set_target_properties(SampleBrowser PROPERTIES
            LINK_FLAGS "-framework IOKit -framework Cocoa -framework Carbon -framework CoreVideo -framework ApplicationServices")

        # Add the path where the Ogre framework was found, if it has been found somewhere
        # if(NOT ${OGRE_FRAMEWORK_PATH} STREQUAL "" AND OGRE_SDK_BUILD)
        #     set_target_properties(SampleBrowser PROPERTIES
        #         COMPILE_FLAGS "-F${OGRE_FRAMEWORK_PATH}"
        #         LINK_FLAGS "-F${OGRE_FRAMEWORK_PATH} -framework IOKit -framework Cocoa -framework Carbon -framework OpenGL -framework CoreVideo"
        #     )
        # endif()

        # # also, symlink frameworks so .app is standalone
	    # # NOTE: $(CONFIGURATION) is not resolvable at CMake run time, it's only 
	    # # valid at build time (hence parenthesis rather than braces)
        # set(OGRE_OSX_BUILD_CONFIGURATION "$(PLATFORM_NAME)/$(CONFIGURATION)")
        # set(OGRE_BUILT_FRAMEWORK "$(PLATFORM_NAME)/$(CONFIGURATION)")
        # set (OGRE_SAMPLE_CONTENTS_PATH ${PROJECT_BINARY_DIR}/bin/$(CONFIGURATION)/SampleBrowser.app/Contents)
        # add_custom_command(TARGET SampleBrowser POST_BUILD
        #       COMMAND mkdir ARGS -p ${OGRE_SAMPLE_CONTENTS_PATH}/Frameworks
        #       COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/lib/${OGRE_BUILT_FRAMEWORK}/Ogre.framework ${OGRE_SAMPLE_CONTENTS_PATH}/Frameworks/
        #       COMMAND ln ARGS -s -f ${Cg_LIBRARY_REL} ${OGRE_SAMPLE_CONTENTS_PATH}/Frameworks/
        # )

        # # now cfg files
        # if(OGRE_SDK_BUILD)
        #     add_custom_command(TARGET SampleBrowser POST_BUILD
        #         COMMAND mkdir ARGS -p ${OGRE_SAMPLE_CONTENTS_PATH}/Resources
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/macosx/plugins.cfg   ${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/macosx/resources.cfg ${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/macosx/samples.cfg   ${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/macosx/quakemap.cfg  ${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_SOURCE_DIR}/Media                    ${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ditto ${PROJECT_SOURCE_DIR}/Samples/Common/misc/SampleBrowser_OSX.icns ${OGRE_SAMPLE_CONTENTS_PATH}/Resources
        #     )
        # else()
        #     add_custom_command(TARGET SampleBrowser POST_BUILD
        #         COMMAND mkdir ARGS -p ${OGRE_SAMPLE_CONTENTS_PATH}/Resources
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/plugins.cfg 		${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/resources.cfg 		${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/samples.cfg   		${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/bin/quakemap.cfg  		${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ln ARGS -s -f ${PROJECT_SOURCE_DIR}/Samples/Media     		${OGRE_SAMPLE_CONTENTS_PATH}/Resources/
        #         COMMAND ditto ${PROJECT_SOURCE_DIR}/Samples/Common/misc/SampleBrowser_OSX.icns ${OGRE_SAMPLE_CONTENTS_PATH}/Resources
        #     )
        # endif()

        # # now plugins
	    # add_custom_command(TARGET SampleBrowser POST_BUILD
        #     COMMAND mkdir ARGS -p ${OGRE_SAMPLE_CONTENTS_PATH}/Frameworks
        #     COMMAND mkdir ARGS -p ${OGRE_SAMPLE_CONTENTS_PATH}/Plugins)
        # set(FRAMEWORKS OgreBites)

        # foreach(FWK ${FRAMEWORKS})
        #     add_custom_command(TARGET SampleBrowser POST_BUILD
        #         COMMAND ARGS if [ -d ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/${FWK}.framework ]\; then ln -s -f ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/${FWK}.framework ${OGRE_SAMPLE_CONTENTS_PATH}/Frameworks/${FWK}.framework\; fi
        #     )
        # endforeach(FWK)

        # # Add links for the sample plugins
        # foreach(SAMPLE_PLUGIN ${OGRE_SAMPLES_LIST})
	    #     add_custom_command(TARGET SampleBrowser POST_BUILD
		#         COMMAND ln ARGS -s -f ${PROJECT_BINARY_DIR}/lib/${OGRE_OSX_BUILD_CONFIGURATION}/${SAMPLE_PLUGIN}.dylib
		#         ${OGRE_SAMPLE_CONTENTS_PATH}/Plugins/
		#     )
        # endforeach(SAMPLE_PLUGIN)

    endif ()

endif ()