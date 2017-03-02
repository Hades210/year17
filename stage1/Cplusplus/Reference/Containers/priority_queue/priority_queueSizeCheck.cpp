// file : priority_queueSizeCheck.cpp
// size_type size() const;
// This member function effectively calls member size of the underlying container object

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> myints;
	cout<<"0. size: " <<myints.size()<<"\n";

	for(int i = 0; i < 5; i ++)
		myints.push(i);

	cout<<"1. size: "<<myints.size()<<"\n";

	myints.pop();

	cout<<"2. size: "<<myints.size()<<"\n";
	
	return 0;
}
