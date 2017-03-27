// file : is_sortedCheck.cpp
// default(1)	template <class ForwardIterator>
//				bool is_sorted(ForwardIterator first, ForwardIterator last);
// custom(2)	template <class ForwardIterator, class Compare>
//				bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp);
// Returns true if the range [first,last) is sorted into ascending order.
// template <class ForwardIterator>
// bool is_sorted(ForwardIterator first, ForwardIterator last)
// {
// 	if(first == last)	return true;
// 	ForwardIterator next = first;
// 	while(++next != last)
// 	{
// 		if(*next < *first) // or, if (comp(*next,*first)) for version 2
// 			return false;
// 		++first;
// 	}
// 	return true;
// }

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	array<int,4> foo {2,4,1,3};

	do {
		prev_permutation(foo.begin(),foo.end());
		cout<<"foo: ";
		for(int& x : foo)	cout<<x<<" ";	cout<<endl;
	}while(!is_sorted(foo.begin(),foo.end()));
	
	cout<<"The range is sorted.\n";
	return 0;
}