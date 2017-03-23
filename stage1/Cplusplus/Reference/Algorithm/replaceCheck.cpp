// file : replaceCheck.cpp
// template <ForwardIterator, class T>
//	void replace (ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value);
// assigns new_value to all the elements in the range[first,last) that compare equal to old_value.
// The function uses operator== to compare the individual elements to old_value.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator, class T>
// void replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value)
// {
// 	while(first != last)
// 	{
// 		if(*first == old_value) *first = new_value;
// 		++first;
// 	}
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};
	vector<int> myvec(myints,myints + 8);

	replace(myvec.begin(),myvec.end(),20,99);

	cout<<"myvec contains: ";
	for(auto& x : myvec) cout<<x<<" "; cout<<endl;


	return 0;
}