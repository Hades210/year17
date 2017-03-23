// file : generate_nCheck.cpp
// template <class OutputIterator, class Size, class Generator>
// void generate_n(OutputIterator first, Size n, Generator gen);
// Assigns the value returned by successive calls to gen to the first n elements of the sequence pointed by first.
// The behavior of this function template is equivalent to:
// template <class OutputIterator, class Size, class Generator>
// void generate_n(OutputIterator first, Size n, Generator gen)
// {
// 	while(n > 0)
// 	{
// 		*first = gen();
// 		++first; --n;
// 	}
// }
#include <iostream>
#include <algorithm>

using namespace std;

struct unique {
	int current;
	unique(){current = 0;}
	int operator() () {return ++current;}
}UniqueNumber;

int main()
{
	int myints[9];

	generate_n(myints,9,UniqueNumber);
	cout<<"myints contains: ";
	for(auto& x : myints)	cout<<x<<" ";	cout<<endl;
	return 0;
}