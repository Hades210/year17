// file : multimapEraseCheck.cpp
/*******************************************************************************
*	iterator erase(const_iterator position);
*	size_type erase(const key_type& k);
*	iterator erase(const_iterator first, const_iterator last);
*******************************************************************************/
// For the key-based version, the function returns the number of elements erased.
// The other version return an iterator to the element that follows the last element removed.
// (or multimap::end, if the last element was removed).

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<char,int> mymap = {{'a',10},
								{'b',20},
								{'b',30},
								{'c',40},
								{'d',50},
								{'d',50},
								{'e',70},
								{'f',80}};

	multimap<char,int>::iterator it = mymap.find('b');
	mymap.erase(it);
	mymap.erase('d');
	it = mymap.find('e');
	mymap.erase(it,mymap.end());

	printInfo("mymap",mymap);
	
	return 0;
}
