#include <string.h>
#include <stdint.h>

/**
 *  Fügt die angegebne Zeichananzahl einer Zeichenkette an eine andere an.
 *  @param src1 Pointer auf die erste Zeichenkette.
 *  @param src2 Pointer auf die Zeichenkette mit den zu kopierenden Zeichen.
 *  @param n Anzahl der Zeichen die kopiert werden sollen.
 *  @return zusammengesetzte Zeichenkette.
 */
char *strncat(char *src1,const char *src2,size_t n)
{
	size_t src2len = strlen(src2);
	src2len = n<src2len?n:src2len;
	size_t src1len = strlen(src1);
	uint32_t i;

	for (i=0;i<src2len;i++)
	{
		src1[src1len+i] = src2[i];
	}
	src1[src1len+src2len] = 0;
	return src1;
}
