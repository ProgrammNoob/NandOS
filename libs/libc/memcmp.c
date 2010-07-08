#include <string.h>
#include <stdint.h>

/**
 *  Vergleicht zwei Speicherbereiche.
 *  @param srca Pointer auf ersten speicherbereich.
 *  @param srcb Pointer auf zweiten Speicherbereich.
 *  @param n länge des zu vergleichendem Speicherbereichs in Bytes.
 *  @return 0 = gleich
 */
int memcmp(const void *srca,const void *srcb,size_t n)
{
	if (srca==srcb) return 0;
	size_t fast_count = n/sizeof(int);
	size_t byte_count = n%sizeof(int);
	int *fast_srca = (int*)srca;
	int *fast_srcb = (int*)srcb;
	uint8_t *byte_srca = ((uint8_t*)srca)+fast_count*sizeof(int);
	uint8_t *byte_srcb = ((uint8_t*)srcb)+fast_count*sizeof(int);
	size_t i;

	for (i=0;i<fast_count;i++)
	{
		if (fast_srca[i]!=fast_srcb[i])
		{
			return fast_srca[i]-fast_srcb[i];
		}
	}
	for (i=0;i<byte_count;i++)
	{
		if (byte_srca[i]!=byte_srcb[i])
		{
			return byte_srca[i]-byte_srcb[i];
		}
	}
	return 0;
}