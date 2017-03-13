// file : unordered_multimapOperatorCheck.cpp
/**************************************************************************************
*	copy(1)		unordered_multimap& operator= (const unordered_multimap& umm);
*	move(2)		unordered_multimap& operator= (unordered_multimap&& umm);
*	il(3)		unordered_multimap& operator= (initializer_list<value_type> il);
***************************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

typedef unordered_multimap<string,string> UMMSTR;

UMMSTR merge(UMMSTR a, UMMSTR b)
{
	UMMSTR t (a);
	t.insert(b.begin(),b.end());
	return t;
}

int main()
{
	UMMSTR first,second,third;

	first = {{"apple","red"},{"orange","orange"},{"lemon","yellow"}}; //init list
	second = {{"banana","yellow"},{"apple","green"},{"pear","green"}}; // init list

	third = merge(first,second); // move
	first = third;

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);

	return 0;
}
