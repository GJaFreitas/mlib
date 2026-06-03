#include "mfiles.h"
#include "mstr.h"
#include "mutils.h"
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Creates the file struct and reads the whole file into a buffer

   - 'oflag' is passed to open() and 'flags' is for controlling the function
   behavior

 * * * * * * * * * * * * * * * * * * * * * * * * */
t_file	*mfilenew(const char *filename, int oflag, int flags)
{
	t_file		*file;
	char		buf[READ_SIZE];
	uint64_t	bytes;
	uint32_t	fd;

	fd = open(filename, oflag);
	if (fd == -1)
		return (NULL);
	file->fd = fd;
	file->alloc = 0;
	file->content = NULL;
	if (flags & NO_READ)
		return (file);
	mutils_memset(buf, 0, READ_SIZE);
	bytes = read(fd, buf, READ_SIZE);
	while (bytes)
	{
		file->content = mstrconstcat(file->content, buf);
		bytes = read(fd, buf, READ_SIZE);
	}
	file->alloc = mstrallocsize(file->content);
	return (file);
}

void	mfilewrite(t_file *file)
{
	write(file->fd, file->content, file->alloc);
}

void	mfiledestroy(t_file *file)
{
	mstrdestroy(file->content);
	free(file);
}
