#pragma once

#include "mutils.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_marena
{
	uint64_t		alloc;
	uint64_t		used;
	void			*mem;
	struct s_marena	*next;
	struct s_marena	*prev;
	struct s_marena	*cur;
}					t_marena;

#define NO_ZERO -1
#define ZEROED 0

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Lib functions

 * * * * * * * * * * * * * * * * * * * * * * * * */

t_marena			*marenanew(uint64_t size, int32_t flags);
void				marenadestroy(t_marena *a);
void				*marenapush(t_marena *a, uint64_t bytes);
void				marenapop(t_marena *a, uint64_t bytes);
void				marenaclear(t_marena *a);

uint64_t			marena_totalused(t_marena *a);
