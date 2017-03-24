// file : reverse_copyCheck.cpp
// template <class BidirectionalIterator, class OutputIterator>
//	OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result);
// copies the elements in [first, last) to the range begining at result, but in reverse order.
// template <class BidirectionalIterator, class OutputIterator>
// OutputIterator reverse(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result)
// {
// 	while(first != last)
// 	{
// 		--last;
// 		*result = *last;
// 		++result;
// 	}
// 	return result;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {1,2,3,4,5,6,7,8,9};
	vector<int> myvec(9);

	reverse_copy(myints,myints + 9, myvec.begin());
	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}