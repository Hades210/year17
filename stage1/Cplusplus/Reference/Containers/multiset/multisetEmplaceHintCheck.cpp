// file : multisetEmplaceHintCheck.cpp
// template <class... Args?
//	iterator emplace_hint(const_iterator position,Args&&... args);

#include <iostream>
#include <set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multiset<string> myset;

	auto it = myset.cbegin();

	myset.emplace_hint(it,"apple");
	it = myset.emplace_hint(myset.cend(),"orange");
	it = myset.emplace_hint(it,"melon");
	myset.emplace_hint(it,"melon");

	printInfo("myset",myset);

	return 0;
}
