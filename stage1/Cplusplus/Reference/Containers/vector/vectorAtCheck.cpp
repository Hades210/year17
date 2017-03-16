// file : vectorAtCheck.cpp
// reference at (size_type n);
// const_reference at(size_type n) const;

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector (10);
	vector<int>::size_type sz = myVector.size();
	for(int i = 0; i <sz; ++i)
		myVector.at(i) = i;

	cout<<"myVector contains:";
	for(int i = 0; i < sz; ++ i)
		cout<<"\t"<<myVector.at(i);
	cout<<endl;
	return 0;
}
