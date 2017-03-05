// file: multisetEraseCheck.cpp
/**************************************************************
*	iterator erase(const_iterator position);
*	size_type erase(const value_type& val);
*	iterator erase(const_iterator first, const_iterator last);
***************************************************************/
// for the value-based version, the function returns the number of element erased.
// The other versions returns an iterator to the element that follows the last element 
// removed (or multiset::end, if the last element was removed.)

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multiset<int> myset;
	multiset<int>::iterator it;

	myset.insert(40);

	for(int i = 1; i < 7; i ++)
		myset.insert(i * 10);

	it = myset.begin();
	it ++;

	myset.erase(it);
	myset.erase(40);

	it = myset.find(50);
	myset.erase(it,myset.end());

	printInfo("myset",myset);
	
	return 0;
}
