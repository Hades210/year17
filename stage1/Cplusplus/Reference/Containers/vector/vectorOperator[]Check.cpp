// file : vectorOperator[]Check.cpp
// reference operator[] (size_type n);
// const_reference operator[] (size_type n) const;

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector (10);
	vector<int>::size_type sz = myVector.size();

	for(int i = 0; i < sz; i ++)
		myVector[i] = i;

	for(int i = 0; i < sz / 2; i ++)
	{
		int tmp = myVector[sz - 1 - i];
		myVector[sz - 1 - i] = myVector[i];
		myVector[i] = tmp;
	}

	cout<<"myVector contains:";
	for(int i = 0; i < sz; i ++)
		cout<<"\t"<<myVector[i];
	cout<<endl; 

	return 0;
}
