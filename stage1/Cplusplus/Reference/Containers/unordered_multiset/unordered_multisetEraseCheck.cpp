// file : unordered_multisetEraseCheck.cpp
/******************************************************************************************
*       by position(1)          iterator erase(const_iterator position);
*       by key(2)                       size_type erase(const key_type& k);
*       range(3)                        iterator erase(const_iterator first,const_iterator last);
******************************************************************************************/
// (1) and (3) return an iterator pointing to the position immediately following the last of the elements erased.
// (2) returns the number of elements erased.

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        unordered_multiset<string> myums = {"fish","duck","cow","cow","pig","hen","sheep"};

        printInfo("myums",myums);
        myums.erase(myums.begin()); // erase by position
        myums.erase("sheep"); // erase by key
        myums.erase(myums.find("duck"),myums.end());

        printInfo("myums",myums);

        return 0;
}
