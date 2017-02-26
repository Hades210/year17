// file : dequeBeginCheck.cpp
// iterator begin() noexcept;
// const_iterator begin() const noexcept;
// iterator end() noexcept;
// const_iterator end() const noexcept;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque;

	for(int i = 1; i <= 5; i ++)
		mydeque.push_back(i);

	for(int i = 6; i <= 10; i ++)
		mydeque.insert(mydeque.end(),i);

	cout<<"mydeque contains:";

	deque<int>::iterator it = mydeque.begin();
	while(it != mydeque.end())
		cout<<"\t"<<*it ++;
	cout<<"\n";

	return 0;
}
