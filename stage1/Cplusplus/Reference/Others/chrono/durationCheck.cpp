// file : durationCheck.cpp
// template <class Rep, class Period = ratio<1> >
// class duration;

// Duration
// A duration object expresses a time span by means of a count and a period.
// Internally, the object stores the count as an object of member type rep (an alias of the first template parameter, Rep), which can be retrieved by calling member function count.
// This count is expresed in terms of periods. The length of a period is integrated in the type (on compile time) by its second template parameter (Period), which is a ratio type that expresses the number (or fraction) of seconds that elapse in each period.
// Rep
// An arithmetic type, or a class emulating an arithmetic type, to be used as the type for the internal count.
// Period
// A ratio type that represents the period in seconds.

// hours	signed integral type of at least 23 bits	ratio<3600,1>
// minutes	signed integral type of at least 29 bits	ratio<60,1>
// seconds	signed integral type of at least 35 bits	ratio<1,1>
// milliseconds	signed integral type of at least 45 bits	ratio<1,1000>
// microseconds	signed integral type of at least 55 bits	ratio<1,1000000>
// nanoseconds	signed integral type of at least 64 bits	ratio<1,1000000000>

// rep	The first template parameter (Rep)	Representation type used as the type for the internal count object.
// period	The second template parameter (Period)	The ratio type that represents a period in seconds.

/******************************************************************
*(1) duration() = default;
*(2) duration (const duration& dtn);
*(3) template <class Rep2, class Period2>
*	 constexpr duration(const duration<Rep2,Period2>& dtn);
*(4) template <class Rep2>
*	 constexpr explicit duration(const Rep2& n);
*******************************************************************/

#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;
using namespace std::chrono;

int main()
{
	typedef duration<int> seconds_type;
	typedef duration<int,std::milli> milliseconds_type;
	typedef duration<int,ratio<60*60> > hours_type;

	hours_type h_oneday(24); // 24h
	seconds_type s_oneday(60 * 60 * 24); // 86400s
	milliseconds_type ms_oneday(s_oneday); //86400000ms

	seconds_type s_onehour (60 * 60); //3600s
	// hours_type h_onehour(s_onehour); // NOT VALID (type truncates),use
	hours_type h_onehour(chrono::duration_cast<hours_type> (s_onehour));
	milliseconds_type ms_onehour (s_onehour); // 3600000ms (ok, no type truncation)


	cout<<h_oneday.count()<<" h in 1 day"<<endl;
	cout<<s_oneday.count()<<" s in 1 day"<<endl;
	cout<<ms_oneday.count()<<" ms in 1 day"<<endl;

	cout<<s_onehour.count()<<" s in 1h"<<endl;
	cout<<h_onehour.count()<<" h in 3600s"<<endl;
	cout<<ms_onehour.count()<<" ms in 1h "<<endl;

	seconds_type s_onehour2 (chrono::duration_cast<seconds_type>(ms_onehour)); // 小单位转大单位要使用 chrono::duration_cast<大单位>(小单位) 强制类型转换
	cout<<s_onehour2.count()<<" s in 3600000ms"<<endl;

	milliseconds_type ms_onehour2 (h_onehour);  // 大单位转小单位， 可以直接转换
	cout<<ms_onehour2.count()<<" ms in 1 h"<<endl;

	return 0;
}