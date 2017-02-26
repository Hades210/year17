// file : dequeSizeCheck.cpp
// size_type size() const noexcept;

#include <iostream>
#include <deque>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	deque<int> myints;
	cout<<"0. size: "<<myints.size()<<"\n";
	printInfo("0",myints);

	for(int i = 0; i < 5; i ++)
		myints.push_back(i);
	cout<<"1. size: "<<myints.size()<<"\n";
	printInfo("1",myints);

	myints.insert(myints.begin(),5,100);
	cout<<"2. size: "<<myints.size()<<"\n";
	printInfo("2",myints);

	myints.pop_back();
	cout<<"3. size: "<<myints.size()<<"\n";
	printInfo("3",myints);

	return 0;
}
