#ifndef __OSXCocoaView_H_
#define __OSXCocoaView_H_

#include "OgreRenderWindow.h"

#include <AppKit/NSView.h>

@interface OgreGLView : NSView
{
    Ogre::RenderWindow* window;
}

- (id)initWithGLOSXWindow:(Ogre::RenderWindow*)w;

@end

#endif  // #ifndef __OSXCocoaView_H_