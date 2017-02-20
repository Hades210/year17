// file : vectorSwap2Check.cpp
// template <class T, class Alloc>
// void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	unsigned int i;
	vector<int> foo (3,100);
	vector<int> bar (5,200);

	swap(foo,bar);

	cout<<"foo contains:";
	for (auto& x : foo)
		cout<<"\t"<<x;

	cout<<endl;

	cout<<"bar contains:";
	for(auto& x:bar)
		cout<<"\t"<<x;

	cout<<endl;

	return 0;
}
