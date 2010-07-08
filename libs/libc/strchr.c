#include <string.h>

/**
 *  Ermttelt Zeiger auf erstes Vorkommen eines Zeichens in einer Zeichenkette.
 *  @param str Pointer auf zu durchsuchende Zeichenkette.
 *  @param chr Zeichen, nach dem gesucht werden soll.
 *  @return Pointer auf erstes Vorkommen des angegebenen zeichens in der angegebenen Zeichenkette.
 */
char *strchr(const char *str,int chr)
{
	size_t i;
	for (i=0;(str[i]!=0 && str[i]!=(char)chr);i++);
	return str[i]==chr?(char*)str+i:NULL;
}