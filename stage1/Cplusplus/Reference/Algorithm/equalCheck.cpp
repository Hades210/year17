// file : equalCheck.cpp
/*****************************************************************************************************
*	equality(1)		template <class InputIterator1, class InputIterator2>
*					bool equal(InputIterator1 first1, InputIterator1 last1,
*							   InputIterator2 first2);
*	predicate(2)	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
*					bool equal(InputIterator1 first, InputIterator1 last1,
*							   InputIterator2 first2, BinaryPredicate pred);
******************************************************************************************************/
// compares the elements in the range [first1,last1) with those in the range beginning at first2, and 
// returns true if all of the elements in both ranges match.
// The elements are compared in both ranges match.
// The elements are compared using operator== (or pred, in version 2)
// The behavior of this function template is equivalent to:
// template <class InputIterator1, class InputIterator2>
// bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
// {
// 	while(first1 != last1)
// 	{
// 		if(!(*first1 == *first2))
// 			return false;
// 		++first1; ++first2;
// 	}
// 	return true;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool mypredicate(int i, int j) {return i == j;}

int main()
{
	int myints[] = {20,40,60,80,100};
	vector<int> myvec(myints, myints + 5);

	if(equal(myvec.begin(),myvec.end(),myints))
		cout<<"The contents of both sequences are equal.\n";
	else
		cout<<"The contents of both sequences differ.\n";

	myvec[3] += 1;

	if(equal(myvec.begin(),myvec.end(),myints))
		cout<<"The contents of both sequences are equal.\n";
	else
		cout<<"The contents of both sequences differ.\n";

	return 0;
}