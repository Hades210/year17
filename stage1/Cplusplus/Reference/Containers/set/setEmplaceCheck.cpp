// file : setEmplaceCheck.cpp
// template <class... Args>
//	pair<iterator,bool> emplace(Args&& ... args);
// If the function successfully inserts the element (because no equivalent element existed already in the set),
// the function returns a pair of an iterator to the newly inserted element and a value of true.
// Otherwise, it returns an iterator to the newly inserted element and a value of true.

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	set<string> myset;

	myset.emplace("foo");
	myset.emplace("bar");

	auto ret = myset.emplace("foo");

	if(!ret.second)
		cout<<"foo already exists in myset\n";
	
	return 0;
}
