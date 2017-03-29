// file : set_intersectionCheck.cpp
/*****************************************************************************************************
*default(1)	template <class InputIterator1, class InputIterator2, class OutputIterator>
*			OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
*											InputIterator2 first2, InputIterator2 last2,
*											OutputIterator result);
*custom(2)	template <class InputIterator1, class InputIterator2,
*					  class OutputIterator, class Compare>
*			OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
*											InputIterator2 first2, InputIterator2 last2,
*											OutputIterator result, Compare comp);
*******************************************************************************************************/
// Constructs a sorted range beginning in the location pointed by result with the set intersection of the two
// sorted ranges [first1,last1) and [first2,last2)
// template <class InputIterator1, class InputIterator2, class OutputIterator>
// OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
// 								InputIterator2 first2, InputIterator2 last2,
// 								OutputIterator result)
// {
// 	while(first1 != last1 && first2 != last2)
// 	{
// 		if(*first1 < *first2) ++first1;
// 		else if(*first2 < *first1) ++ first2;
// 		else {
// 			*result = *first1;
// 			++ result;
// 			++ first1; ++ first2;
// 		}
// 	}
// 	return result;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int first[] {5,10,15,20,25};
	int second[] {50,40,30,20,10};

	vector<int> v(10);

	sort(first,first + 5);
	sort(second,second + 5);

	auto it = set_intersection(first,first + 5, second, second + 5, v.begin());
	v.resize(distance(v.begin(),it));

	cout<<"The intersection has "<<v.size()<<" elements:"<<endl;
	for(auto& x : v)	cout<<x<<" ";	cout<<endl;

	return 0;
}
