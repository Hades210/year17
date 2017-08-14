// file : match_resultsComparisonCheck.cpp
/************************************************************************************************************************************************
*	equality(1)		template <class BidirectionalIterator, class Alloc>
*					bool operator== (const match_results<BidirectionalIterator, Alloc>& lhs,
*									 const match_results<BidirectionalIterator, Alloc>& rhs);
*************************************************************************************************************************************************
*	inequality(2)		template <class BidirectionalIterator, class Alloc>
*					bool operator!= (const match_results<BidirectionalIterator, Alloc>& lhs,
*									 const match_results<BidirectionalIterator, Alloc>& rhs);
*************************************************************************************************************************************************
*The procedure for the equality comparison is as follows (stopping at any point if the procedure finds a conclusive answer)
*	If neither object is ready, true
*	If only one object is ready, false
*	If both objects are empty, true
*	If both prefixes do not compare equal, false.
*	If both sizes are different, false.
*	If the algorithm equal would return false for comparing the ranges of sub_match elements in both objects, false
*	If both suffixs are equal, true
*	Ohterwise, false
*************************************************************************************************************************************************/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	cmatch m1, m2, m3;

	regex_search ("a needle in the hatstack", m1, regex("needle"));
	regex_search ("a needle in the hatstack", m2, regex("needle"));
	regex_search ("the needle in the hatstack", m3, regex("needle"));

	if(m1 == m2)	cout<<"m1 and m2 are equal\n";
	if(m2 != m3)	cout<<"m2 and m3 are not equal\n";
	
	return 0;
}