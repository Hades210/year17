/*************************************************************************
*  File Name: remove1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 07:54:19 PM CST
*************************************************************************/

#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
	list<int> coll;

	for(int i = 1; i <= 6; ++ i) {
		coll.push_front(i);
		coll.push_back(i);
	}

	cout<<"Pre: \n";
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	remove(coll.begin(),coll.end(),3);

	cout<<"Post: \n";
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	return 0;
}

