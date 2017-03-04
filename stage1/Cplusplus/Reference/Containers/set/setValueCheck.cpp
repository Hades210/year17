// file : setValueCompCheck.cpp
// value_compare value_comp() const;
// Return comparison object
// Returns a copy of the comparison object used by the contaner.
// By default, this is a less object, which returns the same as operator<.
// In set containers, value_comp and its sibling member function key_cop are equivalent.

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int highest;
	set<int> myset;

	set<int>::value_compare mycomp = myset.value_comp();
	for(int i = 0; i <= 5; i ++)
		myset.insert(i);

	highest = *(myset.rbegin());

	auto it = myset.begin();

	do
	{
		cout<<*it<<" ";
	}while(mycomp(*(++it),highest));
	
	cout<<"\n";

	return 0;
}

