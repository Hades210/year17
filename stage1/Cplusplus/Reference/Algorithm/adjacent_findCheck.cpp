// file : adjacent_findCheck.cpp
/**************************************************************************************************************
*	equality(1)		template<class ForwardIterator>
*						ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);
*	predicate(2)	template<class ForwardIterator>
*						ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last,
*													  BinaryPredicate pred);
***************************************************************************************************************/ 
// Searches the range [first,last) for the first occurrence of two consecutive elements that match, and returns 
// an iterator to the first of these two elements, or last if no such pair is found.
// Two elements match if they compare equal using operator== (or using pred, in version (2))
// The behavior of this function template is equivalent to:
// template <class ForwardIterator>
// ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
// {
// 	if(first != last)
// 	{
// 		ForwardIterator next = first; ++next;
// 		while(next != last)
// 		{
// 			if(*first == *next)
// 				return first;
// 			++first; ++next;
// 		}
// 	}
// 	return last;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool myfunction(int i, int j)
{
	return (i == j);
}

int main()
{
	int myints[] = {5,20,5,30,30,20,10,10,20};
	vector<int> myvec (myints, myints + 9);

	auto it = adjacent_find(myvec.begin(),myvec.end());
	if(it != myvec.end())
		cout<<"the first pair of repeated elements are: "<<*it<<"\n";
	it = adjacent_find(++it,myvec.end(),myfunction);
	if(it!=myvec.end())
		cout<<"the second pair of repeated elements are: "<<*it<<"\n";

	return 0;
}