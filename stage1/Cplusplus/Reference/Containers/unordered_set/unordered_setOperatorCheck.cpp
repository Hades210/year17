// file : unordered_setOperatorCheck.cpp
/***********************************************************************************
*	copy(1) 	unordered_set& operator= (const unordered_set& ust);
*	move(2)		unordered_set& operator= (unordered_set&& ust);
*	il(3)		unordered_set& operator= (initializer_list<value_type> il);
************************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>

#include "../common/common-print.hpp"

using namespace std;

template <class T>
T cmerge(T a, T b)
{
	T t(a); t.insert(b.begin(),b.end()); return t;
}

int main()
{
	unordered_set<string> first,second,third;
	first =  {"red","green","blue"};
	second = {"orange","pink","yellow"};

	third = cmerge(first,second);
	first = third;

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);

	return 0;
}
