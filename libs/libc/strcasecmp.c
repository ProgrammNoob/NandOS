#include <string.h>

int strcasecmp(const char *str1,const char *str2)
{
	size_t i;
	for (i=0;(str1[i]!=0 && str2[i]!=0);i++)
	{
		if (str1[i]!=str2[i])
		{
			return str1[i]-str2[i];
		}
	}
	return 0;
}
