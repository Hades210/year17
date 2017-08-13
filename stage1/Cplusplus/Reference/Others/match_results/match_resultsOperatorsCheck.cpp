// file : match_resultsOperatorsCheck.cpp
/*********************************************************************
*	copy(1)	match_results& operator= (const match_results& m);
*	move(2) match_results& operator= (match_results&& m);
*********************************************************************/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	cmatch m1,m2;

	regex_match("subject",m1,regex("(sub)(.*)"));

	m2 = m1;

	for(unsigned i = 0; i < m2.size(); ++ i)
		cout<<"match "<<i+1<<" : "<<m2[i]<<endl;
	
	return 0;
}