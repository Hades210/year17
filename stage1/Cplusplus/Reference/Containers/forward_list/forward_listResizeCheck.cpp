// file : forward_listResizeCheck.cpp
// void resize(size_type n);
// void resize(size_type n, const value_type& val);

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {10,20,30,40,50};

	mylist.resize(3);

	mylist.resize(5,100);

	cout<<"mylist contains:";
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;
	
	return 0;
}
