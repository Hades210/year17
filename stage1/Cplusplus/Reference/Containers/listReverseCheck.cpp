// file : listReverseCheck.cpp
// void reverse() noexcept;
// Reverse the order of elements

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	for(int i = 1; i < 10; i ++)
		mylist.push_back(i);

	mylist.reverse();

	cout<<"mylist contains:";
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;
	
	return 0;
}
