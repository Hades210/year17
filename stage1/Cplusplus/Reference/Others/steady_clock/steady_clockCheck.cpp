// file : steady_clockCheck.cpp
// class steady_clock;
// clock classes provide access to the current time_point
// steady_clock is specifically designed to calculate time intervals.

// monotonic : Its member now never returns a lower value than in a previous call.
// steady : Every tick the clock advances takes the same amount of time (in therms of physical time)

// The following aliases are member types of steady_clock
// rep:	An arithmetic type (or a class that emulates it)	Used to store a count of periods.
// period:	A ratio types	Represents the length of period in seconds.
// duration:	duration<rep,period>	The clock's duration type
// time_point : time_point<steady_clock> The clock's time_point type.

// is_ready true

#include <iostream>
#include <ctime>
#include <chrono>
#include <ratio>

using namespace std;

int main()
{
	using namespace std::chrono;

	steady_clock::time_point t1 = steady_clock::now();

	cout<<"printing out 1000 stars..."<<endl;
	for(int i = 0; i < 1000; ++i) cout<<"*";
	cout<<endl;

	steady_clock::time_point t2 = steady_clock::now();

	duration<double> time_span = duration_cast<duration<double> > (t2 - t1);

	cout<<"It took me "<<time_span.count()<<" seconds"<<endl;
	
	return 0;
}