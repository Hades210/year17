// file : unordered_mapEmplaceCheck.cpp
/********************************************************************************
*       template <class... Args>
*               pair<iterator,bool> emplace(Args&& ... args);
*       template <class... Args>
*               iterator emplace_hint(const_iterator position, Args&&... args);
**********************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_map<string,string> mymap;

        mymap.emplace("NCC-1701","J.T. Krik");
        mymap.emplace("NCC-1701-D","J.L. Picard");
        mymap.emplace("NCC-74656","K. Janeway");

        printInfo("mymap",mymap);

        return 0;
}
