#include "testLib.h"
#include <iostream>
using std::cout;
using std::endl;

namespace Ogre {
    void TestLib::log()
    {
        std::cout << "This is Test Lib log." << std::endl;
    }
}