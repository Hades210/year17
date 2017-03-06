// file : multimapFindCheck.cpp
// iterator find(const key_type& k);
// const_iterator find(const key_type& k) const;

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<char,int> mymap;

	mymap.insert(make_pair('x',10));
	mymap.insert(make_pair('y',20));
	mymap.insert(make_pair('z',30));
	mymap.insert(make_pair('z',40));

	multimap<char,int>::iterator it = mymap.find('x');
	mymap.erase(it);
	mymap.erase(mymap.find('z'));

	printInfo("mymap",mymap);

	return 0;
}
