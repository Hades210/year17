// file : initializer_listCheck.cpp

#include <iostream>
#include <initializer_list>

using namespace std;

void rangeCheck(initializer_list<int>  lst)
{
	cout<<"initializer_list used by a range-for\n";

	for(auto x : lst)
		cout<<x<<'\n';
}

void subscriptCheck(initializer_list<int> lst)
{
	cout<<"initializer_list subscript check\n";

	// for(int i = 0; i < lst.size(); ++i)
	// 	cout<<lst[i]<<'\n';   // error

	const int* p = lst.begin();
	for(int i = 0; i <  lst.size(); ++i)
		cout<<p[i]<<'\n';
}

int main()
{

	initializer_list<int> il ({12,34,56,78,90,123,234,345,567,789,890});

	rangeCheck(il);

	subscriptCheck(il);

	return 0;
}