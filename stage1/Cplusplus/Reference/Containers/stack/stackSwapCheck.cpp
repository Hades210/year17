// file : stackSwapCheck.cpp
// void swap(stack& x) noexcept;
// This member function calls the non-member function swap (unqualified) to swap the underlying containers.

#include <iostream>
#include <stack>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        stack<int> foo;
        foo.push(10);foo.push(20);foo.push(30);

        stack<int> bar;
        bar.push(100);bar.push(200);

        foo.swap(bar);

        printInfo("foo",foo);
        printInfo("bar",bar);
        
        return 0;
} 
