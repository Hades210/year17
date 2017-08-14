// file : match_resultsReadyCheck.cpp
// bool ready() const
// Test whether results are ready
//	when the object is default-constructed, this value is initialized to false. Any call to 
//	regex_match or regex_search with the match_results object as argument sets this value to true,
//	even if the function does not succeed in finding any match.

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
	string mystring("subject");
	smatch mymatch;
	regex myregex("sub.*");

	cout<<std::boolalpha;
	cout<<"mymatch.ready() is "<<mymatch.ready()<<endl;

	regex_match(mystring, mymatch, myregex);
	cout<<"attempting match..."<<endl;

	cout<<"mymatch.ready() is "<<mymatch.ready()<<endl;
	if(mymatch.ready())	cout<<"matched : "<<mymatch[0]<<endl;
	
	return 0;
}