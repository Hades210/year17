// file : forward_listRemoveCheck.cpp
// void remove(const value_type& val);

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {10,20,30,40,30,20,10};

	mylist.remove(20);

	cout<<"mylist contains:";
	for(int& x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";
	return 0;
}
