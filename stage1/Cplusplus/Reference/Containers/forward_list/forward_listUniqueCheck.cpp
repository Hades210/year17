// file : forward_listUniqueCheck.cpp
// void unique();
// template <class BinaryPredicate>
//		void unique(BinaryPredicate binary_pred);

#include <iostream>
#include <cmath>
#include <forward_list>

#include "../common/common-print.hpp"

using namespace std;

bool same_integral_part(double first, double second)
{
	return ((int) first == (int) second);
}

class is_near_class
{
public:
	bool operator() (double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
}is_near_object;

int main()
{
	forward_list<double> mylist = {15.2,73.0,3.14,15.85,69.5,73.0,3.99,15.2,69.2,18.5};

	printInfo("Ariginal mylist",mylist);
	
	mylist.sort();
	printInfo("After sort",mylist);

	mylist.unique();
	printInfo("unique",mylist);

	mylist.unique(same_integral_part);
	printInfo("same_integral_part",mylist);

	mylist.unique(is_near_object);
	printInfo("is_near_object",mylist);
	
	return 0;
}
