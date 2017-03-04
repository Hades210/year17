// file : setEqualRangeCheck.cpp
// pair<const_iterator,const_iterator> equal_range(const value_type& val) const;
// pair<iterator,iterator> equal_range(const value_type& val);
// Get range of equal elements
// Returns the bounds of a range that includes all the elements in the container that are equivalent to val
// Because all elements in a set container are unique, the range return will contain a single element at most.
// If no matches are found, the range returned has a length of zero, with both iterators pointing to the first
// element that is considered to go after val according to the container's internal comparison object
// The function returns a pair, whose member pair::first is the lower bound of the range(the same as lower_bound),
// and pair::second is the upper bound (the same as upper_bound).

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> myset;
	for(int i = 1; i <= 5; i ++)
		myset.insert(i * 10);

	pair<set<int>::const_iterator,set<int>::const_iterator> ret;

	ret = myset.equal_range(30);

	cout<<"the lower bound points to: "<<*ret.first<<"\n";
	cout<<"the upper bound points to: "<<*ret.second<<"\n";
	
	return 0;
}
