// file : setClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	set<int> myset;

	myset.insert(100);
	myset.insert(200);
	myset.insert(300);

	printInfo("myset",myset);

	myset.clear();

	myset.insert(1001);
	myset.insert(2002);

	printInfo("myset",myset);

	return 0;
}

