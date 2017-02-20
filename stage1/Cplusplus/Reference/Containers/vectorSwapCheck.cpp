// file : vectorSwapCheck.cpp
// void swap(vector& v)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> foo (3,100);
	vector<int> bar (5,200);

	foo.swap(bar);

	cout<<"foo contains:";
	for(auto cit = foo.cbegin(); cit != foo.cend(); ++ cit)
		cout<<"\t"<<*cit;

	cout<<endl;

	cout<<"bar contains:";
	for(auto cit = bar.cbegin(); cit != bar.cend(); ++ cit)
		cout<<"\t"<<*cit;
	cout<<endl;
	
	return 0;
}
