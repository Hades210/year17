// file : forward_listFrontCheck.cpp
// reference front();
// const reference front() const;

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> mylist = {2,16,77};

	mylist.front() = 11;

	cout<<"mylist now contains:";
	for(int& x : mylist)
		cout<<"\t"<<x;
	cout<<"\n";
	
	return 0;
}
