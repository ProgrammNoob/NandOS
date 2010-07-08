#include <string.h>

/**
 *  Ermttelt Zeiger auf letztes Vorkommen eines Zeichens in einer Zeichenkette.
 *  @param str Pointer auf zu durchsuchende Zeichenkette.
 *  @param chr Zeichen, nach dem gesucht werden soll.
 *  @return Pointer auf erstes Vorkommen des angegebenen zeichens in der angegebenen Zeichenkette.
 */
char *strrchr(const char *s, int c)
{
	char *l = NULL;
	size_t i;
	for (i=0;s[i];i++)
	{
		if (s[i]==c)
		{
			l = (char*)s+i;
		}
	}
	return l;
}