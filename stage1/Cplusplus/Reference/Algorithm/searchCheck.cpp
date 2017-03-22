// file : searchCheck.cpp
/******************************************************************************************************
*	equality(1)		template<class ForwardIterator1, class ForwardIterator2>
*					ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
*											ForwradIterator2 first2, ForwardIterator2 last2);
*	predicate(2)	template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
*					ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1,
*											ForwardIterator2 first2, ForwardIterator2 last2,
*											BinaryPredicate pred);
*******************************************************************************************************/
// searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2), and returns
// an iterator to its first element, or last1 if no occurrences are found.
// The elements in both ranges are compared sequentially using operator== (or pred in version 2): A subsequence of [first1,last1)
// is considered a match only when this is true for all the elements of [first2,last2).
// This function returns the first of such occurrences. For an algorithm that returns the last instead, see find_end.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator1, class ForwardIterator2>
// ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
// {
// 	if(first2 == last2) return first1;

// 	while(first1 != last1)
// 	{
// 		ForwardIterator1 it1 = first1;
// 		ForwardIterator2 it2 = first2;
// 		while(*it1 == *it2)
// 		{
// 			++it1; ++it2;
// 			if(it2 == last2) return first1;
// 			if(it1 == last1) return last1;
// 		}
// 		++first1;
// 	}
// 	return last1;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool mypredicate(int i, int j)
{
	return i == j;
}

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10; ++ i)
		myvec.push_back(i*10);

	int needle1[] = {40,50,60,70};
	auto it = search(myvec.begin(),myvec.end(),needle1,needle1 + 4);
	if(it != myvec.end())
		cout<<"needle1 found at position "<<(it-myvec.begin())<<endl;
	else
		cout<<"needle1 not found"<<endl;

	int needle2[] = {20,30,50};
	it = search(myvec.begin(),myvec.end(),needle2,needle2 + 3,mypredicate);
	if(it != myvec.end())
		cout<<"needle2 found at position "<<(it - myvec.begin())<<endl;
	else
		cout<<"needle2 not found"<<endl;
	
	return 0;
}