// file : stackConstructorCheck.cpp
// template <class T, class Container = deque<T> > class stack;
/***********************************************************************************
* The underlying container may be any of the standard container class templates or 
* some other specifically designed container class. The container shall support the
* following operations:
*
*	empty
*	size
*	back
*	push_back
*	pop_back
*
* The standard container classes vector,deque and list fulfill these requirements. By
* default, if no container class is specified for a particular stack class 
* instantiation, the standard container deque is used.
************************************************************************************/

/*************************************************************************************************************
*		 initialize (1)			explicit stack (const container_type& ctnr);
*	 move-initialize(2)			explicit stack (container_type && cntr = container_type());
*	   	   allocator(3)			template <class Alloc> explicit stack(const Alloc& allloc);
*	 init+ allocator(4)			templlate <class Alloc> stack(const container_type& cntr, const Alloc& alloc);
*move-init+allocator(5)			template <class Alloc> stack(container_type&& ctnr,const Alloc& alloc);
*	copy + allocator(6)			template <class Alloc> stack (const stack& x, const Alloc& alloc);
*   move + allocator(7)			template <class Alloc> stack (stack&& x, const Alloc& alloc);
***************************************************************************************************************/

#include <iostream>
#include <vector>
#include <deque>
#include <stack>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque (3,100);
	vector<int> myvector(2,200);

	stack<int> first;  //empty
	stack<int> second(mydeque);  //stack initialized to copy of deque

	stack<int,vector<int> > third; //empty stack using vector
	stack<int,vector<int> > fourth(myvector);

	cout<<"size of first: "<<first.size()<<"\n";
	cout<<"size of second: "<<second.size()<<"\n";
	cout<<"size of third: "<<third.size()<<"\n";
	cout<<"size of fourth:" <<fourth.size()<<"\n";
	
	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);

	return 0;
}
