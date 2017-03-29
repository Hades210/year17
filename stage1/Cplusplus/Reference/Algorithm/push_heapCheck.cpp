// file : push_heapCheck.cpp
/**********************************************************************************
*default(1)	template <class RandomAccessIterator>
*			void push_heap(RandomAccessIterator first, RandomAccessIterator last);
*custom(2)	template <class RandomAccessIterator, class Compare>
*			void push_heap(RandomAccessIterator first, RandomAccessIterator last,
*						   Compare comp);
***********************************************************************************/
// Given a heap in the range[first,last-1), this function extends the range considered a heap
// to [first,last) by placing the value in (last -1) into its corresponding location within it.
// A range can be organized into a heap by calling make_heap. After that, its heap properties are
// preserved if elements are added and removed from it using push_heap and pop_heap, respectively.
/**********************************************************************************
*default(1)	template <class RandomAccessIterator>
*			void pop_heap(RandomAccessIterator first, RandomAccessIterator last);
*custom(2)	template <class RandomAccessIterator, class Compare>
*			void pop_heap(RandomAccessIterator first, RandomAccessIterator last,
*						   Compare comp);
***********************************************************************************/
/**********************************************************************************
*default(1)	template <class RandomAccessIterator>
*			void make_heap(RandomAccessIterator first, RandomAccessIterator last);
*custom(2)	template <class RandomAccessIterator, class Compare>
*			void make_heap(RandomAccessIterator first, RandomAccessIterator last,
*						   Compare comp);
***********************************************************************************/
/**********************************************************************************
*default(1)	template <class RandomAccessIterator>
*			void sort_heap(RandomAccessIterator first, RandomAccessIterator last);
*custom(2)	template <class RandomAccessIterator, class Compare>
*			void sort_heap(RandomAccessIterator first, RandomAccessIterator last,
*						   Compare comp);
***********************************************************************************/
// The range loses its properties as a heap.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfn(int i, int j) {return i > j;}

int main()
{
	int myints[] = {10,20,30,5,15};
	vector<int> v(myints,myints + 5);

	make_heap(v.begin(),v.end());
	cout<<"initial max heap: "<<v.front()<<endl;

	pop_heap(v.begin(),v.end());
	v.pop_back();
	cout<<"max heap after pop: "<<v.front()<<endl;

	v.push_back(99);
	push_heap(v.begin(),v.end());
	cout<<"max heap after push: "<<v.front()<<endl;

	sort_heap(v.begin(),v.end());
	cout<<"final sorted range: ";
	for(unsigned i = 0; i < v.size(); ++i)
		cout<<" "<<v[i];
	cout<<endl;

	vector<int> minVec(myints,myints + 5);

	make_heap(minVec.begin(),minVec.end(),myfn);
	cout<<"initial min heap: "<<minVec.front()<<endl;

	pop_heap(minVec.begin(),minVec.end(),myfn);
	minVec.pop_back();
	cout<<"min heap after pop: "<<minVec.front()<<endl;

	minVec.push_back(99);
	push_heap(minVec.begin(),minVec.end(),myfn);
	cout<<"min heap after push: "<<minVec.front()<<endl;

	sort_heap(minVec.begin(),minVec.end(),myfn);
	cout<<"final sorted range: ";
	for(unsigned i = 0; i < minVec.size(); ++i)
		cout<<v[i]<<" ";
	cout<<endl;

	return 0;
}