// file : forward_listCBeforeBeginCheck.cpp
// const_iterator cbefore_begin()const noexcept;

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {77, 2, 16};

	mylist.insert_after(mylist.cbefore_begin(),19);

	cout<<"mylist contains:";
	for(auto& x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";
	
	return 0;
}
