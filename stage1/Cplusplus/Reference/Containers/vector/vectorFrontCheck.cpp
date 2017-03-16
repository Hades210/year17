// file : vectorFrontCheck.cpp
// reference front();
// const_reference front() const

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;
	myVector.push_back(78);
	myVector.push_back(16);

	myVector.front() -= myVector.back();
	cout<<"myVector.front() is now: "<<myVector.front()<<"\n";
	return 0;
}

