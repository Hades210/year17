// file : setEmplace_hintCheck.cpp
// template <class... Args>
//	iterator emplace_hint(const_iterator position, Args&& ... args);
// If the function successfully inserts the element (because no equivalent element existed already in the set), the function
// returns an itertor to the newly inserted element.
// Otherwise, it returns an iterator to the equivalent element within the container.

#include <iostream>
#include <set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	set<string> myset;
	auto it = myset.cbegin();

	myset.emplace_hint(it,"alpha");
	it = myset.emplace_hint(myset.end(),"omega");
	it = myset.emplace_hint(it,"epsilon");
	it = myset.emplace_hint(it,"beta");

	printInfo("myset",myset);
	return 0;
}
