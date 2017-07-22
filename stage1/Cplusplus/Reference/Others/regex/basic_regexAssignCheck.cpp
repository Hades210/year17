// file : basic_regexAssignCheck.cpp

/*******************************************************************************************************
* (1) basic_regex& assign(const basic_regex& rgx);
* (2) basic_regex& assign(basic_regex&& rgx) noexcept;
* (3) basic_regex& assign (const charT* str, flag_type flags = ECMAScript);
* (4) basic_regex& assign (const charT* str, size_t len, flag_type flags = ECMAScript);
* (5) template <class ST, class SA>
* basic_regex& assign(const basic_string<charT,ST,SA>& str, flag_type flags = ECMAScript);
* (6) template <class InputIterator>
* basic_regex& assign(InputIterator first, InputIterator last, flag_type flags = ECMAScript);
* (7) basic_regex& assign (initializer_list<charT> il, flag_type flags = ECMAScript);
******************************************************************************************************/
// assigns a new regular expression(pattern) to the object, overwriting any previous value.
// rgx Another basic_regex object of the same type
// str A string with the pattern to use as regular expression. charT is the first class template parameter(the character type)
// flags used to interpret the regular expression.
// len length of string str, with str being an array of characters, not necessarily null-terminated. size_t is an unsigned integral type.
// first,last forward iterators to the initial and final positions in a range of characters.
// il An inintalizer_list of characters.

// return *this

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string pattern ("six");
	regex first;
	regex second (pattern);

	first.assign(second);
	second.assign("[0-9A-F]+", regex::ECMAScript);
	second.assign({'^','a'}, regex::ECMAScript | regex::icase);

	using namespace std::regex_constants; // introducing constants

	string subject = "Sixty six";
	string replacement = "seven";

	cout<<"first: "<<regex_replace(subject, first, replacement)<<endl;

	cout<<"second: "<<regex_replace(subject,second,replacement)<<endl;

	return 0;
}

