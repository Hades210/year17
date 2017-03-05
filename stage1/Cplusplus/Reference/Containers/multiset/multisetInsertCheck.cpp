// file : multisetInsertCheck.cpp
/****************************************************************************************************************
*	single element(1)	iterator insert(const value_type& val);
*						iterator insert(value_type&& val);
*	with hint(2)		iterator insert(const_iterator position,const value_type& val);
*						iterator insert(const_iterator position, value_type&& val);
*	range(3)			template <class InputIterator>
*							void insert(InputIterator first, InputIterator last);
*	il(4)				void insert(initializer_list<value_type> il);
*****************************************************************************************************************/
// position hint for the position where the element can be inserted.
// The function optimizes its insertion time if position points to the element that will follow the inserted element
// (or to the end, if it would be the last).
// Notice that this is just a hint and does not force the new element to be inserted at that position within the 
// multiset container(the elements in a multiset always follow a specific order).
// In the versions returning a value, this is an iterator pointing to the newly inserted element in the multiset.

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

int main()
{
	multiset<int> myset;
	multiset<int>::iterator it ;

	for(int i = 1; i <= 5; i ++)
		myset.insert(i * 10);

	it = myset.insert(25);

	it = myset.insert(it,27);
	it = myset.insert(it,29);
	it = myset.insert(it,24);

	int myints[] = {5,10,15};
	myset.insert(myints,myints + 3);

	printInfo("myset",myset);
	
	return 0;
}
