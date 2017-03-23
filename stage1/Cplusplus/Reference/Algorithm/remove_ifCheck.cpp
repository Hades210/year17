// file : remove_ifCheck.cpp
// template <class ForwardIterator, class UnaryPredicate>
//	ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred);
// Transforms the range[first,last) into a range with all the elements for which pred returns true removed, 
// and returns an iterator to the new end of that range.
// template <class ForwardIterator, class UnaryPredicate>
// ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
// {
// 	ForwardIterator result = first;
// 	while(first != last)
// 	{
// 		if(!pred(*first))
// 		{
// 			*result = *move(first);
// 			++result;
// 		}
// 		++first;
// 	}
// 	return result;
// }

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] = {1,2,3,4,5,6,7,8,9};
	int* pbegin = myints;
	int* pend = myints + sizeof(myints)/sizeof(int);

	pend =remove_if(pbegin,pend,[](int i) {return i % 2;});

	cout<<"myints contains: ";
	while(pbegin != pend)
		cout<<*(pbegin ++)<<" ";
	cout<<endl;

	return 0;
}