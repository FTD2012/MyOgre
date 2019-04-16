


#######################################################################
# Core dependencies
#######################################################################

# Find GLFW
find_package(GLFW)
macro_log_feature(GLFW_FOUND "glfw" "All paltform window" "http://www.glfw.org" FALSE "" "")


# Find FreeType
find_package(Freetype)
macro_log_feature(FREETYPE_FOUND "freetype" "Portable font engine" "http://www.freetype.org" FALSE "" "")

#######################################################################
# RenderSystem dependencies
#######################################################################


# Find OpenGL
if (NOT ANDROID AND NOT EMSCRIPTEN)
    find_package(OpenGL)
    macro_log_feature(OPENGL_FOUND "OpenGL" "Support for the OpenGL and OpenGL 3+ render systems" "http://www.opengl.org/" FALSE "" "")
endif ()
