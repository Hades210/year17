// file : mapInsertCheck.cpp
/**************************************************************************************************************
*	single element(1)	pair<iterator,bool> insert(const value_type& val);
*						template <class P> pair<iterator,bool>insert(P&& val); 		
*	with hint(2)		iterator insert(const_iterator position, const value_type& val);
*						template <class P> iterator insert(const_iterator position, P&& val);
*	range(3)			template <class InputIterator>
*						void insert(InputIterator first, InputIterator last);
*	il(4)				void insert(initializer_list<value_type> il);
***************************************************************************************************************/
// version(1) return a pair, with its memver pair::first set to an iterator pointing to either the newly inserted 
// element or to the element with an equivalent key in the map. The pair::second element in the pair is set to true
// if a new element was inserted or false if an equivalent key already existed.
// The version(2) return an iterator pointing to either the newly inserted element or to the element that already
// had an equivalent key in the map.

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	map<char,int> mymap;

	mymap.insert(pair<char,int>('a',100));
	mymap.insert(pair<char,int>('z',200));

	pair<map<char,int>::iterator,bool> ret;
	ret = mymap.insert(pair<char,int>('z',500));
	if(ret.second== false)
	{
		cout<<"element z already existed";
		cout<<" with a value of "<<ret.first->second<<"\n";
	}

	map<char,int>::iterator it = mymap.begin();
	mymap.insert(it,pair<char,int>('b',300));
	mymap.insert(it,pair<char,int>('c',400));

	map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));

	printInfo("mymap",mymap);

	printInfo("anothermap",anothermap);

	return 0;
}

