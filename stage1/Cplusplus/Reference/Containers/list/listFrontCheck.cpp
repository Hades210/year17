// file : listFrontCheck.cpp
// reference front();
// const_reference front() const;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	mylist.front() -= mylist.back();

	cout<<"mylist.front() is now "<< mylist.front()<<"\n";
	
	return 0;
}
