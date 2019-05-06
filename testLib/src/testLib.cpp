#include "testLib.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

namespace Ogre {

    class A {

    };

    void TestLib::log()
    {
        std::vector<A> v1;
        A a;
        v1.push_back(a);
        std::cout << "v1 = " << v1.size() << std::endl;
        std::cout << "This is Test Lib log." << std::endl;
    }
}