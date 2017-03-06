// file : unordered_setEqualRangeCheck.cpp
/*************************************************************
*	pair<iterator,iterator>
*		equal_range(const key_type& k);
*	pair<const_iterator,const_iterator>
*		equal_range(const key_type& k) const;
*************************************************************/
// The function returns a pair, where its member pair::first is an iterator to the lower bound of the range, and
// pair::second is an iterator to its upper bound. The elements in the range are those between these two iterators,
// including pair::first,but not pair::second.

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> myset = {"apple","orange","banana"};
	typedef unordered_set<string>::iterator It;

	printInfo("myset",myset);

	pair<It,It> ret = myset.equal_range("apple");

	if(ret.first == ret.second)
		cout<<"apple was not in myset\n";
	else
		cout<<*(ret.first)<<" was in myset\n";

	return 0;
}
