// file : nowCheck.cpp
// static time_point now() noexcept;
// Returns the current time_point in the frame of the steady_clock.

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <thread>

using namespace std;

void fn()
{
	this_thread::sleep_for(std::chrono::seconds(1));
}

int main()
{
	using namespace std::chrono;

	steady_clock::time_point clock_begin = steady_clock::now();

	// cout<<"printing out 1000 stars..."<<endl;
	// for(int i = 0; i < 1000; ++i)	cout<<"*";	cout<<endl;

	cout<<"sleep for 1 seconds "<<endl;
	thread t(fn);
	t.join();
	
	steady_clock::time_point clock_end = steady_clock::now();
	
	steady_clock::duration time_span = clock_end - clock_begin;

	double nseconds = double (time_span.count()) * steady_clock::period::num / steady_clock::period::den;

	cout<<"It took me "<<nseconds<<" seconds"<<endl;
	
	return 0;
}