/*************************************************************************
*  File Name: set1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 05:09:08 PM CST
*************************************************************************/

#include <iostream>
#include <set>

using namespace std;

int main()
{
	typedef set<int> IntSet;

	IntSet coll;

	coll.insert(3);
	coll.insert(1);
	coll.insert(5);
	coll.insert(4);
	coll.insert(1);
	coll.insert(6);
	coll.insert(2);

	IntSet::const_iterator cit;
	for(cit = coll.begin(); cit != coll.end(); ++cit)
		cout<<*cit<<" ";
	cout<<endl;
	return 0;
}
