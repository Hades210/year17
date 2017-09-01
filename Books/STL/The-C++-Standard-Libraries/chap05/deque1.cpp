/*************************************************************************
*  File Name: deque1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 04:37:40 PM CST
*************************************************************************/

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<float> coll;

	for(int i = 1; i <= 6; ++ i)
		coll.push_front( 1.1 * i);

	for(int i = 0; i < coll.size(); ++ i)
		cout<<coll[i]<<" ";
	cout<<endl;

	return 0;
}
