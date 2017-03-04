// file : setKeyCompCheck.cpp
// key_compare key_comp() const;
// Return the comparision object.
// Returns a copy of the comparison object used by the container.
// By default, this is a less object, which returns the same as operator<
// In set containers, value_comp and its sibling member function key_comp are equivalent.

#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> myset;

	int highest;

	set<int>::key_compare mycomp = myset.key_comp();

	for(int i = 0; i <= 5; i ++)
		myset.insert(i);

	cout<<"myset contains: ";

	highest = *myset.rbegin();

	set<int>::iterator it = myset.begin();

	do
	{
		cout<<" "<<*it;
	}while(mycomp(*(++it),highest));

	cout<<"\n";

	return 0;
}
