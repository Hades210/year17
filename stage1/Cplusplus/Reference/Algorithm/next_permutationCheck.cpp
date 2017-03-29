// file : next_permutationCheck.cpp
/*********************************************************************************************************
*default(1) template <class BidirectionalIterator>
*			bool next_permutation(BidirectionalIterator first, BidirectionalIterator last);
*custom(2)	template <class BidirectionalIterator, class Compare>
*			bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);
**********************************************************************************************************/
/*********************************************************************************************************
*default(1) template <class BidirectionalIterator>
*			bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last);
*custom(2)	template <class BidirectionalIterator, class Compare>
*			bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp);
**********************************************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int myints[] {1,2,3};
	sort(myints,myints + 3);

	cout<<"The 3! possible permutations with 3 elements"<<endl;

	do {
		cout<<myints[0]<<" "<<myints[1]<<" "<<myints[2]<<endl;
	}while(next_permutation(myints,myints + 3));

	cout<<"after loop: "<< myints[0]<<" "<<myints[1]<<" "<<myints[2]<<endl;


	reverse(myints,myints+3);

	cout<<"The 3! possible permutations with 3 elements"<<endl;

	do {
		cout<<myints[0]<<" "<<myints[1]<<" "<<myints[2]<<endl;
	}while(prev_permutation(myints,myints + 3));
	cout<<"after loop: "<< myints[0]<<" "<<myints[1]<<" "<<myints[2]<<endl;

	return 0;
}


