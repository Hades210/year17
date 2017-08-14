// file : match_resultsFormatCheck.cpp
/****************************************************************************************************
*	string_type format(const char_type* fmt,
*	regex_constants::match_flag_type flags = regex_constants::format_default) const;
*
*	template <class sT, class sA>
*	basic_string<char_type, sT, sA> format(const basic_string<char_type,sT,sA>& fmt,
*	regex_constants::match_flag_type flags = regex_constants::format_default) const;
*
*	template <class OutputIterator, class sT, class sA>
*	OutputIterator format(OutputIterator out, const basic_string<char_type, sT, sA>& fmt,
*	regex_constants::match_flag_type flags = regex_constants::format_default) const;
*
*	template <class OutputIterator>
*	OutputIterator format(OutputIterator out, const char_type* fmt_first, const char_type* fmt_last,
*	regex_constants::match_flag_type flags = regex_constants::format_default) const;
***************************************************************************************************
*fmt:
*	$n	n-th backreference. n integer value.
*	$&	A copy of the entire match
*	$`	The prefix
*	$'	The suffix
*	$$	A single $ character.
*
*flags:
*	match_default/format_default:		uses the standard formatting rules to replace matches(those 
*										used by ECMAScript's replace method).
*	format_sed							uses the same rules as the sed utility in POSIX to replace
*	format_no_copy						the sections in the target sequence that do not match the
*										regular expression are not copied when replacing matches.
*	format_first_only					only the first occurrence of a regular expression is replaced.
***************************************************************************************************/


// pay attention to the difference between regex_match() and regex_search().
#include <iostream>
#include <regex>

using namespace std;

int main()
{
	cmatch m;
	regex_match("subject", m, regex("(sub)(.*)"));
	cout<<m.format("the expression matched [$0]. \n");
	cout<<m.format("with sub-expressions [$1] and [$2].\n");

	string s("there is a needle on the haystack");
	regex e("needle");
	smatch m2;
	regex_search(s, m2, e);
	for(auto it = m2.begin(); it != m2.end(); ++ it)
		cout<<*it<<endl;

	cout<<m2.format("matched [$0]\n");
	cout<<m2.format("with prefix [$`] and suffix [$']\n");


	return 0;
}