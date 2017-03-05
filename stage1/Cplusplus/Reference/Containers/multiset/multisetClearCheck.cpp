// file : multisetClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multiset<int> myset;

	myset.insert(11);
	myset.insert(42);
	myset.insert(11);

	printInfo("myset",myset);

	myset.clear();

	myset.insert(1101);
	myset.insert(2202);

	printInfo("myset",myset);
	
	return 0;
}
