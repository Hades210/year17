// file : is_sorted_untilCheck.cpp
// default(1)	template <class ForwardIterator>
//				ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last);
// custom(2)	template <class ForwardIterator, class Compare>
//				ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last, Compare comp);
//Returns an iterator to the first element in the range [first,last) which does not follow an ascending order.
// template <class ForwardIterator>
// ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last)
// {
// 	if(first == last)	return first;
// 	ForwardIterator next = first;
// 	while(++next != last)
// 	{
// 		if(*next < *first) return next;
// 		++first;
// 	}
// 	return last;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	array<int,4> foo {2,4,1,3};
	array<int,4>::iterator it;

	do {
		prev_permutation(foo.begin(),foo.end());
		cout<<"foo: ";
		for(auto& x : foo)	cout<<x<<" ";
		it = is_sorted_until(foo.begin(),foo.end());
		cout<<" ("<<distance(foo.begin(),it)<<" elements sorted)"<<endl;
	}while(it != foo.end());

	return 0;
}