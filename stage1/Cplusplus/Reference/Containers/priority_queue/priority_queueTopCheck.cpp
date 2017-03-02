// file: priority_queueTopCheck.cpp
// const_reference top() const;
// This member function effectively calls member front of the underlying container object.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> mypq;

	mypq.push(10);
	mypq.push(20);
	mypq.push(15);

	cout<<"mypq.top() is now "<<mypq.top()<<"\n";
	
	return 0;
}
