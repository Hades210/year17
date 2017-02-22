// file : listBackCheck.cpp
// reference back();
// const_reference back() const;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	mylist.push_back(10);

	while(mylist.back() != 0)
	{
		mylist.push_back(mylist.back() - 1);
	}

	cout<<"mylist contains: ";

	for(auto x : mylist)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
