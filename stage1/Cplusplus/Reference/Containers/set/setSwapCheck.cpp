// file : setSwapCheck.cpp
// void swap(set& x)
// The internal comparison objects must be the same.

#include <iostream>
#include <set>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	int myints[] = {12,75,10,32,20,25};

	set<int,less<int> > first (myints,myints + 3);
	set<int,less<int> > second (myints + 3, myints + 6);

	printInfo("first",first);
	printInfo("second",second);

	cout<<"after swap"<<"\n";

	// first.swap(second);
	swap(first,second);

	printInfo("first",first);
	printInfo("second",second);

	return 0;
}
