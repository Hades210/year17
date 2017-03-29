// file : is_heapCheck.cpp
/*****************************************************************************************
*default(1)	template <class RandomAccessIterator>
*			bool is_heap(RandomAccessIterator first, RandomAccessIterator last);
*custom(2)	template<class RandomAccessIterator, class Compare>	
*			bool is_heap(RandomAccessIterator first, RandomAccessIterator last,
*						 Compare comp);
*******************************************************************************************/
// Returns true if the range [first,last) forms a heap, as if constructed with make_heap.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> foo {9,5,2,6,4,1,3,8,7};
	if(!is_heap(foo.begin(),foo.end()))
		make_heap(foo.begin(),foo.end());

	cout<<"popping out elements: ";
	while(!foo.empty())
	{
		pop_heap(foo.begin(),foo.end());
		cout<<foo.back()<<" ";
		foo.pop_back();
	}
	cout<<endl;
	return 0;
}