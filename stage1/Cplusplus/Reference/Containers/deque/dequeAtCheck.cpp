// file : dequeAtCheck.cpp
// reference at(size_type n);
// const_reference at(size_type n) const;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<unsigned> mydeque(10);

	for(unsigned int i = 0; i < mydeque.size(); ++ i)
		mydeque.at(i) = i;

	cout<<"mydeque contains:";
	for(unsigned int i = 0; i < mydeque.size(); ++ i)
		cout<<"\t"<<mydeque.at(i);

	cout<<"\n";
	
	return 0;
}
