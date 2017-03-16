// file : vectorEmptyCheck.cpp
// bool empty() const noexcept;
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;
	int sum (0);

	for(int i = 1; i <= 10; i ++) 
		myVector.push_back(i);

	while(!myVector.empty())
	{
		sum += myVector.back();
		myVector.pop_back();
	}

	cout<<"total: "<<sum<<endl;
	return 0;
}
