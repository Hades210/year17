/*************************************************************************
*  File Name: templateConstructorCheck.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 02:08:25 PM CST
*************************************************************************/

#include <iostream>
using namespace std;

template <class T>
class MyClass
{
	public:
		MyClass(){}
		//copy constructor with implicit type conversion
		//- does not hide implicit copy constructor
		template <class U>
			MyClass(const MyClass<U>& x){cout<<"template constructor called.\n";}

};

int main()
{

	MyClass<double> xd;
	MyClass<double> xd2 (xd); // calls built-in copy constructor
	MyClass<int> xi(xd); //class template constructor

	return 0;
}
