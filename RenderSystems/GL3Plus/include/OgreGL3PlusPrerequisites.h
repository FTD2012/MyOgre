#ifndef __GL3PlusPrerequisites_H_
#define __GL3PlusPrerequisites_H_

#include "OgrePrerequisites.h"

#include "OgreLogManager.h"

namespace Ogre {
    class GLContext;
    class GLRTTManager;
    typedef GLContext GL3PlusContext;
    typedef GLRTTManager GL3PlusRTTManager;
    class GL3PlusRenderSystem;
    class GL3PlusStateCacheManager;
    class GLNativeSupport;
    class GL3PlusTexture;
    class GL3PlusTextureManager;
    class GL3PlusFBOManager;
    class GL3PlusHardwarePixelBuffer;
    class GL3PlusRenderBuffer;
    class GL3PlusDepthBuffer;

    class GLSLShader;

    // typedef shared_ptr<GLSLSHader> GLSLShaderPtr;
    // typedef shared_ptr<GL3PlusTexture> GL3PlusTexturePtr;

}

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32

#elif OGRE_PLATFORM == OGRE_PLATFORM_LINUX

#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE
#   include "glad.h"
#endif

// Lots of generated code in here which triggers the new VC CRT security warnings
#if !defined( _CRT_SECURE_NO_DEPRECATE )
#   define _CRT_SECURE_NO_DEPRECATE
#endif

#if (OGRE_PLATFORM == OGRE_PLATFORM_WIN32) && !defined(__MINGW32__) && !defined(OGRE_STATIC_LIB)

#elif defined ( OGRE_GCC_VISIBILITY )

#else
#    define _OgreGL3PlusExport
#endif

// Convenience macro from ARB_vertex_buffer_object spec
#define GL_BUFFER_OFFSET(i) ((char *)(i))

#if OGRE_COMPILER == OGRE_COMPILER_MSVC
#   define __PRETTY_FUNCTION__ __FUNCTION__
#endif

#define ENABLE_GL_CHECK 1
#define ENABLE_GL_DEBUG_OUTPUT 0

#if ENABLE_GL_CHECK
#include "OgreStringVector.h"
#define OGRE_CHECK_GL_ERROR(glFunc) \
{ \
    glFunc; \
    int e = glGetError(); \
    if (e != 0) \
    { \
        const char* errorString = ""; \
        switch(e) \
        { \
            case GL_INVALID_ENUM:       errorString = "GL_INVALID_ENUM";        break; \
            case GL_INVALID_VALUE:      errorString = "GL_INVALID_VALUE";       break; \
            case GL_INVALID_OPERATION:  errorString = "GL_INVALID_OPERATION";   break; \
            case GL_INVALID_FRAMEBUFFER_OPERATION:  errorString = "GL_INVALID_FRAMEBUFFER_OPERATION";   break; \
            case GL_OUT_OF_MEMORY:      errorString = "GL_OUT_OF_MEMORY";       break; \
            default:                                                            break; \
        } \
        char msgBuf[4096]; \
        StringVector tokens = StringUtil::split(#glFunc, "("); \
        sprintf(msgBuf, "OpenGL error 0x%04X %s in %s at line %i for %s\n", e, errorString, __PRETTY_FUNCTION__, __LINE__, tokens[0].c_str()); \
        LogManager::getSingleton().logMessage(msgBuf, LML_CRITICAL); \
    } \
    char msgBuf[4096]; \
    StringVector tokens = StringUtil::split(#glFunc, "("); \
    sprintf(msgBuf, "OpenGL exec [%s] in %s at line %i \n", tokens[0].c_str(), __PRETTY_FUNCTION__, __LINE__); \
    LogManager::getSingleton().logMessage(msgBuf, LML_CRITICAL); \
}
#else
#   define OGRE_CHECK_GL_ERROR(glFunc) { glFunc; }
#endif

#endif  // #ifndef __GL3PlusPrerequisites_H_