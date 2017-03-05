// file : multisetLowerBoundCheck.cpp
// const_iterator lower_bound (const value_type& val) const;
// iterator lower_bound(const value_type& val);
// const_iterator upper_bound(const value_type& val) const;
// iterator upper_bound (const value_type& val);
// Returns an iterator pointing to the first element in the container which is not considered to go before val(either it is equivalent or goes after)
// The function uses its internal comparison object(key_comp) to determine this, returning an iterator to the first element for which key_comp(element,val)
// would return false.
// If the multiset class is instantiated with the default comparison type(less), the function returns an iterator to the first element that is not less than val.
// A similar member funcction, upper_bound, has the same behavior as lower_bound, except in the case that multiset contains elements equivalent to val: In this case
// lower_bound returns an iterator pointing to the first of such elements, whereas upper_bound returns an iterator pointing to the element following the last.

#include <iostream>
#include <set>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multiset<int> myset;
	multiset<int>::iterator itlow,itup;

	multiset<int, greater<int> > myset2;
	multiset<int, greater<int> > ::iterator itlow2,itup2;

	for(int i = 1; i < 8; i ++)
	{
		myset.insert(i * 10);
		myset2.insert(i * 10);
	}

	itlow = myset.lower_bound(30);
	itup = myset.upper_bound(40);

	myset.erase(itlow,itup);
	printInfo("myset",myset);

	itlow2 = myset2.lower_bound(30);
	itup2 = myset2.upper_bound(40);
	cout<<*itlow2<<"\n";
	cout<<*itup2<<"\n";
	myset2.erase(itlow2);

	printInfo("myset2",myset2);

	return 0;
}
