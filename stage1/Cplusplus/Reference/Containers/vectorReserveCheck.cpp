// file : vectorReserveCheck.cpp
// void reserve(size_type n);
// Requests that the vector capacity be at least enough to contain n elements.
// If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater)
// In all other cases, the function call does not cause a reallocation and the vector capacity iss not affected.
// This function has no effect on the vector size and cannot alter its elements

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int>::size_type sz;

		
	vector<int> foo;
	sz = foo.capacity();
	cout<<"making foo grow:\n";
	for(int i = 0; i < 100; i ++)
	{
		foo.push_back(i);
		if(sz != foo.capacity())
		{
			sz = foo.capacity();
			cout<<"capacity changed: "<<sz<<endl;
		}
	}

	vector<int> bar;
	sz = bar.capacity();
	cout<<sz<<endl;
	bar.reserve(100);
	cout<<"making bar grow:\n";
	for(int i = 0; i < 100; i ++){
		bar.push_back(i);
		if(sz != bar.capacity()) {
			sz = bar.capacity();
			cout<<"capacity changed: "<<sz<<endl;
		}
	}
	return 0;
}
