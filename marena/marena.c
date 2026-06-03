#include "marena.h"

t_marena	*marenanew(uint64_t size, int32_t flags)
{
	t_marena	*a;

	a = malloc(sizeof(t_marena));
	size = mutils_nextpow2(size);
	a->mem = malloc(size);
	a->alloc = size;
	a->used = 0;
	if (
	return (a);
}

void	marenadestroy(t_marena *a)
{
}

void	*marenapush(t_marena *a, uint64_t bytes)
{
}

void	marenapop(t_marena *a, uint64_t bytes)
{
}

void	marenaclear(t_marena *a)
{
}

