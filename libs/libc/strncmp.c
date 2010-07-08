#include <string.h>

/**
 *  Vergleicht eine Zeichenkette mit einem Teil einer anderen Zeichenkette.
 *  @param str1 Pointer auf die erste Zeichenkette.
 *  @param str2 Pointer auf die zweite Zeichenkette.
 *  @param n Anzal der zu Vergleichenden Zeichen.
 *  @return 0 = Gleich
 */
int strncmp(const char *str1,const char *str2,size_t n)
{
	if (str1==str2)
	{
		return 0;
	}
	size_t i;

	for (i=0;(str1[i] || str2[i]) && i<n;i++)
	{
		if (str1[i]!=str2[i]) return str1[i]-str2[i];
	}
	return 0;
}