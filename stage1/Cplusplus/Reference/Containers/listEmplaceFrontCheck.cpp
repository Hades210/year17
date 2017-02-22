// file : listEmplaceFrontCheck.cpp
// template <class... Args>
//	void emplace_front(Args&&... args);


#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<pair<int,char> > mylist;

	mylist.emplace_front(10,'a');
	mylist.emplace_front(20,'b');
	mylist.emplace_front(30,'c');

	cout<<"mylist contains:";

	for (auto& x: mylist)
		cout<<"( "<<x.first<<", "<<x.second<<")\t";
	cout<<endl;

	return 0;

}
