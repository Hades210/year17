// file : time_since_epochCheck.cpp
// duration time_since_epoch() const;
// Returns a duration object with the time span value between the epoch and the time point.

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
	system_clock::time_point tp = system_clock::now();
	system_clock::duration dtn = tp.time_since_epoch();

	cout<<"current time since epoch, expressed in:"<<endl;
	cout<<"periods: "<<dtn.count()<<endl;
	cout<<"seconds: "<<dtn.count() * system_clock::period::num / system_clock::period::den<<endl;

	return 0;
}
