// file : setInsertCheck.cpp
/*****************************************************************************************
*	single element(1)		pair<iterator,bool> insert(const value_type& val);
*							pair<iterator,bool> insert(value_type&& val);
*	with hint(2)			iterator insert(const iterator position ,const value_type& val )
*							iterator insert(const iterator position, value_type&& val);
*	range(3)				template <class InputIterator>
*								void insert(InputIterator first, InputIterator last);
*	il(4)					void insert(initializer_list<value_type>il);
******************************************************************************************/
// with hint(2) position
// Hint for the position where the element can be inserted.
// The function optimizes its insertion time if position points to the element that will follow the 
// inserted element ro to the end, if it would be the last
// Notice that this is just a hint and does not force the new element to be inserted at that position
// with the set container.

// version(1) retun a pair, with its member pair::first seet to an iterator pointing to either the newly
// inserted element or to the equivalent element already in the set. The pair:second element in the pair
// is set to true if a new element was inserted or false if an equivalent element already existed.

// version (2) return an iterator pointing to either the newly inserted element or to the element that
// already had its same value in the set.

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	set<int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator, bool> ret;

	for(int i = 1; i <= 5; i ++)
		myset.insert(i * 10);

	printInfo("myset",myset);

	ret = myset.insert(20);

	if(ret.second == false)
		it = ret.first;

	myset.insert(it,25); // max efficiency inserting
	myset.insert(24);    // max efficiency inserting
	myset.insert(26);	// no max efficiency inserting

	int myints[] = {5,10,15};
	myset.insert(myints,myints + 3);

	printInfo("myset",myset);

	return 0;
}



