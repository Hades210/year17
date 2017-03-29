// file : set_symmetric_differenceCheck.cpp
/**********************************************************************************************
*default(1)	template <class InputIterator1, class InputIterator2, class OutputIterator>
*			OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
*													InputIterator2 first2, InputIterator2 last2,
*													OutputIterator result);
*custom(2) template <class InputIterator1, class InputIterator2, class OutputIterator,
*					 class Compare>
*			OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last,
*													InputIterator2 first2, InputIterator2 last2,
*													OutputIterator result, Compare comp);
**********************************************************************************************/
// Constructs a sorted range beginning in the location pointed by result with the set symmetric difference
// of the two sorted ranges [first1,last1) and [first2,last2).
// template <class InputIterator1, class InputIterator2, class OutputIterator>
// OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1,
// 										InputIterator2 first2, InputIterator2 last2,
// 										OutputIterator result)
// {
// 	while(true)
// 	{
// 		if(first 1 == last1) return copy(first2,last2,result);
// 		if(first2 == last2) return copy(first1,last1,result);

// 		if(*first1 < *first2) {*result = *first1; ++first1; ++result;}
// 		else if (*first2 < *first1) {*result = *first2; ++result; ++first2;}
// 		else {++first1; ++first2;}
// 	}
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int first[] {5,10,15,20,25};
	int second[] {50,40,30,20,10};
	vector<int> myvec (10);

	sort(first,first + 5);
	sort(second,second + 5);

	auto it = set_symmetric_difference(first,first + 5, second, second + 5, myvec.begin());

	myvec.resize(distance(myvec.begin(),it));

	cout<<"The Symmetric difference has "<<myvec.size()<<" elements:"<<endl;
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	
	return 0;
}