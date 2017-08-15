// file : match_resultsAccessCheck.cpp
/************************************************************************
*	const_reference operator[](size_type n) const;
*	Returns the n-th match in a match_results object that is ready.
*************************************************************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	cmatch m;

	regex_match("subject", m, regex("(sub)(.*)"));

	for(unsigned i = 0; i < m.size(); ++ i)
	{
		cout<<"match "<<i<<": "<<m[i];
		cout<<" (with a length of "<<m[i].length()<<")\n";
	}

	return 0;
}