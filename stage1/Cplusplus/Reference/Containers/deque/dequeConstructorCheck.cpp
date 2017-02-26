// file : dequeConstructorCheck.cpp
/**********************************************************************************************
*	default (1)		explicit deque(const allocator_type& alloc = allocator_type()); 
*	fill (2)		explicit deque(size_type n);
*							 deque (size_type n, const value_type& val,
*									const allocator_type& alloc = allocator_type());
*	range(3)		template <class InputIterator>
*						deque(InputIterator first, InputIterator last,
*								const allocator_type& alloc = allocator_type());
*	copy(4)			deque(const deque& x);
* 					deque(const deque& x, const allocator_type& alloc);
*	move(5)			deque(deque&& x);
*					deque(deque&& x, const allocator_type& alloc);
*	il(6)			deque(initializer_list<value_type> il,
*							const allocator_type& alloc = allocator_type());
***********************************************************************************************/

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> first ;
	deque<int> second (4,100);
	deque<int> third (second.begin(),second.end());
	deque<int> fourth (third);

	int myints[] = {16, 2, 77, 29};
	deque<int> fifth (myints, myints + sizeof(myints) / sizeof (int));

	printInfo("fifth", fifth);

	return 0;
}	
