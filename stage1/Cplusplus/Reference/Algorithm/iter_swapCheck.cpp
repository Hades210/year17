// file : iter_swapCheck.cpp
// template <class ForwardIterator1, class ForwardIterator2>
//	void iter_swap(ForwardIterator1 a, ForwardIterator2 b);
// swaps the elements pointed by a and b.
// The function calls swap to exchange the elements.
// The behavior of this functioin template is equivalent to:
// template <class ForwardIterator1, class ForwardIterator2>
// void iter_swap(ForwardIterator1 a, ForwardIterator2 b)
// {
// 	swap(*a, *b);
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {10,20,30,40,50};
	vector<int> myvector(4,99);

	iter_swap(myints,myvector.begin());

	for(auto& i : myints ) cout<<i<<" ";
	cout<<endl;

	for(auto& x : myvector) cout<<x<<" ";
	cout<<endl;

	iter_swap(myints+3,myvector.begin()+2);

	for(auto& i : myints ) cout<<i<<" ";
	cout<<endl;

	for(auto& x : myvector) cout<<x<<" ";
	cout<<endl;

	return 0;
}