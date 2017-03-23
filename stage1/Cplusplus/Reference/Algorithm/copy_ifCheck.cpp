// file : copy_ifCheck.cpp
// template <class InputIterator, class OutputIterator, class UnaryPredicate>
//	OutputIterator copy_if(InputIterator first, InputIterator last,
//						   OutputIterator result, UnaryPredicate pred);
// copies the elements in the range[first,last) for which pred returns true to the range beginning at result.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class OutputIterator, UnaryPredicate>
// OutputIterator copy_if(InputIterator first, InputIterator last, OutputIterator result, UnaryPredicate pred)
// {
// 	while(first != last)
// 	{
// 		if(pred(*first))
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
	int myints[] {1,2,3,4,5,6,7,8,9,10};

	vector<int> myvec(5);

	copy_if(myints,myints + 10, myvec.begin(), [](int i) {return i % 2;});

	cout<<"myvec contains : ";
	for(auto& x : myvec)
		cout<<x<<" ";
	cout<<endl;

	vector<int> foo = {25,15,5,-5,-15};
	vector<int> bar(foo.size());

	auto it = copy_if(foo.begin(),foo.end(),bar.begin(),[](int i) { return !(i<0);});
	bar.resize(distance(bar.begin(),it));
	cout<<"bar contains : ";
	for(auto& x : bar)
		cout<<x<<" ";
	cout<<endl;

	return 0;
}