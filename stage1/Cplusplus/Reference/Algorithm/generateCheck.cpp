// file : generateCheck.cpp
// template <class ForwardIterator, class Generator>
// void generate(ForwardIterator first, ForwardIterator last, Generator gen);
// Assigns the value returned by successive calls to gen to the elements in the range[first,last).
// The behavior of this function template is equivalent to:
// template <class ForwardIterator, class Generator>
// void generate(ForwardIterator first, ForwardIterator last, Generator gen)
// {
// 	while(first != last)
// 	{
// 		*first = gen();
// 		++first;
// 	}
// }


#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime> // time
#include <cstdlib> //rand,srand

using namespace std;

int RandomNumber() {return rand() % 100 ;}

struct c_unique {
	int current;
	c_unique(){current = 0;}
	int operator() (){return ++current;}
}UniqueNumber;

int main()
{
	srand(unsigned (time(NULL)));
	vector<int> myvec(8);

	generate(myvec.begin(),myvec.end(),RandomNumber);

	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;

	generate(myvec.begin(),myvec.end(),UniqueNumber);
	
	cout<<"myvec contains: ";
	for(auto& x : myvec)	cout<<x<<" ";	cout<<endl;
	return 0;
}