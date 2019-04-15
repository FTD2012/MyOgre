#import "OgreOSXCocoaWindow.h"

#import <AppKit/NSScreen.h>
#import <AppKit/NSOpenGLView.h>
#import <QuartzCore/CVDisplayLink.h>
#import <iomanip>

@implementation OgreGLWindow

- (BOOL)canBecomeKeyWindow
{
    return YES;
}

- (BOOL)acceptsFirstMouse:(NSEvent *)theEvent
{
    return YES;
}

- (BOOL)acceptsFirstResponder
{
    return YES;
}

@end

namespace Ogre {

    CocoaWindow::CocoaWindow()
    : mWindow(nil)
    , mView(nil)
    // , mGLContext(nil)
    , mWindowOriginPt(NSZeroPoint)
    , mContentScalingFactor(1.0)
    , mStyleMask(NSResizableWindowMask|NSTitledWindowMask)
    {

    }

    CocoaWindow::~CocoaWindow() 
    {

    }

    void CocoaWindow::create(const String& name, unsigned int widthPt, unsigned int heightPt,
                        bool fullScreen, const NameValuePairList* miscParams)
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        NSApplicationLoad();

        NSString* windowTitle = [NSString stringWithCString:name.c_str() encoding:NSUTF8StringEncoding];
        int winxPt = 0, winyPt = 0;
        int colourDepth = 32;
        int surfaceOrder = 1;
        NameValuePairList::const_iterator opt;


        // Make active
        mName = [windowTitle cStringUsingEncoding:NSUTF8StringEncoding];
        mWidth = _getPixelFromPoint(widthPt);
        mHeight = _getPixelFromPoint(heightPt);

        if (!miscParams || opt == miscParams->end())
        {
            createNewWindow(widthPt, heightPt, [windowTitle cStringUsingEncoding:NSUTF8StringEncoding]);
        }
        else
        {

        }

        // Create register the context with the rendersystem and associate it with this window
        // mContext = OGRE_NEW CocoaContext(mGLContext, mGlPixelFormat);

        if (mContentScalingFactor > 1.0)
            [mView setWantsBestResolutionOpenGLSurface:YES];
        
        // CGLLockContext((CGLContextObj)[mGLContext CGLContextObj]);

        [mView setNeedsDisplay:YES];

        // if ([mGLContext view] != mView)
            // [mGLContext setView:mView];
        // [mGLContext makeCurrentContext];

#if OGRE_DEBUG_MODE
        // Crash on functions that have been removed from the API
        // CGLEnable((CGLContextObj)[mGLContext CGLContextObj], kCGLCECrashOnRemovedFunctions);
#endif

        // Enable GL multithreading
        // CGLEnable((CGLContextObj)[mGLContext CGLContextObj], kCGLCEMPEngine);

        // [mGLContext update];

        // rs->clearFrameBuffer(FBT_COLOUR);

        // [mGLContext flushBuffer];
        // CGLUnlockContext((CGLContextObj)[mGLContext CGLContextObj]);

        [pool drain];

        StringStream ss;
        ss << "Cocoa: Window created " << widthPt << " x " << heightPt
        << " with backing store size " << mWidth << " x " << mHeight
        << " using content scaling factor " << std::fixed << std::setprecision(1) << getViewPointToPixelScale();


    }


    void CocoaWindow::setHidden(bool hidden)
    {
        mHidden = hidden;
        if (mIsExternal)
        {
            if (hidden)
                [mWindow orderOut:nil];
            else
                [mWindow makeKeyAndOrderFront:nil];
        }
    }

    float CocoaWindow::getViewPointToPixelScale()
    {
        return mContentScalingFactor > 1.0f ? mContentScalingFactor : 1.0f;
    }

    int CocoaWindow::_getPixelFromPoint(int viewPt) const
    {
        return mContentScalingFactor > 1.0 ? viewPt * mContentScalingFactor : viewPt;
    }

    void CocoaWindow::createNewWindow(unsigned int widthPt, unsigned int heightPt, String title)
    {
        // Get the dimensions of the display. We will use it for window size but not context resolution
        NSRect windowRect = NSZeroRect;

        if (mIsFullScreen)
        {

        }
        else
            windowRect = NSMakeRect(0.0, 0.0, widthPt, heightPt);

        mWindow = [[OgreGLWindow alloc] initWithContentRect:windowRect
                                            styleMask:mIsFullScreen ? NSBorderlessWindowMask : mStyleMask
                                                backing:NSBackingStoreBuffered
                                                    defer:YES];
        [mWindow setTitle:[NSString stringWithCString:title.c_str() encoding:NSUTF8StringEncoding]];
        mWindowTitle = title;

        mView = [[OgreGLView alloc] initWithGLOSXWindow:this];

        _setWindowParameters(widthPt, heightPt);

        
        
    }

    void CocoaWindow::_setWindowParameters(unsigned int widthPt, unsigned int heightPt)
    {
        if (mWindow)
        {
            if (mIsFullScreen)
            {

            }
            else
            {
                // Reset and disable the backing store in windowed mode
                GLint backingStoreDimension[2] = {0, 0};
                // CGLSetParameter((CGLContextObj)[mGLContext CGLContextObj], kCGLCPSurfaceBackingSize, backingStoreDimension);
                // CGLDisable((CGLContextObj)[mGLContext CGLContextObj], kCGLCESurfaceBackingSize);

                NSRect viewRect = NSMakeRect(mWindowOriginPt.x, mWindowOriginPt.y, widthPt, heightPt);
                [mWindow setFrame:viewRect display:YES];
                [mView setFrame:viewRect];
                [mWindow setStyleMask:mStyleMask];
                [mWindow setOpaque:YES];
                [mWindow setHidesOnDeactivate:NO];
                [mWindow setContentView:mView];
                [mWindow setLevel:NSNormalWindowLevel];
                [mWindow center];

                // Set the drawable, and current context
                // If you do this last, there is a moment before the rendering window pop-up
                // [mGLContext makeCurrentContext];
            }

            // [mGLContext update];

            // Even though OgreCocoaView doesn't accept first responder, it will get passed onto the next in the chain
            [mWindow makeFirstResponder:mView];
            [NSApp activateIgnoringOtherApps:YES];
        }
    }

}
