/*************************************************************************
*  File Name: remove4.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 08:20:50 PM CST
*************************************************************************/

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	list<int> coll;

	for(int i = 1; i <= 6; ++ i)
	{
		coll.push_front(i);
		coll.push_back(i);
	}

	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	coll.erase(remove(coll.begin(),coll.end(),3),coll.end());
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	coll.remove(4);
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;
	return 0;
}

