// file : queueEmptyCheck.cpp
// bool empty() const;
// This member function effectively calls member empty of the underlying container object

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> myqueue;

	for(int i = 1; i <= 10; i ++)
		myqueue.push(i);

	int sum(0);

	while(! myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}

	cout<<sum<<"\n";
	
	return 0;
}
