// file : fesetroundCheck.cpp
// int fesetround (int rdir);
// parameters the same as fegetround

#include <iostream>
#include <cfenv>
#include <cmath>
#include <iomanip>

#pragma STDC FENV_ACCESS on

using namespace std;

int main()
{
	cout<<"roundint -3.8:\n";

	cout<<setiosflags(ios::fixed)<<setprecision(1);

	fesetround(FE_DOWNWARD);
	cout<<"FE_DOWNWARD: "<<rint(-3.8)<<"\n";

	fesetround(FE_TONEAREST);
	cout<<"FE_TONEAREST: "<<rint(-3.8)<<"\n";

	fesetround(FE_TOWARDZERO);
	cout<<"FE_TOWARDZERO: "<<rint(-3.8)<<"\n";

	fesetround(FE_UPWARD);
	cout<<"FE_UPWARD: "<<rint(-3.8)<<"\n";

	return 0;
}
