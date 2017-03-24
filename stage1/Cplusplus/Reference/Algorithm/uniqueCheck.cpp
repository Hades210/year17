// file : uniqueCheck.cpp
/**************************************************************************************************
*	equality(1)	template <class ForwardIterator>
*				ForwardIterator unique(ForwardIterator first, ForwardIterator last);
*	predicate(2)template <class ForwardIterator, class BinaryPredicate>
*				ForwardIterator unique(ForwardIterator first, ForwardIterator last,
*									   BinaryPredicate pred);
***************************************************************************************************/
// Removes all but the first element from every consecutive group of equivalent elements in the range [first,last).
// The function cannot alter the properties of the object containint the range of elements.
// The relative order of the elements not removed is preserved, while the elements between the returned iterator and last
// are left in a valid but unspecified state.
// template <class ForwardIterator?
// ForwardIterator unique(ForwardIterator first, ForwardIterator last)
// {
// 	ForwardIterator result = first;
// 	if(first == last ) return last;

// 	while(++first != last)
// 	{
// 		if(!(*result == *first))
// 		{
// 			*(++result) = *first;
// 		}
// 	}
// 	return ++result;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {10,20,20,20,30,30,20,20,10};
	vector<int> myvec(myints,myints + 9);

	auto it = unique(myvec.begin(),myvec.end());
	myvec.resize(distance(myvec.begin(),it));

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;

	vector<int> myvec2(myints,myints + 9);
	auto it2 = unique(myvec2.begin(),myvec2.end(),[](int i, int j) {return i == j;});
	myvec2.resize(distance(myvec2.begin(),it2));
	cout<<"myvec2 contains: ";
	for(auto& x : myvec2)	cout<<x<<" ";	cout<<endl;

	return 0;
}