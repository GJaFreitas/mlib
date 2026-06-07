#include "mstr.h"

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Ensures the allocation size is at least 'size' bytes

   - The original pointer is assumed to be freed and can't be used

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrensuresize(char *s, uint64_t size)
{
	char	*new_str;

	if (mstrallocsize(s) >= size)
		return (s);
	new_str = mstrnewlen(s, size);
	mstrdestroy(s);
	return (new_str);
}

int32_t	mstrncmp(const char *s1, const char *s2, uint64_t n)
{
	uint64_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

int32_t	mstrcmp(const char *s1, const char *s2)
{
	uint64_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a pointer to the first place in the string where 'pattern' was
   found

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrsrch(char *s, const char *pattern)
{
	uint64_t	i;
	uint64_t	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == *pattern)
		{
			j = i;
			while (s[j] && s[j] == pattern[j - i])
				j++;
			if (pattern[j - i] == 0)
				return (&s[i]);
		}
		i++;
	}
	return (NULL);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a pointer to the first place in the string where the char was
   found

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrch(const char *s, const char c)
{
	uint64_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
