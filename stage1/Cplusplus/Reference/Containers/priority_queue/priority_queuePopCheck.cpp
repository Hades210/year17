// file : priority_queuePopCheck.cpp
// void pop();
// This member function effectively calls the pop_heap algorithm to keep the heap property of priority_queue and then
// calls the member function pop_back of the underlying container object to remove the element.

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

	cout<<"Popping out elements...";

	while(!mypq.empty())
	{
		cout<<mypq.top()<<" ";
		mypq.pop();
	}
	cout<<"\n";
	
	return 0;
}
