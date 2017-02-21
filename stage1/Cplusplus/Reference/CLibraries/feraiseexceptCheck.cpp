// file : feraiseexceptCheck.cpp
// int feraiseexcept (int excepts);
// Raise floating-point exception
// parameters the same as feclearexcept
// c++ 11 only

#include <iostream>
#include <cfenv>

using namespace std;

#pragma STDC FENV_ACCESS on

double fn (double x) {
	if (x == 0.0) feraiseexcept(FE_INVALID);
	return x;
}

int main()
{
	feclearexcept(FE_ALL_EXCEPT);
	fn(0.0);

	if(fetestexcept(FE_INVALID))
		cout<<"FE_INVALID raised\n";

	return 0;
}
