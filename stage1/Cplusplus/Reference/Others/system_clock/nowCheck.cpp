// file : nowCheck.cpp
// static time_point now() noexcept;

#include <iostream>
#include <chrono>
#include <ratio>
#include <ctime>

using namespace std;
using namespace std::chrono;

int main()
{
	system_clock::time_point today = system_clock::now();

	duration<int,ratio<60*60*24> > one_day (1);

	time_t tt;

	tt = system_clock::to_time_t(today);
	cout<<"today is "<<ctime(&tt);

	system_clock::time_point yesterday = today - one_day;
 	
 	tt = system_clock::to_time_t(yesterday);
 	cout<<"yesterday is "<<ctime(&tt);

 	
	return 0;
}