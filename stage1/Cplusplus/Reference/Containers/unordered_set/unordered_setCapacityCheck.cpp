// file : unordered_setCapacityCheck.cpp
// bool empty() const noexcept;
// size_type size() const noexcept;
// size_type max_size() const noexcept;
// size_type max_bucket_count() const noexcept;
// size_type max_load_factor() const noexcept;

#include <iostream>
#include <unordered_set>
#include <string>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_set<string> myset;

	cout<<"max_size = "<<myset.max_size()<<"\n";
	cout<<"max_bucket_count = "<<myset.max_bucket_count()<<"\n";
	cout<<"max_load_factor = "<<myset.max_load_factor()<<"\n";

	cout<<"size "<<myset.size()<<"\n";
	if(myset.empty())
		cout<<"myset is empty now\n";

	myset = {"math","physics","science"};

	cout<<"size "<<myset.size()<<"\n";
	if(!myset.empty())
		cout<<"myset is not empty now\n";

	printInfo("myset",myset);


	return 0;
}
