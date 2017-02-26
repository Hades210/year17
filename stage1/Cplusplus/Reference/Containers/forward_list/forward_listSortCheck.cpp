// file : forward_listSortCheck.cpp
// void sort();
// template <class Compare>
//   void sort(Compare comp);

#include <iostream>
#include <forward_list>
#include <functional>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	forward_list<int> mylist = {22,13,5,40,90,62,31};

	mylist.sort();

	printInfo("default sort (operator<), mylist",mylist);

	mylist.sort(greater<int>());

	printInfo("sort with greater(), mylist", mylist);

	return 0;
}

