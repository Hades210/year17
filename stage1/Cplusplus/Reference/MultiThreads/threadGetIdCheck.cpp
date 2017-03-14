// file : threadGetIdCheck.cpp
// id get_id() const noexcept;
// Returns the thread id.
// If the thread object is joinable, the function returns a value that uniquely identifies the thread.
// If the thread object is not joinable, the function returns a default-constructed object of member type thread::id.

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

thread::id main_thread_id = this_thread::get_id();

void is_main_thread()
{
	if(main_thread_id == this_thread::get_id())
		cout<<"This is the main thread.\n";
	else
		cout<<"This is not the main thread.\n";
}

int main()
{

	is_main_thread();

	thread th = thread(is_main_thread);
	th.join();

	return 0;
}