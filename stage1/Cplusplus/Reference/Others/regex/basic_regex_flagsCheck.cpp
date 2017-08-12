// file : basic_regex_flagsCheck.cpp
/**************************************************************************
*	flat_type flags() const;
* Return the syntax flags used to interpret the regular expression.
***************************************************************************/
#include <iostream>
#include <regex>

using namespace std;

int main()
{
	using namespace std::regex_constants;
	regex first("[a-z]+");
	regex second("[a-z]+",ECMAScript | icase);

	cout<<"first ";
	cout<<((first.flags() & icase) == icase ? "is":"is not");
	cout<<" case insensitive.\n";

	cout<<"second ";
	cout<<((second.flags() & icase) == icase ? "is":"is not");
	cout<<" case insensitive.\n";
	
	return  0;
}