// file : unordered_multisetEmplaceCheck.cpp
// template <class... Args> iterator emplace(Args&& ... args);
// template <class... Args> iterator emplace_hint(const_iterator position, Args&&... args);

#include <iostream>
#include <unordered_set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_multiset<string> ums;

        ums.emplace("milk");
        ums.emplace("tea");
        ums.emplace("coffee");
        ums.emplace("milk");

        printInfo("ums",ums);
        
        return 0;
}
