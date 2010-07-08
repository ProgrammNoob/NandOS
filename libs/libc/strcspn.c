#include <string.h>

/**
 *  Sucht einer Zeichenkette nach Zeichen, die in der anderen Zeichenkette nicht enthalten sind.
 */
size_t (strcspn)(const char *s1, const char *s2)
{
    const char *sc1;
    for (sc1 = s1; *sc1 != '\0'; sc1++)
        if (strchr(s2, *sc1) != NULL)
            return (sc1 - s1);
    return sc1 - s1;            /* terminating nulls match */
}
