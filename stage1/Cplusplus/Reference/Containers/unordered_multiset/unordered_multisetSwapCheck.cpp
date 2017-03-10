// file : unordered_multisetSwapCheck.cpp
// void swap(unordered_multiset& ums);

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_multiset<string> 
        first = {"cow","chicken","pig","pig"},
        second = {"wolf","rabbit","rabbit"};

        printInfo("first",first);
        printInfo("second",second);

        first.swap(second);
        printInfo("first",first);
        printInfo("second",second);

        swap(first,second);
        printInfo("first",first);
        printInfo("second",second);
        
        return 0;
}
