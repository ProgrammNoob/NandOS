#include <string.h>
#include <stdint.h>

/**
 * Copies memory
 *  @param dest Destination for memory copy
 *  @param src Source for memory copy
 *  @param c Char which first oncurrence will stop copying
 *  @param n How many bytes to copy
 *  @return dest
 */
void *memccpy(void *dest,const void *src,int c,size_t n)
{
	uint8_t *dest8 = (uint8_t*)dest;
	uint8_t *src8 = (uint8_t*)src;
	uint32_t i;

	for (i=0;i<n;i++)
	{
		dest8[i] = src8[i];
		if (src8[i]==((uint8_t)c))
		{
			break;
		}
	}
	return dest;
}