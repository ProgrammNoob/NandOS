#include <string.h>

int ffs(int x)
{
  size_t i;
  for (i=0;i<sizeof(int)*8;i++)
  {
    if (x&(1<<i))
	{
		return i+1;
	}
  }
  return 0;
}