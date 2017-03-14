// file : this_threadGetIdCheck.cpp
// This namespace groups a set of functions that access the current thread.
// this_thread::get_id()
// Returns the thread id of the calling thread.
// This value uniquely identifies the thread.

#include <iostream>
#include <thread>

using namespace std;

thread:: id main_thread_id = this_thread::get_id();

void is_main_thread()
{
	if(main_thread_id == this_thread::get_id())
		cout<<"This is the main thread."<<endl;
	else
		cout<<"This is not the main thread."<<endl;
}

int main()
{
	is_main_thread();

	thread th(is_main_thread);
	th.join();

	return 0;
}