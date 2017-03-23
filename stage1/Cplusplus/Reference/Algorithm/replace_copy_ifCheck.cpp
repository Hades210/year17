// file : replace_copy_ifCheck.cpp
// template <class InputIterator, class OutputIterator, class UnaryPredicate, class T>
//	OutputIterator replace_copy_if(InputIterator first, InputIterator last,	
//								   OutputIterator result, UnaryPredicate pred,
//								   const T& new_value);
// copies the elements in the range[first,last) to the range begining at result, replacing those for which pred returns true by new_value.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class OutputIterator, class unaryPredicate, class T>
// OutputIterator replace_copy_if(InputIterator first, InputIterator last,
// 							   OutputIterator result, UnaryPredicate pred, const T& new_value)
// {
// 	while(first != last)
// 	{
// 		*result = (pred(*first)) ? new_value : *first;
// 		++first; ++result;
// 	}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> foo,bar;

	for(int i =1; i < 10; ++i) foo.push_back(i);

	bar.resize(foo.size());
	replace_copy_if(foo.begin(),foo.end(),bar.begin(),[](int i){return i % 2;},0);

	cout<<"bar contains: ";
	for(auto& x : bar)	cout<<x<<" ";	cout<<endl;
	return 0;
}