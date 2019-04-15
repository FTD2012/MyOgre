# Configure Samples build

if (OGRE_BUILD_SAMPLES)

    include_directories(${PROJECT_SOURCE_DIR}/Samples/include)
    include_directories(${PROJECT_SOURCE_DIR}/Samples/Browser/include)
    file(GLOB SAMPLES_HEADERS ${PROJECT_SOURCE_DIR}/Samples/*/include/*.h)
    file(GLOB SAMPLES_SOURCES ${PROJECT_SOURCE_DIR}/Samples/*/src/*.cpp)

    add_executable(DefaultSamples
            ${OGRE_LIB_TYPE} 
            ${SAMPLES_HEADERS}
            ${SAMPLES_SOURCES}
    )
    target_link_libraries(DefaultSamples OgreMain OgreBites OgreTestLib OgreGLSupport)

    # if (APPLE AND NOT APPLE_IOS)
    #     # Set the INSTALL_PATH so that Samples can be installed in the application package
    #     set_target_properties(DefaultSamples
    #         PROPERTIES BUILD_WITH_INSTALL_RPATH 1
    #         INSTALL_NAME_DIR "@executable_path/../Plugins"
    #     )
    # endif()

    ## Add browser last
    # add_subdirectory(Browser)

endif ()