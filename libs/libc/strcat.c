#include <string.h>

/**
 *  Fügt Zeichenkette an eine andere an.
 *  @param str1 Pointer auf die erste Zeichenkette.
 *  @param str2 Pointer auf die zweite zeichenkette.
 *  @return Pointer auf die zusammengesetzte Zeichenkette.
 */
char *strcat(char *str1,const char *str2)
{
	return strcpy(str1+strlen(str1),str2);
}