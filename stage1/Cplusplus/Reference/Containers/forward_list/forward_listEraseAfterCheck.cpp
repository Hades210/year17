// file : forward_listEraseAfterCheck.cpp
// iterator erase_after(const_iterator position);
// iterator erase_after(const_iterator position,const_iterator last);
// Erase elements Removes from the forward_list container either a single element (the one after position) or a range of elements (position,last)
// An iterator pointing to the element that follows the last element erased by the function call, which is last for the second version.

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {10,20,30,40,50};

	auto it = mylist.begin();

	it = mylist.erase_after(it);

	it = mylist.erase_after(it,mylist.end());

	cout<<"mylist contains:";
	for(int & x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";
	
	return 0;
}

