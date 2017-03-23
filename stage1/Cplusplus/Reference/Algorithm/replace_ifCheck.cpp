// file : replace_ifCheck.cpp
// template <class ForwardIterator, class UnaryPredicate, class T>
// void replace_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_value);
// Assigns new_value to all the elements in the range[first,last) for which pred returns true.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator, class UnaryPredicate, class T>
// void replace_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred, const T& new_value)
// {
// 	while(first != last)
// 	{
// 		if(pred(*first)) *first = new_value;
// 		++first;
// 	}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> myvec;

	for(int i =1; i < 10; ++ i) myvec.push_back(i);
	replace_if(myvec.begin(),myvec.end(),[](int i) {return i % 2;}, 0);
	cout<<"myvec contains: ";
	for(auto& x : myvec) cout<<x<<" "; cout<<endl;
	return 0;
}