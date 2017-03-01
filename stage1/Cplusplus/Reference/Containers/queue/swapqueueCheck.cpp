// file : swapqueueCheck.cpp
// template <class T, class Container>
//              void swap(queue<T,Container>& x, queue<T,Container>& y) noexcept (noexcept(x.swap(y)));

#include <iostream>
#include <queue>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        queue<int> foo,bar;

        foo.push(10);foo.push(20);foo.push(30);

        bar.push(100);bar.push(200);

        foo.swap(bar);

        printInfo("foo",foo);
        printInfo("bar",bar);
        
        return 0;
}
