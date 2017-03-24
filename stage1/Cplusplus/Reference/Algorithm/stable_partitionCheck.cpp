// file : stable_partitionCheck.cpp
// template <class BidirectionalIterator, class UnaryPredicate>
// BidirectionalIterator stable_partition (BidirectionalIterator first, BidirectionalIterator last, UnaryPredicate pred);
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> myvec;
	for(int i = 1; i < 10; ++i) myvec.push_back(i);
	auto bound = stable_partition(myvec.begin(),myvec.end(),[](int i) {return i % 2;});
	
	cout<<"odd elements:";
	for(auto it = myvec.begin(); it != bound; ++it)	cout<<*it<<" ";	cout<<endl;
	cout<<"even elements:";
	for(auto it = bound; it != myvec.end(); ++it)	cout<<*it<<" "; cout<<endl;
	
	return 0;
}