#include <string.h>

/**
 * Compares memory
 *  @param srca First source to compare
 *  @param srcb Second source to compare
 *  @param n How many bytes to compare
 *  @return 0 = equal
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
		if (fast_srca[i]!=fast_srcb[i]){
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

char strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' || *str2 != '\0') {
        if (*str1 != *str2)
            return 1;
        str1++;
        str2++;
    }

    return 0;
}

void* memset(void* buf, int c, int n)
{
    unsigned char* p = buf;

    while (n--) {
        *p++ = c;
    }

    return buf;
}

void* memcpy(void* dest, const void* src, size_t n)
{
    unsigned char* d = dest;
    const unsigned char* s = src;

    while (n--) {
        *d++ = *s++;
    }

    return dest;
}
