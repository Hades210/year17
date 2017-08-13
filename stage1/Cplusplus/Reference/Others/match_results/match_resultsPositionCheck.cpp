// file : match_resultsPositionCheck.cpp
/*********************************************************
*	difference_type position (size_type n = 0) const;
*	Return position of match
*********************************************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string s("test subject");
	smatch m;
	regex e("(sub)(.*)");

	regex_search( s, m, e);

	for(unsigned i = 0; i < m.size(); ++ i)
	{
		cout<<"match "<<i<<" ("<<m[i]<<") ";
		cout<<"at position "<<m.position(i)<<endl;
	}
	
	return 0;
}