// file : lower_boundCheck.cpp
// default(1)	template <class ForwardIterator, class T>
// 				ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val);
//custom(2)		template <class ForwardIterator, class T, class Compare>
//				ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val, Compare comp);
// template <class ForwardIterator, class T>
// ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& val)
// {
// 	ForwardIterator it;
// 	iterator_traits<ForwardIterator>::difference_type count, step;
// 	count = distance(first,last);
// 	while(count > 0)
// 	{
// 		it = first;
// 		step = count/2;
// 		advance(it,step);
// 		if(*it < val)
// 		{
// 			first = ++it;
// 			count -=step + 1;
// 		}
// 		else
// 			count = step;
// 	}
// 	return first;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};
	vector<int> myvec (myints,myints + 8);
	sort(myvec.begin(),myvec.end());

	vector<int>::iterator low,up;
	low = lower_bound(myvec.begin(),myvec.end(),20);
	up = upper_bound(myvec.begin(),myvec.end(),20);

	cout<<"lower_bound at position "<<(low-myvec.begin())<<endl;
	cout<<"lower_bound at position "<<distance(myvec.begin(),low)<<endl;
	cout<<"upper_bound at position "<<(up - myvec.begin())<<endl;
	cout<<"upper_bound at position "<<distance(myvec.begin(),up)<<endl;

	return 0;
}