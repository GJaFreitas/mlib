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

t_file	*mfilenew(const char *filename, int oflag, int flags);
t_file	*mfilestdin(void);
void	mfilewrite(t_file *file);
void	mfiledestroy(t_file *file);
char	*mfilereadwholefile(int fd);
void	mfileread(t_file *mf);
t_file	*mfilecreate(const char *filename);

#define READ_SIZE 4096
#define NO_COPY -1
#define DEFAULT_BUFFER_SIZE 1024
