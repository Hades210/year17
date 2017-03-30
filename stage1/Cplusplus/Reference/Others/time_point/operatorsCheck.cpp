// file : operatorsCheck.cpp

#include <iostream>
#include <chrono>

using namespace std;

int main()
{
	using namespace chrono;

	system_clock::time_point tp,tp2; // epoch value
	system_clock::duration dtn (duration<int> (1)); // 1s

	tp += dtn;
	tp2 -= dtn;
	tp2 = tp + dtn;
	tp = dtn + tp2;
	tp2 = tp2 - dtn;
	dtn = tp - tp2;

	cout<<std::boolalpha;

	cout<<"tp == tp2: "<<(tp == tp2)<<endl;
	cout<<"tp > tp2: "<<(tp > tp2)<<endl;
	cout<<"dtn: "<<dtn.count()<<endl;

	return 0;
}