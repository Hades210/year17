// file : listMaxSizeCheck.cpp
// size_type max_size() const noexcept;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	unsigned int i;
	list<int> mylist;
	cout<<mylist.max_size()<<endl;

	cout<<"Enter number of elements: ";
	cin>>i;

	if(i < mylist.max_size())
	{
		mylist.resize(i);
		cout<<"resize mylist to "<<i<<"\n";
	}
	else
		cout<<"That size exceeds the limit.\n";

	return 0;
}
