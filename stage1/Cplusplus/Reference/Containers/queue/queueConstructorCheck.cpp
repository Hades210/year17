// file : queueConstructorCheck.cpp
// template <class T, class Container = deque<T> > class queue;
/***********************************************************************************
* The underlying container may be any of the standard container class templates or 
* some other specifically designed container class. The container shall support the
* following operations:
*
*	empty
*	size
*	front
*	back
*	push_back
*	pop_front
*
* The standard container classes deque and list fulfill these requirements. By
* default, if no container class is specified for a particular queue class 
* instantiation, the standard container deque is used.
************************************************************************************/

/*************************************************************************************************************
*		 initialize (1)			explicit queue (const container_type& ctnr);
*	 move-initialize(2)			explicit queue (container_type && cntr = container_type());
*	   	   allocator(3)			template <class Alloc> explicit queue(const Alloc& allloc);
*	 init+ allocator(4)			templlate <class Alloc> queue(const container_type& cntr, const Alloc& alloc);
*move-init+allocator(5)			template <class Alloc> queue(container_type&& ctnr,const Alloc& alloc);
*	copy + allocator(6)			template <class Alloc> queue (const queue& x, const Alloc& alloc);
*   move + allocator(7)			template <class Alloc> queue (queue&& x, const Alloc& alloc);
***************************************************************************************************************/

#include <iostream>
#include <queue>
#include <list>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque(2,100);
	list<int> mylist (3,50);

	queue<int> first;
	queue<int> second(mydeque); 

	queue<int,list<int> > third;
	queue<int,list<int> > fourth (mylist);

	cout<<"first size "<<first.size()<<"\n";
	cout<<"second size "<<second.size()<<"\n";
	cout<<"third size "<<third.size()<<"\n";
	cout<<"fourth size "<<fourth.size()<<"\n";

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	
	return 0;
}
