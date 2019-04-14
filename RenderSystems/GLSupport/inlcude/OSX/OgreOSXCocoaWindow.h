#ifndef __OSXCocoaWindow_H_
#define __OSXCocoaWindow_H_

#include <AppKit/NSWindow.h>
#include <QuartzCore/CVDisplayLink.h>

#include "OgreOSXCocoaView.h"

typedef NSUInteger NSWindowStyleMask; // NS WindowStyleMaks was declared only since OSX 10.2 SDK

@interface OgreGLWindow : NSWindow

@end

namespace Ogre {
    class _OgreExport CocoaWindow : public RenderWindow /* , public GLRenderTarget */
    {
    private:
        NSWindow* mWindow;
        NSView* mView;
        NSOpenGLContext* mGLContext;

        NSPoint mWindowOriginPt;

        bool mHidden;
        bool mIsExternal;
        float mContentScalingFactor;
        NSWindowStyleMask mStyleMask;

        int _getPixelFromPoint(int viewPt) const;
        void _setWindowParameters(unsigned int widthPt, unsigned int heightPt);

    public:
        CocoaWindow();
        ~CocoaWindow();

        /** @copydoc see RenderWindow::getViewPointToPixedScale */
        float getViewPointPixelScale();
        /** Overridden - see RenderWindow */
        void create(const Strinb& name, unsigned int widthPt, unsigned int heightPt,
                    bool fullScreen, const NameValuePairList* miscParams);

        void setHidden(bool hidden);

        void createNewWindow(unsigned int width, unsigned int height, String title);


    }




}


#endif  // #ifndef __OSXCocoaWindow_H_