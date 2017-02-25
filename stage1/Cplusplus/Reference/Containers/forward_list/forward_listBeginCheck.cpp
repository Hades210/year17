// file : forward_listBeginCheck.cpp
// iterator begin() noexcept;
// const_iterator begin() const noexcept;

// iterator end() noexcept;
// const_iterator end() const noexcept;

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {10,20,30,40};

	forward_list<int>::iterator it = mylist.begin();

	cout<<"mylist contains:\t";
	for(; it != mylist.end(); ++ it)
		cout<<*it<<"\t";
	cout<<"\n";
	return 0;
}
