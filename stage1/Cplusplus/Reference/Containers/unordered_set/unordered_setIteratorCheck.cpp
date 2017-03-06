// file : unordered_setIteratorCheck.cpp
/************************************************************************************************
*	container iterator(1)	iterator begin() noexcept;
*							const_iterator begin() const noexcept;
*	bucket iterator(2)		local_iterator begin(size_type n); 
*							const_local_iterator begin(size_type n) const;
*	container iterator(1)	iterator end() noexcept;
*							const_iterator end() const noexcept;
*	bucket iterator(2)		local_iterator end(size_type n);
*							const_local_iterator end(size_type n) const;
*************************************************************************************************/
// Return iterator pointing to the first element in the unordered_set container(1) or in one of its buckets(2)
// Return iterator pointing to the past-the-end element in the unordered_set container(1) or in one of its buckets(2)

#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	unordered_set<string> myset = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

	cout<<"myset contains:";

	for(auto it = myset.begin(); it != myset.end(); ++it)
		cout<<" "<<*it;
	cout<<endl;

	cout<<"myset's buckets contain:\n";
	for(unsigned int i = 0; i < myset.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" contains:";
		for(auto local_it = myset.begin(i); local_it != myset.end(i); ++ local_it)
			cout<<" "<<*local_it;
		cout<<endl;
	}

	return 0;
}
