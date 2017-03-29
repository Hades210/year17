// file : inplace_mergeCheck.cpp
/*************************************************************************************************
*default(1)	template <class BidirectionalIterator>
*			void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle,
*							   BidirectionalIterator last);
*custom(2)	template <class BidirectionalIterator, class Compare>
*			void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle,
*							   BidirectionalIterator last, Compare comp);
*************************************************************************************************/
// Merges two consecutive sorted ranges [first,middle) and [middle,last),putting the result into the
// combined sorted range[first,last).
// The function preserves the relative order of elements with equivalent values, with the elements in the first
// range preceding those equivalent in the second.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int first[] {5,10,15,20,25};
	int second[] {50,40,30,20,10};

	vector<int> v(10);

	sort(first,first + 5);
	sort(second,second + 5);

	auto it = copy(first,first +5, v.begin());
	copy(second,second + 5, it);

	inplace_merge(v.begin(),v.begin() + 5, v.end());

	for(it = v.begin(); it != v.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;

	return 0;
}