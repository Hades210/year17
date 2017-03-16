// file : listUniqueCheck.cpp
//		(1)		 void unique();
// 		(2)		template <class BinaryPredicate>
//					void unique(BinaryPredicate binary_pred);
//
// Remove duplicate values
//
// The version (1) removes all but the first element from every consecutive group of equal elements in the container.
//
// The version(2) will call binary_pred(*it, *(it - 1)) for all pairs of elements and remove i from the list if the predicate returns true.
//
// Notice that an element is only removed from the list container if it compares equal to the element immediately preceding it. Thus, this function is especially used for sorted lists.

#include <iostream>
#include <list>
#include <cmath>

using namespace std;

template <class T>
void printList(const list<T> & mylist) 
{
	cout<<"mylist contains";
	for( auto & x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";
}


bool same_integral_part(double first, double second)
{
	return ((int)(first) == (int) (second));
}

struct is_near
{
	bool operator() (double first, double second)
	{
		return fabs(first-second) < 5.0;
	}
};

int main()
{
	double mydoubles[] = {12.15,2.72,73.0,12.77,3.14,12.77,73.35,72.25,15.3,72.25};
	list<double> mylist (mydoubles,mydoubles + 10);

	mylist.sort();

	cout<<"After sort:\n";
	printList(mylist);

	mylist.unique();
	cout<<"After default unique:\n";
	printList(mylist);

	mylist.unique(same_integral_part);
	cout<<"After same_integral_part unique:\n";
	printList(mylist);

	mylist.unique(is_near());
	cout<<"After is_near unique:\n";
	printList(mylist);
	
	return 0;
}
