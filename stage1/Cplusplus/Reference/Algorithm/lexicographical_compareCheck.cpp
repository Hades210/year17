// file : lexicographical_compareCheck.cpp
/*************************************************************************************************
*default(1)	template <class InputIterator1, class InputIterator2>
*			bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
*										 InputIterator2 first2, InputIterator2 last2);
*custom(2)	template <class InputIterator1, class InputIterator2, class Compare>
*			bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
*										 InputIterator2 first1, InputIterator2 last2,
*										 Compare comp);										
*************************************************************************************************/
// Returns true if the range [first1,last1) compares lexicographically(alphabetically in dictionaries)
// less than the range [first2,last2).
// template <class InputIterator1, class InputIterator2>
// bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
// 							 InputIterator2 first2, InputIterator2 last2)
// {
// 	while(first1 != last1)
// 	{
// 		if(first2 == last2 || *first2 < *first1) return false;
// 		else if (*first1 < *first2)	return true;
// 		++first1; ++first2;
// 	}
// 	return (first2 != last2);
// }

#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

bool myfn(char c1, char c2)
{
	return tolower(c1) < tolower(c2);
}

int main()
{
	char foo[] = "Apple";
	char bar[] = "apartment";

	cout<<std::boolalpha;

	cout<<"Comparing foo and bar lexicographically(foo < bar) :\n";
	cout<<"Using default comparison (operation <): ";
	cout<<lexicographical_compare(foo,foo+5,bar,bar + 9);
	cout<<endl;

	cout<<"Using myfn as comparison object: ";
	cout<<lexicographical_compare(foo,foo + 5, bar, bar + 9, myfn);
	cout<<endl;

	return 0;
}