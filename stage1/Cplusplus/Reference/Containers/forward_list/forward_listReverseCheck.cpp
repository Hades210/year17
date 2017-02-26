// file : forward_listReverseCheck.cpp
// void reverse() noexcept;

#include <iostream>
#include <forward_list>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	forward_list<int> mylist = {10, 20, 30, 40};

	printInfo("Ariginal mylist",mylist);

	mylist.reverse();

	printInfo("Reverse mylist",mylist);
	
	return 0;
}
