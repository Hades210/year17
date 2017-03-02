// file : priority_queueConstructorCheck.cpp
// template <class T, class Container = vector<T>,
//			class Compare = less<typename Container::value_type> > class priority_queue;
// The underlying container may be any of the standard container class templates or some other specifically
// designed container class. The container shall be accessible through random access iterators and support
// the following operations:
//
//		empty()
//		size()
//		front()
//		push_back()
//		pop_back()
//
// The standard container classes vector and deque fulfill these requirements. By default, if no container class
// is specified for a particular priority_queue class instantiation, the standard container vector is used.
// Support of random access iterators is required to keep a heap structure internally at all times. This is done
// automatically by the container adaptor by automatically calling the algorithm functions make_heap,push_heap and pop_heap when needed.

/****************************************************************************************************************************************** 
*	initialize(1)				priority_queue(const Compare& comp, const Container& ctnr);
*					
*								template <class InputIterator>
*								priority_queue(InputIterator first, InputIterator last,
*	range(2)									const Compare& comp, const Container& ctnr);
*	
*	
*	move-initialize(3)			explicit priority_queue(const Compare& comp = Compare(),
*														Container&& cntr = Container());
*
*	move-range(4)				template <class InputIterator>
*								priority_queue (InputIterator first, InputIterator last,
*												Const Compare& comp, Container&& ctrn = Container());
*	
*	allocator versions(5)		template <class Alloc> explicit priority_queue(Const Alloc& alloc);
*								template <class Alloc> priority_queue(const Compare& comp,const Alloc& alloc);
*								template <class Alloc> priority_queue(const Compare& comp, const Container& ctnr,const Alloc& alloc);
*								template <class Alloc> priority_queue(const priority_queue& x, const Alloc& alloc);
*								template <class Alloc> priority_queue(priority_queue&& x, const Alloc& alloc);
*******************************************************************************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

class myComparison
{
	bool reverse;
public:
	myComparison(const bool& revparam= false)
	{	reverse = revparam; }
	bool operator() (const int& lhs, const int& rhs) const 
	{
		if(reverse) return (lhs > rhs);
		else return (lhs < rhs);
	}
};


int main()
{
	int myints[] = {10, 60, 50, 20};

	priority_queue<int> first;
	priority_queue<int> second(myints,myints + 4);
	priority_queue<int,vector<int>,greater<int> > third (myints, myints + 4);

	typedef priority_queue<int,vector<int>,myComparison> mypq_type;

	mypq_type fourth (myints,myints + 4);
	mypq_type fifth(myints,myints + 4,myComparison(true));

	printInfo("first",first);
	printInfo("second",second);
	printInfo("third",third);
	printInfo("fourth",fourth);
	printInfo("fifth",fifth);

	return 0;
}

