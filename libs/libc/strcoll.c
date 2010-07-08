#include <string.h>

/**
 *  Vergleicht zwei Zeichenketten unter berücksichtigung der Locales.
 *  @param str1 Pointer auf die erste Zeichenkette.
 *  @param str2 Pointer auf die zweite Zeichenkette.
 *  @return 0 = Gleich
 *  @todo Locales und ann eine Richtige strcoll.
 */ 
int strcoll( const char *str1, const char *str2)
{
	return strcmp( str1, str2 );
}