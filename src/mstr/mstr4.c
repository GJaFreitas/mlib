#include "mstr.h"

uint32_t	strfromlonglong_helper(char s[21], long long value)
{
	char				*p;
	char				aux;
	unsigned long long	v;
	size_t				l;

	if (value < 0)
	{
		if (value != LLONG_MIN)
			v = -value;
		else
			v = ((unsigned long long)LLONG_MAX) + 1;
	}
	else
		v = value;
	p = s;
	while (1)
	{
		*p++ = '0' + (v % 10);
		v /= 10;
		if (!v)
			break ;
	}
	if (value < 0)
		*p++ = '-';
	l = p - s;
	*p = '\0';
	p--;
	while (s < p)
	{
		aux = *s;
		*s = *p;
		*p = aux;
		s++;
		p--;
	}
	return (l);
}

char	*mstrfromll(long long number)
{
	char		buffer[21];
	uint32_t	len;

	len = strfromlonglong_helper(buffer, number);
	return (mstrnewlen(buffer, len));
}

void	mstrdestroy(char *s)
{
	t_mstr	*t;

	t = mstr_getptr(s);
	if (t->alloc & ALLOCSIZE_MASK)
		return ;
	free(t);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Takes an mstr and concatenates the given string literal

   - The original pointer is freed and can't be used

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrconstcat(char *str1, const char *literal)
{
	char		*s;
	uint64_t	len;
	uint64_t	lencat;

	lencat = _strlen(literal);
	len = _strlen(str1);
	s = mstrnewlen((char *)(const char *)NO_ZERO, len + lencat);
	mutils_memcpy(s, str1, len);
	mutils_memcpy(s + len, literal, lencat);
	mstrdestroy(str1);
	mstrsetlen(s, len + lencat);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Takes 2 mstr's and concatenates the second after the first.

   - The original pointer is freed and can't be used

   - The second string gets destroyed

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrcat(char *str1, char *str2)
{
	char		*s;
	uint64_t	len;
	uint64_t	lencat;

	lencat = _strlen(str2);
	len = _strlen(str1);
	s = mstrnewlen((char *)(const char *)NO_ZERO, len + lencat);
	mutils_memcpy(s, str1, len);
	mutils_memcpy(s + len, str2, lencat);
	mstrdestroy(str1);
	mstrdestroy(str2);
	mstrsetlen(s, len + lencat);
	return (s);
}
