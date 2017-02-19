// file : vectorCbeginCheck.cpp
// const_iterator cbegin() const noexcept;
// const_iterator cend() const noexcept;
// c++ 11 only
// g++ -std=c++11 

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <int> myVector = {10,20,30,40,50};

	cout<<"myVector contains:";
	for(auto it = myVector.cbegin(); it != myVector.end(); ++it)
		cout<<"\t"<<*it;
	cout<<endl;
	return 0;
}
