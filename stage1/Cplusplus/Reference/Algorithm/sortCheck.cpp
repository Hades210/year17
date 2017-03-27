// file : sortCheck.cpp
// default(1)	template <class RandomAccessIterator>
//				void sort(RandomAccessIterator first, RandomAccessIterator last);
// custom(2)	template <class RandomAccessIterator, class Compare>
//				void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
// sorts the elements in the range [first, last) into ascending order.
// Equivalent elements are not guaranteed to keep their original relative order(see stable_sort).

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfn(int i, int j) {return i < j;}

struct myclass {
	bool operator() (int i, int j) {return i < j;}
}myobj;

int main()
{
	int myints[] = {32,71,12,45,26,80,53,33};
	vector<int> myvec(myints, myints + sizeof(myints) / sizeof (int));

	sort(myvec.begin(),myvec.begin() + 4);
	sort(myvec.begin() + 4, myvec.end(), myfn);

	sort(myvec.begin(),myvec.end(),myobj);

	cout<<"myvec contains: ";
	for(auto& x : myvec )	cout<<x<<" ";	cout<<endl;

	return 0;
}