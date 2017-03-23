// file : transformCheck.cpp
/****************************************************************************************************************
*	unary operation(1)	template <class InputIterator, class OutputIterator, class UnaryOperation>
*						OutputIterator transform(InputIterator first1, InputIterator last1,
*												 OutputIterator result, UnaryOperation op);
*	binary operation(2)	template <class InputIterator1, class InputIterator2,
*								  class OutputIterator, class BinaryOperation>
*						OutputIterator transform(InputIterator1 first1, InputIterator1 last1,
*												 InputIterator2 first2, OutputIterator result,
*												 BinaryOperation binary_op);
****************************************************************************************************************/
// Applies an operation sequentially to the elements of one(1) or two(2) ranges and stores the result in the range that
// begins at result.
// (1)	Applies op to each of the elements in the range [first1,last1) and stroes the value returned by each operation
// in the range that begins at result.
// (2)	calls binary_op using each of the elements in the range[first1,last1) as first argument, and the respective
// argument in the range that begins at first2 as second argument. The value returned by each call is stored in the 
// range that begins at result.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class OutputIterator, class UnaryOperation>
// OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation op)
// {
// 	while(first != last)
// 	{
// 		*result = op(*first); // or *result = binary_op(*first,*first2++);
// 		++result; ++first;
// 	}
// 	return result;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int op_increase(int i) {return ++i;}

int main()
{
	vector<int> foo;
	vector<int> bar;

	for(int i = 1; i < 6; ++i)
		foo.push_back(i * 10);

	bar.resize(foo.size());

	transform(foo.begin(),foo.end(),bar.begin(),op_increase);

	cout<<"bar contains: ";
	for(auto& x : bar)	cout<<x<<" "; cout<<endl;

	transform(foo.begin(),foo.end(),bar.begin(),foo.begin(),plus<int>());
	cout<<"foo contains: ";
	for(auto& x : foo)	cout<<x<<" "; cout<<endl;
	
	return 0;
}