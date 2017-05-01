// file : valarrayOperationCheck.cpp

#include <iostream>
#include <valarray>

using namespace std;

int main()
{
	int init[] {10 , 20 , 30 , 40};

	valarray<int> foo (init, 4);
	valarray<int> bar (25, 4);

	bar += foo;
	foo = bar + 10;
	foo -= 10;

	// if(foo == bar)
	// 	cout<<"foo and bar are equal."<<"\n";
	// else
	// 	cout<<"foo and bar are not equal."<<"\n";

	valarray<bool> comp = (foo == bar);

	if(comp.min() == true)
		cout<<"foo and bar are equal.\n";
	else
		cout<<"foo and bar are not equal. \n";

	return 0;
}