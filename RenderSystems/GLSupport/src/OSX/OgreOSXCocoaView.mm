#import "OgreOSXCocoaView.h"
#import <AppKit/AppKit.h>

@implementation OgreGLView

- (id)initWithGLOSXWindow:(Ogre::RenderWindow*)w
{
   	if((self = [super initWithFrame:NSMakeRect(0, 0, w->getWidth(), w->getHeight())]))
    {
        window = w;
    }
	return self; 
}

@end