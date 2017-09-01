/*************************************************************************
*  File Name: vector1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 04:33:51 PM CST
*************************************************************************/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<int> coll;

	for(int i = 1; i <= 6; ++ i)
		coll.push_back(i);

	for(int i = 0; i < coll.size(); ++i)
		cout<<coll[i]<<" ";

	cout<<endl;
	return 0;
}
