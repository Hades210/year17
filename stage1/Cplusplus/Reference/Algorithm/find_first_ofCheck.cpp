// file : find_first_ofCheck.cpp
/****************************************************************************************************************
*	equality(1)		template <class InputIterator,class ForwardIterator>
*					InputIterator find_first_of(InputIterator first1, InputIterator last1,
*											  ForwardIterator first2, FOrwardIterator last2);
*	predicate(2)	template <class InputIterator, class ForwardIterator, class BinaryPredicate>
*					InputIterator find_first_of(InputIterator first1, InputIterator last1,
*											  ForwardIterator first2, ForwardIterator last2,
*											  BinaryPredicate pred);
******************************************************************************************************************/
// Returns an iterator to the first element in the range [first1,last1) that matches any of the elements in [first2,last2).
// If no such element is found, the function returns last1.
// The elements in [first1,last1) are sequentially compared to each of the values in [first2,last2) using operator== (or
// pred in version(2)),until a pair matches.
// The behavior of this function template is equivalent to:
// template<class InputIterator, class ForwardIterator>
// InputIterator find_first_of(InputIterator first1, InputIterator last1,
// 							ForwardIterator first2, ForwardIterator last2)
// {
// 	while(first1 != last1)
// 	{
// 		for(ForwardIterator it = first2; it != last2; ++it)
// 		{
// 			if(*it==*first1)
// 				return first1;
// 		}
// 		++first1;
// 	}
// 	return last1;
// }

#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>

using namespace std;

bool comp_case_insensitive(char c1, char c2)
{
	return tolower(c1) == tolower(c2);
}

int main()
{
	char mychars[] {'a','b','c','A','B','C'};
	vector<char> myvec(mychars,mychars + 6);

	char needle[] {'A','B','C'};

	auto it = find_first_of(myvec.begin(),myvec.end(),needle,needle + 3);
	if(it != myvec.end())
		cout<<"The first match is : "<<*it<<endl;

	it = find_first_of(myvec.begin(),myvec.end(),needle,needle + 3, comp_case_insensitive);
	if(it != myvec.end())
		cout<<"The first match is: "<<*it<<endl;

	return 0;
}