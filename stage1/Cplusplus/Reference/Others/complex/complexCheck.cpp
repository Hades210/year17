// file : complexCheck.cpp
// The complex numbers library
// template <class T> class complex;
/**********************************************************************************
*initialization(1)	complex(const T& re = T(), const T& im = T());
*copy(2)			complex(const complex& x);
*conversion(3)		template <class U>
*					complex (const complex<U>& x);
***********************************************************************************/
// The float, double and long double specializations have constexpr constructors and only
// allow explicit conversions to types with lower precision. Their constructors are declared as:
// template <> class complex<float> {
// 	constexpr complex (float re = 0.0f, float im = 0.0f);
// 	explicit constexpr complex(const complex<double>& x);
// 	explicit constexpr complex(const complex<long double>& x);
// 	// ... (other members)	
// };

// template <> class complex<double> {
// 	constexpr complex (double re = 0.0, double im = 0.0);
// 	constexpr complex(const complex<float>& x);
// 	explicit constexpr complex(const complex<long double>& x);
// 	// ...(other members)
// };

// template <> class complex<long double> {
// 	constexpr complex(long double re = 0.0L, long double im = 0.0L);
// 	constexpr complex (const complex<float>& x);
// 	constexpr complex (const complex<double>& x);	
// };

#include <iostream>
#include <complex>

using namespace std;

int main()
{
	complex<double> first (2.0,2.0);
	complex<double> second (first);
	complex<long double> third (second);

	cout<<first<<endl;
	cout<<second<<endl;
	cout<<third<<endl;
	
	return 0;
}