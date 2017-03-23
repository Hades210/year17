// file : copyCheck.cpp
// template <class InputIterator, class OutputIterator>
//	OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);
// Copies the elements in the range[first,last) into the range beginning at result.
// The function returns an iterator to the end of the destination range(which points to the element following the last element copied).
// The ranges shall not overlap in such a way that result points to an element in the range[first,last). For such cases, see copy_backward.
// The behavior of this function template is equivalent to :
// template <class InputIterator, class OutputIterator>
// OutputIterator copy(InputItetator first, InputIterator last, OutputIterator result)
// {
// 	while(first != last)
// 	{
// 		*result = *first;
// 		++first; ++result;
// 	}
// 	return result;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,30,40,50,60,70};
	vector<int> myvec(7);

	copy(myints,myints + 7, myvec.begin());

	cout<<"myvec contains: ";
	for(auto & x : myvec )
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}