// file : search_nCheck.cpp
/*********************************************************************************************************
*	equality(1)		template <class ForwardIterator, class Size, class T>
*					ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
*											  Size count, const T& val);
*	predicate(2)	template <class ForwardIterator class Size, class T, class BinaryPredicate>
*					ForwardIterator search_n (ForwardIterator first, ForwardIterator last,
*											  Size count, const T& val, BinaryPredicate pred);
*********************************************************************************************************/
// searches the range [first, last) for a sequence of count elements, each comparing equal to val(or for which pred returns true)
// The function returns an iterator to the first of such elements, or last if no such sequence is found.
// The behavior of this function template is equivalent to:
// template <class ForwardIterator, class Size, class T>
// ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Size count, const T& val)
// {
// 	ForwardIterator it, limit;
// 	Size i;

// 	limit=first; advance(limit,distance(first,last) - count);

// 	while(first != limit)
// 	{
// 		it = first; i = 0;
// 		while(*it == val)
// 		{
// 			++it;
// 			if(++i == count )
// 				return first;
// 		}
// 	}
// 	return last;
// }


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool mypredicate(int i, int j)
{
	return i==j;
}

int main()
{
	int myints[] = {10,20,30,30,20,10,10,20};

	vector<int> myvec (myints, myints + 8);

	auto it = search_n(myvec.begin(),myvec.end(),2,30);
	if(it != myvec.end())
		cout<<"two 30s found at position "<<(it - myvec.begin())<<endl;
	else
		cout<<"match not found\n";

	it = search_n(myvec.begin(),myvec.end(),2,10,mypredicate);
	if(it!= myvec.end())
		cout<<"two 10s found at positioin "<<(it- myvec.begin())<<endl;
	else
		cout<<"match not found\n";

	return 0;
}