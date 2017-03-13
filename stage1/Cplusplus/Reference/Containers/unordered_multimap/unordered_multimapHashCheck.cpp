// file : unordered_multimapHashCheck.cpp
/*******************************************************************
*	float load_factor() const noexcept;
*	get (1) float max_load_factor() const noexcept;
*	set	(2)	void max_load_factor(float z);
*	void rehash(size_type n);
*	void reserve(size_type n);
********************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_multimap<string,string> umm;
	cout<<"size = "<<umm.size()<<endl;
	cout<<"bucket_count = "<<umm.bucket_count()<<endl;
	cout<<"load_factor = "<<umm.load_factor()<<endl;
	cout<<"max_load_factor = "<<umm.max_load_factor()<<endl;

	unordered_multimap<string,string> umm1 = {
			{"apple","NY"},
			{"apple","WA"},
			{"peach","GA"},
			{"cherry","UT"}
	};

	cout<<"current max_load_factor: "<<umm1.max_load_factor()<<endl;
	cout<<"current size: "<<umm1.size()<<endl;
	cout<<"current bucket_count: "<<umm1.bucket_count()<<endl;
	cout<<"current load_factor: "<<umm1.load_factor()<<endl;

	float z = umm1.max_load_factor();
	umm1.max_load_factor( z / 2.0 );
	cout<<"[max_load_factor halved]"<<endl;

	cout<<"new max_load_factor: "<<umm1.max_load_factor()<<endl;
	cout<<"new size: "<<umm1.size()<<endl;
	cout<<"new bucket_count: "<<umm1.bucket_count()<<endl;
	cout<<"new load_factor: "<<umm1.load_factor()<<endl;

	unordered_multimap<string,string> umm2;
	umm2.rehash(20);

	umm2.insert({{"apple","NY"},{"apple","WA"},{"peach","GA"}});
	umm2.insert({{"orange","FL"},{"cherry","UT"}});
	umm2.insert({{"strawberry","LA"},{"strawberry","NC"}});
	printInfo("umm2",umm2);
	cout<<"current bucket_count: "<<umm2.bucket_count()<<endl;

	unordered_multimap<string,string> umm3;
	umm3.reserve(7);

	umm3.insert({{"apple","NY"},{"apple","WA"},{"peach","GA"}});
	umm3.insert({{"orange","FL"},{"cherry","UT"}});
	umm3.insert({{"strawberry","LA"},{"strawberry","NC"}});

	printInfo("umm3",umm3);
	cout<<"current bucket_count: "<<umm3.bucket_count()<<endl;
	
	return 0;
}
