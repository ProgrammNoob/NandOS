#include <string.h>

/**
 *  Kopiert die angegebne Zeichananzahl einer Zeichenkette in eine andere Zeichenkette.
 *  @param dest Pointer auf Ziel-Zeichenkette.
 *  @param src Pointer auf Quell-Zeichenkette.
 *  @param n Anzahl der Zeichen die kopiert werden sollen.
 *  @return  Pointer auf Ziel-Zeichenkette.
 */
char *strncpy(char *dest,const char *src,size_t n)
{
	size_t len = strlen(src)+1;
	if (n<len)
	{
		len = n;
	}
	memcpy(dest,src,len-1);
	dest[len-1] = 0;
	return dest;
}