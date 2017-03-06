// file : multimapSwapCheck.cpp
// void swap(multimap& x);

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<char,int> foo,bar;

	foo.insert(make_pair('a',11));
	foo.insert(make_pair('b',22));
	foo.insert(make_pair('a',55));

	bar.insert(make_pair('x',100));
	bar.insert(make_pair('y',200));

	foo.swap(bar);

	printInfo("foo",foo);
	printInfo("bar",bar);

	swap(foo,bar);
	printInfo("foo",foo);
	printInfo("bar",bar);
	
	return 0;
}
