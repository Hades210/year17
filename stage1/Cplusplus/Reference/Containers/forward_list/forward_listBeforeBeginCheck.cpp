// file : forward_listBeforeBeginCheck.cpp
//	iterator before_begin() noexcept;
//	const_iterator before_begin() const noexcept;
// Return iterator to before beginning

// It is meant to be used as an argument for member functions emplace_after,insert_after,erase_after,or splice_after

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {20,30,40,50};
	mylist.insert_after(mylist.before_begin(),10);

	cout<<"mylist contains:"; 
	for(auto & x : mylist)
		cout<<"\t"<<x;
	cout<<endl;
	return 0;
}
