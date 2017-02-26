// file : forward_listSwapCheck2.cpp
// template <class T, class Alloc>
//		void swap(forward_list<T,Alloc>& x, forward_list<T,Alloc>& y);

#include <iostream>
#include <forward_list>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	forward_list<int> first = {10,20,30};
	forward_list<int> second = {100,200};

	swap(first,second);

	printInfo("first",first);
	printInfo("second",second);
	 
	return 0;
}
