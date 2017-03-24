// file : unique_copyCheck.cpp
/************************************************************************************************
*	equality(1)		template <class InputIterator, class OutputIterator>
*					OutputIterator unique_copy(InputIterator first, InputIterator last,
*											   OutputIterator result);
*	predicate(2)	template <class InputIterator, class OutputIterator, class BinaryPredicate>
*					OutputIterator unique_copy(InputIterator first, InputIterator last,
*											   OutputIterator result, BinaryPredicate pred);
*************************************************************************************************/
// Copies the elements in the range [first,last) to the range beginning at result, except consecutive
// duplicates .

// template <class InputIterator, class OutputIterator>
// OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result)
// {

// 	if(first == last)	return result;
// 	*result = *first;
// 	while(++ first != last)
// 	{
// 		typename iterator_traits<InputIterator>::value_type val = *first;
// 		if(!(*result == val))
// 		{
// 			*(++result) = val;
// 		}
// 	}
// 	return ++result;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,20,20,30,30,20,20,10};
	vector<int> myvec(9);

	auto it = unique_copy(myints,myints + 9, myvec.begin());

	sort(myvec.begin(),it);

	it = unique_copy(myvec.begin(),it,myvec.begin(),[](int i, int j) {return i == j;});

	myvec.resize(distance(myvec.begin(),it));
	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;

	return 0;
}