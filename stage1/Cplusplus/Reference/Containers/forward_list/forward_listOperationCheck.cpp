// file : forward_listOperationCheck.cpp
/*************************************************************************
*	copy(1)		forward_list& operator= (const forward_list& fwdlst);
*	move(2)		forward_list& operator= (const forward_list& fwdlst);
*	il(3)		forward_list& operator= (initializer_list<value_type> il);
**************************************************************************/
/*************************************************************************
*In the fist assignment, second is an lvalue: the copy assignment function 
*is called. In the second assignment, the value returned by by_two(first) 
*is an rvalue: the move assignment function is called.
**************************************************************************/
#include <iostream>
#include <forward_list>

using namespace std;

template <class Container>
Container by_two (const Container& x)
{
	Container temp(x);
	for(auto & i : temp ) i *= 2; return temp;
}

int main()
{
	forward_list<int> first(4);
	forward_list<int> second(3,5);

	first = second; // copy assignment
	second = by_two(first); // move assignment

	cout<<"first: ";
	for(int& x : first)
		cout<<x<<"\t";
	cout<<endl;

	cout<<"second: ";
	for(int& x : second)
		cout<<x<<"\t";
	cout<<endl;

	return 0;
}
