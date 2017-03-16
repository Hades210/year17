// file : listRemoveCheck.cpp
// void remove(const vaule_type& val);
// remove elements with specific value
// Removes from the container all the elements that compare equal to val.

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int myints[] = {17,89,7,14,17};
	list<int> mylist(myints,myints + 5);

	mylist.remove(17);

	cout<<"mylist contains:";

	for(auto& x : mylist)
		cout<<"\t"<<x;
	cout<<endl;
	
	return 0;
}
