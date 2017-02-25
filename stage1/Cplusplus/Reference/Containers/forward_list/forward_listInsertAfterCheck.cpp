// file : forward_listInsertAfterCheck.cpp
// Insert elements
/*********************************************************************************************
*	(1)	iterator insert_after (const_iterator position, const value_type& val);
*	(2) iterator insert_after (const_iterator position, value_type&& val);
*	(3) iterator insert_after (const_iterator position, size_type n, const value_type& val);
*	(4) template <class InputIterator>
*			iterator insert_after (const_iterator position, InputIterator first, InputIterator last);
*	(5) iterator insert_after (const_iterator position, initializer_list<value_type> il);
**********************************************************************************************/

// Return an iterator that points to the last of the newly inserted elements, or position if no element was inserted.

#include <iostream>
#include <forward_list>
#include <array>

using namespace std;

int main()
{
	array<int,3> myarray = {11,22,33};
	forward_list<int> mylist;
	forward_list<int>::iterator it;

	it = mylist.insert_after(mylist.before_begin(),10);
	it = mylist.insert_after(it,2,20);
	it = mylist.insert_after(it,myarray.begin(),myarray.end());

	it = mylist.begin();
	it = mylist.insert_after(it,{1,2,3});

	cout<<"mylist contains:";
	for(int& x : mylist)
		cout<<"\t"<<x;
	cout<<endl;
	
	return 0;
}
