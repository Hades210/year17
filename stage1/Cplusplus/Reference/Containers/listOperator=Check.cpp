// file : listOperator=Check.cpp
/********************************************************************
*	copy(1)		list& operator= (const list& x);
*	move(2)		list& operator= (list && x);
*	il (3)		list& operator= (initializer_list<value_type> il);
*********************************************************************/

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> first (3);
	list<int> second (5);

	second = first;
	first = list<int> ();

	cout<<"Size of first: "<<int(first.size())<<"\n";
	cout<<"Size of second: "<<int (second.size())<<"\n";

	return 0;
}
