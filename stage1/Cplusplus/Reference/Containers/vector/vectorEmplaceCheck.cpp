// file : vectorEmplaceCheck.cpp
// template <class ... Args>
// iterator emplace (const_iterator position, Args&&... args);
// c++ 11 only

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector = {10,20,30};

	auto it = myVector.emplace(myVector.begin() + 1, 100);
	myVector.emplace(it,200);
	myVector.emplace(myVector.end(),300);

	cout<<"myVector contains:";
	for(auto & x : myVector)
		cout<<"\t"<<x;
	cout<<endl;

	return 0;
}
