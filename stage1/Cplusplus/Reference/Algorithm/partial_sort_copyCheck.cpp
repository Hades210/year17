// file : partial_sort_copyCheck.cpp
// default(1)	template <class InputIterator, class RandomAccessIterator>
//				RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last, 
//														RandomAccessIterator result_first,
//														RandomAccessIterator result_last);
// custom(2)	template <class InputIterator, class RandomAccessIterator, class Compare>
//				RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last,
//													   RandomAccessIterator result_first,
//													   RandomAccessIterator result_last, Compare comp);
// Copies the smallest elements in the range [first,last) to [result_first,result_last), sorting the elements copied.
// The number of elements copied is the same as the distance between result_first and result_last (unless this is
// more than the amout of element in [first,last)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {9,8,7,6,5,4,3,2,1};
	vector<int> myvec(5);

	partial_sort_copy(myints,myints + 9, myvec.begin(),myvec.end(),[](int i , int j) {return i < j;});
	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}