// file : listEmptyCheck.cpp
// bool empty() const noexcept;

#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> mylist;

	for(int i = 1; i <= 10; i ++)
		mylist.push_back(i);
	int sum(0);

	while(!mylist.empty()) 
	{
		sum += mylist.back();
		mylist.pop_back();
	}
	
	cout<<"total: "<<sum<<"\n";

	return 0;

}
