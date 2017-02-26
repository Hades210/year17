// file : dequeRbeginCheck.cpp
// reverse_iterator rbegin() noexcept;
// const_reverse_iterator rbegin() const noexcept;
// reverse_iterator rend() noexcept;
// const_reverse_iterator rend() const noexcept;

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque (5);

	deque<int>::reverse_iterator rit = mydeque.rbegin();

	int i = 0;
	for(;rit != mydeque.rend(); ++ rit)
		*rit = ++ i;

	printInfo("mydeque",mydeque);

	return 0;
}
