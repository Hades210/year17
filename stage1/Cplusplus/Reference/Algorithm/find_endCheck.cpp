// file : find_endCheck.cpp
/****************************************************************************************************************
*	equality(1)		template <class ForwardIterator1,class ForwardInterator2>
*					ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
*											  ForwardIterator2 first2, FOrwardIterator2 last2);
*	predicate(2)	template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
*					ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
*											  ForwardIterator2 first2, ForwardIterator2 last2,
*											  BinaryPredicate pred);
******************************************************************************************************************/
// Searches the range[first1,last1) for the last occurrence of the sequence defined by[first2,last2), and returns an
// iterator to its first element, or last1 if no occurrences are found.
// The elements in both ranges are compared sequentially using operator== (or pred). A subsequence of [first1,last1) is 
// considered a match only when this is true for all the elements of [first2,last2)
// This function returns the last of such occurrences. FOr an algorithm that returns the first instead, see search.
// The behavior of this function template is equivalent to:
// template<class ForwardIterator1,class ForwardIterator2>
// ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1,
// 						  ForwardIterator2 first2, ForwardIterator2 last2)
// {
// 	if(first2 == last2) return last1;

// 	ForwardIterator ret = last1;

// 	while(first1 != last1)
// 	{
// 		ForwardIterator1 it1 = first1;
// 		ForwardIterator2 it2 = first2;
// 		while(*it1 == *it2) // while(pred(*it1,*it2)) for version 2
// 		{
// 			++it1; ++it2;
// 			if(it2 == last2) {ret = first1; break;}
// 			if(it1==last1) return ret;
// 		}
// 		++first1;
// 	}
// 	return ret;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction(int i, int j)
{
	return i == j;
}

int main()
{	
	int myints[] = {1,2,3,4,5,1,2,3,4,5};
	vector<int> myvec(myints, myints + 10);

	int needle1[] = {1,2,3};

	auto it = find_end(myvec.begin(),myvec.end(),needle1,needle1 + 3);
	if(it != myvec.end())
		cout<<"needle1 last found at position "<<(it-myvec.begin())<<"\n";

	int needle2[] = {4,5,1};
	it = find_end(myvec.begin(),myvec.end(),needle2,needle2+3,myfunction);
	if(it != myvec.end())
		cout<<"needle2 last found at position "<<(it-myvec.begin())<<"\n";
	
	return 0;
}