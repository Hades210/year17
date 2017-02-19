// file : vectorBackCheck.cpp
// reference back();
// const_reference back() const;

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;
	myVector.push_back(10);

	while(myVector.back() != 0)
	{
		myVector.push_back(myVector.back() - 1);
	}

	cout<<"myVector contains:";
	for(auto cit = myVector.cbegin(); cit != myVector.cend(); ++cit)
		cout<<"\t"<<*cit;
	cout<<endl;
	return 0;
}
