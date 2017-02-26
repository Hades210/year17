// file : dequeShrinkToFitCheck.cpp
// void shrink_to_fit();
// This function requests that the memory usage is adapted to the current size of the container
// but the request is non-binding, and the container implementation is free to opetimize its memory usage otherwise.

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque(100);
	cout<<"1. size of mydeque: "<<int(mydeque.size())<<"\n";

	mydeque.resize(10);
	cout<<"2. size of mydeque: "<<int(mydeque.size())<<"\n";

	mydeque.shrink_to_fit();

	return 0;
}
