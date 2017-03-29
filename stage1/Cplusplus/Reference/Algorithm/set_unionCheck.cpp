// file : set_unionCheck.cpp
/********************************************************************************************
*default(1)	template <class InputIterator1, class InputIterator2, class OutputIterator>
*			OutputIterator set_union(InputIterator1 first1, InputIterator1 last1,
*									 InputIterator2 first2, InputIterator2 last2,
*									 OutputIterator result);										
*custom(2) template <class InputIterator1, class InputIterator2, class OutputIterator,
*					 class Compare>
*		   OutputIterator set_union(InputIterator1 first1, InputIterator1 last1,
*									InputIterator2 first2, InputIterator2 last2,
*									OutputIterator result, Compare comp);
********************************************************************************************/
// constructs a sorted range beginning in the location pointed by result with the set union of the
// two sorted ranges [first1,last1) and [first2,last2).
// The union of two sets is formed by the elements that are present in either one of the sets, or in both.
// template <class InputIterator1,class InputIterator2,class OutputIterator>
// OutputIterator set_union(InputIterator1 first1, InputIterator1 last1,
// 						 InputIterator2 first2, InputIterator2 last2,
// 						 OutputIterator result)
// {
// 	while(true)
// 	{
// 		if(first1 == last1) return copy(first2,last2,result);
// 		if(first2 == last2) return copy(first1,last1,result);

// 		if(*first1 < *first2) {*result = *first1; ++first1;}
// 		else if (*first2 < *first1) {*result = *first2; ++first2;}
// 		else {*result = *first1; ++first1; ++first2;}
// 		++result;
// 	}
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int first[] = {5,10,15,20,25};
	int second[] = {50,40,30,20,10};
	vector<int> myvec(10);

	sort(first,first + 5);
	sort(second,second + 5);

	auto it = set_union(first,first + 5, second,second + 5, myvec.begin());

	myvec.resize(distance(myvec.begin(),it));

	cout<<"The union has "<<myvec.size()<<" elements:"<<endl;
	for(auto& x : myvec)
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}