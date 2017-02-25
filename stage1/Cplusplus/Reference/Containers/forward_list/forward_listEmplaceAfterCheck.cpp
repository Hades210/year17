// file : forward_listEmplaceAfterCheck.cpp
// template <class ... Args>
//	iterator emplace_after(const_iterator position, Args&&... args);

// Construct and insert element after the element at position
// Return an iterator that points to the newly emplaced element

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<pair<int,char> > mylist;
	auto it = mylist.before_begin();

	it = mylist.emplace_after(it,100,'x');
	it = mylist.emplace_after(it,200,'y');
	it = mylist.emplace_after(it,300,'z');

	cout<<"mylist contains:\n";
	for(auto& x : mylist)
		cout<<"("<<x.first<<","<<x.second<<")\t";
	cout<<endl;
	return 0;
}
