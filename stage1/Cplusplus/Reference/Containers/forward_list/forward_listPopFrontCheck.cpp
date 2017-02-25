// file : forward_listPopFrontCheck.cpp
// void pop_front();

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist;
	int myints[] = {10,20,30,40};

	mylist.assign(myints,myints + 4);

	cout<<"mylist contains: ";
	while(!mylist.empty())
	{
		cout<<mylist.front()<<" ";
		mylist.pop_front();
	}
	cout<<"\n";

	return 0;
}
