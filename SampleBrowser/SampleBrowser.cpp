// SampleBrowser.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <string>
#include <iostream>
#include "OgreAlignedAllocator.h"
#include "OgreString.h"

int main()
{
	//std::cout << "string trim = " << StringUtil.trim("   1111  3 ") << std::endl;
	Ogre::AlignedMemory::allocate(10);

	std::string str("   ddd   ");
	Ogre::StringUtil::trim(str);
	std::cout << str << std::endl;
	std::cout << "\nHello World!\n"; 
}
