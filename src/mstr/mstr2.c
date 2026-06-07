#include "mstr.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Removes each character in the 'remove' array from the string

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrtrim(char *s, const char *remove)
{
	uint64_t	i;
	int64_t		l;

	i = 0;
	l = 0;
	mstrupdatelen(s);
	while (s[i])
	{
		if (mstrch(remove, s[i]))
		{
			mutils_memcpy(&s[i], &s[i + 1], mstrlen(s) - i);
			l++;
		}
		else
			i++;
	}
	mstrsetlen(s, mstrlen(s) - l);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Removes each occasion of 'pattern' from the string

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrtrimpattern(char *s, const char *pattern)
{
	uint64_t	pattern_len;
	int64_t		l;
	char		*found;

	l = 0;
	pattern_len = _strlen(pattern);
	mstrupdatelen(s);
	found = mstrsrch(s, pattern);
	while (found)
	{
		mutils_memcpy(found, found + pattern_len, mstrlen(s) - (found - s)
			- pattern_len);
		found = mstrsrch(s, pattern);
	}
	mstrsetlen(s, mstrlen(s) - l);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Concatenates every string given

   - Last argument must be NULL to signify the end

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrjoinall(char *s1, ...)
{
	va_list	ap;
	char	*s;
	char	*cur;

	s = mstrnew(s1);
	va_start(ap, s1);
	cur = va_arg(ap, char *);
	while (cur)
	{
		s = mstrconstcat(s, cur);
		cur = va_arg(ap, char *);
	}
	va_end(ap);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Concatenates every string given with 'sep' in between

   - Last argument must be NULL to signify the end

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrjoinallsep(char sep, char *s1, ...)
{
	va_list	ap;
	char	*s;
	char	*cur;
	char	separator[2];

	separator[0] = sep;
	separator[1] = 0;
	s = mstrnew(s1);
	va_start(ap, s1);
	cur = va_arg(ap, char *);
	while (cur)
	{
		s = mstrconstcat(s, cur);
		s = mstrconstcat(s, separator);
		cur = va_arg(ap, char *);
	}
	va_end(ap);
	return (s);
}
