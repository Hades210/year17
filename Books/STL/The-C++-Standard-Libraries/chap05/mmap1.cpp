/*************************************************************************
*  File Name: mmap1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 05:18:05 PM CST
*************************************************************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{
	typedef multimap<int, string> IntStringMap;

	IntStringMap coll;
	coll.insert(make_pair(5,"tagged"));
	coll.insert(make_pair(2,"a"));
	coll.insert(make_pair(1,"this"));
	coll.insert(make_pair(4,"of"));
	coll.insert(make_pair(6,"strings"));
	coll.insert(make_pair(1,"is"));
	coll.insert(make_pair(3,"multimap"));

	IntStringMap::const_iterator cit;
	for(cit = coll.begin(); cit != coll.end(); ++ cit)
		cout<<cit->second<<" ";
	cout<<endl;
	return 0;
}
