// file : dequeCbeginCheck.cpp
// const_iterator cbegin() const noexcept;
// const_iterator cend() const noexcept;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque = {10, 20, 30, 40, 50};

	cout<<"mydeque contains:";

	for(auto it = mydeque.cbegin(); it != mydeque.cend(); ++ it)
		cout<<"\t"<<*it;
	cout<<"\n";
	
	return 0;
}
