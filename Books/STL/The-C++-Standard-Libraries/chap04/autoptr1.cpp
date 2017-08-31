/*************************************************************************
*  File Name: autoptr1.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 04:45:49 PM CST
*************************************************************************/

#include <iostream>
#include <memory>

using namespace std;

template <class T>
ostream& operator<<(ostream& out, const auto_ptr<T>& p)
{
	if(p.get() == NULL)		out<<"NULL";
	else					out<<*p;
	return out;
}

int main()
{
	auto_ptr<int> p (new int(42));
	auto_ptr<int> q;

	cout<<"after initialization:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;

	q = p;
	cout<<"after assigning auto pointers:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;

	*q += 13;
	p = q;
	cout<<"after change and reassignment:"<<endl;
	cout<<"p: "<<p<<endl;
	cout<<"q: "<<q<<endl;

	return 0;
}
