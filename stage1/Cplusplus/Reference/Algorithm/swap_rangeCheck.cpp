// file : swap_rangeCheck.cpp
// template <class ForwardIterator1, class ForwardIterator2>
//	ForwardIterator2 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2);
// Exchanges the values of each of the elements in the range [first1,last1) with those of their respective elements
// in the range beginning at first2.
// The function calls swap to exchange the elements.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator1, class ForwardIterator2>
// ForwardIterator2 swap_ranges(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)
// {
// 	while(first1 != last1)
// 	{
// 		swap(*frist1,*first2);
// 		++first1; ++first2;
// 	}
// 	return first2;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> foo (5,10);
	vector<int> bar (5,33);

	swap_ranges(foo.begin() +1, foo.end() -1, bar.begin());

	cout<<"foo contains :";
	for(auto& x : foo)
		cout<<x<<" ";
	cout<<endl;

	cout<<"bar contains :";
	for(auto& x : bar)
		cout<<x<<" ";
	cout<<endl;
	
	return 0;
}
