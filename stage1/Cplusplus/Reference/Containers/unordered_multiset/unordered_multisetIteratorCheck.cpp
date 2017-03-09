// file : unordered_multisetIteratorCheck.cpp
/*************************************************************************************
*	container iterator(1) 		iterator begin() noexcept;
*								const_iterator begin() const noexcept;
*	bucket_iterator (2)			local_iterator begin(size_type n);
*								const_local_iterator begin(size_type n) const;
*	container iterator(1)		iterator end() noexcept;
*								const_iterator end() const noexcept;
*	bucket_iterator (2)			local_iterator end(size_type n);
*								const_local_iterator end(size_type n) cosnt;
*	container iterator(1)		const_iterator cbegin() const noexcept;
*	bucket_iterator (2)			const_local_iterator cbegin(size_type n) const;
*	container iterator(1)		const_iterator cend() const noexcept;
* 	bucket iterator(2)			const_local_iterator cend(size_type n) const;
**************************************************************************************/

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_multiset<string> myset = {"THU","PKU","ZJU","SHJT","FDU","HIT","HKUST","MIT","Standford","Harvard","UC Berkeley"};

	cout<<"myset contains: ";

	for(auto it = myset.begin(); it != myset.end(); ++it)
		cout<<*it<<" ";
	cout<<endl;

	cout<<"myset's buckets contain:"<<endl;

	for(int i = 0; i < myset.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<"contains : ";

		for(auto it = myset.begin(i); it != myset.end(i); ++ it)
			cout<<*it<<" ";
		cout<<endl;
	}

	unordered_multiset<string> myset2 = {"Microsoft","Apple","Google","Facebook","Amazon","Snap"};

	cout<<"myset2 contains: ";
	for(auto it = myset2.cbegin(); it != myset2.cend(); ++ it)
		cout<<*it<<" ";
	cout<<endl;

	cout<<"myset2's buckets contains: "<<endl;

	for(int i = 0; i < myset2.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" contains: ";

		for(auto it = myset2.cbegin(i); it != myset2.cend(i); ++ it)
			cout<<*it<<" ";
		cout<<endl;
	}

	return 0;
}
