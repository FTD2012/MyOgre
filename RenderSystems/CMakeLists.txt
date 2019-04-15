# Configure Rendersystem build

if (OGRE_BUILD_RENDERSYSTEM_GL OR OGRE_BUILD_RENDERSYSTEM_GL3PLUS OR OGRE_BUILD_RENDERSYSTEM_GLES2)
    add_subdirectory(GLSupport)
endif ()

