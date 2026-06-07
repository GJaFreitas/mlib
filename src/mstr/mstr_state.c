#include "marena.h"
#include "mstr.h"
#include <stdint.h>

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Pass a valid t_marena ptr to set that arena as the current allocator, pass
   -1 to set it to mstralloc() and NULL to get the current arena

 * * * * * * * * * * * * * * * * * * * * * * * * */
static t_marena	*_cur_alloc(t_marena *a)
{
	static t_marena	*cur_arena = NULL;

	if (a == NULL)
		return (cur_arena);
	if (a == (t_marena *)NO_ARENA)
		cur_arena = NULL;
	else
		cur_arena = a;
	return (NULL);
}

void	mstrsetalloc(t_marena *a)
{
	if (a == NULL)
		_cur_alloc((t_marena *)NO_ARENA);
	else
		_cur_alloc(a);
}

void	*mstralloc(uint64_t bytes)
{
	t_marena	*a;

	a = _cur_alloc(NULL);
	if (a == NULL)
		return (malloc(bytes));
	else
		return (marenapush(a, bytes));
}

int32_t	is_arena_allocation(void)
{
	if (_cur_alloc(NULL))
		return (1);
	else
		return (0);
}
