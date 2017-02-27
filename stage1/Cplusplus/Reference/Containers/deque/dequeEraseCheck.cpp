// file : dequeEraseCheck.cpp
// iterator erase(const_iterator position);
// iterator erase(const_iterator first, const_iterator last);
// Return iterator followed the last element erased by the function call.
// This is the container end if the operation erased the last element in the sequence.

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque;

	for(int i = 1; i <= 10; ++ i)
		mydeque.push_back(i);

	mydeque.erase(mydeque.begin() + 5);
	mydeque.erase(mydeque.begin(),mydeque.begin() + 3);

	printInfo("mydeque",mydeque);
	
	return 0;
}
