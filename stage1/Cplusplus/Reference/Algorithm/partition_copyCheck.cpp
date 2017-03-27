// file : partition_copyCheck.cpp
// template <class InputIterator, class OutputIterator1, class OutputIterator2, class UnaryPredicate>
// pair<OutputIterator1,OutputIterator2>
//	partition_copy(InputIterator first, InputIterator last,
//				   OutputIterator1 result_true, OutputIterator2 return_false,
//				   UnaryPredicate pred);	
// Copies the elements in the range [first,last) for which pred returns true into the range pointed by result_true, and 
// those for which it does not into the range pointed by result_false.
// template <class InputIterator, class OutputIterator1, class OutputIterator2, class UnaryPredicate>
// pair<OutputIterator1, OutputIterator2>
// partition_copy(InputIterator first, InputIterator last,
// 			   OutputIterator1 result_true, OutputIterator2 result_false,
// 			   UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(pred(*first))
// 		{
// 			*result_true = *first;
// 			++ result_true;
// 		}
// 		else
// 		{
// 			*result_false = *first
// 			++ result_false;
// 		}

// 		++first;
// 	}
// 	return make_pair(result_true,result_false);
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> foo {1,2,3,4,5,6,7,8,9};
	vector<int> odd,even;

	unsigned int n = count_if(foo.begin(),foo.end(), [](int i) {return i % 2;});
	odd.resize(n);
	even.resize(foo.size() - n);

	partition_copy(foo.begin(),foo.end(),odd.begin(),even.begin(), [](int i) { return i % 2;});

	cout<<"odd contains: "; for(auto& x : odd )	cout<<x<<" ";	cout<<endl;
	cout<<"even contains: "; for(auto& x : even )	cout<<x<<" ";	cout<<endl;

	return 0;
}