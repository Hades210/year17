// file : setEraseCheck.cpp
/********************************************************************
*	iterator erase(const_iterator position);
*	size_type erase(const value_type& val);
*	iterator erase(const_iterator first, const_iterator last);
*********************************************************************/
// For the value-based version, the function returns the number of elements 
// erased, which in set containers is at most 1.
// The other versions return an iterator to the element that follows the last element removed(or set::end,if the last element was removed)

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	set<int> myset;
	set<int>::iterator it;

	for(int i = 1; i < 10; i ++)
		myset.insert(i * 10);

	it = myset.begin();
	++it;

	myset.erase(it);
	myset.erase(40);

	it = myset.find(60);
	myset.erase(it,myset.end());

	printInfo("myset",myset);
	
	return 0;
}
