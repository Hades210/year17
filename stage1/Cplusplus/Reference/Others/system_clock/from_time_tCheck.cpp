// file : from_time_tCheck.cpp
// static time_point from_time_t( time_t t) noexcept;
// converts t into its equivalent of member type time_point

#include <iostream>
#include <chrono>
#include <ratio>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
	tm timeinfo = tm();
	timeinfo.tm_year = 117;
	timeinfo.tm_mon = 2;
	timeinfo.tm_mday = 1;

	time_t tt = mktime(&timeinfo);

	system_clock::time_point tp = system_clock::from_time_t(tt);
	system_clock::duration d = system_clock::now() - tp;

	typedef duration<int,ratio<60*60*24> > days_type;
	days_type ndays = duration_cast<days_type> (d);

	cout<<ndays.count()<<" days have passed since 3/1/2017";
	cout<<endl;

	system_clock::time_point epoch;
	tt = system_clock::to_time_t(epoch);
	cout<<ctime(&tt);
	
	return 0;
}