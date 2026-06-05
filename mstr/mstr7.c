#include "mstr.h"
#include "mutils.h"
#include <stdint.h>

static inline int64_t
	_calculate_size(char *s, char *pattern, char *substitution)
{
	int64_t	i;
	int64_t	sublen;
	int64_t	patternlen;
	int64_t	count;

	sublen = mstrlen(substitution);
	patternlen = mstrlen(pattern);
	if (sublen < patternlen)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == *pattern && !mstrncmp(&s[i], pattern, mstrlen(pattern)))
		{
			count++;
			i += patternlen - 1;
		}
		i++;
	}
	if (mstrallocsize(s) > (count * (sublen - patternlen)))
		return (-1);
	return (_strlen(s) + (count * (sublen - patternlen)));
}

static void	_loop(char *s, char *pattern, char *substitution, char *temp)
{
	uint64_t	j;
	uint64_t	i;

	i = 0;
	j = 0;
	while (temp[i])
	{
		if (temp[i] == *pattern && \
			!mstrncmp(&temp[i], pattern, mstrlen(pattern)))
		{
			mutils_memcpy(&s[j], substitution, mstrlen(substitution));
			j += mstrlen(substitution);
			i += mstrlen(pattern);
			mutils_memcpy(&s[j], &temp[i], mstrlen(temp) - i);
		}
		i++;
		j++;
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Subsitutes every instance of the mstr 'pattern' with 'substitute', neither
   can be NULL

   - 'pattern' and 'substitution' must be mstr's initialized with the right size

   - The original pointer is assumed to be freed and can't be used

   - 'pattern' and 'substitution' are destroyed

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrsubstitute(char *s, char *pattern, char *substitution)
{
	int64_t		size;
	char		*temp;

	temp = mstrnew(s);
	size = _calculate_size(s, pattern, substitution);
	if (size != -1)
	{
		mstrdestroy(s);
		s = mstrnewlen(temp, size);
	}
	_loop(s, pattern, substitution, temp);
	mstrdestroy(pattern);
	mstrdestroy(substitution);
	mstrdestroy(temp);
	return (s);
}
