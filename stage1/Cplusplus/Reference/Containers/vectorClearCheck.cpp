// file : vectorClearCheck.cpp
// void clear() noexcpt;
// vector<T> ().swap(x); // A reallocation is not guaranteed to happen, the alternative that forces a reallocation is to use swap

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myVector {100,200,300};

	cout<<"original data:";
	for(auto cit = myVector.cbegin() ; cit != myVector.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;

	myVector.clear();

	myVector.push_back(1001);
	myVector.push_back(2002);

	cout<<"changed data:";
	for(auto cit = myVector.cbegin() ; cit != myVector.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;

	return 0;
}
