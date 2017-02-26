// file : dequeAssignCheck.cpp
/******************************************************************************************************
*	range(1)	template <class InputIterator>
*					void assign(InputIterator first, InputIterator last);
*	fill(2)		void assign(size_type n, const value_type& val);
*	il(3)		void assign(initializer_list<value_type> il);
*******************************************************************************************************/

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> first;
	deque<int> second;
	deque<int> third;

	first.assign(7,100);

	printInfo("1.",first);

	deque<int>::iterator it = first.begin() + 1;

	second.assign(it,first.end() - 1);

	printInfo("2.",second);

	int myints[] = {1776,7,4};
	third.assign(myints,myints + 3);
		
	printInfo("3",third);


	return 0;
}
