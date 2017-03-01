// file : stackEmplaceCheck.cpp
// template<class... Args> void emplace(Args&& ... args);
// This member function effectively calls the member function emplace_back of the underlying container, forwarding args.

#include <iostream>
#include <stack>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        stack<string> mystack;

        mystack.emplace("first sentence");
        mystack.emplace("second stance");

        printInfo("mystack",mystack);

        return 0;
}
