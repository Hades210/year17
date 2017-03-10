// file : unordered_multisetClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <unordered_set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_multiset<string> myums = {"chair","table","lamp","sofa","chair"};

        printInfo("myums",myums);

        myums.clear();

        myums = {"bed","bed","wardrobe","nightstand"};

        printInfo("myums",myums);
        
        return 0;
}
