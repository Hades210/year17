// file : dequeClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
        deque<int> mydeque;
        mydeque.push_back(100);
        mydeque.push_back(200);
        mydeque.push_back(300);

        printInfo("mydeque",mydeque);

        mydeque.clear();
        mydeque.push_back(1001);
        mydeque.push_back(2002);

        printInfo("mydeque",mydeque);
        
        return 0;
}
