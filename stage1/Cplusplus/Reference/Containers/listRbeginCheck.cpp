// file : listRbeginCheck.cpp
// reserve_iterator rbegin();
// const_reverse_iterator rbegin() const;
// reserve_iterator rend() nothrow;
// const_reverse_iterator rend() const nothrow;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	for(int i = 1; i<= 5; ++i) 
		mylist.push_back(i);

	cout<<"mylist backwards:";
	for(list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++ rit)
		cout<<"\t"<<*rit;
	cout<<"\n";

	return 0;
}
