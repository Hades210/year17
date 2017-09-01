/*************************************************************************
*  File Name: remove2.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 08:00:27 PM CST
*************************************************************************/

#include <iostream>
#include <list>
#include <iterator>
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


	list<int>::iterator end = remove(coll.begin(),coll.end(),3);
	copy(coll.begin(),end,ostream_iterator<int>(cout," "));
	cout<<endl;

	cout<<"number of resulting elements "<<distance(end,coll.end())<<endl;
	copy(coll.begin(),coll.end(),ostream_iterator<int>(cout," "));
	cout<<endl;

	return 0;
}

