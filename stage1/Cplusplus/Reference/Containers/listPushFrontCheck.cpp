// file : listPushFrontCheck.cpp
// void push_front(const value_type& val);
// void push_front(value_type&& val);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist (2, 100);
	mylist.push_front(200);
	mylist.push_front(300);

	cout<<"mylist contains:";
	for(auto& x: mylist)
		cout<<"\t"<<x;
	cout<<endl;
	return 0;
}
