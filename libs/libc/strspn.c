#include <string.h>

/**
 *  Ermittelt Index des ersten Zeichens in einer Zeichenkette, das nicht zum Zeichensatz in einer anderen Zeichen Kette
 */
size_t strspn(const char *string, const char *spanset)
{
    const char *sc1;
    for (sc1 = string; *sc1 != '\0'; sc1++)
        if (strchr(spanset, *sc1) == NULL)
		{
            return (sc1 - string);
		}
    return sc1 - string;
}
