// file : countCheck.cpp
// constexpr rep count() const;
// Returns the internal count of the duration object.

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	using namespace std::chrono;

	milliseconds foo(1000);
	foo *= 60;

	cout<<"duration (in periods):";
	cout<<foo.count()<<" milliseconds."<<endl;

	cout<<"duration (in seconds): ";
	cout<<foo.count() * milliseconds::period::num / milliseconds::period::den<<" seconds."<<endl;
	
	return 0;
}