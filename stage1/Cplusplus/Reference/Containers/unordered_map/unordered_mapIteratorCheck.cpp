// file : unordered_mapIteratorCheck.cpp
/*****************************************************************************************
*	container iterator (1)	iterator begin() noexcept;
*							const_iterator begin() const noexcept;
*	bucket iterator(2)		local_iterator begin(size_type n);
*							const_local_iterator begin(size_type n) const;
*	container iterator (1)  iterator end() noexcept;
*							const_iterator end() const noexcept;
*	bucket iterator(2)		local_iterator end(size_type n);
*							const_local_iterator end(size_type n);
*	container iterator(1)  	const_iterator cbegin() const noexcept;
*	bucket iterator (2)		const_local_iterator cbegin(size_type n) const;
*	container iterator (1)  const_iterator cend() const noexcept;
*	bucket_iterator(2)		const_local_iterator cend(size_type n) const; 
******************************************************************************************/
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	unordered_map<string,string> mymap;
	mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};

	cout<<"mymap contains:";
	for(auto it = mymap.begin(); it != mymap.end(); ++ it)
	{
		cout<<" "<<it->first<<":"<<it->second;
	}
	cout<<endl;


	cout<<"mymap's buckets contains:\n";
	for(unsigned i = 0; i < mymap.bucket_count(); ++ i)
	{
		cout<<"bucket #"<<i<<" contains:";
		for(auto local_it = mymap.begin(i); local_it != mymap.end(i); ++ local_it)
			cout<<" "<<local_it->first<<":"<<local_it->second<<" ";
		cout<<endl;
	}

	unordered_map<string,string> mymap2;
	mymap2 = {{"zhangsanfeng","wudang"},{"saodiseng","shaolin"},{"linghucong","huashan"},{"guojing","gaibang"},{"yangguo","quanzhen"}};

	cout<<"mymap2 contains:";
	for(auto it = mymap2.cbegin(); it != mymap2.cend(); ++ it)
		cout<<it->first<<":"<<it->second<<" ";
	cout<<endl;

	cout<<"mymap2's bucket contains:\n";
	for(int i = 0; i < mymap2.bucket_count(); ++ i)
	{
		cout<<"bucket #"<<i<<"contains: ";
		for(auto local_it = mymap2.begin(i); local_it !=mymap2.end(i); ++ local_it )
			cout<<local_it->first<<":"<<local_it->second<<" ";
		cout<<endl;
	}

	return 0;
}



