/*************************************************************************
*  File Name: foreach2.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Fri 01 Sep 2017 09:11:10 PM CST
*************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PrintInt {
	public:
		void operator() (int elem) {
			cout<<elem<<" ";
		}
};

int main()
{
	vector<int> coll;
	for(int i = 1; i <= 9; ++ i)
		coll.push_back(i);

	for_each(coll.begin(),coll.end(), PrintInt());
	cout<<endl;
	return 0;
}

