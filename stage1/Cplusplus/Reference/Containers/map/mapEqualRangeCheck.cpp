// file : mapEqualRangeCheck.cpp
// pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
// pair<iterator,iterator> equal_range(const key_type& k);
// Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.

#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> mymap;
	typedef map<char,int>::iterator It;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	pair<It,It> ret;
	ret = mymap.equal_range('b');

	cout<<"lower bound points to: ";
	cout<<ret.first->first<<" : "<<ret.first->second<<"\n";

	cout<<"upper bound points to: ";
	cout<<ret.second->first<<" : "<<ret.second->second<<"\n";
	
	return 0;
}
