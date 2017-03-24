// file : reverseCheck.cpp
// template <class BidirectionalIterator>
// void reverse(BidirectionalIterator first, BidirectionalIterator last);
// Reverses the order of the elements in the range [first, last).
// The function calls iter_swap to swap the elements to their new location.
// template <class BidirectionalIterator>
// void reverse(BidirectionalIterator first, BidirectionalIterator last)
// {
// 	while((first != last) && (first != --last) )
// 	{
// 		iter_swap(first,last);
// 		++first;
// 	}
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10 ; ++i)	myvec.push_back(i);
	reverse(myvec.begin(),myvec.end());

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}