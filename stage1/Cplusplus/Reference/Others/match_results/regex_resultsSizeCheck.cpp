// file : regex_resultsSizeCheck.cpp
/*****************************************************
*	size_type size() const
*	return number of matches
*****************************************************/

#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
	string s("subject");
	smatch m;
	regex r("sub(.*)");

	regex_match(s,m,r);

	cout<<m.size()<<" matches found."<<endl;
	for(unsigned i = 0; i < m.size(); ++ i)
		cout<<"match # "<<i<<": "<<m[i]<<endl;

	return 0;
}