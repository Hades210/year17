// file : multisetConstructorCheck.cpp
/************************************************************************************************
*	
*	 template <class T,							//multiset::key_type/value_type
*			  class Compare = less<T>,			//multiset::key_compare/value_compare
*			  class Alloc = allocator<T> >		//mulitset::allocator_type
*			  > class multiset;
************************************************************************************************/
// multisets are typically implemented as binary search trees.
/************************************************************************************************************************************************************
*	empty(1)	explicit multiset(const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type());
*				explicit mulitiset(const allocator_type& alloc);
*	range(2)	template <class InputIterator>
*					multiset(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),const allocator_type& = allocator_type());
*	copy(3)		multiset(const multiset& x);
*				multiset(const multiset& x, const allocator_type& alloc);
*	move(4)		multiset(multiset&& x);
*				multiset(multiset&&x, const allocator_type& alloc);
*	il(5)		multiset(initializer_list<value_type> il, const key_compare& comp =  key_compare(), const allocator_type& alloc = allocator_type());
**************************************************************************************************************************************************************/

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

bool fncomp(int lhs, int rhs)
{
	return lhs < rhs;
}

struct classcomp
{
	bool operator() (const int& lhs, const int& rhs) const
	{
		return lhs < rhs;
	}
};


int main()
{
	multiset<int> first;
	int myints[] = {10,20,30,20,20};
	multiset<int> second (myints, myints + 5);

	multiset<int> third (second);
	multiset<int> fourth(second.begin(),second.end());
	multiset<int,classcomp>fifth(myints,myints + 5);

	bool(*fn_pt)(int,int) = fncomp;
	multiset<int,bool(*)(int,int)>sixth(myints,myints + 5, fn_pt);

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);
	printInfo("sixth",sixth);

	return 0;
}
