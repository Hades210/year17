// file : listEmplaceBackCheck.cpp
// template <class... Args>
//	void emplace_back(Args&&... args);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<pair<int,char> > mylist;

	mylist.emplace_back(10,'a');
	mylist.emplace_back(20,'b');
	mylist.emplace_back(30,'c');

	cout<<"mylist contains:";
	for(auto& x:mylist)
		cout<<"\t("<<x.first<<", "<<x.second<<")";
	cout<<"\n";

	return 0;
}
