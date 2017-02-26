// file : dequeMaxSizeCheck.cpp
// size_type max_size() const noexcept;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque;

	unsigned int i;

	cout<<"Enter number of elements: ";
	cin>>i;

	if(i < mydeque.max_size()) 
	{
		mydeque.resize(i);
		cout<<"resize deque";
	}
	else
	{
		cout<<"That size exceeds the limit.\n";
	}
	
	return 0;
}
