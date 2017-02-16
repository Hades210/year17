/**
 *category
 *Portion of the locale affected. It is one of the following constant values defined as macros in <clocale>:
 *     	value                                       Portion of the locale affected
 *		LC_ALL										The entire locale.
 *		LC_COLLATE									Affects the behavior of strcoll and strxfrm.
 *		LC_CTYPE									Affects character handling functions (all functions of <cctype>, except isdigit and isxdigit), and the multibyte and wide character functions.
 *		LC_MONETARY									Affects monetary formatting information returned by localeconv.
 *		LC_NUMERIC									Affects the decimal-point character in formatted input/output operations and string formatting functions, as well as non-monetary information returned by localeconv.
 *		LC_TIME										Affects the behavior of strftime.
 *
 *locale
 *C string containing the name of a C locale. These are system specific, but at least the two following locales must exist:
 *	locale name 		description
 *	"C"					Minimal "C" locale
 *	""					Environment's default locale
 *If the value of this parameter is NULL, the function does not make any changes to the current locale, but the name of the current locale is still returned by the function.
*/

#include <cstdio>
#include <clocale> // struct lconv, setlocale,localeconv
#include <ctime> // time_t, struct tm, time, localtime, strftime 

int main()
{
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];

	struct lconv * lc;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	int twice = 0;

	do 
	{
		printf("Current locale is %s\n",setlocale(LC_ALL,NULL));

		strftime(buffer,80,"%c",timeinfo);
		printf("Date is %s\n",buffer);

		lc = localeconv();
		printf("Currency symbol is %s\n",lc->currency_symbol);

		setlocale(LC_ALL,"");
	}while(!twice ++);

	return 0;
}
