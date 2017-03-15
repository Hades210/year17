// file : this_threadSleepUntilCheck.cpp
// template <class Clock, class Duration>
//	void sleep_until(const chrono::time_point<Clock,Duration>& abs_time);
// Sleep until time point
// Blocks the calling thread until abs_time.
// The execution of the current thread is stopped until at least abs_time, while other threads may continue to advance.

#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
	using chrono::system_clock;

	std::time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
	struct std::tm* ptm = localtime(&tt);
	char buffer[80];
	strftime(buffer,80,"%c",ptm);
	cout<<"Current time: "<<buffer<<endl;

	cout<<"Waiting for the next minute to begin...\n";
	++ptm->tm_min;
	ptm->tm_sec = 0;

	this_thread::sleep_until(chrono::system_clock::from_time_t(mktime(ptm)));
	strftime(buffer,80,"%c",ptm);
	cout<<buffer<<" reached!\n";
	return 0;
}
