//// file : time_pointCheck.cpp
// template <class Clock, class Duration = typename Clock::duration>
// class time_point;

// A time_point object expresses a point in time relative to a clock's epoch.
// Internally, The object stores an object of a duration type, and uses the Clock type as a reference for its epoch.

// Clock: A clock class, such as system_clock, steady_clock, high_resolution_clock or a custom clock class.
// Duration: A duration type.

// The following aliases are member types of time_point. They are widely used as parameter and return types by member functions.
// clock:		The first template parameter 	The clock class (system_clock, steady_clock, high_resolution_clock or a custom clock class)
// duration: 	The second template parameter	The duration type used to represent the time point
// rep:			duration::rep 					Type returned by duration::count
// period:		duration::period				The ratio type that represents the length of a period in seconds.

// (1) time_point();
// (2) template <class Duration2> time_point(const time_point<clock, Duration2>& tp);
// (3) explicit time_point(const duration& dtn);

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
	system_clock::time_point tp_epoch; // epoch_value
	time_point<system_clock,duration<int> > tp_seconds(duration<int>(1));

	system_clock::time_point tp(tp_seconds);
	
	cout<<"1 second since system_clock = ";
	cout<<tp.time_since_epoch().count()<<" system_clock periods."<<endl;

	time_t tt = system_clock::to_time_t(tp);
	cout<<"time_point tp is: "<<ctime(&tt)<<endl;

	tt = system_clock::to_time_t(tp_epoch);
	cout<<"time_point tp_epoch is: "<<ctime(&tt)<<endl;

	return 0;
}