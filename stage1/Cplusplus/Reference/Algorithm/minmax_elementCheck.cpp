// file : min_elementCheck.cpp
/********************************************************************************************************
*	default(1)	template <class ForwardIterator>
*				ForwardIterator min_element(ForwardIterator first, ForwardIterator last);
*	custom(2)	template <class ForwardIterator, class Compare>
*				ForwardIterator min_element(ForwardIterator first, ForwardIterator last,	
*											Compare comp);
********************************************************************************************************/
// Returns an iterator pointing to the element with the smalllest value in the range[first,last).
// The comparisons are performed using either operator< for the first version, or comp for the second version; An element is the 
// smallest if no other element compares less than it. If more than one element fulfills this condition, the iterator returned points
// to the first of such elements.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator>
// ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
// {
// 	if(first == last) return last;
// 	ForwardIterator smallest = first;

// 	while(++first != last)
// 	{
// 		if(*first < *smallest)
// 			smallest = first;
// 	}
// 	return smallest;
// }

/********************************************************************************************************
*	default(1)	template <class ForwardIterator>
*				ForwardIterator max_element(ForwardIterator first, ForwardIterator last);
*	custom(2)	template <class ForwardIterator, class Compare>
*				ForwardIterator max_element(ForwardIterator first, ForwardIterator last,	
*											Compare comp);
********************************************************************************************************/
// Returns an iterator pointing to the element with the largest value in the range[first,last).
// The comparisons are performed using either operator< for the first version, or comp for the second version; An element is the 
// largest if no other element does not compare less than it. If more than one element fulfills this condition, the iterator returned points
// to the first of such elements.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator>
// ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
// {
// 	if(first == last) return last;
// 	ForwardIterator largest = first;

// 	while(++first != last)
// 	{
// 		if(*largest < *first)
// 			largest = first;
// 	}
// 	return largest;
// }

/********************************************************************************************************************************
*	default(1)	template <class ForwardIterator>
*				pair<ForwardIterator,ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last);
*	custom(2)	template <class ForwardIterator, class Compare>
*				pair<ForwardIterator,ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last,	
*											Compare comp);
*********************************************************************************************************************************/
// Returns a pair with an iterator pointing to the element with the smallest value in the range[first,last) as first element, and the
// largest as second.
// The comparisons are performed using either operator< for the first version, or comp for the second version;
// If more than one equivalent element has the smallest value, the first iterator points to the first of such elements.
// If more than one equivalent element has the largest value, the second iterator points to the last of such elements.

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

bool myfn(int i, int j) { return i < j;}

struct myclass {
	bool operator() (int i, int j) { return i < j;}
}myobj;

int main()
{
	int myints[] = {3,7,2,5,6,4,9};

	cout<<"The smallest element is "<<*min_element(myints,myints + 7)<<endl;
	cout<<"The largest element is "<<*max_element(myints,myints + 7)<<endl;

	cout<<"The smallest element is "<<*min_element(myints,myints + 7, myfn)<<endl;
	cout<<"The largest element is "<<*max_element(myints,myints + 7, myfn)<<endl;

	cout<<"The smallest element is "<<*min_element(myints,myints + 7, myobj)<<endl;
	cout<<"The largest element is "<<*max_element(myints,myints+7,myobj)<<endl;
		
	array<int,7> foo {3,7,2,9,5,8,6};

	auto result = minmax_element(foo.begin(),foo.end());
	cout<<"min is "<<*result.first<<" , at position "<<(result.first - foo.begin())<<endl;
	cout<<"max is "<<*result.second<<" , at position "<<(result.second - foo.begin())<<endl;
	
	return 0;
}