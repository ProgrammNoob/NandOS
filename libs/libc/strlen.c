#include <string.h>

/**
 *  Ermitelt die Länge einer Zeichenkette.
 *  @param str Pointer auf die Zeichenkette.
 *  @return Länge der Zeichenkette.
 */
size_t strlen(const char *str)
{
	if (str==NULL)
	{
		return 0;
	}
	size_t i;
	for (i=0;str[i];i++);
	return i;
}