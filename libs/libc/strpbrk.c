#include <string.h>

/**
 *  Sucht nach dem ersten Vorkommen eines belibigen Zeichens aus einer Zeichenkette in einer anderen Zeichenkette.
 *  @param s Pointer auf Zeichenkette in der gesucht werden soll.
 *  @param accept Zeichenkette aus der das gesuchte Zeichen stammt..
 *  @return  Pointer auf gefundenes Zeichen.
 */
char *strpbrk(const char *s1, const char *s2)
{
    const char *sc1;
    for (sc1 = s1; *sc1 != '\0'; sc1++)
        if (strchr(s2, *sc1) != NULL)
            return (char *)sc1;
    return NULL;
}
