// file : dequeEmplaceFrontBackCheck.cpp
// template <class... Args>
//              void emplace_front(Args&&... args);
// Construct and insert element at beginning
// template <class... Args>
//              void emplace_back(Args&&... args);
// Construct and insert element at the end

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        deque<int> mydeque = {10, 20, 30};
        mydeque.emplace_front(111);
        mydeque.emplace_front(222);

        mydeque.emplace_back(100);
        mydeque.emplace_back(200);

        printInfo("mydeque",mydeque);
        
        return 0;
}
