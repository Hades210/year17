// file : swapDequeCheck.cpp
// template <class T, class Alloc>
//      void swap(deque<T,Alloc>& x, deque<T,Alloc>& y);

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        deque<int> foo (3,100);
        deque<int> bar (5,200);

        swap(foo,bar);

        printInfo("foo",foo);
        printInfo("bar",bar);
        
        return 0;
}
