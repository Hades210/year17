// file : basic_regexGetLocCheck.cpp
/****************************************************************************************************
*	locale_type getloc() const;
*	The value returned is the object set iin the last call to basic_regex::imbue, or the locale by 
*	default if regex::imbue has not been called on the object(this is locale::global for objects using
*	the standard regex_traits)
*****************************************************************************************************/

#include <iostream>
#include <regex>
#include <locale>

using namespace std;

int main()
{
	regex myregex;
	locale mylocale("");
	myregex.imbue(mylocale);
	myregex.assign("sub[a-z]*");

	if(regex_match("subject",myregex))
	{
		cout<<"The string matches";
	}
	else
	{
		cout<<"The string doesn't match";
	}

	cout<<" using locale: "<<myregex.getloc().name()<<endl;
	return 0;
}