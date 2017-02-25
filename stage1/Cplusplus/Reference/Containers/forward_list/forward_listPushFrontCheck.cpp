// file : forward_listPushFrontCheck.cpp
// void push_front(const value_type& val);
// void push_front(value_type&& val);

// Insert element at beginning

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {77,2,16};
	mylist.push_front(19);
	mylist.push_front(34);

	cout<<"mylist contains:";
	for(int& x : mylist)
		cout<<"\t"<<x;
	cout<<endl;
	
	return 0;
}
