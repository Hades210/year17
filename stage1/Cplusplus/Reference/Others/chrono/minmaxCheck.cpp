// file : minmaxCheck.cpp
// static constexpr duration min();
// Returns the minimum value of duration.
// static constexpr duration_min() {
//	return duration_values<rep>::min();
//}

// static constexpr duration max();
// Returns the maximum value of duration.
// static constexpr duration max() {
//	return duration_values<rep>::max();
//}

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	cout<<"system_clock durations can represent:"<<endl;
	cout<<"min: "<<std::chrono::system_clock::duration::min().count()<<"\n";
	cout<<"max: "<<std::chrono::system_clock::duration::max().count()<<"\n";

	return 0;
}
