/*************************************************************************
*  File Name: list1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 04:44:41 PM CST
*************************************************************************/

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<char> coll;

	for(char c = 'a'; c != 'z'; ++c)
		coll.push_back(c);

	cout<<"Output using iterators:\n";
	for(list<char>::iterator it = begin(coll); it != end(coll); ++ it)
		cout<<*it<<" ";
	cout<<endl;

	cout<<"Output using front() and pop_front()\n";
	while(!coll.empty())
	{
		cout<<coll.front()<<" ";
		coll.pop_front();
	}
	cout<<endl;

	return 0;
}
