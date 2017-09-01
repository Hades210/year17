/*************************************************************************
*  File Name: remove3.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 08:14:14 PM CST
*************************************************************************/

#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	set<int> coll;

	for(int i = 1; i <= 9; ++ i)
		coll.insert(i);

	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	int num = coll.erase(3);

	cout<<"number of removed elements: "<<num<<endl;

	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	return 0;
}

