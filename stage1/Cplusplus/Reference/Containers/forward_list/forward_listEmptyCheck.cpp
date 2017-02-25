// file : forward_listEmptyCheck.cpp
// bool empty() const noexcept;

#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> first;
	forward_list<int> second = {20,40,80};

	cout<<"first "<<(first.empty() ? "is empty.\n" : "is not empty.\n");
	cout<<"second "<<(second.empty() ? "is empty.\n " : "is not empty.\n");
	
	return 0;
}
