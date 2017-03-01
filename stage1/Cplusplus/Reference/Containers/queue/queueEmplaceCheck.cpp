// file : queueEmplaceCheck.cpp
// template <class... Args>
//              void emplace(Args&&... args)
// This member function effectively call member function emplace_back of the underlying container

#include <iostream>
#include <queue>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        queue<string> myqueue;
        myqueue.emplace("first line");
        myqueue.emplace("second line");

        printInfo("myqueue",myqueue);

        return 0;
}
