// file : nth_element.cpp
// default(1)	template <class RandomAccessIterator>
// 				void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);
// custom(2)	template <class RandomAccessIterator, class Compare>
//				void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, Compare comp);
// Rearranges the elements in the range [first,last),in such a way that the element at the nth position is the element
// that would be in that position in a sorted sequence.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10; i ++) myvec.push_back(i);

	random_shuffle(myvec.begin(),myvec.end());
	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	
	nth_element(myvec.begin(),myvec.begin() + 5,myvec.end());

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
}