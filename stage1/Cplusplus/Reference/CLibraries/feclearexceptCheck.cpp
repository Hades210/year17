// file: feclearexceptCheck.cpp
// <cfenv> Floating-point environment
// int feclearexcept(int excepts);
// Attempts to clear the floating-point exceptions specified by excepts.
// Programs calling this function shall ensure that program FENV_ACCESS is enabled for the call.
// c++ 11 only

/***********************************************************************************************************************************
*	FE_DIVBYZERO	Pole error: division by zero, or some other asymptotically infinite result (from finite arguments).
*	FE_INEXACT		Inexact: the result is not exact.
*	FE_INVALID		Domain error: At least one of the arguments is a value for which the function is not defined.
*	FE_OVERFLOW		Overflow range error: The result is too large in magnitude to be represented as a value of the return type
*	FE_UNDERFLOW	Underflow range error: The result is too small in magnitude to be represented as a value of the return type
*	FE_ALL_EXCEPT	All exceptions (selects all of the exceptions supported by the implementation)
************************************************************************************************************************************/


#include <iostream>
#include <cmath>
#include <cfenv>

#pragma STDC FENV_ACCESS on

using namespace std;

int main()
{
	feclearexcept (FE_ALL_EXCEPT);
	sqrt(-1);
	if(fetestexcept(FE_INVALID))
		cout<<"sqrt(-1) raises FE_INVALID\n";

	return 0;
}
