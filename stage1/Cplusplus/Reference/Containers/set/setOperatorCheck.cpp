// file: setOperatorCheck.cpp
// copy(1)	set& operator= (const set& x);
// move(2)	set& operator= (set&& x);
// il(3) 	set& operator= (initializer_list<value_type> il);

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	int myints[] = {12,82,37,64,15};

	set<int> first (myints, myints + 5);
	set<int> second;

	second = first;
	first = set<int>();

	cout<<"size of first: "<<first.size()<<"\n";
	cout<<"size of second: "<<second.size()<<"\n";

	printInfo("first",first);
	printInfo("second",second);

	return 0;
}
