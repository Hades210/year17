// file : listEraseCheck.cpp
// iterator erase(const_iterator position);
// iterator erase(const_iterator first, const_iterator last);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;
	list<int>::iterator it1, it2;

	for(int i = 1; i < 10; i ++)
		mylist.push_back(i * 10);

	it1 = it2 = mylist.begin();
	advance(it2,6);
	++it1;

	it1 = mylist.erase(it1);

	it2 = mylist.erase(it2);

	++it1;
	--it2;

	mylist.erase(it1,it2);

	cout<<"mylist contains:";
	for(it1 = mylist.begin(); it1 != mylist.end(); ++ it1)
		cout<<"\t"<<*it1;
	cout<<"\n";

	return 0;
}
