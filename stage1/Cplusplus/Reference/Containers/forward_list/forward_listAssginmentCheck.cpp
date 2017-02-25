// file : forward_listAssignCheck.cpp
/****************************************************************************************
*	range(1)	template <class InputIterator>
*					void assign (InputIterator first, InputIterator last);
*	fill(2)		void assign (size_type n, const value_type& val);
*	il (3)		void assign (initializer_list<value_type> il);
*****************************************************************************************/

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> first;
	forward_list<int> second;

	first.assign(4,15);
	second.assign(first.begin(),first.end());

	first.assign({77,2,16});

	cout<<"first contains: ";
	for(int& x : first )
		cout<<x<<"\t";
	cout<<endl;

	cout<<"second contains: ";
	for(int& x : second)
		cout<<x<<"\t";
	cout<<"\n";
	
	return 0;
}
