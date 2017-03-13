// file : unordered_multimapIteratorCheck.cpp
/***********************************************************************************************
*	container iterator (1)		iterator begin() noexcept;
*								const_iterator begin() const noexcept;
*	bucket iterator (2)			local_iterator begin(size_type n);
*								const_local_iterator begin(size_type n) const;
*	container iterator (1)		iterator end() noexcept;
*								const_iterator end() const noexcept;
*	bucket iterator (2)			local_iterator end(size_type n);
*								const_local_iterator end(size_type n) const;
*	container iterator (1)		const_iterator cbegin() const noexcept;
*	bucket iterator(2)			const_local_iterator cbegin(size_type n) const;
*	container iterator (1)		const_iterator cend() const noexcept;
*	bucket iterator(2)			const_local_iterator cend(size_type n) const;
************************************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_multimap<string,string> movies = {
				{"A Beautiful Mind" , "John Nash"},
				{"The Story of Time", "Stephen Hawking"},
				{"Eninsten and Endington","Eninsten"},
				{"Eninsten and Endington","Endington"}
	};

	cout<<"movies contains:";
	for(auto it = movies.begin(); it != movies.end(); ++ it)
		cout<<" ["<<it->first<<":"<<it->second<<"]";
	cout<<endl;

	cout<<"movies buckets contain\n";
	for(unsigned i = 0; i < movies.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" contains:";

		for(auto it = movies.begin(i); it != movies.end(i); ++it)
			cout<<" ["<<it->first<<":"<<it->second<<"]";
		cout<<endl;

	}


	cout<<"movies contains:";
	for(auto it = movies.cbegin(); it != movies.cend(); ++ it)
		cout<<" ["<<it->first<<":"<<it->second<<"]";
	cout<<endl;

	cout<<"movies buckets contain\n";
	for(unsigned i = 0; i < movies.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" contains:";

		for(auto it = movies.cbegin(i); it != movies.cend(i); ++it)
			cout<<" ["<<it->first<<":"<<it->second<<"]";
		cout<<endl;

	}
	return 0;
}
