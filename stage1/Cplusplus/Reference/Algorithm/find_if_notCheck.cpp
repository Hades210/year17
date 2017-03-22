// file : find_if_notCheck.cpp
// template <class InputIterator, class UnaryPredicate>
//	InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns an iterator to the first element in the range [first, last) for which pred returns false. If no such element is found,
// the function returns last.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class UnaryPredicate>
// InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(!pred(first)) return first;
// 		++ first;
// 	}

// 	return last; 
// }

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	array<int,5> foo {1,2,3,4,5};

	auto it = find_if_not(foo.begin(),foo.end(), [](int i){ return i % 2 ;});

	if(it != foo.end())
		cout<<"The first even value is "<<*it<<endl;
	return 0;
}