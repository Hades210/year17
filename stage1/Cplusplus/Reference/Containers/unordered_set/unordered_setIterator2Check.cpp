// file : unordered_setIterator2Check.cpp
/************************************************************************************************
*	container iterator(1)	const_iterator cbegin() const noexcept;			
*	bucket iterator(2)		const_local_iterator cbegin(size_type n) const;
*	container iterator(1)	const_iterator cend() const noexcept;
*	bucket iterator(2)		const_local_iterator cend(size_type n) const;
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

	for(auto it = myset.cbegin(); it != myset.cend(); ++it)
		cout<<" "<<*it;
	cout<<endl;

	cout<<"myset's buckets contain:\n";
	for(unsigned int i = 0; i < myset.bucket_count(); i ++)
	{
		cout<<"bucket #"<<i<<" contains:";
		for(auto local_it = myset.cbegin(i); local_it != myset.cend(i); ++ local_it)
			cout<<" "<<*local_it;
		cout<<endl;
	}
	
	return 0;
}
