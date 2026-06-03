#pragma once

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h>

#include "mutils.h"

#define NO_ZERO		-1
#define BUFFER_SIZE		1024
#define WHITESPACE	"\n\t\r\v "

typedef struct s_mstr
{
	uint64_t	len;
	uint64_t	alloc;
}	t_mstr;

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Lib functions

 * * * * * * * * * * * * * * * * * * * * * * * * */

t_mstr	*mstr_getptr(const char *s);
char	*mstrnewlen(const char * init, uint64_t initlen);
char	*mstrnew(const char * init);
uint64_t	mstrallocsize(char *s);
void	mstrsetlen(char *s, uint64_t len);
uint64_t	mstrupdatelen(char *s);
uint64_t	mstrlen(char *s);
char	*mstrfromll(long long number);
void	mstrdestroy(char *s);
char	*mstrconstcat(char *str1, const char * literal);
char	*mstrcat(char *str1, const char *str2);
char	*mstrensuresize(char *s, uint64_t size);

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Utilities

 * * * * * * * * * * * * * * * * * * * * * * * * */
uint64_t	_strlen(const char * s);
