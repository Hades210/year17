// file : system_clockCheck.cpp
// class system_clock;
// Clock classes provide access to the current time_point
// Specifically, system_clock is a system-wide realtime clock.
// realtime : It is intended to represent the real time, and thus it can be translated in some way to and from calendar representations
// (see to_time_t and from_time_t member functions).
// signed count : Its time_point values can refer to times before the epoch (with negative values)
// system-wide :  All processes running on the system shall retrieve the same time_point values by using this clock.

// The following aliases are member types of system_clock.
// rep:	A signed arithmetic type (or a class that emulates it)	used to store a count of periods
// period: A ratio type 	Represents the length of a period in seconds.
// duration: duration<rep,period>	The clock's duration type.
// time_point: time_point<system_clock>	The clock's time_point type.

// is_steady	a bool value specifying whether the clock always advances, and whether it does at a steady state
// relative to physical time. If true, this implies that the system clock may not be adjusted.

#include <iostream>
#include <chrono>
#include <ratio>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
	using std::chrono::system_clock;

	duration<int,ratio<60*60*24> > one_day(1);

	system_clock::time_point today = system_clock::now();
	system_clock::time_point tomorrow = today + one_day;
	system_clock::time_point the_day_after_tomorrow = tomorrow + one_day;

	time_t tt;

	tt = system_clock::to_time_t(today);
	cout<<"Today is "<<ctime(&tt);

	tt = system_clock::to_time_t(tomorrow);
	cout<<"Tomorrow will be "<<ctime(&tt);

	tt = system_clock::to_time_t(the_day_after_tomorrow);
	cout<<"The day after Tomorrow  will be "<<ctime(&tt);

	return 0;
}