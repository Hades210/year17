// file : dequeEmplaceCheck.cpp
// template <class... Args>
//              iterator emplace(const_iterator position, Args&&... args);

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        deque<int> mydeque = {10,20,30};

        auto it = mydeque.emplace(mydeque.begin() + 1, 100);
        mydeque.emplace(it,200);

        mydeque.emplace(mydeque.end(),300);

        printInfo("mydeque",mydeque);
        
        return 0;
}
