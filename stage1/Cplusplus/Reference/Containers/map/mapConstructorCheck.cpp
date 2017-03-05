// file : mapConstructorCheck.cpp
/*************************************************************************************************
*	template <class Key,										//map::key_type
*			  class T,											//map::mapped_type
*			  class Compare = less<Key>,						//map::key_compare
*			  class Alloc = allocator<pair<const Key,T> >		//map::allocator_type
*			  > class map;
**************************************************************************************************/
// In a map, the key values are generally used to sort and uniquely identify the element, while the mapped values store
// the content associated to this key. The types of key and mapped value may differ, and are grouped together in member
// type value_type, which is a pair type combining both:
//			typedef pair<const Key, T> value_type;
// The mapped values in a map can be accessed directly by their corresponding key using the bracket operator(operator[])
// Maps are typically implemented as binary search trees.

/************************************************************************************************************************
*	empty(1)	explicit map(const key_compare& comp = key_compare, const allocator_type& alloc = allocator_type());
*				explicit map(const allocator_type& alloc);
*	range(2)	template <class InputIterator>
*					map(InputIterator first, InputIterator last,
*						 const key_compare& comp = key_compare, const allocator_type& = allocator_type());
*	copy(3)		map(const map& x);
*				map(const map& x, const allocator_type& alloc);
*	move(4)		map(map&& x);			
*				map(map&& x, const allocator_type& alloc);
*	il(5)		map(initializer_list<value_type> il,
*					 const key_compare& comp = key_compare(), const allocator_type & alloc = allocator_type());
*************************************************************************************************************************/

#include <iostream>
#include <map>

#include "../common/common-print.hpp"

using namespace std;

bool fncomp(char lhs, char rhs)
{
	return lhs > rhs;
}

struct classcomp
{
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs > rhs;
	}
};

int main()
{
	map<char,int> first;
	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	map<char,int> second (first.begin(),first.end());
	map<char,int> third(second);
	map<char,int,classcomp> fourth (first.begin(),first.end());

	bool(*fn_pt)(char,char) = fncomp;
	map<char,int,bool(*)(char,char)>fifth(first.begin(),first.end(),fn_pt);

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);

	return 0;
}
