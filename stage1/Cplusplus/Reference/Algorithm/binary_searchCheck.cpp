// file : binary_searchCheck.cpp
/********************************************************************************************
*default(1)	template <class ForwardIterator, class T>
*			bool binary_search(ForwardIterator first, ForwardIterator last, const T& val);
*custom(2)	template <class ForwardIterator, class T, class Compare>
*			bool binary_search(ForwardIterator first, ForwardIterator last,
*							   const T& val, Compare comp);
*********************************************************************************************/
// template <class ForwardIterator, class T>
// bool binary_search(ForwardIterator first, ForwardIterator last, const T& val)
// {
// 	first = lower_bound(first,last,val);
// 	return (first != last && !(val<*first));
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int myints[] = {1,2,3,4,5,4,3,2,1};
	vector<int> v (myints, myints + 9);

	sort(v.begin(),v.end());
	cout<<"looking for 3...";
	if(binary_search(v.begin(),v.end(),3))
		cout<<"found\n";
	else
		cout<<"not found\n";

	sort(v.begin(),v.end(),[](int i, int j) {return i < j;});
	cout<<"looking for 6...";
	if(binary_search(v.begin(),v.end(),6,[](int i, int j) {return i < j;}))
		cout<<"found\n";
	else
		cout<<"not found\n";

	return 0;
}