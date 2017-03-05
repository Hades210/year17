// file : multisetEmptyCheck.cpp
// bool empty() const noexcept;
// size_type size() const noexcept;
// size_type max_size() const noexcept; 

#include <iostream>
#include <set>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	multiset<int> myset;

	myset.insert(10);
	myset.insert(20);
	myset.insert(10);

	cout<<"myset contains: ";

	while(!myset.empty())
	{
		cout<<*myset.begin()<<" ";
		myset.erase(myset.begin());
	}
	cout<<"\n";

	myset.clear();
	cout<<"0. size: "<<myset.size()<<"\n";
	printInfo("0",myset);

	for(int i = 0; i < 10; i ++)
		myset.insert(i);
	cout<<"1. size: "<<myset.size()<<"\n";
	printInfo("1",myset);

	myset.insert(5);
	cout<<"2. size: "<<myset.size()<<"\n";
	printInfo("2",myset);

	myset.erase(5);
	cout<<"3. size: "<<myset.size()<<"\n";
	printInfo("3",myset);

	cout<<"max_size: "<<myset.max_size()<<"\n";
	
	return 0;
}
