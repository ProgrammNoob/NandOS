#include <string.h>
#include <stdint.h>

/**
 *  Kopiert Anzahl Zeichen von einem Speicherbereich in einen anderen, der sich mit dem Ursprungsbereich überlappen darf.
 *  @param dest Pointer auf Ziel-Speicherbereich.
 *  @param src pointer auf Quell-speicherbereich.
 *  @param n Länge des zu kopierendem speicherbereichs in Bytes.
 *  @return Pointer auf Ziel-Speicherbereich.
 */
void *memmove(void *dest, const void *src, size_t n)
{
	if (dest==src) 
	{
		return dest;
	}
	size_t fast_count = n/sizeof(int);
	size_t byte_count = n%sizeof(int);
	int *fast_dest = (int*)dest;
	int *fast_src = (int*)src;
	uint8_t *byte_dest = ((uint8_t*)dest)+fast_count*sizeof(int);
	uint8_t *byte_src = ((uint8_t*)src)+fast_count*sizeof(int);
	size_t i;

	if (src>dest)
	{
		for (i=0;i<fast_count;i++) fast_dest[i] = fast_src[i];
		for (i=0;i<byte_count;i++) byte_dest[i] = byte_src[i];
	}
	else
	{
		for (i=byte_count;i>0;i--) byte_dest[i-1] = byte_src[i-1];
		for (i=fast_count;i>0;i--) fast_dest[i-1] = fast_src[i-1];
	}
	return dest;
}

