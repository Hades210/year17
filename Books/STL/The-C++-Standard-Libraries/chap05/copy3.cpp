/*************************************************************************
*  File Name: copy3.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 06:58:16 PM CST
*************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

template <class InputIterator>
void Output(InputIterator begin, InputIterator end) {
	for(InputIterator it = begin; it != end; ++ it)
		cout<<*it<<" ";
	cout<<endl;
}

int main()
{
	list<int> coll1;
	vector<int>coll2;
	deque<int> coll3;
	set<int> coll4;

	for(int i = 1; i <= 9; ++ i)
		coll1.push_back(i);

	// copy the elements of coll1 into coll2 by appending them 
	copy(coll1.begin(),coll1.end(),back_inserter(coll2));

	// copy the elements of coll1 into coll3 by inserting them at the front - reverses the order of the elements
	copy(coll1.begin(),coll1.end(),front_inserter(coll3));

	// copy the elements of coll1 into coll4
	// - only inserter that works for associative collections
	copy(coll1.begin(),coll1.end(),inserter(coll4,coll4.begin()));

	Output<vector<int>::iterator> (coll2.begin(),coll2.end());
	Output<list<int>::iterator> (coll1.begin(),coll1.end());
	Output<deque<int>::iterator>(coll3.begin(),coll3.end());
	Output<set<int>::iterator>(coll4.begin(),coll4.end());

	return 0;
}
