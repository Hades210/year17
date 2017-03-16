// file : listResizeCheck.cpp
// void resize(size_type n);
// void resize(size_type n, const value_type& val);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	for(int i = 1; i < 10; i ++)
		mylist.push_back(i);

	mylist.resize(5);
	mylist.resize(8,100);
	mylist.resize(12);

	cout<<"mylist contains:";
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;

	
	return 0;
}
