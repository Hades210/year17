// file : operatorsCheck.cpp
#include <iostream>
#include <complex>

using namespace std;

int main()
{
	complex<double> mycomplex;

	mycomplex = 10.0;
	mycomplex += 2.0;

	cout<<mycomplex<<endl;

	mycomplex = complex<double>(10.0,1.0);
	mycomplex += 10.0;

	if(mycomplex == complex<double> (20.0,1.0))
		cout<<"mycomplex is "<<mycomplex<<endl;
	
	return 0;
}