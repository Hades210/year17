// file : vectorShrinktofitCheck.cpp
// void shrink_to_fit()
// Requests the container to reduce its capacity to fit its size
// c++ 11 only

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector(100);
	cout<<"1. capacity of myVector: "<<myVector.capacity()<<"\n";

	myVector.resize(10);
	cout<<"2. capacity of myVector: "<<myVector.capacity()<<"\n";

	myVector.shrink_to_fit();
	cout<<"3. capacity of myVector: "<<myVector.capacity()<<"\n";
	
	return 0;
}
