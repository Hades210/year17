// file : priority_queueEmplaceCheck.cpp
// template <class... Args> void emplace(Args&&... args);
// This member function effectively calls the member function emplace_back of the underlying container, forwarding args,
// and then reorders it to its locations in the heap by calling the push_heap algorithm on the range that includes all the elements of the container.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	priority_queue<string> mypq;

	mypq.push("orange");
	mypq.push("strawberry");
	mypq.push("apple");
	mypq.push("pear");

	cout<<"mypq contains: ";
	while(!mypq.empty())
	{
		cout<<mypq.top()<<" ";
		mypq.pop();
	}
	cout<<"\n";

	return 0;
}
