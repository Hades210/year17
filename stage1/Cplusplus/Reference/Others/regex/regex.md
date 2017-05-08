## regex
Regular Expressions</br>
Regular expressions are a standardized way to express patterns to be matched against sequences of characters.</br>

The standard C++ library provides support for regular expressions in the `<regex>` header through a series of operations. All these operations make use of some typical regex parameters:</br>
`Target sequence (subject):` The sequence of characters searched for the pattern. Generally, this is a range specified by two iterators, but some functions also accept a c-string or a string object instead.</br>
`Regular expression (pattern):` The pattern which is searched for in the target sequence. This must be an object of a basic_regex type (such as regex), generally constructed from a string with a special syntax that describes what constitutes a match (see ECMAScript syntax).</br>
`Matches array:` Some operations allow to retrieve information about matches. This information is stored in one of the special match_results array types (such as cmatch or smatch).</br>
`Replacement string:` Some operations can replace matches. These replacements are specified in strings that allow for a special format (see ECMAScript syntax).</br>

## Regex operations
Regex operations are performed using either functions or special iterator adaptors:</br>
Functions:</br>
`regex_match`       Match sequence (function template )</br>
`regex_search`      Search sequence (function template )</br>
`regex_replace`     Replace matched sequence (function template )</br>

Iterator types:</br>
`regex_iterator`    Regex iterator (class template )</br>
`regex_token_iterator  `Regex token iterator (class template )</br>

## Classes
The regex functions and iterators make heavy use of a set of supporting types as arguments and return values:</br>
Basic types:</br>
`basic_regex`
Regular expression (class template )</br>
`match_results`
Match results (class template )</br>
`sub_match`
Sub-expression match (class template )</br>
`regex_traits`
Regex traits (class template )</br>
`regex_error`
Regex exception (class )</br>

Some of these types are templates, and have aliases for their most common instantiations:</br>
basic_regex instantiations:</br>
`regex`
Regex (class )</br>
`wregex`
Regex for wchar_t (class )</br>
match_results instantiations:</br>
`cmatch`
match_results for string literals (class )</br>
`wcmatch`
match_results for wide string literals (class )</br>
`smatch`
match_results for string objects (class )</br>
`wsmatch`
match_results for wide string objects (class )</br>
sub_match instantiations:</br>
`csub_match`
sub_match for string literals (class )</br>
`wcsub_match`
sub_match for wide string literals (class )</br>
`ssub_match`
sub_match for strings (class )</br>
`wssub_match`
sub_match for wide strings (class )</br>

## Namespaces
This header also defines a namespace, regex_constants, under which all constant values to be used by the library are located.</br>
`regex_constants` regex constants(namespace)
 
 ## Grammer
 Regular expressions follow very strict grammars. By default, the functions in this library use the ECMAScript grammar:</br>
 `ECMAScript syntax` ECMAScript regular expressions pattern syntax(syntax specifications)</br>