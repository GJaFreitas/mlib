#include "mstr.h"

t_mstr	*mstr_getptr(const char *s)
{
	t_mstr	*t;

	t = (t_mstr *)(s - sizeof(t_mstr));
	return (t);
}

uint64_t	_strlen(const char *s)
{
	uint64_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*mstrnewlen(const char *init, uint64_t size)
{
	t_mstr		*t;
	char		*s;
	uint64_t	l;

	l = 0;
	if (init && init != (char *)(const char *)NO_ZERO)
	{
		l = _strlen(init);
		if (l > size)
			size = l;
	}
	t = mstralloc(sizeof(t_mstr) + size + 1);
	s = (char *)t + sizeof(t_mstr);
	if (init)
		mutils_memcpy(s, init, l);
	if (init != (char *)(const char *)NO_ZERO)
		mutils_memset(s + l, 0, size - l);
	t->len = l;
	t->alloc = size;
	if (is_arena_allocation())
		t->alloc |= ALLOCSIZE_MASK;
	s[size] = 0;
	return (s);
}

int	main(void)
{
	char	*str;
	char	*str2;
	char	*str3;

// 	str = mstrnew("Hello world!");
// 	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
// 	str = mstrconstcat(str, " Goodbye world!");
// 	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
// 	str2 = mstrnew(" Well maybe i'll stay.");
// 	str = mstrcat(str, str2);
// 	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
// 	str = mstrensuresize(str, 10);
// 	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));
// 	str = mstrensuresize(str, 120);
// 	printf("String: %s mstr size: %ld\n", str, mstrallocsize(str));

	// str = mstrnew("Hello world");
	// str2 = mstrnew("Hello world");
	// str3 = mstrnew("I am (here) hello th{}ere");
	// printf("string: %s\n", str);
	// printf("strcmp: %d\n", mstrcmp(str, str2));
	// printf("strncmp: %d\n", mstrncmp(str, str2, 4));
	// printf("mstrsrch: %s\n", mstrsrch(str, "world"));
	// printf("mstrch: %s\n", mstrch(str, 'r'));
	// printf("mstrtrim: %s\n", mstrtrim(str, WHITESPACE));
	// printf("mstrtrim before: %s\n", str3);
	// mstrtrim(str3, "{}[]()");
	// printf("mstrtrim after: %s\n", str3);
	// mstrtrimpattern(str3, "hello ");
	// printf("After mstrtrimpattern: %s\n", str3);

	// char	*strtok = mstrnew("A string to make tokens\n");
	// char	*substr = mstrsubstr(strtok, 0, 10);
	// printf("Original: %s\n", strtok);
	// printf("substr: %s\n", substr);
	// char	**tokens = mstrtokenizetrim(strtok, " ");
	// int i = 0;
	// while (tokens[i])
	// {
	// 	printf("Tokens: %s\n", tokens[i]);
	// 	i++;
	// }
	// tokens = mstrtokenize("", "");
	// char	*str4 = mstrjoinall("Hello", " world", "idk", " this is cool?",
	// 			NULL);
	// printf("mstrjoinall: %s\n", str4);
	//
	// char	*s = mstrnew("A string to test stuff");
	// char	*sub = mstrnew("sub");
	// char	*pattern = mstrnew("to");
	// printf("String: %s\n", s);
	// mstrsubstitute(s, pattern, sub);
	// printf("After sub: %s\n", s);
}
