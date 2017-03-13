// file : threadCheck.cpp

#include <iostream>
#include <thread>

using namespace std;

void foo()
{
	unsigned i = 0;
	while(i < 20)
	{
		cout<<"foo --> this is line "<< ++i<<endl;
	}
}

void bar(int x)
{
	while(x < 20)
	{
		cout<<"bar --> this is line"<< ++x<<endl;
	}
}

int main()
{
	thread first(foo);
	thread second(bar,0);

	cout<<"main, foo and bar now execute concurrently...\n";

	first.join();
	second.join();

	cout<<"foo and bar completed.\n";
	return 0;
}
