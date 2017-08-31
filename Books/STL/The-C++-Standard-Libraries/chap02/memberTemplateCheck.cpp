/*************************************************************************
*  File Name: memberTemplateCheck.cpp
*  Author: JohnMiller
*  Mail: jfmcs_0211@126.com
*  Created Time: Thu 31 Aug 2017 01:56:16 PM CST
*************************************************************************/

#include <iostream>
using namespace std;


template <class T>
class MyClass 
{
	private:
		T value;
	public:
		void assign(const MyClass<T>& x)
		{ // x must have same T as * this
			value = x.value;
		}
};

template <class T>
class MyClass2
{
	private:
		T value;
	public:
		template <class X>
			void assign(const MyClass2<X>& x) 
			{ //allows different template types
				value = x.getValue();
			}
		T getValue() const
		{
			return value;
		}
};
int main()
{
	MyClass<double> d;
	MyClass<int> i;

	d.assign(d); //OK
//	d.assign(i); // ERROR
	MyClass2<double> d2;
	MyClass2<int> i2;

	d2.assign(i2);
	return 0;
}
