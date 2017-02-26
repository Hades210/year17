// file : dequeBackCheck.cpp
// reference back();
// const_reference back() const;

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque;

	mydeque.push_back(10);

	while(mydeque.back() != 0)
		mydeque.push_back(mydeque.back() - 1);

	printInfo("mydeque",mydeque);

	return 0;
}
