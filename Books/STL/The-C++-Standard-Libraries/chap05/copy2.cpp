/*************************************************************************
*  File Name: copy2.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 06:05:34 PM CST
*************************************************************************/

#include <iostream>
#include <vector>
#include <list>
#include <deque>

#include <algorithm>


using namespace std;

int main()
{
	list<int> coll1;
	vector<int> coll2;
	
	for(int i = 1; i <= 9; ++ i)
		coll1.push_back(i);

	coll2.resize(coll1.size());

	copy(coll1.begin(),coll1.end(),coll2.begin());

	deque<int> coll3(coll1.size());
	copy(coll1.begin(),coll1.end(),coll3.begin());

	list<int> ::iterator lit;
	vector<int>::iterator vit;
	deque<int>::iterator dit;

	for(lit = coll1.begin(); lit != coll1.end(); ++ lit)
		cout<<*lit<<" ";
	cout<<endl;

	for(vit = coll2.begin(); vit != coll2.end(); ++ vit)
		cout<<*vit<<" ";
	cout<<endl;

	for(dit = coll3.begin(); dit != coll3.end(); ++ dit)
		cout<<*dit<<" ";
	cout<<endl;

	
}
