#ifndef __OGREGLFWWINDOW_H_
#define __OGREGLFWWINDOW_H_

#include "OgreRenderWindow.h"

#include "glad.h"
#include "GLFW/glfw3.h"

namespace Ogre
{
    class _OgreExport GLFWWindow : public RenderWindow
    {
    public:
        GLFWWindow();
        ~GLFWWindow();

        void create(const String& name, unsigned int widthPt, unsigned int heightPt,
                    bool fullScreen, const NameValuePairList* miscParams);


        void swapBuffers();

    private:
        bool mActive;
        bool mClosed;
        bool mHidden;
        bool mVSync;
        bool mHasResized;
        String mWindowTitle;
        float mContentScalingFactor;

        GLFWwindow *window;

    };
} // namespace Ogre





#endif // #ifndef __OGREGLFWWINDOW_H_