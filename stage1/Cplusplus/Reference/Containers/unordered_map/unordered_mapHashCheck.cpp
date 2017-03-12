// file : unordered_mapHashCheck.cpp
/******************************************************************
*	get(1) float max_load_factor() const noexcept;
*	set(2) void max_load_factor(float z);
*	void rehash(size_type n);
*	void reserve(size_type n);
*******************************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_map<string,string> first = {
				{"Au","gold"},
				{"Ag","silver"},
				{"Cu","copper"},
				{"Pt","Platinum"}
	};

	cout<<"current max_load_factor: "<<first.max_load_factor()<<endl;
	cout<<"current size: "<<first.size()<<endl;
	cout<<"current bucket_count: "<<first.bucket_count()<<endl;
	cout<<"current load_factor: "<<first.load_factor()<<endl;

	float z = first.max_load_factor();
	first.max_load_factor(z / 2.0);

	cout<<"new max_load_factor: "<<first.max_load_factor()<<endl;
	cout<<"new size: "<<first.size()<<endl;
	cout<<"new bucket_count: "<<first.bucket_count()<<endl;
	cout<<"new load_factor: "<<first.load_factor()<<endl;

	return 0;
}
