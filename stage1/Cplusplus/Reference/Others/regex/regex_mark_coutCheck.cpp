// file : regex_mark_countCheck.cpp
// C++ 11 only

/************************************************************************
*	unsigned mark_count() const
* Return number of marked sub-expressions.
************************************************************************/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	regex myregex ("(sub)([a-z]*).*");
	cout<<"The pattern captures "<<myregex.mark_count()<<" sub-expressions.\n";

	cmatch m;
	regex_match("subject",m,myregex);

	if(m.size() == myregex.mark_count() + 1) 
	{
		cout<<"OK, all sub-expressions captured.\n";
		cout<<"Matched expression: "<<m[0]<<"\n";

		for(unsigned i = 1; i < m.size(); ++ i)
			cout<<"Sub-expression "<<i<<": "<<m[i]<<"\n";
	}

	cout<<"=======================================\n";

	regex myregex2("(sub)([a-z]*)([0-9]*)");
	cout<<"The pattern captures "<<myregex2.mark_count()<<" sub-expressions.\n";

	regex_match("subclass101",m,myregex2);

	if(m.size() == myregex2.mark_count() + 1)
	{
		cout<<"OK, all sub-expressions captured.\n";
		cout<<"Matched expression: "<<m[0]<<endl;

		for(unsigned i = 1; i < m.size(); ++ i)
			cout<<"Sub-expression "<<i<<": "<<m[i]<<"\n";
	}

	return 0;
}