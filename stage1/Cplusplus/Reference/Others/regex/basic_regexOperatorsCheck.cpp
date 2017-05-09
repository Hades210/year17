// file : basic_regexOperatorsCheck.cpp
/*************************************************************************************************
* (1)	basic_regex& operator= (const basic_regex& rgx);
* (2)	basic_regex& operator= (basic_regex&& rgx) noexcept;
* (3)	basic_regex& operator= (const charT* str);
* (4)	template <class ST, class SA>
*			basic_regex& operator= (const basic_string(charT,ST,SAL)& str);
* (5)	basic_regex& operator= (initializer_list<charT> il);
*
*
* Assign regular expression
* Versions(3),(4),(5) reset the flags to its default value: ECMAScript.
*************************************************************************************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string pattern("six");
	regex first;
	regex second(pattern,std::regex::icase);

	first = second; // copy assignment (flags preserved)
	second = "[0-9A-F]+"; // assigning string literal (flags reset)
	second = {'^','.'}; // assigning initializer list(flags reset)
	second = pattern ; // assigning string object(flags reset)

	string subject = "Sixty six";
	string replacement = "seven";

	cout<<"first: "<<regex_replace(subject,first,replacement)<<endl;
	cout<<"second: "<<regex_replace(subject,second,replacement)<<endl;
	
	return 0;
}