// file : atomicOperatorCheck.cpp
/************************************************************************************
*	set value(1)		T operator= (T val) noexcept;
*						T operator= (T val) volatile noexcept;
*	copy[delete](2)		atomic& operator= (const atomic&) = delete;		
*						atomic& operator= (const atomic&) volatile = delete;
*************************************************************************************/

#include <iostream>
#include <atomic>
#include <thread>

using namespace std;

atomic<int> foo (0);

void set_foo(int x)
{
	foo = x;
}

void print_foo()
{
	while(foo == 0)
		this_thread::yield();
	cout<<"foo: "<<foo<<endl;
}

int main()
{
	thread first(print_foo);
	thread second(set_foo,10);
	first.join();
	second.join();

	return 0;
}