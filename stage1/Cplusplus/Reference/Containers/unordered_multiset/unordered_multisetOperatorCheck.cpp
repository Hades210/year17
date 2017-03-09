// file : unordered_multisetOperatorCheck.cpp
/***************************************************************************************
*	copy(1)		unordered_multiset& operator= (const  unordered_multiset& ums)
*	move(2)		unordered_multiset& operator= (unordered_multiset&& ums);
*	il(3)		unordered_multiset& operator= (initializer_list<value_type> il);
****************************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

template <class T>
T cmerge(T a, T b)
{
	T t(a);
	t.insert(b.begin(),b.end());
	return t;
}

int main()
{
	unordered_multiset<string> first, second, third;

	first = {"red","green","blue"}; // init list
	second = {"red","yellow","blue"}; // init list
	third = cmerge(first,second); // move
	first = third; // copy

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	return 0;
}

