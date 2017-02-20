// file : vectorPushbackCheck.cpp
// void push_back (const value_type& val)
// void push_back(value_type& val)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;
	int myint;

	cout<<"Please enter some integers (enter 0 to end):\n";

	do {
		cin>>myint;
		myVector.push_back(myint);
	} while(myint);

	cout<<"myVector stores "<<myVector.size()<<" numbers.\n";

	cout<<"myVector contains:";
	for(auto cit = myVector.cbegin(); cit != myVector.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;

	return 0;
}
