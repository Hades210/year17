// file : multimapConstructorCheck.cpp
/****************************************************************************************************
*	template <class Key,									//multimap::key_type
*			  class T,										//multimap::mapped_type
*			  class Compare = less<Key>,					//multimap::key_compare				
*			  class Alloc = allocator<pair<const Key,T> >	//multimap::allocator_type
*			 > class multimap;
*****************************************************************************************************/
// The types of key and mapped value may differ, and are grouped together in member type value_type,
// which is a pair type combining both:
//										typedef pair<const Key,T> value_type;
// multimaps are typically implemented as binary search trees.
/***************************************************************************************************************************************
*	empty(1)	explicit multimap(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
*				explicit multimap(const allocator_type& alloc);
*	range(2)	template <class InputIterator>
*					multimap(InputIterator first, InputIterator last,
*							 const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
*	copy(3)		multimap(const multimap& x);
*				multimap(const multimap& x, const allocator_type& alloc);
*	move(4)		multimap(multimap&& x);
*				multimap(multimap&& x, const allocator_type& alloc);
*	il(5)		multimap(initializer_list<value_type> il,
*						 const key_compare& comp = key_compare(),
*						 const allocator_type& alloc = allocator_type());
****************************************************************************************************************************************/

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

bool fncomp(char lhs, char rhs) { return lhs > rhs; }

struct classcomp
{
	bool operator() (const char& lhs, const char& rhs) { return lhs > rhs; }
};

int main()
{
	multimap<char,int> first;

	first.insert(pair<char,int>('a',10));
	first.insert(pair<char,int>('b',15));
	first.insert(pair<char,int>('b',20));
	first.insert(pair<char,int>('c',25));

	multimap<char,int> second(first.begin(),first.end());
	multimap<char,int> third(second);

	multimap<char,int,classcomp> fourth(second.begin(),second.end());

	bool(*fn_pt)(char,char) = fncomp;
	multimap<char,int,bool(*)(char,char)> fifth(second.begin(),second.end(),fn_pt);

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);

	return 0;
}

