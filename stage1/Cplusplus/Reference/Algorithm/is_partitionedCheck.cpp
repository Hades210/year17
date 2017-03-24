// file : is_partitionedCheck.cpp
// template <class InputIterator, class UnaryPredicate>
//	bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred);
// Returns true if all the elements in the range [first, last) for which pred returns true precede those for which 
// it returns false.
// If the range is empty, the function returns true.
// template <class InputIterator , class UnaryPredicate>
// bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred)
// {
// 	while((first != last) && pred(*first))
// 		++first;
// 	while(first != last)
// 	{
// 		if(pred(*first)) return false;
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
	array<int,7> foo {1,2,3,4,5,6,7};
	cout<<"foo:"; for(auto& x : foo) cout<<x<<" ";
	if(is_partitioned(foo.begin(),foo.end(),[](int i){return i % 2;}))
		cout<<" (partitioned)"<<endl;
	else
		cout<<" (not partitioned)"<<endl;

	partition(foo.begin(),foo.end(),[](int i) {return i % 2;});
	cout<<"foo:"; for(auto& x : foo) cout<<x<<" ";
	if(is_partitioned(foo.begin(),foo.end(),[](int i){return i % 2;}))
		cout<<" (partitioned)"<<endl;
	else
		cout<<" (not partitioned)"<<endl;

	return 0;
}