// file : match_resultsConstructorCheck.cpp
/*************************************************************************************************
*	default(1)	explicit match_results(const allocator_type& alloc = allocator_type());
*	copy(2)		match_results(const match_results& m);
*	move(3)		match_results(match_results&& m);
*	when default-constructed, a match_results's object ready member function returns false.
**************************************************************************************************/

#include <iostream>
#include <regex>

using namespace std;

int main()
{
	cmatch m;
	regex_match("subject",m,regex("sub(.*)"));

	cmatch mcopy(m);

	for(unsigned i = 0; i < mcopy.size(); ++ i)
		cout<<"match "<<i + 1<<" : "<<mcopy[i]<<endl;

	return 0;
}