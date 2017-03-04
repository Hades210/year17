// file:setFindCheck.cpp
// const_iterator find(const vaule_type& val) const;
// iterator find(const value_type& val);
// Return an iterator to the element, if val is found, or set::end otherwise.

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	set<int> myset;
	set<int>::iterator it;

	for(int i = 1; i <= 5; i ++)
		myset.insert(i * 10);

	it = myset.find(20);
	myset.erase(it);
	myset.erase(myset.find(40));

	printInfo("myset",myset);
	
	return 0;
}
