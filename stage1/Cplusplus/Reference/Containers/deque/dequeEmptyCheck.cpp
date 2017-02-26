// file : dequeEmptyCheck.cpp
// bool empty() const noexcept;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque;

	int sum(0);

	for(int i = 1; i <= 10; i ++)
		mydeque.push_back(i);

	while(! mydeque.empty())
	{
		sum += mydeque.front();
		mydeque.pop_front();
	}

	cout<<"total: "<<sum<<"\n";
	
	return 0;
}
