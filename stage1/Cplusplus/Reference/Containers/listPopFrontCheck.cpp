// file : listPopFrontCheck.cpp
// void pop_front();

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;
	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	cout<<"Popping out the elements in mylist:";
	while(!mylist.empty()) 
	{
		cout<<" "<<mylist.front();
		mylist.pop_front();
	}
	cout<<"\nFinal size of mylist is "<<mylist.size()<<"\n";
	
	return 0;
}
