// file : vectorEraseCheck.cpp
// iterator erase(const_iterator position);
// iterator erase(const_iterator first, const_iterator last);
// An iterator pointing to the new location of the element that followed the last element erased by the function call.
// This is the container end if the operation erased the last element in the sequence

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector;

	for(int i = 1; i <= 10; i ++) 
		myVector.push_back(i);

	myVector.erase(myVector.begin() + 5);

	myVector.erase(myVector.begin(),myVector.begin() + 3);

	cout<<"myVector contains:";
	for(auto cit = myVector.begin(); cit != myVector.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;
	return 0;
}
