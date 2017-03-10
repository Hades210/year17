// file : unordered_multisetOperationCheck.cpp
/****************************************************************************************************
*	equality(1)		template <class Key, class Hash, class Pred, class Alloc>
*						bool operator== (const unordered_multiset<Key,Hash,Pred,Alloc>& lhs,
*										 const unordered_multiset<Key,Hash,Pred,Alloc>& rhs);
*	inequality(2)	template <class Key, class Hash, class Pred, class Alloc>	
*						bool operator!= (const unordered_multiset<Key,Hash,Pred,Alloc>& lhs,
										 const unordered_multiset<Key,Hahs,Pred,Alloc>& rhs);
****************************************************************************************************/
// The procedure for the equality comparison is as follows(stopping at any point if the procedure finds a 
// conclusive answer):
// First,the sizes are compared.
// For every group of equivalent values(such as those returned by equal_range)
//				sizes are compared(count)
//				all possible permutations of each group are compared(permutation)

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	unordered_multiset<string> 
	a = {"ICML","IEEE","ACM"},
	b = {"ACM","IEEE","ICML"},
	c = {"ACM","ICML","IEEE","ACM"};

	if(a == b) cout << "a and b are equal\n";
	if (b != c) cout<< "b and c are not equal\n";

	return 0;
}
