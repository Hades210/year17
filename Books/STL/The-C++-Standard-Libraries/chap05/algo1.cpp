/*************************************************************************
*  File Name: algo1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 05:45:54 PM CST
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> coll;
	vector<int>::iterator pos;

	coll.push_back(2);
	coll.push_back(5);
	coll.push_back(4);
	coll.push_back(1);
	coll.push_back(6);
	coll.push_back(3);

	pos = min_element(coll.begin(),coll.end());
	cout<<"min: "<<*pos<<endl;
	pos = max_element(coll.begin(),coll.end());
	cout<<"max: "<<*pos<<endl;

	//sort all elements
	sort(coll.begin(),coll.end());

	pos = find(coll.begin(),coll.end(),3);

	reverse(pos,coll.end());

	for(pos = coll.begin(); pos != coll.end(); ++ pos)
		cout<<*pos<<" ";
	cout<<endl;
	return 0;
}

