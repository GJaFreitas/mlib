#pragma once

#include "mutils.h"
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define NO_ZERO -1
#define BUFFER_SIZE 1024
#define WHITESPACE "\n\t\r\v "

typedef struct s_mstr
{
	uint64_t	len;
	uint64_t	alloc;
}				t_mstr;

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Lib functions

 * * * * * * * * * * * * * * * * * * * * * * * * */

void	mstrtoupper(char *s);
char	*mstrskipch(const char *s, const char *skip);
int64_t	mstratoi(const char *s);
char	*mstrsubstr(const char *s, uint64_t start, uint64_t end);
void	mstrtolower(char *s);
char	*mstrtrim(char *s, const char *remove);
char	*mstrtrimpattern(char *s, const char *pattern);
char	**mstrtokenize(const char *s, const char *separators);
char	**mstrtokenizetrim(const char *s, const char *separators);
char	*mstrjoinall(char *s1, ...);
char	*mstrjoinallsep(char sep, char *s1, ...);
char	*mstrensuresize(char *s, uint64_t size);
int32_t	mstrncmp(const char *s1, const char *s2, uint64_t n);
int32_t	mstrcmp(const char *s1, const char *s2);
char	*mstrsrch(char *s, const char *pattern);
char	*mstrch(const char *s, const char c);
char	*mstrfromll(long long number);
void	mstrdestroy(char *s);
char	*mstrconstcat(char *str1, const char *literal);
char	*mstrcat(char *str1, char *str2);
char	*mstrnew(const char *init);
uint64_t	mstrallocsize(char *s);
void	mstrsetlen(char *s, uint64_t len);
uint64_t	mstrupdatelen(char *s);
uint64_t	mstrlen(char *s);
t_mstr	*mstr_getptr(const char *s);
char	*mstrnewlen(const char *init, uint64_t size);
static inline char	*choose_buffer(char *static_buf, char *fmt);
char	*mstrcatvprintf(char *s, const char *fmt, va_list ap);
char	*mstrcatprintf(char *s, const char *fmt, ...);
void	mstrsubstitute(char *s, char *pattern, char *substitution);

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Utilities

 * * * * * * * * * * * * * * * * * * * * * * * * */
uint64_t		_strlen(const char *s);
int32_t			mstrisdigit(char c);
int32_t			mstrischar(char c);
int32_t			mstrisspace(char c);
