// file : dequeInsertCheck.cpp
/*********************************************************************************************************************
*	single element(1)	iterator insert(const_iterator position, const value_type& val);
*	fill (2)			iterator insert(const_iterator position, size_type n, const value_type& val);
*	range(3)			template <class InputIteraot>
*						iterator insert(const_iterator position, InputIterator first, InputIterator last);
*	move(4)				iterator insert(const_iterator position, value_type&& val);
*	il (5)				iterator insert(const_iterator position, initializer_list<value_type> il);
**********************************************************************************************************************/
// Return value An iterator that points to the first of the newly inserted elements.

#include <iostream>
#include <deque>
#include <vector>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque;

	for(int i = 1; i <= 5; ++ i)
		mydeque.push_back(i);

	deque<int>::iterator it = mydeque.begin();
	++ it;

	it = mydeque.insert(it,10);

	mydeque.insert(it,2,20);

	it = mydeque.begin() + 2;

	vector<int> myvector(3,30);
	mydeque.insert(it,myvector.begin(),myvector.end());

	printInfo("mydeque",mydeque);

	return 0;
}
