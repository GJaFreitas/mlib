#include "mstr.h"

int32_t	mstrisdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int32_t	mstrischar(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int32_t	mstrisspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == ' ');
}
