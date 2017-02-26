// file : dequeCrbeginCheck.cpp
// const_reverse_iterator crbegin() const noexcept;
// const_reverse_iterator crend() const noexcept;

#include <iostream>
#include <deque>

using namespace std;

int main()
{
	deque<int> mydeque = {1, 2, 3, 4, 5};

	cout<<"mydeque backwards:";

	for(auto rit = mydeque.crbegin(); rit != mydeque.crend(); ++ rit)
		cout<<"\t"<<*rit;
	cout<<"\n";
	
	return 0;
}
