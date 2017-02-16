// file : climitsCheck.cpp
// This header defines constants with the limits of fundamental integral types for the specific system and compiler implementation used.
// The limits for fundamental floating-point types are defined in <cfloat> (<float.h>).
// The limits for width-specific integral types and other typedef types are defined in <cstdint> (<stdint.h>).
// macro contains in <climits>

#include <cstdio>
#include <climits>

int main()
{
	printf("Number of bits in a char object (byte): %d\n",CHAR_BIT);

	printf("Minimum value for an object of type signed char: %d\n",SCHAR_MIN);
	printf("Maximum value for an object of type signed char: %d\n",SCHAR_MAX);
	printf("Maximum value for an object of type unsigned char: %d\n",UCHAR_MAX);
	printf("Minimum value for an object of type char: %d\n",CHAR_MIN);
	printf("Maximum value for an object of type char: %d\n",CHAR_MAX);
	printf("Maximum number of bytes in a multibyte character, for any locale: %d\n",MB_LEN_MAX);

	printf("Minimum value for an object of type short int: %d\n",SHRT_MIN);
	printf("Maximum value for an object of type short int: %d\n",SHRT_MAX);
	printf("Maximum value for an object of type unsigned short int: %d\n",USHRT_MAX);

	printf("Minimum value for an object of type int: %d\n",INT_MIN);
	printf("Maximun value for an object of type int: %d\n",INT_MAX);
	printf("Maximum value for an object of type unsigned int: %lld\n",UINT_MAX);

	printf("Minimum value for an object of type long int: %ld\n",LONG_MIN);
	printf("Maximum value for an object of type long int: %ld\n",LONG_MAX);
	printf("Maximum value for an object of type unsigned long int: %lld\n",ULONG_MAX);

	printf("Minimum value for an object of type long long int: %lld\n",LLONG_MIN);
	printf("Maximum value for an object of type long long int: %lld\n",LLONG_MAX);
	printf("Maximum value for an object of type unsigned long long int: %lld\n",ULLONG_MAX);

	return 0;
}
