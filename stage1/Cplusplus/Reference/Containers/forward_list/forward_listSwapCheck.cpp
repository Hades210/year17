// file : forward_listSwapCheck.cpp
// void swap(forward_list & fwdlst);

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> first = {10,20,30};
	forward_list<int> second = {100,200};

	first.swap(second);

	cout<<"first contains:";
	for(int& x : first)
		cout<<"\t"<<x;
	cout<<endl;

	cout<<"second contains:";
	for(int& x : second)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
