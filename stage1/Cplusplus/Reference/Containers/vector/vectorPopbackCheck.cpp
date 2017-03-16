// file : vectorPopbackCheck.cpp
// void pop_back()

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;
	int sum (0);
	myVector.push_back(100);
	myVector.push_back(200);
	myVector.push_back(300);

	while(!myVector.empty()) 
	{
		sum += myVector.back();
		myVector.pop_back();
	}

	cout<<"The elements of myVector add up to "<<sum<<"\n";

	return 0;
}
