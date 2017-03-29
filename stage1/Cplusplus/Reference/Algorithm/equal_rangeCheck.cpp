// file : equal_rangeCheck.cpp
/***************************************************************************************
*default(1)	template <class ForwardIterator, class T>
*			pair<ForwardIterator, ForwardIterator>
*			equal_range(ForwardIterator first, ForwardIterator last, const T& val);
*custom(2)	template <class ForwardIterator, class T, class Compare)
*			pair<ForwardIterator, ForwardIterator>
*			equal_range(ForwardIterator first, ForwardIterator last, const T& val,
*						Compare comp);
***************************************************************************************/
// template <class ForwardIterator, class T>
// pair<ForwardIterator,ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& val)
// {
// 	ForwardIterator it = lower_bound(first,last,val);
// 	return make_pair(it,upper_bound(first,last,val));
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};
	vector<int> myvec(myints, myints + 8);
	pair<vector<int>::iterator, vector<int>::iterator> bounds;

	sort(myvec.begin(),myvec.end());
	bounds = equal_range(myvec.begin(),myvec.end(),20);
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	cout<<"bounds at positions "<<distance(myvec.begin(),bounds.first)
		<<" and "<<distance(myvec.begin(),bounds.second)<<endl;

	sort(myvec.begin(),myvec.end(),[](int i, int j) {return i > j;});
	bounds = equal_range(myvec.begin(),myvec.end(),20, [](int i, int j) { return i > j ;});
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	cout<<"bounds at positions "<<distance(myvec.begin(),bounds.first)
		<<" and "<<distance(myvec.begin(),bounds.second)<<endl;

	return 0;
}
