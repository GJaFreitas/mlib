#include "mstr.h"

t_mstr	*mstr_getptr(const char *s)
{
	t_mstr	*t;

	t = (t_mstr *)(s - sizeof(t_mstr));
	return (t);
}

uint64_t	_strlen(const char * s)
{
	uint64_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*mstrnewlen(const char * init, uint64_t size)
{
	t_mstr	*t;
	char	*s;
	uint64_t	l;

	l = 0;
	if (init && init != (char *)NO_ZERO)
	{
		l = _strlen(init);
		if (l > size)
			size = l;
	}
	t = malloc(sizeof(t_mstr) + size + 1);
	s = (char *)t + sizeof(t_mstr);
	if (init)
		mutils_memcpy(s, init, l);
	if (init != (char *)NO_ZERO)
		mutils_memset(s + l, 0, size - l);
	t->len = l;
	t->alloc = size;
	s[size] = 0;
	return (s);
}

char	*mstrnew(const char * init)
{
	t_mstr	*t;
	char	*s;
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

uint32_t	strfromlonglong_helper(char s[21], long long value)
{
	char *p;
	char aux;
	unsigned long long v;
	size_t l;

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
	while (1) {
		*p++ = '0'+ (v % 10);
		v /= 10;
		if (!v)
			break ;
	}
	if (value < 0)
		*p++ = '-';
	l = p-s; *p = '\0'; p--;
	while(s < p) {
		aux = *s; *s = *p; *p = aux; s++; p--;
	}
	return l;
}

char	*mstrfromll(long long number)
{
	char	buffer[21];
	uint32_t	len;

	len = strfromlonglong_helper(buffer, number);
	return (mstrnewlen(buffer, len));
}

void	mstrdestroy(char *s)
{
	t_mstr	*t;

	t = mstr_getptr(s); 
	free(t);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Takes an mstr and concatenates the given string literal

   - The original pointer is freed and can't be used

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrconstcat(char *str1, const char * literal)
{
	char		*s;
	uint64_t	len;
	uint64_t	lencat;

	lencat = _strlen(literal);
	len = _strlen(str1);
	s = mstrnewlen((char *)NO_ZERO, len + lencat);
	mutils_memcpy(s, str1, len);
	mutils_memcpy(s + len, literal, lencat);
	mstrdestroy(str1);
	mstrsetlen(s, len + lencat);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Takes 2 mstr's and concatenates the second after the first.

   - The original pointer is freed and can't be used

   - The second string remains unchanged

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrcat(char *str1, const char *str2)
{
	char		*s;
	uint64_t	len;
	uint64_t	lencat;

	lencat = _strlen(str2);
	len = _strlen(str1);
	s = mstrnewlen((char *)NO_ZERO, len + lencat);
	mutils_memcpy(s, str1, len);
	mutils_memcpy(s + len, str2, lencat);
	mstrdestroy(str1);
	mstrsetlen(s, len + lencat);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Ensures the allocation size is at least 'size' bytes

   - The original pointer is assumed to be freed and can't be used

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrensuresize(char *s, uint64_t size)
{
	t_mstr	*t;

	t = mstr_getptr(s);
	if (t->alloc >= size)
		return (s);
	mstrdestroy(s);
	return (mstrnewlen(s, size));
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a pointer to the first place in the string where 'pattern' was
   found

 * * * * * * * * * * * * * * * * * * * * * * * * */
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
	return (s1[i] - s2[i];
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a pointer to the first place in the string where 'pattern' was
   found

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrsrch(char *s, const char *pattern)
{
	uint64_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Returns a pointer to the first place in the string where the char was
   found

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrchsrch(char *s, const char c)
{
	uint64_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Removes each character in the 'remove' array from the string

   - Updates the lenght of the string

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrtrim(char *s, const char *remove)
{
	uint64_t	i;
	int64_t		l;

	i = 0; l = 0;
	while (s[i])
	{
		if (mstrsearch(remove, 
		i++;
	}
	mstrsetlen(s, len);
	return (s);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Removes each occasion of 'pattern' from the string

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	*mstrtrimpattern(char *s, const char *pattern)
{
	return (s);
}

int main()
{
	char	*str;
	char	*str2;

	str = mstrnew("Hello world!");
	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
	str = mstrconstcat(str, " Goodbye world!");
	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
	str2 = mstrnew(" Well maybe i'll stay.");
	str = mstrcat(str, str2);
	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
	str = mstrensuresize(str, 10);
	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
	str = mstrensuresize(str, 120);
	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
}
