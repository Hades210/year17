// file : dequeSwapCheck.cpp
// void swap(deque& x);

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        deque<int> foo (3,100);
        deque<int> bar(5,200);

        foo.swap(bar);

        printInfo("foo",foo);
        printInfo("bar",bar);
        
        return 0;
}
