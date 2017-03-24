// file : remove_copy_ifCheck.cpp
// template <class InputIterator, class OutputIterator, class UnaryPredicate>
//	OutputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred);
// copies the elements in the range[first,last) to the range beginning at result, except those elements for which pred returns true.
// template <class InputIterator, class OutputIterator, class UnaryPredicate>
// OutputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(!pred(*first))
// 		{
// 			*result = *first;
// 			++result;
// 		}
// 		++first;
// 	}
// 	return result;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {1,2,3,4,5,6,7,8,9};
	vector<int> myvec (9);
	auto last = remove_copy_if(myints, myints + 9,myvec.begin(), [](int i) {return i % 2 ;});
	cout<<"myvec contains: ";
	for(auto& x : myvec )	cout<<x<<" ";	cout<<endl;
	myvec.resize(last - myvec.begin());
	cout<<"myvec contains: ";
	for(auto& x : myvec )	cout<<x<<" ";	cout<<endl;

	vector<int> foo {1,2,3,4,5,6,7,8,9};
	vector<int> bar(foo.size());

	vector<int>::iterator lit = remove_copy_if(foo.begin(),foo.end(),bar.begin(),[](int i) {return !(i % 2);});
	cout<<"bar contains: ";
	for(auto& x : bar )	cout<<x<<" ";	cout<<endl;

	bar.resize(lit - bar.begin());
	cout<<"bar contains: ";
	for(auto& x : bar)	cout<<x<<" ";	cout<<endl;
	return 0;
}