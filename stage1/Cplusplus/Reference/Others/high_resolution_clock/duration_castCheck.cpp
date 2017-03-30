// file : duration_castCheck.cpp
// template <class ToDuration, class Rep, class Period>
// constexpr ToDuration duration_cast(const duration<Rep,Period>& dtn);

// Converts the value of dtn into some other duration type, taking into account differences in their periods.

// The function does not use implicit conversions. Instead, all count values are internally converted into the widest representation
// (the common_type for the internal count types) and then casted to the destination type, all conversions being done 
// explicitly with static_cast.
// If the destination type has less precision, the value is truncated.

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	using namespace std::chrono;

	seconds s(1); // 1 second
	milliseconds ms = duration_cast<milliseconds> (s);

	ms += milliseconds(2500); // 2500 ms

	s = duration_cast<seconds> (ms); // truncated 

	cout<<"ms : "<<ms.count()<<endl;  // 3500
 	cout<<"s : "<<s.count()<<endl;   // 3
	return 0;
}