// file : match_resultsStrCheck.cpp
/**************************************************************
*	string_type str(size_type n = 0) const;
*	Return match as a string
**************************************************************/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	using namespace std::regex_constants;

	cmatch m;
	regex_match("subject", m, regex("(sub)(.*)"));

	string output = "matches:\n";

	for(unsigned i = 0; i < m.size(); ++ i)
	{
		output += m.str(i) + "\n";
	}

	cout<<output<<endl;
	return 0;
}