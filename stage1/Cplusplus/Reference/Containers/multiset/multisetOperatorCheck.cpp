// file : multisetOperatorCheck.cpp
//	copy(1)	multiset& operator= (const multiset& x);
//  move(2)	multiset& operator= (multiset&& x);
//	il(3)	multiset& operator=(initializer_list<value_type> il);

#include <iostream>
#include <set>

using namespace std;

int main()
{
	int myints [] = {19,81,36,36,19};
	multiset<int> first (myints, myints + 5);
	multiset<int> second;

	second = first;
	first = multiset<int>();

	cout<<"size of first: "<<first.size()<<"\n";
	cout<<"size of second: "<<second.size()<<"\n";
	
	return 0;
}
