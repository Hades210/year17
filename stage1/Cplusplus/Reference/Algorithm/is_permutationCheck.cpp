// file : is_permutationCheck.cpp
/**************************************************************************************************
*	equality(1)	template<class ForwardIterator1, class ForwardIterator2>
*				bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1,
*									ForwardIterator2 first2);
*	predicate(2)template<class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
*				bool is_permutation(ForwardIterator1 first1, ForwardIterator last1,
*									ForwardIterator2 first2, BinaryPredicate pred);
**************************************************************************************************/
// compares the elements in the range [first1,last1) with those in the range beginning at first2, and returns true if all
// of the elements in both ranges match, even in a different order.
// The elements are compared using operator== (or pred, in version 2)
// The behavior of this function template is equivalent to :
// template <class InputIterator1, class InputIterator2>
// bool is_permutation(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
// {
// 	tie(first1,first2) = mismatch(first1,last1,first2);
// 	if(first1 == last1)
// 		return true;
// 	InputIterator2 last2 = first2;
// 	advance(last2,distance(first1,last1));
// 	for(InputIterator1 it1 = first1; it1 != last1; ++it1)
// 	{
// 		if(find(first1,it1,*it1) == it1)
// 		{
// 			auto n = count(first2,last2,*it1);
// 			if(n==0 || count(it1,last1,*it1)!= n)
// 				return false;
// 		}
// 	}
// 	return true;
// }

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	array<int,5> foo {1,2,3,4,5};
	array<int,5> bar {3,1,4,5,2};

	if(is_permutation(foo.begin(),foo.end(),bar.begin()))
		cout<<"foo and bar contain the same elements.\n";

	return 0;
}