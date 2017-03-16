// file : listClearCheck.cpp
// void clear() noexcept;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;
	list<int>::iterator it;

	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	cout<<"mylist contains:";
	for(it = mylist.begin(); it != mylist.end(); ++ it)
		cout<<"\t"<<*it;
	cout<<endl;

	mylist.clear();


	mylist.push_back(1001);
	mylist.push_back(2002);

	cout<<"mylist contains:";
	for(it = mylist.begin(); it != mylist.end(); ++ it)
		cout<<"\t"<<*it;
	cout<<endl;
	
	return 0;
}
