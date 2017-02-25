// file : forward_listClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {10,20,30};

	cout<<"mylist contains:";
	for(int& x : mylist)
		cout<<' '<<x;
	cout<<'\n';

	mylist.clear();
	mylist.insert_after(mylist.before_begin(),{100,200});

	cout<<"mylist contains:";
	for(int& x : mylist)
		cout<<' '<<x;
	cout<<"\n";

	return 0;
}
