// file: vectorSizeCheck.cpp
// size_type size() const noexcept;

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> myInts;
	cout<<"0. size: "<<myInts.size()<<endl;

	for(int i = 0; i < 10; i ++) myInts.push_back(i);

	cout<<"1. size: "<<myInts.size()<<endl;
	
	myInts.insert(myInts.end(),10,100);
	cout<<"2. size: "<<myInts.size()<<endl;

	myInts.pop_back();
	cout<<"3. size: "<<myInts.size()<<endl;
	
	return 0;
}
