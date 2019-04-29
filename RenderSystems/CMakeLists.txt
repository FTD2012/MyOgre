# Configure Rendersystem build

if (OGRE_BUILD_RENDERSYSTEM_GL OR OGRE_BUILD_RENDERSYSTEM_GL3PLUS OR OGRE_BUILD_RENDERSYSTEM_GLES2)
    add_subdirectory(GLSupport)
endif ()

if (OGRE_BUILD_RENDERSYSTEM_GL3PLUS)
    if (NOT OPENGL_FOUND)
        MESSAGE(STATUS "Could not find dependency: GL3Plus")
        MESSAGE(STATUS "Skipping GL3Plus rendersystem build")
        set(OGRE_BUILD_RENDERSYSTEM_GL3PLUS 0)
    else ()
        add_subdirectory(GL3Plus)
    endif ()
endif ()
