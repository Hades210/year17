// file : setLower_boundCheck.cpp
/**************************************************************************************************************************
// iterator lower_bound(const value_type& val);
// const_iterator lower_bound(const value_type& val) const;
// Returns an iterator pointing to the first element in the container which is not considered to go before val
// (either it is equivalent or goes after)
// The function uses its internal comparison object to determine this, returning an itertor to the first element 
// for which key_comp(element,val) would return false.
**************************************************************************************************************************/
/**************************************************************************************************************************
// iterator upper_bound(const value_type& val);
// const_iterator upper_bound(const value_type& val) const;
// Returns an iterator pointing to the first element in the container which is considered to go after val
// The function uses its internal comparision object to determine this, returning an iterator to the first element
// for which key_comp(element,val) would return true.
// If the set class key_comp is less, the function returns an iterator to the first element that is greater than val.
**************************************************************************************************************************/

#include <iostream>
#include <set>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	set<int> myset;
	set<int>::iterator itlow,itup;

	for(int i = 1; i < 10; i ++)
		myset.insert(i * 10);

	itlow = myset.lower_bound(30);
	itup = myset.upper_bound(60);

	myset.erase(itlow,itup);

	printInfo("myset",myset);

	set<int, greater<int> > myset2;
	set<int, greater<int> >::iterator itlow2,itup2;

	for(int i = 1; i < 10; i ++)
		myset2.insert(i * 10);

	printInfo("myset2",myset2);

	itlow2 = myset2.lower_bound(30);
	cout<<*itlow2<<"\n";

	itup2 = myset2.upper_bound(60);
	cout<<*itup2<<"\n";

	myset2.erase(itup2,itlow2);

	printInfo("myset2",myset2);

	return 0;
}
