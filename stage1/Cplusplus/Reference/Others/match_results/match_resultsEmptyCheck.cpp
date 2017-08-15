// file : match_resultsEmptyCheck.cpp

/*********************************************
*	bool empty() const;
*	Test whether object has no matches
*********************************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	using namespace regex_constants;

	string s("Subject");
	regex e1("sub.*");
	regex e2("sub.*", ECMAScript | icase);

	smatch m1,m2;

	regex_match(s, m1, e1);
	regex_match(s, m2, e2);

	cout<<"e1 "<<(m1.empty() ? "did not match" : "matched")<<endl;
	cout<<"e2 "<<(m2.empty() ? "did not match" : "matched")<<endl;
	
	return 0;
}