// file : priority_queuePushCheck.cpp
// void push(const value_type& val);
// void push(value_type&& vval);

// This member function effectively calls the member function push_back of the underlying container object
// And then reorders it to its locations in the heap by calling the push_heap algorithm on the range that 
// includes all the elements of the container.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> mypq;

	mypq.push(30);
	mypq.push(100);
	mypq.push(25);
	mypq.push(40);

	while(!mypq.empty())
	{
		cout<<"\t"<<mypq.top();
		mypq.pop();
	}
	cout<<"\n";
	
	return 0;
}
