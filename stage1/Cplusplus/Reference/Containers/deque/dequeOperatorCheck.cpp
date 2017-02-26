// file : dequeOperatorCheck.cpp
/************************************************************************
*	copy(1)		deque& operator= (const deque& x);
*	move(2)		deque& operator= (deque&& x);
*	il(3)		deque& operator= (initializer_list<value_type> il)
*************************************************************************/

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> first (3);
	deque<int> second (5);

	second = first ;
	first = deque<int>();

	cout<<"Size of first: "<<int(first.size())<<"\n";
	cout<<"Size of second: "<<int(second.size())<<"\n";

	return 0;
}
