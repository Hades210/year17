// file : to_time_tCheck.cpp
// static time_t to_time_t(const time_point& tp) noexcept;
// converts tp into its equivalent of type time_t.

#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main()
{
	using namespace std::chrono;

	system_clock::time_point nowTime = system_clock::now();
	duration<int,ratio<60*60> > one_hour (1);

	time_t tt;

	tt = system_clock::to_time_t(nowTime);
	cout<<"now is : "<<ctime(&tt);

	system_clock::time_point one_hour_after = nowTime + one_hour;

	tt = system_clock::to_time_t(one_hour_after);
	cout<<"one hour after now is "<<ctime(&tt);
	
	return 0;
}