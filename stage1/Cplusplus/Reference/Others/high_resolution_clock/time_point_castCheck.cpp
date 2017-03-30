// file : time_point_castCheck.cpp
// template <class ToDuration, class Clock, class Duration>
//	time_point<Clock,Duration> time_point_cast (const time_point<Clock,Duration> & tp);
// Converts the value of tp into a time_point type with a different duration internal object, taking iinto account differences in 
// their durations's periods.
// The function uses duration_cast to convert the internal duration objects.
// Notice that the function's first template paramenter is not the return type, but its duration component.

#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;

int main()
{
	using namespace std::chrono;

	typedef duration<int,ratio<60*60*24> > days_type;

	time_point<system_clock, days_type> today = time_point_cast<days_type> (system_clock::now());
	cout<<today.time_since_epoch().count()<<" days since epoch"<<endl;
	return 0;
}