// file:localeCheck.cpp
// char* setlocale(int category, const char* locale)
// struct lconv* lc = localeconv();

#include <cstdio>
#include <clocale>

int main()
{
	setlocale(LC_MONETARY,"");
	struct lconv* lc;
	lc = localeconv();

	printf("Local currency symbol: %s\n",lc->currency_symbol);
	printf("International currency symbol: %s\n",lc->int_curr_symbol);

	return 0;
}
