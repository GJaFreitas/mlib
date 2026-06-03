#include "mutils.h"

void	*mutils_memcpy(void *dst, const void *src, uint64_t n)
{
	uint64_t	i;
	uint8_t		*cdst;
	const uint8_t		*csrc = src;

	i = 0;
	cdst = dst;
	if (!dst || !src || !n)
		return (dst);
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	cdst[i] = 0;
	return (dst);
}

void	*mutils_memset(void * ptr, uint8_t byte, uint64_t len)
{
	uint8_t	*cast;
	uint64_t	i;

	cast = ptr;
	i = 0;
	while (i < len)
	{
		cast[i] = byte;
		i++;
	}
	return (ptr);
}

int64_t	mutils_nextpow2(int64_t n)
{
	 // compute the next highest power of 2 of 32-bit v

	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;
	n++;
	return (n);
}
