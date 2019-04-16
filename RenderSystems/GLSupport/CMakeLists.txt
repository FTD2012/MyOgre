# Configure OpenGL Support build

# Add platform specific settings

if (OGRE_BUILD_WINDOW_ALL_PLATFORM)
    message("Building window using GLFW.")
    file(GLOB PLATFORM_HEADERS "include/GLFW/*.h")
    file(GLOB PLATFORM_SOURCES "src/GLFW/*.cpp" "src/GLFW/*.c")
    set(PLATFORM_LIBS ${GLFW_glfw_LIBRARY} ${OPENGL_gl_LIBRARY})
    set(PLATFORM_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include/GLFW>)
elseif (ANDROID)

elseif (EMSCRIPTEN)

elseif (WIN32)

elseif (APPLE_IOS)

elseif (APPLE)
    file(GLOB PLATFORM_HEADERS "include/OSX/*.h")
    file(GLOB PLATFORM_SOURCES "src/OSX/*.mm")

    # ignore usage of deprecated OSX API for now
    add_definitions(-Wno-deprecated-declarations)

    set(NATIVE_INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/OSX
        ${PROJECT_SOURCE_DIR}/OgreMain/inlcude/OSX
    )
    
    set(PLATFORM_LIBS ${Cocoa_LIBRARY_FWK})

endif ()

file(GLOB GLSUPPORT_HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
set(GLSUPPORT_HEADERS ${GLSUPPORT_HEADERS} ${PROJECT_BINARY_DIR}/include/OgreGLSupportPrerequisites.h PARENT_SCOPE)

add_library(OgreGLSupport STATIC
    ${PLATFORM_HEADERS}
    ${PLATFORM_SOURCES}
)


target_link_libraries(OgreGLSupport PUBLIC OgreMain PRIVATE ${PLATFORM_LIBS})
target_include_directories(OgreGLSupport
    PUBLIC 
    "$<BUILD_INTERFACE:${GLFW_INCLUDE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/OSX>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GLSL>"
    "$<BUILD_INTERFACE:${PLATFORM_INCLUDES}"
    PRIVATE
    "$<BUILD_INTERFACE:${NATIVE_INCLUDES}>"
)

if (APPLE)
    set_target_properties(OgreGLSupport PROPERTIES LINK_FLAGS "-framework Cocoa -framework OpenGL")
endif ()

# ogre_config_component(OgreGLSupport)