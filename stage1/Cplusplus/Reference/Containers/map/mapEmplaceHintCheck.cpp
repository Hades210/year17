// file : mapEmplaceHintCheck.cpp
// template <class... Args>
//	iterator emplace_hint(const_iterator position, Args&&... args);

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int> mymap;
	auto it = mymap.end();

	it = mymap.emplace_hint(it,'b',10);
	mymap.emplace_hint(it,'a',12);
	mymap.emplace_hint(mymap.end(),'c',14);

	printInfo("mymap",mymap);
	
	return 0;
}
