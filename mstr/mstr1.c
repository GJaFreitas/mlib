#include "mstr.h"

void	mstrtoupper(char *s)
{
	uint64_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a pointer after every character in 'skip'

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrskipch(const char *s, const char *skip)
{
	uint64_t	i;

	i = 0;
	while (s[i])
	{
		if (!mstrch(skip, s[i]))
			return ((char *)s + i);
		i++;
	}
	return ((char *)s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Atoi

 * * * * * * * * * * * * * * * * * * * * * * * * */
int64_t	mstratoi(const char *s)
{
	int64_t	num;
	int32_t	sign;
	char	*cur;

	sign = 1;
	num = 0;
	cur = mstrskipch(s, WHITESPACE);
	if (*cur == '-')
		sign = -1;
	cur = mstrskipch(s, "+-");
	while (mstrisdigit(*cur))
		num = (num * 10) + (*(cur++) - '0');
	num *= sign;
	return (num);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a sub mstr

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrsubstr(const char *s, uint64_t start, uint64_t end)
{
	char		*sub;
	uint64_t	len;
	uint64_t	total_size;

	len = mstrupdatelen((char *)s);
	if (start > end || start > len)
		return (mstrnew(""));
	total_size = end - start;
	sub = mstrnewlen((const char *)(const char *)NO_ZERO, total_size);
	mutils_memcpy(sub, s + start, total_size);
	return (sub);
}

void	mstrtolower(char *s)
{
	uint64_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		i++;
	}
}
