#include <string.h>
#include <stdint.h>

/**
 *  Schreib Zeichen in ein Speicherbereich.
 *  @param dest Pointer Ziel-Speicher.
 *  @param val Zeichen die geschrieben werden sollen.
 *  @param n Anzahl der zu schreibenden Bytes.
 *  @return Pointer Ziel-Speicher.
 */
void *memset(void *dest,int val,size_t n)
{
	size_t i;
	uint8_t *byte_dest = (uint8_t*)dest;
	for (i=0;i<n;i++) byte_dest[i] = val;
	return dest;
}