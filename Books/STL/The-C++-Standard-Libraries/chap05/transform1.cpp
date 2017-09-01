/*************************************************************************
*  File Name: transform1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 08:40:56 PM CST
*************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "print.hpp"

using namespace std;

int square(int value) {
	return value*value;
}

int main()
{
	set<int> coll1;
	vector<int> coll2;

	for(int i = 1; i <= 9; ++ i)
		coll1.insert(i);

	PRINT_ELEMENTS(coll1,"initialized: ");

	std::transform(coll1.begin(),coll1.end(),std::back_inserter(coll2),square);

	PRINT_ELEMENTS(coll2,"squared: ");
	return 0;
}

