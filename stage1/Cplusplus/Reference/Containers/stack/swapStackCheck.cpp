// file : swapStackCheck.cpp
// template <class T, class Container>
//              void swap(stack<T,Container>& x, stack<T,Container>& y) noexcept (noexcept(x.swap(y)));

#include <iostream>
#include <stack>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        stack<int> foo,bar;

        foo.push(10);foo.push(20);foo.push(30);
        bar.push(100);bar.push(200);

        swap(foo,bar);

        printInfo("foo",foo);
        printInfo("bar",bar);

        return 0;
}
