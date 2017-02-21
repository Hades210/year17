// file : int fegetround(void);
// Get rounding direction mode
// Returns a value that indicates the rounding direction mode, as specified in the current floating point environment
// return value
/**********************************************************************
*	FE_DOWNWARD		Round downward
*	FE_TONEAREST	Round to nearest
*	FE_TOWARDZERO	Round toward zero
*	FE_UPWARD		Round upward
***********************************************************************/

#include <iostream>
#include <cfenv>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	cout<<"rounding using ";
	switch(fegetround())
	{
		case FE_UPWARD: cout<<"upward"; break;
		case FE_TOWARDZERO: cout<<"toward-zero"; break;
		case FE_TONEAREST: cout<<"to-nearest";  break;
		case FE_DOWNWARD: cout<<"downward"; break;
		default: cout<<"unknown";
	}
	cout<<" rounding:\n";

	cout<<setiosflags(ios::fixed)<<setprecision(1)<<
		"rint (2.3) = " <<rint(2.3)<<"\n"<<
		"rint (3.8) = " <<rint(3.8)<<"\n"<<
		"rint(-2.3) = " <<rint(-2.3)<<"\n"<<
		"rint(-3.8) = " <<rint(-3.8)<<"\n";

	return 0;
}
