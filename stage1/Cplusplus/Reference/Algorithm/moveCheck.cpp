// file : moveCheck.cpp
// template <class InputIterator, class OutputIterator>
// OutputIterator move(InputIterator first, InputIterator last, OutputIterator result);
// Moves the elements in the range[first,last) into the range beginning at result.
// The value of the elements in the [first,last) is transferred to the elements pointed by result. After the call, the
// elements in the range[first,last) are left in an unspecified but valid state.
// The ranges shall not overlap in such a way that result points to an elment in the range[first,last). For such cases, see move_backward.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class OutputIterator>
// OutputIterator move(InputIterator first,InputIterator last, OutputIterator result)
// {
// 	while(first != last)
// 	{
// 		*result = std::move(*first);
// 		++result; ++first;
// 	}
// 	return result;
// }

#include <iostream>
#include <algorithm> // std::move(ranges)
#include <utility> // std::move(objects)
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> foo {"air","water","fire","earth"};
	vector<string> bar(4);

	cout<<"Moving ranges...\n";
	move(foo.begin(),foo.begin() + 4,bar.begin());

	cout<<"foo contains "<<foo.size()<<" elements:";
	cout<<"(each in an unspecified but valid state)"<<endl;
	// for(auto& x : foo)	cout<<" ["<<x<<"]";
	// cout<<endl;

	cout<<"bar contains "<<bar.size()<<" elements:";
	for(string& x : bar)
		cout<<" ["<<x<<"]";
	cout<<endl;

	cout<<"Moving container...\n";
	foo = move(bar);

	cout<<"foo contains "<<foo.size()<<" elements:";
	for(string& x : foo) cout<<" ["<<x<<"]";
	cout<<endl;
	
	cout<<"bar is in an unspecified but valid state"<<endl;

	// for(auto& x : bar)	cout<<" ["<<x<<"]";
	// cout<<endl;

	return 0;
}