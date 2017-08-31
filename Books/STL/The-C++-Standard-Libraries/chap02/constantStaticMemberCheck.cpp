/*************************************************************************
*  File Name: constantStaticMemberCheck.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 02:44:06 PM CST
*************************************************************************/

#include <iostream>
using namespace std;

class MyClass
{
	public:
	static const int num = 10;
	private:
	int elems[num];
	
	public:
	MyClass()
	{
		for(int i = 0; i < num; ++ i)
		{
			elems[i] = i;
		}
	}

	void printInfo()
	{
		for(int i = 0; i < num; ++ i)
			cout<<elems[i]<<" ";
		cout<<endl;
	}

};

const int MyClass::num;

int main()
{
	MyClass m;
	m.printInfo();
	cout<<MyClass::num<<endl;
	return 0;
}
