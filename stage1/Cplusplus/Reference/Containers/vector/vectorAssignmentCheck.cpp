// file : vectorAssignmentCheck.cpp
// vector& operator= (const vector& v)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> foo (3,0);
	vector<int> bar (5,0);

	bar = foo;
	foo = vector<int>();

	cout<<"size of foo: "<<foo.size()<<endl;
	cout<<"size of bar: "<<bar.size()<<endl;

	return 0;
}
