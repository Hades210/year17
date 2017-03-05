// file : multisetSwapCheck.cpp
// void swap(multiset& x);

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	int myints[] = {19,72,4,36,20,20};
	multiset<int> first (myints, myints + 3);
	multiset<int> second (myints + 3, myints + 6);

	first.swap(second);

	printInfo("first",first);
	printInfo("second",second);

	swap(first,second);
	printInfo("first",first);
	printInfo("second",second);
	return 0;
}
