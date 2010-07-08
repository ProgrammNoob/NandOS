#include <string.h>

/**
 *  Vergleicht zwei Zeichenketten.
 *  @param str1 Pointer auf die erste Zeichenkette.
 *  @param str2 Pointer auf die zweite Zeichenkette.
 *  @return 0 = Gleich
 */
int strcmp(const char *str1,const char *str2)
{
	if (str1==str2) return 0;
	size_t i;
	
	for (i=0;(str1[i] || str2[i]);i++)
	{
		if (str1[i]!=str2[i])
		{
			return str1[i]-str2[i];
		}
	}
	return 0;
}