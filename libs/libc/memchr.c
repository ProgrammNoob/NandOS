#include <string.h>
#include <stdint.h>

/**
 *  Sucht in einem Speicherbereich nach erstem Vorkommen eines Zeichens.
 *  @param src Pointer auf Speicherbereich der durchsucht werden soll.
 *  @param c Zeichen nach dem gesucht wird
 *  @param n länge des zu durchuchenden Speicherbereichs in Bytes.
 *  @return Pointer auf c im angegebenem Speicherbereich.
 */
void *memchr(const void *src,int c,size_t n)
{
	uint8_t *src8 = (uint8_t*)src;
	uint32_t i;
	
	for (i=0;i<n;i++)
	{
		if (src8[i]==((uint8_t)c))
		{
			return (void*)(src8+i);
		}
	}
	return NULL;
}