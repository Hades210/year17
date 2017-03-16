// file : vectorEmplacebackCheck.cpp
// template <class... Args>
// void emplace_back(Args&&... args);
// c++ 11 only

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector = {10,20,30};
	myVector.emplace_back(100);
	myVector.emplace_back(200);

	cout<<"myVector contains:";
	for(auto& x : myVector)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
