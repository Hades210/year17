// file : mapSwapCheck.cpp
// void swap(map& x);

#include <iostream>
#include <map>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int,greater<char> > foo,bar;
	
	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	printInfo("foo",foo);
	printInfo("bar",bar);

	swap(foo,bar);
	printInfo("foo",foo);
	printInfo("bar",bar);

	return 0;
}
