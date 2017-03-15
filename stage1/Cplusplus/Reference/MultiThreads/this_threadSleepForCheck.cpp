// file : this_threadSleepForCheck.cpp
// template <class Rep, class Period>
//	void sleep_for(const chrono::duration<Rep,Period>& rel_time);
// Sleep for time span
// Blocks execution of the calling thread during the span of time specified by rel_time.
// The execution of the current thread is stopped until at least rel_time has passed form now. other threads continue their execution.

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
	cout<<"countdown\n";

	for(int i = 10; i > 0; i--)
	{
		cout<<i<<endl;
		this_thread::sleep_for(chrono::seconds(1));
	}

	cout<<"List off!\n";
	
	return 0;
}