// file : unordered_setEmplaceCheck.cpp
// template <class... Args> pair<iterator,bool> emplace(Args&&... args);
// template <class... Args> iterator emplace_hint(const_iterator position, Args&&... args);
// If the insertion takes place(because no other element existed with the same value),the function returns an iterator to the inerted element.
// Otherwise, it returns an iterator pointing to the element in the container that compared equivalent to it.

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> myums;

	pair<unordered_set<string>::iterator,bool> ret;

	myums.emplace("milk");
	myums.emplace("tea");
	myums.emplace("coffee");
	ret = myums.emplace("milk");

	if(ret.second == false)
		cout<<*(ret.first)<<" already existed.\n";

	printInfo("myums",myums);

	return 0;
}
