// file : match_resultsMaxSizeCheck.cpp
/********************************************************************************
*	size_type max_size() const;
*	Returns the maximum number of matches a match_results object can hold.
**********************************************************************************/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	match_results<char*> mr;

	cout<<"max_size: "<<mr.max_size()<<endl;

	return 0;
}