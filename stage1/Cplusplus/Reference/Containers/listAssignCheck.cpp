// file : listAssignCheck.cpp
/********************************************************************************************
*	range(1)	template <class InputIterator>
*					void assign(InputIterator first, InputIterator last);
*	fill(2)		void assign(size_type n, const value_type& val);
*	il (3)		void assign(initializer_list<value_type> il);
*******************************************************************************************/

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> first;
	list<int> second;

	first.assign(7,100);
	second.assign(first.begin(),first.end());

	int myints[] = {1775,7,4};
	first.assign(myints,myints+3);

	cout<<"Size of first: "<< int (first.size())<<"\n";
	cout<<"Size of second: "<< int (second.size())<<"\n";
	
	return 0;
}
