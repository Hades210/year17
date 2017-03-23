// file : copy_nCheck.cpp
// template <class InputIterator, class Size, class OutputIterator>
//	OutputIterator copy_n(InputIterator first, Size n, OutputIterator result);
// Copies the first n elements from the range beginning at first into the range beginning at result.
// The function returns an iterator to the end of the destination range (which points to one past the last element copied).
// If n is negative, the function does nothing.
// If the ranges overlap. some of the elements in the range pointed by result may have undefined but valid values.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class Size, class OutputIterator>
// OutputIterator copy_n(InputIterator first, Size n, OutputIterator result)
// {
// 	while(n > 0)
// 	{
// 		*result = *first;
// 		++result; ++first;
// 		--n;
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
	copy_n(myints,7,myvec.begin());

	cout<<"myvec contains: ";
	for(auto& x : myvec)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}