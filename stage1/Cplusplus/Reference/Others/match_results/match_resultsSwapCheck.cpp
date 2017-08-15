// file : match_resultsSwapCheck.cpp
//	void swap(match_results& mrs);

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string s("there is a needle in this haystack.");
	smatch m1, m2;

	regex_search(s, m1, regex("needle"));
	regex_search(s, m2, regex("haystack"));

	m1.swap(m2);

	cout<<m1.format("m1 contains [$0] with prefix [$`] and suffix [$'].\n");
	cout<<m2.format("m2 contains [$0] with prefix [$`] and suffix [$'].\n");
	return 0;
}