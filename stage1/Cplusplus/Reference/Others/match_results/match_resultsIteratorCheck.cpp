// file : match_resultsIteratorCheck.cpp
/**********************************************************
*	const_iterator begin() const;
*	const_iterator end() const;
*	
*	const_iterator cbegin() const;
*	const_iterator cend() const;
**********************************************************/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string s("subject");
	regex r("(sub)(.*)");
	smatch m;

	regex_match(s, m, r);

	cout<<"matches: "<<endl;

	for(smatch::iterator it = m.begin(); it != m.end(); ++ it)
		cout<<*it<<endl;

	cout<<"=========================================\n";


	cout<<"matches: "<<endl;

	for(smatch::const_iterator cit = m.cbegin(); cit != m.cend(); ++ cit)
		cout<<*cit<<endl;

	return 0;
}