// file : multisetEmplaceCheck.cpp
// template <class... Args>
//	iterator emplace(Args&&... args);
// The relative ordering of equivalent elements is preserved, and newly inserted elements follow their equivalents already in the congtainer.

#include <iostream>
#include <set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multiset<string> myset;

	myset.emplace("foo");
	myset.emplace("bar");
	myset.emplace("foo");

	printInfo("myset",myset);
	
	return 0;
}
