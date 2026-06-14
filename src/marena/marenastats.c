#include "marena.h"
#include <stdint.h>

uint64_t	marena_totalused(t_marena *a)
{
	uint64_t	total;
	t_marena	*cur;

	total = 0;
	cur = a;
	while (cur)
	{
		total += cur->used;
		cur = cur->next;
	}
	return (total);
}
