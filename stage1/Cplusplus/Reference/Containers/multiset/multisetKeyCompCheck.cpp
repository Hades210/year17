// file : multisetKeyCompCheck.cpp
// key_compare key_comp() const;
// value_compare value_comp() const;
// Returns a copy of the comparision object used by the container. By default, this is a less object, which returns the same as operator<.
// In multiset container, the keys to sort the elements are the values themselves, therefore key_comp and its sibling member function value_comp are equivalent.

#include <iostream>
#include <set>

using namespace std;

int main()
{
	multiset<int> myset;

	for(int i = 0; i < 5; i ++)
		myset.insert(i);

	multiset<int>::key_compare mycomp = myset.key_comp();

	cout<<"myset contains: ";

	int highest = * myset.rbegin();

	multiset<int>::iterator it = myset.begin();

	do
	{
		cout<<*it<<" ";
	}while(mycomp(*(++it),highest));

	cout<<"\n";

	multiset<int, greater<int> > myset2;

	for(int i = 5; i >= 0; i --)
		myset2.insert(i);

	multiset<int,greater<int> > ::value_compare mycomp2 = myset2.value_comp();

	cout<<"myset2 contains: ";
	int lowest = * myset2.rbegin();

	multiset<int,greater<int> >::iterator it2 = myset2.begin();

	do
	{
		cout<<*it2<<" ";
	}while(mycomp2(*(++it2),lowest));
	cout<<"\n";

	return 0;
}
