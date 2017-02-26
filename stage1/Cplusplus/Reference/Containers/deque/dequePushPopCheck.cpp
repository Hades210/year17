// file : dequePushPopCheck.cpp
// void push_back(const value_type& val);
// void push_back(value_type&& val);
// void push_front(const value_type& val);
// void push_front(value_type&& val);
// void pop_back();
// void pop_front();

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> mydeque1;
	int myint;

	cout<<"Please enter some integers (enter 0 to stop) :\n";

	do
	{
		cin>>myint;
		mydeque1.push_back(myint);
	}while(myint);

	cout<<"mydeque stores "<<(int)mydeque1.size()<<" numbers.\n";
	printInfo("1",mydeque1);

	mydeque1.clear();

	mydeque1.assign(2,100);
	mydeque1.push_front(200);
	mydeque1.push_front(300);

	printInfo("2",mydeque1);

	mydeque1.clear();


	int sum(0);
	int myints[] = {10,20,30};
	mydeque1.assign(myints,myints + 3);

	while(!mydeque1.empty())
	{
		sum += mydeque1.back();
		mydeque1.pop_back();
	}
	cout<<"3: The elements sum "<<sum<<"\n";

	mydeque1.insert(mydeque1.begin(),{100,200,300});
	cout<<"4: Poping out the elements in mydeque:";
	while(!mydeque1.empty())
	{
		cout<<"\t"<<mydeque1.front();
		mydeque1.pop_front();
	}

	cout<<"\n";

	return 0;
}

