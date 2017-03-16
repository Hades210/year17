// file : listRemoveIfCheck.cpp
// template <class Predicate>
//	void remove_if(Predicate pred);
// Remove elements fulfilling condition
// This function calls pred(*it) for each element (where it is an iterator to that element).
// Any of the elements in the list for which this returns true, are removed from the container.

#include <iostream>
#include <list>

using namespace std;

bool single_digit(const int& value)
{
	return (value < 10);
}

struct is_odd
{
	bool operator() (const int& value)
	{
		return value % 2;
	}
};

int main()
{
	int myints[] = {15,36,7,17,20,39,4,1};

	list<int> mylist(myints,myints + 8);

	mylist.remove_if(single_digit);

	cout<<"After remove single_digit:";
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;

	mylist.remove_if(is_odd());

	cout<<"After remove odd:";
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
