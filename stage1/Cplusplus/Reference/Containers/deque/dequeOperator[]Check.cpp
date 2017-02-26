// file : dequeOperator[]Check.cpp
// reference operator[] (size_type n);
// const_reference operator[] (size_type n) const;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque(10);
	deque<int>::size_type sz = mydeque.size();

	for(unsigned int i = 0; i < sz; ++ i)
		mydeque[i] = i;
	
	for(unsigned int i = 0; i < sz / 2; ++ i)
	{
		int tmp = mydeque[i];
		mydeque[i] = mydeque[sz - i - 1];
		mydeque[sz - i - 1] = tmp;
	}

	cout<<"mydeque contains:";
	for(unsigned i = 0; i < sz; ++ i)
		cout<<"\t"<<mydeque[i];
	cout<<"\n";

	return 0;
}
