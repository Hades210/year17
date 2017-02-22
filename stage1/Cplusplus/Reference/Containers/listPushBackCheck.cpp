// file : listPushBackCheck.cpp
// void push_back(const value_type& val);
// void push_back(value_type && val);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	int myint;

	cout<<"Please enter some integers (enter 0 to end):\n";

	do
	{
		cin>>myint;
		mylist.push_back(myint);
	}while(myint);

	cout<<"mylist stores "<<mylist.size()<<" numbers.\n";
	for(auto& x : mylist)
		cout<<x<<"\t";
	cout<<endl;
	
	return 0;
}
