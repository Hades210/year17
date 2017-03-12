//  file : unordered_mapbucketCheck.cpp
/**********************************************************
*	size_type bucket_count() const noexcept;
*	size_type bucket_size(size_type n) const;	 
*	size_type bucket(const key_type& k) const;
***********************************************************/

#include <iostream>
#include <string>
#include <unordered_map>

#include "../common/common-print.hpp"

using namespace std;

int main()
{
	unordered_map<string,string> first = {
				{"house","maison"},
				{"apple","pomme"},
				{"tree","arbre"},
				{"book","livre"},
				{"door","porte"},
				{"grapefruit","pamplemousse"}
	};

	cout<<"first has "<<first.size()<<" elements.\n";
	cout<<"first has "<<first.bucket_count()<<" buckets.\n";
	for(unsigned i = 0; i < first.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" has "<<first.bucket_size(i)<<" elements.\n";
		cout<<"bucket #"<<i<<" contains: ";
		for(auto it = first.begin(i); it != first.end(i);  ++it)
			cout<<"["<<it->first<<":"<<it->second<<"] ";
		cout<<endl;
	}

	unordered_map<string,string> second = {
					{"us","United States"},
					{"uk","United Kingdom"},
					{"fr","France"},
					{"ge","Germany"}
	};

	cout<<"second has "<<second.size()<<" elements.\n";
	cout<<"second has "<<second.bucket_count()<<" buckets.\n";
	for(unsigned i = 0; i < second.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" has "<<second.bucket_size(i)<<" elements.\n";
		cout<<"bucket #"<<i<<" contains: ";
		for(auto it = second.begin(i); it != second.end(i); ++it)
			cout<<"["<<it->first<<":"<<it->second<<"] ";
		cout<<endl;
	}

	for(auto& x : first)
	{
		cout<<"Element "<<"["<<x.first<<":"<<x.second<<"] is in bucket "<<first.bucket(x.first)<<endl;
	}

	for(auto& x : second)
	{
		cout<<"Element "<<"["<<x.first<<":"<<x.second<<"] is in bucket "<<second.bucket(x.first)<<endl;
	}

	return 0;
}
