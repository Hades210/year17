// file : forward_listRemoveIfCheck.cpp
// template <class Predicate>
//		void remove_if(Predict pred);
// The function calls pred(*it) for each element (where i is an iterator to that element).
// Any of the elements in the list for which this returns true, are removed from the container.

#include <iostream>
#include <forward_list>

#include "../common/common-print.hpp"

using namespace std;

bool single_digit(const int& value) 
{
	return ( value < 10 );
}

class is_odd
{
public:
	bool operator() (const int& value) { return value % 2 ;}
}is_odd_object;

int main()
{
	forward_list<int> mylist = {7,80,7,15,85,52,6};
	
	mylist.remove_if(single_digit);
	printInfo("mylist",mylist);

	mylist.remove_if(is_odd_object);
	printInfo("mylist",mylist);

	return 0;
}

