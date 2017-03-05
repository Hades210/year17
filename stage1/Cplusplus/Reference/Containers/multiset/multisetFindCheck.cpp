// file : multisetFindCheck.cpp
// const_iterator find(const value_type& val) const;
// iterator find(const value_type& val);
// Searches the container for an element equivalent to val and returns an iterator to it if found, otherwise it returns an iterator to multiset::end.
// Notice that this function returns an iterator to a single element(of the possibly multiple equivalent elements). To obtain the entire range of equivalent elements,
// see multiset::equal_range.

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{	
	multiset<int> myset;
	multiset<int>::iterator it;

	for(int i = 1; i <= 5; i ++)
		myset.insert(i * 10);

	it = myset.find(20);
	myset.erase(it);
	myset.erase(myset.find(40));

	printInfo("myset",myset);
	
	return 0;
}
