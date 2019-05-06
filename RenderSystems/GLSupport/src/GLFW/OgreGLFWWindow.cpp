
#include <iostream>
#include "glad.h"
#include "OgreGLFWWindow.h"

namespace Ogre {

    //-----------------------------------------------------------------------
    GLFWWindow::GLFWWindow()
    {

    }

    //-----------------------------------------------------------------------
    GLFWWindow::~GLFWWindow()
    {

    }

    //-----------------------------------------------------------------------
    void GLFWWindow::create(const String& name, unsigned int widthPt, unsigned int heightPt, bool fullScreen, const NameValuePairList* miscParams)
    {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        window = glfwCreateWindow(widthPt, heightPt, name.c_str(), NULL, NULL);
        if (!window)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            // return -1;
        }

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            // return -1;
        }

        while (!glfwWindowShouldClose(window))
        {

            // processInput(window);

            // glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            // glClear(GL_COLOR_BUFFER_BIT);

            glfwPollEvents();

            // glfwSwapBuffers(window);
        }

    }
}