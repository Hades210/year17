// file : setConstructorCheck.cpp
// template <class T,class Compare = less<T>, class Alloc = allocator<T> >class set;
// Sets are containers that store unique elements following a specific order.
// Sets are typically implemented as binary search trees.

/****************************************************************************************************
*	empty(1)	explicit set(const key_compare& comp = key_compare(),
*							const allocator_type& alloc = allocator_type());
*				explicit set(const allocator_type& alloc);
*	range(2)	template <class InputIterator>
*				set(InputIterator first, InputIterator last,
*					const key_compare& comp = key_compare(),
*					const allocator_type& alloc = allocator_type());
*	copy(3)		set(const set& x);
*				set(const set& x, const allocator_type& alloc);
*	move(4)		set(set&& x);
*				set(set&& x,const allocator_type& alloc);
*	il(5)		set(initializer_list<value_type> il,
*					const key_compare& comp = key_compare(),
*					const allocator_type alloc = allocator_type());
****************************************************************************************************/

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
	set<int> first;
	int myints[] = {50,30,20,10,40};
	set<int> second(myints, myints + 5);
	set<int> third (second);
	set<int> fourth(second.begin(),second.end());
	set<int,classcomp> fifth;

	bool(*fn_pt)(int,int) = fncomp;
	set<int,bool(*)(int,int)> sixth(myints,myints + 5,fn_pt);

	cout<<"first size :" << first.size()<<"\n";
	cout<<"second size: "<<second.size()<<"\n";
	cout<<"thrid size: "<<third.size()<<"\n";
	cout<<"fourth size: "<<fourth.size()<<"\n";

	cout<<"fifth size: "<<fifth.size()<<"\n";
	cout<<"sixth size: "<<sixth.size()<<"\n";

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);
	printInfo("sixth",sixth);

	return 0;
}
