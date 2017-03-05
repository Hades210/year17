// file : mapClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int> mymap;
	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	printInfo("mymap",mymap);

	mymap.clear();

	mymap['a'] = 1001;
	mymap['b'] = 2002;

	printInfo("mymap",mymap);

	return 0;
}
