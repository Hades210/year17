// file : multimapInsert.cpp
/***************************************************************************************************************************
*	single element (1)		iterator insert(const value_type& val);
*							template <class P> iterator insert(P&& val);
*	with hint(2)			iterator insert(const_iterator position,const value_type& val);
*							template <class P> iterator insert(const_iterator position, P&& val);
*	range(3)				template <class InputIterator>
*								void insert(InputIterator first, InputIterator last);
*	il(4)					void insert(initializer_list<value_type> il);
****************************************************************************************************************************/
// In the versions returning a value, this is an iterator pointing to the newly inserted element in the multiset.

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multimap<char,int> mymap;
	multimap<char,int>::iterator it;

	mymap.insert(pair<char,int>('a',100));
	mymap.insert(pair<char,int>('z',150));
	it = mymap.insert(pair<char,int>('b',75));

	mymap.insert(it,pair<char,int>('c',300));
	mymap.insert(it,pair<char,int>('z',400));

	multimap<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	printInfo("mymap",mymap);
	printInfo("anothermap",anothermap);

	return 0;
}
