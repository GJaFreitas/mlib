#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef struct s_marena
{
	uint64_t	alloc;
	uint64_t	used;
	void		*mem;
}	t_marena;

#define NO_ZERO	-1

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Lib functions

 * * * * * * * * * * * * * * * * * * * * * * * * */

t_marena	*marenanew(uint64_t size);
void	marenadestroy(t_marena *a);
void	*marenapush(t_marena *a, uint64_t bytes);
void	marenapop(t_marena *a, uint64_t bytes);
void	marenaclear(t_marena *a);

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Utils

 * * * * * * * * * * * * * * * * * * * * * * * * */

