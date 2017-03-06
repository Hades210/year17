// file : multimapClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<char,int> mymap;
	multimap<char,int>::iterator it;

	mymap.insert(pair<char,int>('b',80));
	mymap.insert(pair<char,int>('b',120));
	mymap.insert(pair<char,int>('q',360));

	printInfo("mymap",mymap);

	mymap.clear();
	mymap.insert(pair<char,int>('a',11));
	mymap.insert(pair<char,int>('b',22));

	printInfo("mymap",mymap);
	
	return 0;
}
