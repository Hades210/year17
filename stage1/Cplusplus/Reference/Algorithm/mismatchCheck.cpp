// file : mismatchCheck.cpp
/*******************************************************************************************************
*	equality(1)		template<class InputIterator1,class InputIterator2>
*					pair<InputIterator1, InputIterator2>
*					mismatch(InputIterator1 first1, InputIterator1 last1,
*							 InputIterator2 first2);
*	predicate(2)	template<class InputIterator1, class InputIterator2, class BinaryPredicate>
*					pair<InputIterator1, InputIterator2>
*					mismatch(InputIterator1 first1, InputIterator last1,
*							 InputIterator2 first2, BinaryPredicate pred);
********************************************************************************************************/
// compares the elements in the range[first1,last1) with those in the range beginning at first2, and returns
// the first element of both sequences that does not match.
// The elements are compared using operator== (or pred in version 2).
// The function returns a pair of iterators to the first element in each range that does not match.
// The behavior of this function template is equivalent to:
// template <class InputIterator1, class InputIterator2>
// pair<InputIterator1,InputIterator2> 
// mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
// {
// 	while((first1 != last1) && (*first1 == *first2))
// 	{
// 		++first1; ++first2;
// 	}
// 	return make_pair(first1,first2);
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility> // pair

using namespace std;

bool mypredicate(int i, int j)
{
	return i==j;
}

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 6; ++i)
		myvec.push_back(i * 10);
	int myints[] = {10,20,80,320,1024};

	pair<vector<int>::iterator,int*> mypair;

	mypair = mismatch(myvec.begin(),myvec.end(),myints);
	cout<<"First mismatching elements: "<<*mypair.first;
	cout<<" and "<<*mypair.second<<endl;

	++mypair.first;
	++mypair.second;

	mypair = mismatch(mypair.first,myvec.end(),mypair.second,mypredicate);
	cout<<"Second mismatching elements: "<<*mypair.first;
	cout<<" and "<<*mypair.second<<endl;
	
	return 0;
}
