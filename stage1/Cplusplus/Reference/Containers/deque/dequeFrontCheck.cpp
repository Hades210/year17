// file : dequeFrontCheck.cpp
// reference front();
// const_reference front() const;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque;

	mydeque.push_front(77);
	mydeque.push_back(20);

	mydeque.front() -= mydeque.back();

	cout<<"mydeque.front() is now "<<mydeque.front()<<"\n";
	
	return 0;
}
