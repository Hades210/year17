// file : replace_copyCheck.cpp
// template <class InputIterator, class OutputIterator, class T>
// OutputIterator replace_copy(InputIterator first, InputIterator last, 
//							   OutputIterator result, const T& old_value, const T& new_value);
// Copies the elements in the range[first,last) to the range beginning at result, 
// replacing the appearances of old_value by new_value.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class OutputIterator, class T>
// OutputIterator replace_copy(InputIterator first, InputIterator last,
// 							OutputIterator result, const T& old_value, const T& new_value)
// {
// 	while(first != last)
// 	{
// 		*result = (*first == old_value )? new_value : *first;
// 		++first; ++result;
// 	}
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};
	vector<int> myvec(8);

	replace_copy(myints,myints + 8,myvec.begin(),20,99);

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}