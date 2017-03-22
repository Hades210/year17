// file : findCheck.cpp
// template <class InputIterator, class T>
//	InputIterator find(InputIterator first, InputIterator last, const T& val);
// Returns an iterator to the first element in the range[first, last) that compares equal to val. If no such element is found,
// the function returns last.
// The function uses operator== to compare the individual elements to val.
// The behavior of this function template is equivalent to:
// template <class InputIterator, class T>
// InputIterator find(InputIterator first, InputIterator last, const T& val)
// {
// 	while(first != last)
// 	{
// 		if(*first == val)
// 			return first;
// 		++ first;
// 	}
// 	return last;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,30,40,};
	int* p;

	p = find(myints,myints + 4, 30);
	if(p != myints + 4)
		cout<<"Element found in myints: "<<*p<<"\n";
	else
		cout<<"Element not found in myints\n";

	vector<int> myvec(myints,myints + 4);
	auto it = find(myvec.begin(),myvec.end(),30);

	if(it != myvec.end())
		cout<<"Element found in myvec: "<<*it<<"\n";
	else
		cout<<"Element not found in myvec\n";
	
	return 0;
}