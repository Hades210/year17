// file : forward_listCbeginCheck.cpp
// const_iterator cbegin() const noexcept;
// const_iterator cend() const noexcept;

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list <int> mylist = {21,32,12};

	cout<<"mylist contains:";
	for(forward_list<int>::const_iterator cit = mylist.cbegin(); cit != mylist.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<"\n";
	
	return 0;
}
