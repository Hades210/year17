// file : arraySwapCheck.cpp
// void swap(array& x) noexcept (noexcept(swap(declval<value_type&>(),declval<value_type&>())));
// same type and same size

#include <iostream>
#include <array>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        array<int,5> foo = {1,2,3,4,5};
        array<int,5> bar = {6,7,8,9,10};

        foo.swap(bar);

        printInfo("foo",foo);
        printInfo("bar",bar);

        return 0;
}
