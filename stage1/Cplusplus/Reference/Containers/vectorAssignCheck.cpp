// file : vectorAssignCheck.cpp
//
// range(1) template <class InputIterator>
//			void assign(InputIterator first, InputIterator last);
// 
// fill(2)	void assign(size_type n, const value_type& val);
//
// initializer list(3) void assign(initializer_list<value_type> il);

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> first;
	vector<int> second;
	vector<int> third;

	first.assign(7,100);

	vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it,first.end()-1);

	int myints[] = {1973,12,5};
	third.assign(myints,myints+3);

	cout<<"Size of first: "<<int(first.size())<<"\n";
	cout<<"Size of second: "<<int(second.size())<<"\n";
	cout<<"Size of third: "<<int(third.size())<<"\n";

	return 0;
}
