// file : multisetEqualRange.cpp
// pair<const_iterator,const_iterator> equal_range(const value_type& val) const;
// pair<iterator,iterator> equal_range(const value_type& val);
// If no matches are found, the range returned has a length of zero, with both iterators pointing to the first element
// that is considered to go after val according to the container's internal comparison object (key_comp)
// The function returns a pair, whose member pair::first is the lower bound of the range(the same as lower_bound),
// and pair::second is the upper bound (the same as upper_bound)

#include <iostream>
#include <set>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

typedef multiset<int>::iterator It;
typedef multiset<int,greater<int> >::iterator GIt;

int main()
{
	int myints[] = {30,30,30,77,2,16};

	multiset<int> myset(myints , myints + 6);
	multiset<int,greater<int> > myset2(myints,myints + 6);

	pair<It,It> ret = myset.equal_range(30);
	myset.erase(ret.first,ret.second);
	printInfo("myset",myset);

	pair<GIt,GIt> ret2 = myset2.equal_range(30);
	myset2.erase(ret2.first,ret2.second);
	printInfo("myset2",myset2);
	
	return 0;
}
