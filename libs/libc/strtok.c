#include <string.h>

char *strsep (char **stringp, const char *delim)
{
	char *begin, *end;

	begin = *stringp;
	if (begin == NULL)
		return NULL;

	if (delim[0] == '\0' || delim[1] == '\0')
    {
		char ch = delim[0];

		if (ch == '\0')
		{
			end = NULL;
		}
		else
		{
			if (*begin == ch)
			{
				end = begin;
			}
			else if (*begin == '\0')
			{
				end = NULL;
			}
			else
			{
				end = strchr (begin + 1, ch);
			}
		}
    }
	else
    /* Find the end of the token.  */
    {
		end = strpbrk (begin, delim);
	}
	
	if (end)
    {
		/* Terminate the token and set *STRINGP past NUL character.  */
		*end++ = '\0';
		*stringp = end;
    }
	else
    /* No more delimiters; this is the last token.  */
    *stringp = NULL;

	return begin;
}

char *strtok(char *s, const char *delim)
{
	static char *holder;

	if (s)
	{
		holder = s;
	}
	
	do
	{
		s = strsep(&holder, delim);
	} while (s && !*s);

	return s;
}