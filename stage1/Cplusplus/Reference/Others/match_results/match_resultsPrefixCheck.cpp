// file : match_resultsPrefixCheck.cpp
/****************************************************************
*	const_reference prefix() const;
*	Returns a reference to a sub_match object representing the 
*	character sequence that precedes the matched sequence in 
*	the target sequence.
*
*	const_reference suffix() const;
*	Returns a reference to a sub_match object representing the
*	character sequence that follows the end of the matched 
*	sequence in the target sequence.
****************************************************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string s("there is a needle in this haystack");
	smatch m;
	regex e("needle");

	cout<<"searching for needle in ["<<s<<"]\n";
	regex_search(s, m, e);

	if(m.ready()) 
	{
		cout<<m[0]<<" found!\n";
		cout<<"prefix: ["<<m.prefix()<<"]\n";
		cout<<"suffix: ["<<m.suffix()<<"]\n";
	}

	return 0;
}