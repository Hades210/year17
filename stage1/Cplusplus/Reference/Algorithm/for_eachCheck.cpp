// file : for_eachCheck.cpp
// template <class InputIterator, class Function>
//	Function for_each(InputIterator first, InputIterator last, Function fn);
// Applies function fn to each of the elements in the range [first,last)
// The behavior of this template function is equivalent to :
// template <class InputIterator, class Function>
// Function for_each(InputIterator first, InputIterator last, Function fn)
// {
// 	while(first != last)
// 	{
// 		fn(*first);
// 		++ first;
// 	}
// 	return fn; // or, since c++ 11: return move(fn);
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void myfunction(int i) // function
{
	cout<<' '<<i;	
}
struct myclass { // function object type
	void operator() (int i) {cout<<' '<<i;}
}myobject;


int main()
{
	vector<int> myvector;
	myvector = {10, 20, 30};

	cout<<"myvector contains:";
	for_each(myvector.begin(),myvector.end(),myfunction);

	cout<<endl;

	cout<<"myvector contains:";
	for_each(myvector.begin(),myvector.end(),myobject);

	cout<<endl;
		
	return 0;
}

