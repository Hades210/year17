// file : unordered_multimapCapacityCheck.cpp
/*****************************************************************************
*	bool empty() const noexcept;
* 	size_type size() const noexcept;
*	size_type max_size() const noexcept;
*	size_type max_bucket_count() const noexcept;
******************************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	unordered_multimap<string,string> umm1;
	unordered_multimap<string,string> umm2 = {{"AI","Alan Turing"},{"Math","John Nash"},{"Physics","Isacca Newtown"}};

	if(umm1.empty())
		cout<<"umm1 is empty\n";
	if(!umm2.empty())
		cout<<"umm2 is not empty\n";

	cout<<"umm1 size: "<<umm1.size()<<"\n";
	cout<<"umm2 size: "<<umm2.size()<<"\n";

	cout<<"max_size = "<<umm1.max_size()<<"\n";
	cout<<"max_bucket_count = "<<umm1.max_bucket_count()<<"\n";
	cout<<"max_load_factor = "<<umm1.max_load_factor()<<"\n";

	return 0;
}
