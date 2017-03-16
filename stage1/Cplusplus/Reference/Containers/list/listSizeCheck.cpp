// file : listSizeCheck.cpp
// size_type size() const noexcept;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> myints;
	cout<<"0. size: "<<myints.size()<<"\n";

	for(int i = 0; i < 10; i ++) 
		myints.push_back(i);
	cout<<"1. size: "<<myints.size()<<"\n";

	myints.insert(myints.begin(),10,100);
	cout<<"2. size: "<<myints.size()<<"\n";

	myints.pop_back();
	cout<<"3. size: "<<myints.size()<<"\n";

	return 0;
}
