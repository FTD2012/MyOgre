# Configure OpenGl 3+ RenderSystem build

file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")


set(HEADER_FILES ${HEADER_FILES} ${GLSL_HEADERS})

foreach(header ${HEADER_FILES})
    message(${header})
endforeach()

# add_definitions(${OGRE_VISIBILITY_FLAGS})

add_library(RenderSystem_GL3Plus ${OGRE_LIB_TYPE} ${HEADER_FILES} ${GLSL_SOURCE} ${SOURCE_FILES})
target_link_libraries(RenderSystem_GL3Plus OgreMain OgreGLSupport ${OPENGL_gl_LIBRARY} ${CMAKE_DL_LIBS})
target_include_directories(RenderSystem_GL3Plus PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/GLSL>")
    
if (APPLE)
    set_target_properties(RenderSystem_GL3Plus PROPERTIES LINK_FLAGS "-framework Cocoa -framework OpenGL")
else ()
    target_include_directories(RenderSystem_GL3Plus PUBLIC ${OPENGL_INCLUDE_DIR})
endif ()