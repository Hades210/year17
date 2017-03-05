// file : mapEraseCheck.cpp
/***************************************************************************
*	iterator erase(const_iterator position);
*	size_type erase(const key_type& k);
*	iterator erase(const_iterator first, const_iterator last);
****************************************************************************/
#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int> mymap;
	map<char,int>::iterator it;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase(it);

	mymap.erase('c');

	it = mymap.find('e');
	mymap.erase(it,mymap.end());

	printInfo("mymap",mymap);
	
	return 0;
}
