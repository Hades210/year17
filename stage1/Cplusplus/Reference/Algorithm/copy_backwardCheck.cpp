// file : copy_backwardCheck.cpp
// template <class BidirectionalIterator1, class BidirectionalIterator2>
//	BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, BidirectionalIterator2 result);
// copies the elements in the range [first,last) starting from end into the range terminating at result.
// The function returns an iterator to the first element in the destination range.
// The resulting range has the elements in the exact same order as [first,last). To reverse their order, see reverse_copy.
// The function begins by copying *(last -1) into *(result-1), and then follows backeard by the elements preceding these, 
// until first is reached(and including it).
// The ranges shall not overlap in such a way that result(which is the past-the-end element in the element in the destination range)
// points to an element in the range [first,last). For such cases, see copy.
// The behavior of this function template is equivalent to:
// template <class BidirectionalIterator1, class BidirectionalIterator2>
// BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator last, BidirectionalIterator2 result)
// {
// 	while(last != first)
// 	{
// 		*(--result) == *(--last);
// 	}
// 	return result;
// }
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvec;
	for(int i = 1; i <= 5; ++ i)
		myvec.push_back(i * 10);

	myvec.resize(myvec.size() + 3);

	copy_backward(myvec.begin(),myvec.begin() + 5, myvec.end());

	cout<<"myvec contains: ";
	for(auto& x : myvec)
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}