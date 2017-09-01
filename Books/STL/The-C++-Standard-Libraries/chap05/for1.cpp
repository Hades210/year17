/*************************************************************************
*  File Name: for1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 09:47:22 PM CST
*************************************************************************/

#include <iostream>
#include <set>
#include <deque>
#include <algorithm>
#include "print.hpp"

using namespace std;

int main()
{
	set<int, greater<int> > coll1;
	deque<int> coll2;

	for(int i = 1; i <= 9; ++ i)
		coll1.insert(i);

	PRINT_ELEMENTS(coll1,"initialized: ");

	transform(coll1.begin(),coll1.end(),back_inserter(coll2),bind2nd(multiplies<int>(),10));
	PRINT_ELEMENTS(coll2,"transformed: ");

	replace_if(coll2.begin(),coll2.end(),bind2nd(equal_to<int>(),70),42);
	PRINT_ELEMENTS(coll2,"replaced: ");

	coll2.erase(remove_if(coll2.begin(),coll2.end(),bind2nd(less<int>(),50)),coll2.end());
	PRINT_ELEMENTS(coll2,"removed: ");

	return 0;
}

