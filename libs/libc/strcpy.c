#include <string.h>

/**
 *  Kopiert eine Zeichenkette in eine andere.
 *  @param dest Pointer auf Ziel-Zeichenkette.
 *  @param src Pointer auf Quell-Zeichenkette.
 *  @return Pointer auf Ziel-Zeichnkette.
 */
char *strcpy(char *dest,const char *src)
{
	size_t i;
	for (i=0;src[i];i++) dest[i] = src[i];
	dest[i] = 0;
	return dest;
}