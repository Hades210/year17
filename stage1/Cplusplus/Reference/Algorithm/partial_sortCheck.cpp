// file : partial_sortCheck.cpp
// default(1)	template <class RandomAccessIterator>
//				void partial_sort(RandomAccessIterator first, RandomIterator middle, RandomAccessIterator last);
// custom(2)	template <class RandomAccessIterator, class Compare>
//				void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, Compare comp);
// Rearranges the elements in the range[first,last), in such a way that elements before middle are the smallest elements in the entire
// range and are sorted in ascending order, while the remaining elements are left without any specific order.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {9,8,7,6,5,4,3,2,1};
	vector<int> myvec(myints,myints + 9);

	partial_sort(myvec.begin(),myvec.begin() + 5, myvec.end());

	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;

	partial_sort(myvec.begin(),myvec.begin() + 5, myvec.end(),[](int i, int j) {return i > j;});

	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}