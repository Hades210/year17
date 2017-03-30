// file : image_real_check.cpp
/*********************************************
*get(1)	T imag() const;
*set(2) void image(T val);
*get(1) T real() const;
*set(2) void real(T val);
*********************************************/
#include <iostream>
#include <complex>

using namespace std;

int main()
{
	complex<double> mycomplex(20.0,2.0);

	cout<<"Imaginary part: "<<mycomplex.imag()<<endl;
	cout<<"Real part: "<<mycomplex.real()<<endl;

	return 0;
}