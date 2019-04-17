// SampleBrowser.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <time.h>
#include "OgrePlatform.h"
#include <iostream>

#include <string>
#include "OgreAlignedAllocator.h"
#include "OgreString.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#	define WIN32_LEAN_AND_MEAN
#	include "window.h"
#	include "OgreString.h"
#elif OGRE_PLATFORM == OGRE_PLATFORM_APPLE_IOS
#	include "SampleBrowser_iOS.h"		/// TODO: ljm >>> implemation
#elif OGRE_PLATFORM == OGRE_PLATFORM_ANDROID
#	include "SampleBrowser_Android.h"	/// TODO: ljm >>> implemation
/// TODO: ljm >>> implemation
#endif

#include "SampleBrowser.h"

// #include "OgreOSXCocoaWindow.h"
#include "testLib.h"
#include "OgreGLFWWindow.h"
#include "OgreLogManager.h"

int main()
{
	//std::cout << "string trim = " << StringUtil.trim("   1111  3 ") << std::endl;
	Ogre::AlignedMemory::allocate(10);

	std::string str("   ddd   ");
	Ogre::StringUtil::trim(str);
	std::cout << str << std::endl;
	std::cout << "\nHello World!\n";

	Ogre::TestLib* testLib = new Ogre::TestLib();
	testLib->log();
	
	Ogre::LogManager* logMgr = new Ogre::LogManager();
	logMgr->createLog("firstLog.log", true);
	logMgr->getSingletonPtr()->logMessage("11111");

	Ogre::GLFWWindow* window = new Ogre::GLFWWindow();
	window->create("1", 800, 600, false, nullptr);
	window->create("2", 800, 600, false, nullptr);

	// Ogre::CocoaWindow* window = new Ogre::CocoaWindow();
	// window->create("1", 600, 800, false, nullptr);
}
