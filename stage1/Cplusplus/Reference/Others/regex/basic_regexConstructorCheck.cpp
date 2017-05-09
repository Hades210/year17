// file : basic_regexConstructorCheck.cpp
/*************************************************************************************************************************************************************************
*	template <class charT, class traits = regex_traits<charT> > class basic_regex;
*	Regular expression
*	A regular expression is an object defining a particular pattern to be matched against a sequence of characters using the tools of the standard regex library.
*	Such objects are essentially constructed from a sequence of characters that can include several wildcards and constraints to define the set of rules (the pattern) that make a sequence of characters qualify as a match. By default, regex patterns follow the ECMAScript syntax.
*	basic_regex object do not conduct the matches directly through any of its members. Instead, they are used as arguments for regex algorithms (regex_match, regex_search and regex_replace) and regex iterator adaptors (regex_iterator and regex_token_iterator) that perform these matches using the rules specified when constructing the basic_regex object.
*	Two instantiations of this basic class exist in the standard header <regex> for the most common cases:
*
*	typedef basic_regex<char> regex;
*	typedef basic_regex<wchar_t> wregex;
*
*The following aliases are member types of basic_regex. They are widely used as parameter and return types by member functions:
*member type	definition												notes
*value_type			The first template parameter (charT)			The character type.
traits_type			The second template parameter (traits)<char>	Regex traits (defaults to regex_traits).
string_type			traits::string_type								String type (string for regex, wstring for wregex).
flag_type			regex_constants::syntax_option_type	
locale_type			traits::locale_type								locale for the standard regex_traits.
****************************************************************************************************************************************************************************/

/***************************************************************************************************************************************************************************
*	basic_regex(); // default 
*	basic_regex(const basic_regex& rgx); // copy
*	basic_regex(basic_regex&& rgx) noexcept; // move
*	explicit basic_regex(const charT* str, flag_type flags = ECMAScript); // initialization constructors 
*	basic_regex (const charT* str, size_t len, flag_type flags = ECMAScript); // initialization constructors 
*	template <class ST, class SA>
*		explicit basic_regex(const basic_string<charT,ST,SA>& str, flag_type flags = ECMAScript); // initialization constructors 
*	template <class ForwardIterator>
*		basic_regex(ForwardIterator first, ForwardIterator last, flag_type flags = ECMAScript); // initialization constructors 
*	basic_regex(initializer_list<charT> il, flag_type flags = ECMAScript); // initialization constructors 
*
* initialization constructors 
* The regular expression is initialized to a sequence of characters, that is to be interpreted according to the flags specified in f.
* If the syntax used in the sequence of characters has come syntax error, the constructor throws a regex_error exception.
****************************************************************************************************************************************************************************/

/****************************************************************************************************************************************************************************
Flags used to interpret the regular expression.
One or more of these constants can be combined (using the bitwise OR operator, |) to form a valid bitmask value of type flag_type:
These bitmask flag names are member constants of basic_regex. They are also availabe as global constants under the std::regex_constants namespace (see regex_constants for more details).
flag_type is a member type, defined as an alias of the bitmask type regex_constants::syntax_option_type.

flag*		effects on syntax				Notes
icase		Case insensitive		Regular expressions match without regard to case.
nosubs		No sub-expressions		The match_results structure will not contain sub-expression matches.
optimize	Optimize matching		Matching efficiency is preferred over efficiency constructing regex objects.
collate		Locale sensitiveness	Character ranges, like "[a-b]", are affected by locale.
ECMAScript	ECMAScript grammar		The regular expression follows one of these grammars.One (and only one) of these six grammar flags needs to be set for the bitmask to have a valid value.By default, ECMAScript is selected.
basic		Basic POSIX grammar
extended	Extended POSIX grammar
awk			Awk POSIX grammar
grep		Grep POSIX grammar
egrep		Egrep POSIX grammar
****************************************************************************************************************************************************************************/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string pattern = "^.*$";
	regex first; // default
	regex second = first; // copy
	regex third(pattern); // string object initialization
	regex fourth("<[^>]>"); // string literal initialization
	regex fifth(pattern.begin(),pattern.end()); // range initialization
	regex sixth {'.','+'}; // initializer_list initialization

	regex seventh ("[0-9A-Z]+",std::regex::ECMAScript); // with syntax option
	using namespace std::regex_constants; // introducing constants namespace
	regex eigth("[0-9A-Z]+",ECMAScript); 
	regex ninth ("\\bd\\w+",ECMAScript | icase) ; // multiple flags

	string subject = "Duddy the duck";
	string replacement = "yup";

	cout<<regex_replace(subject,ninth,replacement);
	cout<<endl;
	
	return 0;
}


