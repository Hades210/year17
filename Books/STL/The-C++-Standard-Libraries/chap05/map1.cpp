/*************************************************************************
*  File Name: map1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 05:25:10 PM CST
*************************************************************************/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	typedef map<string, float> StringFloatMap;

	StringFloatMap coll;

	coll["VAT"] = 0.15;
	coll["Pi"] = 3.1415;
	coll["an arbitrary number"] = 4983.223;
	coll["Null"] = 0;

	StringFloatMap::const_iterator cit;

	for(cit = coll.begin(); cit != coll.end(); ++ cit)
	{
		cout<<"Key: \""<<cit->first<<"\"  "
			<<"Value: "<<cit->second<<endl;
	}
	cout<<endl;
	return 0;
}

