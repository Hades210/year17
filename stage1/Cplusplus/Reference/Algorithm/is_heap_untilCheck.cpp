// file : is_heap_untilCheck.cpp
/**************************************************************************************
*default(1)	template <class RandomAccessIterator>
*			RandomAccessIterator is_heap_until(RandomAccessIterator first,
*											   RandomAccessIterator last);
*custom(2)	template <class RandomAccessIterator, class Compare>
*			RandomAccessIterator is_heap_until(RandomAccessIterator first,
*											   RandomAccessIterator last,
*											   Compare comp);
***************************************************************************************/
//Returns an iterator to the first element in the range[first,last) which is not in 
//a valid position if the range is considered a heap(as if constructed with make_heap).
// If the entire range is a valid heap, the function returns last.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> foo {2,6,9,3,8,4,5,1,7};

	sort(foo.begin(),foo.end());
	reverse(foo.begin(),foo.end());

	auto last = is_heap_until(foo.begin(),foo.end());

	cout<<"The "<<distance(foo.begin(),last)<<" first elements are a valid heap: ";
	for(auto it = foo.begin(); it != last; ++it)
		cout<<*it<<" ";
	cout<<endl;

	return 0;
}