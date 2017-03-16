// file : vectorCrbeginCheck.cpp
// const_reverse_iterator crbegin() const noexcept;
// const_reverse_iterator crend() const noexcept;
// c++ 11 only
// g++ -std=c++11

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector = {1,2,3,4,5};

	cout<<"myVector contains:";

	for(auto rit = myVector.crbegin(); rit != myVector.crend(); ++ rit)
		cout<<"\t"<<*rit;
	cout<<endl;
	
	return 0;
}
