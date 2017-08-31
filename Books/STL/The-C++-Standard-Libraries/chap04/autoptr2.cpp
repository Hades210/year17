/*************************************************************************
*  File Name: autoptr2.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 04:56:44 PM CST
*************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

template <class T>
ostream& operator<< (ostream& out, const auto_ptr<T>& p) {
	if(p.get() == NULL)	out<<"NULL";
	else				out<<*p;
	return out;
}

int main()
{
	const auto_ptr<int> p (new int(42));
	const auto_ptr<int> q (new int(0));
	const auto_ptr<int> r;

	cout<<"after initialization:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;
	cout<<"r: "<<r<<endl;

	*q = *p;
	*p = -77;
	cout<<"after assigning values:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;
	cout<<"r: "<<r<<endl;

//	q = p; ERROR at compile time
	return 0;
}
