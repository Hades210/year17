// file : complexFnCheck.cpp
/******************************************************************************
*complex(1) 		template <class T> T real(const complex<T>& x);
*arithmetic type(2)	double real(ArithmeticType x); // additional overloads
*******************************************************************************/
/******************************************************************************
*complex(1) 		template <class T> T imag(const complex<T>& x);
*arithmetic type(2)	double imag(ArithmeticType x); // additional overloads
*******************************************************************************/
/******************************************************************************
* template <class T> T abs (const complex<T>& x);
* This function is overloaded in <cstdlib> for integral types, in <cmath> for
* floating-point types, in<valarray> for valarrays.
*******************************************************************************/
/******************************************************************************
*complex(1) 		template <class T> T arg(const complex<T>& x);
*arithmetic type(2)	double arg(ArithmeticType x); // additional overloads
*******************************************************************************/
// Returns the phase angle (or angular component) of the complex number x, expressed in radians.
// It returns the same as atan2(x.imag(),x.real());

/******************************************************************************
*complex(1) 		template <class T> T norm(const complex<T>& x);
*arithmetic type(2)	double norm(ArithmeticType x); // additional overloads
*******************************************************************************/
// Returns the norm value of the complex number x.
// This is the square of abs(x).
/******************************************************************************
*complex(1) 		template <class T> complex<T> conj(const complex<T>& x);
*arithmetic type(2)	complex<double> conj(ArithmeticType x); // additional overloads
*******************************************************************************/
// Returns the conjugate of the complex number x.
// The conjugate of a complex number (real,imag) is (real, -imag).

// template <class T> complex<T> polar(const T& rho, const T& theta = 0);
// Returns a complex object (in cartesian format) corresponding to the complex number defined by 
// its polar components rho and theta, where rho is the magnitude(modulus) and theta is the phase angle. 
// The values in the return value are the same as if:
// real = rho * cos(theta);
// imag = rho * sin(theta);

/******************************************************************************
*complex(1) 		template <class T> complex<T> proj(const complex<T>& x);
*arithmetic type(2)	complex<double> proj(ArithmeticType x); // additional overloads
*******************************************************************************/
// Returns the projection of the complex number x onto the Riemann sphere.

#include <iostream>
#include <complex>
#include <limits>

using namespace std;

int main()
{
	complex<double> mycomplex(10.0,1.0);

	cout<<"Real part: "<<real(mycomplex)<<endl;
	cout<<"Imaginary part: "<<imag(mycomplex)<<endl;

	complex<double> c1(3.0,4.0);
	cout<<"The absolute value of "<<c1 <<" is "<<abs(c1)<<endl;
	cout<<"The polar form of "<<c1<<" is "<<abs(c1)<<"*e^i*"<<arg(c1)<<"rad"<<endl;

	cout<<"The norm of "<<c1 <<" is "<<norm(c1)<<endl;
	cout<<"The conjugate of "<<c1<<" is "<<conj(c1)<<endl;

	cout<<"The complex whose magnitude is "<<2.0;
	cout<<" and phase angle is "<<0.5;
	cout<<" is "<<polar(2.0,0.5)<<endl;

	complex<double> c2(numeric_limits<double>::infinity(),2.0);
	cout<<"The projection of "<<cw<<" is "<<proj(c2)<<endl;

	return 0;
}