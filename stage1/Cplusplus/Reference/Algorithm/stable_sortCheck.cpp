// file : stable_sortCheck.cpp
// template <class RandomAccessIterator>
// void stable_sort(RandomAccessIterator first, RandomAccessIterator last);
// template <class RandomAccessIterator, class Compare>
// void stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
// preserves the relative order of the elements with equivalent values.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	double mydoubles[] = {3.14,1.41,2.72,4.67,1.73,1.32,1.62,2.58};

	vector<double> myvec;

	myvec.assign(mydoubles,mydoubles + 8);

	cout<<"myvec contains (using default comparison) ";
	stable_sort(myvec.begin(),myvec.end());
	for(auto& x : myvec) cout<<x<<" "; cout<<endl;

	myvec.assign(mydoubles,mydoubles + 8);
	cout<<"myvec contains (using custom comparison) ";
	stable_sort(myvec.begin(),myvec.end(),[](double i, double j) { return (int (i)) < (int (j));});
	for(auto& x : myvec) cout<<x<<" "; cout<<endl;
	
	return 0;
}