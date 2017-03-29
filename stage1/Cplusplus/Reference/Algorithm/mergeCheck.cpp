// file : mergeCheck.cpp
/****************************************************************************************************
*default(1)	template <class InputIterator1, class InputIterator2, class OutputIterator>
*			OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
*								 InputIterator2 first2, InputIterator2 last2,
*								 OutputIterator result);
*custom(2)	template <class InputIterator1, class InputIterator2,
*					  class OutputIterator, class Compare>
*			OutputIterator merge(InputIterator1 first1, InputIterator1 last1
*								 InputIterator2 first2, InputIterator2 last2,
*								 OutputIterator result, Compare comp);
*****************************************************************************************************/
// template <class InputIterator1, class InputIterator2, class OutputIterator>
// OutputIterator(InputIterator1 first1, InputIterator1 last1,
// 			   InputIterator2 first2, InputIterator2 last2,
// 			   OuptutIterator result)
// {
// 	while(true)
// 	{
// 		if(first1 == last1) return copy(first2,last2,result);
// 		if(first2 == last2) return copy(first1,last1,result);
// 		*result++ = (*first2 < *first1) ? *first2++ : *first1++;
// 	}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int first[] = {5,10,15,20,25};
	int second[] = {50,40,30,20,10};
	vector<int> v(10);

	sort(first,first + 5);
	sort(second,second + 5);

	merge(first,first + 5, second, second + 5, v.begin());

	for(vector<int>::iterator it = v.begin(); it != v.end(); ++ it)
		cout<<*it<<" ";
	cout<<endl;


	int foo[] = {4,3,1,5,6,7,8};
	int bar[] = {2,9};

	unsigned size = sizeof(foo)/sizeof(int) + sizeof(bar)/sizeof(int);
	int* parr = new int [size];

	sort(foo,foo+7);
	sort(bar,bar+2);

	merge(foo,foo + 7, bar, bar + 2, parr);

	for(int i = 0; i < size; ++i)
		cout<<parr[i]<<" ";
	cout<<endl;

	delete[] parr;
	return 0;
}