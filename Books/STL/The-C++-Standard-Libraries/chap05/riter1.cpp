/*************************************************************************
*  File Name: riter1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 07:40:14 PM CST
*************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<int> coll;

	copy(istream_iterator<int>(cin),istream_iterator<int>(),back_inserter(coll));

	copy(coll.rbegin(),coll.rend(),ostream_iterator<int>(cout," "));
	cout<<endl;
	return 0;
}
