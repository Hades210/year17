// file : template <class ForwardIterator>
// template <class ForwardIterator>
// ForwardIterator rotate (ForwardIterator first, ForwardIterator middle, ForwardIterator last);
// Rotates the order of the elements in the range [first, last), in such a way that the element pointed by middle
// becomes the new first element.
// template <class ForwardIterator>
// void rotate (ForwardIterator first, ForwardIterator middle, ForwardIterator last)
// {
// 	ForwardIterator next = middle;
// 	while(first != next)
// 	{
// 		swap(*first++,*next++);
// 		if(next == last)	next =middle;
// 		else if(first == middle)	middle = next;
// 	}
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void myrotate(int* begin, int* middle, int* last)
{
	int* next = middle;
	while(begin != next)
	{
		swap(*(begin++),*(next++));
		if(next == last )	next = middle;
		else if (begin == middle)	middle = next;
	}
}

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10; ++i)	myvec.push_back(i);
	rotate(myvec.begin(),myvec.begin() + 3, myvec.end());
	
	cout<<"myvec contains: ";
	for(auto& x : myvec )	cout<<x<<" ";	cout<<endl;

	int myints[] = {1,2,3,4,5,6,7,8,9};
	
	myrotate(myints,myints + 3, myints + 9);

	cout<<"myints contains: ";
	int* p = myints;
	while(p != myints + 9)	cout<<*(p++)<<" ";	cout<<endl;
	return 0;
}