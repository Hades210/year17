// file : partition_pointCheck.cpp
// template <class ForwardIterator, class UnaryPredicate>
// ForwardIterator partition_point (ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
// Returns an iterator to the first element in the partitioned range [first, last) for which pred is not true, indicating its 
// partition point.
// The elements in the range shall already be partitioned, as if partition had been called with the same arguments.
// template <class ForwardIterator, class UnaryPredicate>
// ForwardIterator partition_point(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
// {
// 	auto n = distance(first, last);

// 	while(n > 0)
// 	{
// 		ForwardIterator it = first;
// 		auto step = n / 2;
// 		advance(it,step);

// 		if(pred(*it)) {first =++it; n -= step + 1;}
// 		else n = step;
// 	}
// 	return first;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> foo {1,2,3,4,5,6,7,8,9};
	vector<int> odd;
	stable_partition(foo.begin(),foo.end(),[](int i) {return i % 2;});

	auto it = partition_point(foo.begin(),foo.end(),[](int i) {return i % 2;});

	odd.assign(foo.begin(),it);
	cout<<"odd contains: "; for(auto& x : odd )	cout<<x<<" ";	cout<<endl;

	return 0;
}