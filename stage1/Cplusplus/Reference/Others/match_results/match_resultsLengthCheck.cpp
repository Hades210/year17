// file : match_resultsLengthCheck.cpp
/********************************************************
*	difference_type length(size_type n = 0) const;
********************************************************/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string s ("subject");
	smatch m;
	regex e("(sub)(.*)");

	regex_match( s, m, e);

	for(unsigned i = 0; i < m.size(); ++ i) 
	{
		cout<<"match "<<i<<" ("<<m[i]<<")";
		cout<<" has a length of "<<m.length(i)<<endl;
	}
	
	return 0;
}