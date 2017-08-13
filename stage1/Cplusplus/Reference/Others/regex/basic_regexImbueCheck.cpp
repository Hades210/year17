// file : basic_regexImbueCheck.cpp
// C++ 11 only
/*****************************************************************************
*	local_type imbue(local_type loc);
*
*	This function resets the basic_regex object, so it
*   no longer matches any charcter sequence(as if
*	constructed with regex's default constructor.)
*	You can use basic_regex::assign or basic_regex::
*	operator= to assign a new regular expression pattern
*	to the object once imbued.
*	On construction, a basic_regex object that uses the
*	default regex_traits uses the global locale(locale::global)
*******************************************************************************/

#include <iostream>
#include <regex>
#include <locale>

using namespace std;

int main()
{
	regex myregex;
	myregex.imbue(std::locale::classic());
	myregex.assign("sub[a-z]*");

	if(regex_match("subject",myregex))
	{
		cout<<"The string matches. "<<endl;
	}
	
	return 0;
}
