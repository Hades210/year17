// file : unordered_mapComparisonCheck.cpp
/**************************************************************************************************
*	equality(1)		template <class Key, class T, class Hash, class Pred, class Alloc>
*						bool operator== (const unordered_map<Key,T,Hash,Pred,Alloc>& lhs,
*										 const unordered_map<Key,T,Hash,Pred,Alloc>& rhs);
*	inequality(2)	template <class Key, class T, class Hash, class Pred, class Alloc>
*						bool operator!= (const unordered_map<Key,T,Hash,Pred,Alloc>& lhs,
*										 const unordered_map<Key,T,Hash,Pred,Alloc>& rhs);											
****************************************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

typedef unordered_map<string,string> STRMAP;

int main()
{
	STRMAP a = {{"AAPL","Apple"},{"MSFT","Microsoft"},{"GOOG","Google"}};
	STRMAP b = {{"MSFT","Microsoft"},{"GOOG","Google"},{"AAPL","Apple"}};
	STRMAP c = {{"MSFT","Microsoft Corp."},{"GOOG","Google Inc."},{"AAPL","Apple Inc."}};

	if(a == b)
		cout<<"a and b are equal\n";
	if(b != c)
		cout<<"b and c are not equal\n";

	return 0;
}
