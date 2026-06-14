#include "marena.h"
#include "mutils.h"
#include <stdint.h>

t_marena	*marenanew(uint64_t size, int32_t flags)
{
	t_marena	*a;

	a = malloc(sizeof(t_marena));
	size = mutils_nextpow2(size);
	a->mem = malloc(size);
	a->alloc = size;
	a->used = 0;
	a->next = NULL;
	a->prev = NULL;
	a->cur = a;
	if (flags != NO_ZERO)
		mutils_memset(a->mem, 0, size);
	return (a);
}

void	marenadestroy(t_marena *a)
{
	if (a->next)
	{
		marenadestroy(a->next);
	}
	free(a->mem);
	free(a);
}

void	*marenapush(t_marena *_a, uint64_t bytes)
{
	void		*push;
	uint64_t	alloc;
	t_marena	*a;

	a = _a->cur;
	alloc = a->alloc;
	if (a->used + bytes < alloc)
	{
		a->used += bytes;
		push = a->mem + a->used;
	}
	else
	{
		while (alloc <= bytes)
			alloc *= 2;
		if (!a->next)
			a->next = marenanew(alloc, ZEROED);
		_a->cur = a->next;
		a->next->prev = a;
		push = marenapush(a->next, bytes);
	}
	return (push);
}

void	marenapop(t_marena *_a, uint64_t bytes)
{
	t_marena	*a;

	a = _a->cur;
	if (bytes >= a->used)
	{
		a->used = 0;
		_a->cur = a->prev;
	}
	else
	{
		a->used -= bytes;
	}
}

void	marenaclear(t_marena *passed)
{
	t_marena	*a;

	mutils_memset(passed->mem, 0, passed->used);
	passed->used = 0;
	passed->cur = passed;
	if (passed->next)
	{
		a = passed->next;
		mutils_memset(a->mem, 0, a->used);
		marenadestroy(a->next);
		a->next = NULL;
		a->used = 0;
	}
}

// int	main(void)
// {
// 	t_marena *arena = marenanew(4, ZEROED);
// 	t_marena *loop = arena;
//
// 	void	*v1 = marenapush(arena, 4);
// 	void	*v2 = marenapush(arena, 8);
// 	void	*v3 = marenapush(arena, 12);
// 	void	*v4 = marenapush(arena, 16);
// 	printf("arena lenghts:\n");
// 	loop = arena;
// 	while (loop)
// 	{
// 		printf("Len: %ld\n", loop->alloc);
// 		loop = loop->next;
// 	}
// 	loop = arena;
// 	printf("arena use:\n");
// 	while (loop)
// 	{
// 		printf("Used: %ld\n", loop->used);
// 		loop = loop->next;
// 	}
// 	marenapop(arena, 7);
// 	loop = arena;
// 	printf("arena use:\n");
// 	while (loop)
// 	{
// 		printf("Used: %ld\n", loop->used);
// 		loop = loop->next;
// 	}
// 	marenapop(arena, 16);
// 	loop = arena;
// 	printf("arena use:\n");
// 	while (loop)
// 	{
// 		printf("Used: %ld\n", loop->used);
// 		loop = loop->next;
// 	}
// 	marenapop(arena, 16);
// 	loop = arena;
// 	printf("arena use:\n");
// 	while (loop)
// 	{
// 		printf("Used: %ld\n", loop->used);
// 		loop = loop->next;
// 	}
// 	marenaclear(arena);
// 	loop = arena;
// 	printf("arena use:\n");
// 	while (loop)
// 	{
// 		printf("Used: %ld\n", loop->used);
// 		loop = loop->next;
// 	}
// }
