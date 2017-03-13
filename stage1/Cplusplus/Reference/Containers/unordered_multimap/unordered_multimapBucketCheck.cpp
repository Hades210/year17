// file : unordered_multimapBucketCheck.cpp
/************************************************************
*	size_type bucket_count() const noexcept;
*	size_type bucket_size(size_type n) const;
*	size_type bucket(const key_type& k) const;
*************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_multimap<string,string> myumm = {
			{"bed","bedroom"},
			{"oven","kitchen"},
			{"towel","bathroom"},
			{"towel","beach"},
			{"plant","garden"}
	};

	unsigned n = myumm.bucket_count();
	cout<<"myumm has "<<n<<" buckets\n";

	for(unsigned i = 0; i < n; i ++)
	{
		cout<<"bucket #"<<i<<" contains: ";
		for(auto it = myumm.begin(i); it != myumm.end(i); ++ it)
			cout<<"["<<it->first<<":"<<it->second<<"] ";
		cout<<"bucket #"<<i<<" has "<<myumm.bucket_size(i)<<" elements\n";
		cout<<endl;
	}

	for(auto x : myumm)
		cout<<"Element ["<<x.first<<"] is in bucket#"<<myumm.bucket(x.first)<<endl;

	return 0;
}
