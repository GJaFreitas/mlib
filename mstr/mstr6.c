#include "mstr.h"
#include <stdint.h>

static uint64_t	_get_token_amount(const char *s, const char *separators)
{
	uint64_t	count;
	uint64_t	i;

	count = 1;
	i = 0;
	while (s[i])
	{
		if (mstrch(separators, s[i]))
			count++;
		i++;
	}
	return (count);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Creates an array of strings based on the 'separators' and given string

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	**mstrtokenize(const char *s, const char *separators)
{
	char		**arr;
	uint64_t	i;
	uint64_t	j;
	uint64_t	count;

	j = 0;
	i = 0;
	count = _get_token_amount(s, separators);
	arr = malloc(sizeof(char *) * (count + 1));
	arr[count] = NULL;
	count = 0;
	while (s[i])
	{
		if (mstrch(separators, s[i]))
		{
			arr[count++] = mstrsubstr(s, j, i);
			j = i + 1;
		}
		i++;
	}
	if (!count)
		return (arr);
	arr[count] = mstrsubstr(s, j, i);
	return (arr);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Creates an array of strings based on the 'separators' and given string and
   removes whitespaces from tokens

   - Sets string lenght

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	**mstrtokenizetrim(const char *s, const char *separators)
{
	char		**arr;
	uint64_t	i;
	uint64_t	j;
	uint64_t	count;

	j = 0;
	i = 0;
	count = _get_token_amount(s, separators);
	arr = malloc(sizeof(char *) * (count + 1));
	arr[count] = NULL;
	count = 0;
	while (s[i])
	{
		if (mstrch(separators, s[i]))
		{
			arr[count++] = mstrtrim(mstrsubstr(s, j, i), WHITESPACE);
			j = i + 1;
		}
		i++;
	}
	if (!count)
		return (arr);
	arr[count] = mstrtrim(mstrsubstr(s, j, i), WHITESPACE);
	return (arr);
}
