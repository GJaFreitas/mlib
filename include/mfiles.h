#pragma once

/*
 * The objective is to use files like the are strings
 */

#include "mstr.h"
#include <stdint.h>

typedef struct s_file
{
	uint32_t	fd;
	uint64_t	alloc;
	char		*content;
}				t_file;

#define READ_SIZE 4096
#define NO_READ -1
