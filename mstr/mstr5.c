#include "mstr.h"

char	*mstrnew(const char *init)
{
	t_mstr		*t;
	char		*s;
	uint64_t	l;

	if (!init)
		return (NULL);
	l = _strlen(init);
	t = malloc(sizeof(t_mstr) + l + 1);
	if (!t)
		return (NULL);
	s = (char *)t + sizeof(t_mstr);
	mutils_memcpy(s, init, l);
	t->len = l;
	t->alloc = l;
	s[l] = 0;
	return (s);
}

uint64_t	mstrallocsize(char *s)
{
	t_mstr	*t;

	t = mstr_getptr(s);
	return (t->alloc);
}

void	mstrsetlen(char *s, uint64_t len)
{
	t_mstr	*t;

	t = mstr_getptr(s);
	t->len = len;
}

uint64_t	mstrupdatelen(char *s)
{
	t_mstr	*t;

	t = mstr_getptr(s);
	mstrsetlen(s, _strlen(s));
	return (t->len);
}

uint64_t	mstrlen(char *s)
{
	t_mstr	*t;

	t = mstr_getptr(s);
	return (t->len);
}
