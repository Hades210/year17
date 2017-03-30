// file : nowCheck.cpp
// class high_resolution_clock;
// The members of clock classes provide access to the current time_point
// high_resolution_clock is the clock with the shortest tick period. It may be a synonym for system_clock or steady_clock.

// highest precision: It is the clock type with the highest precision.

// static time_point now() noexcept;
// Returns the current time_point in the frame of the high_resolution_clock.

#include <iostream>
#include <ctime>
#include <chrono>
#include <ratio>
#include <thread>

using namespace std;

int main()
{
	using namespace std::chrono;

	high_resolution_clock::time_point clock_begin = high_resolution_clock::now();
	// cout<<"printing out 1000 stars..."<<endl;
	// for(int i = 0; i < 1000; ++i) cout<<"*";	cout<<endl;

	cout<<"sleep for 1 s"<<endl;
	this_thread::sleep_for(seconds(1));
	high_resolution_clock::time_point clock_end = high_resolution_clock::now();
	
	duration<double> time_span = duration_cast<duration<double> > (clock_end - clock_begin);

	cout<<"It took me "<<time_span.count()<<" seconds"<<endl;
	return 0;
}