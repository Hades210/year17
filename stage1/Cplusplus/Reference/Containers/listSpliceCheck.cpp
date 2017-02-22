// file : listSpliceCheck.cpp
// Transfer elements from list to list
/*************************************************************************************************************************
*	entire list (1)		void splice(const_iterator position,list& x);
*	entire list (1)		void splice(const_iterator position,list&& x);
*	single element(2)	void splice(const_iterator position,list& x, const_iterator i);
*	single element(2)	void splice(const_iterator position,list&& x, const_iterator i);
*	element range(3)	void splice(const_iterator position,list& x, const_iterator first, const_iterator last);
*	element range(3)	void splice(const_iterator position, list&& x, const_iterator first, const_iterator last);
*************************************************************************************************************************/

// Transfers elements from x into the container, inserting them at position.
// This effectively inserts those elements into the container and removes them from x, altering the sizes of bot
// containers. The operation does not involve the construction or destruction of any element. They are transferred, no
// matter whether x is an lvalue or an rvalue, or whether the value_type supports move-construction or not.

// The first version(1) transfers all the elements of x into the container.
// The second version(2) transfers only the element pointed by i from x into the container.
// The third version(3) transfers the range[first,last) from x into the container.

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist1,mylist2;
	list<int>::iterator it;

	for(int i = 1; i <= 4; ++i)
		mylist1.push_back(i);

	for(int i = 1; i <= 3; ++ i)
		mylist2.push_back(i * 10);

	it = mylist1.begin();
	++ it;

	mylist1.splice(it,mylist2);
	mylist2.splice(mylist2.begin(),mylist1,it);

	it = mylist1.begin();
	advance(it,3);

	mylist1.splice(mylist1.begin(),mylist1,it,mylist1.end());

	cout<<"mylist1 contains:";
	for(auto & x : mylist1)
		cout<<"\t"<<x;
	cout<<endl;

	cout<<"mylist2 contains:";
	for(auto & x : mylist2)
		cout<<"\t"<<x;
	cout<<endl;
	
	return 0;
}

