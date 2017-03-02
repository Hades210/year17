// file : priority_queueEmptyCheck.cpp
// bool empty() const;
// This member function effectively calls member empty of the underlying container object.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	priority_queue<int> mypq;
	int sum(0);

	for(int i = 1; i <= 10; i ++)
		mypq.push(i);

	while(!mypq.empty())
	{
		sum += mypq.top();
		mypq.pop();
	}

	cout<<"total : "<< sum<<"\n";
	
	return 0;
}
