// file : remove_copyCheck.cpp
// template <class InputIterator, class OutputIterator, class T>
//	OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T& val);
// copies the elements in the range[first,last) to the range beginning at result, except those elements that compare
// equal to val.
// The resulting range is shorter than [first,last) by as many elements as matches in the sequence, which are "removed"
// The behavior of this function template is equivalent to:
// template <class InputIterator, class OutputIterator, class T>
// OutputIterator remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T& val)
// {
// 	while(first != last)
// 	{
// 		if(!(*first == val))
// 		{
// 			*result = *first;
// 			++result;
// 		}
// 		++first;
// 	}
// 	return result;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};
	vector<int> myvec(8);

	remove_copy(myints,myints + 8, myvec.begin(),20);

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}