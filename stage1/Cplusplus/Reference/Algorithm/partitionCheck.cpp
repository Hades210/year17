// file : partitionCheck.cpp
// template <class ForwardIterator, class UnaryPredicate>
// ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
// Rearranges the elements from the range[first,last), in such a way that all the elements for which pred returns
// true precede all those for which it returns false. The iterator returned points to the first element of the second group.
// The relative ordering within each group is not necessarily the same as before the call. See stable_partition for a 
// function with a simalar behavior but with stable ordering within each group.
// template <class BidirectionalIterator, class UnaryPredicate>
// BidirectionalIterator partition(BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		while(pred(*first))
// 		{
// 			++first;
// 			if(first == last)
// 				return first;
// 		}
// 		do {
// 			--last;
// 			if(first==last)
// 				return first;

// 		}while(!pred(*last));
// 		swap(*first,*last);
// 		++first;
// 	}
// 	return first;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10; ++i)	myvec.push_back(i);

	auto bound = partition(myvec.begin(),myvec.end(),[](int i) {return i % 2;});

	cout<<"odd elements:";
	for(auto it = myvec.begin(); it != bound; ++it)	cout<<" "<<*it;	cout<<endl;
	cout<<"even elements:";
	for(auto it = bound; it != myvec.end(); ++it) cout<<" "<<*it;		cout<<endl;
	
	return 0;
}