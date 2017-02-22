// file : listSwapCheck.cpp
// void swap(list& x);

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> first (3,100);
	list<int> second (5,200);

	first.swap(second);

	cout<<"first contains";
	for(auto & x : first)
		cout<<"\t"<<x;
	cout<<endl;


	cout<<"second contains";
	for(auto & x : second)
		cout<<"\t"<<x;
	cout<<endl;


	return 0;
}
