#include "mfiles.h"
#include "mstr.h"
#include "mutils.h"
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Creates the file struct and reads the whole file into a buffer, the mfile
   struct always uses mstrs for the content.

   - 'oflag' is passed to open() and 'flags' is for controlling the function
   behavior

 * * * * * * * * * * * * * * * * * * * * * * * * */
t_file	*mfilenew(const char *filename, int oflag, int flags)
{
	t_file		*file;
	char		buf[READ_SIZE];
	uint64_t	bytes;
	int32_t	fd;

	fd = open(filename, oflag);
	if (fd == -1)
		return (NULL);
	file = mstralloc(sizeof(t_file));
	file->is_arena = !(is_arena_allocation() == NULL);
	file->fd = fd;
	file->alloc = 0;
	file->content = NULL;
	if (flags & NO_COPY || (oflag & O_CREAT))
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

t_file	*mfilecreate(const char *filename)
{
	t_file	*file;
	int32_t	fd;

	fd = open(filename, O_RDWR | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
		return (NULL);
	file = mstralloc(sizeof(t_file));
	file->fd = fd;
	file->content = mstrnewlen(NULL, DEFAULT_BUFFER_SIZE);
	file->alloc = mstrallocsize(file->content);
	return (file);
}

t_file	*mfilestdin(void)
{
	t_file	*file;

	file = mstralloc(sizeof(t_file));
	file->fd = STDIN_FILENO;
	file->content = mstralloc(DEFAULT_BUFFER_SIZE);
	file->alloc = DEFAULT_BUFFER_SIZE;
	return (file);
}

void	mfilewrite(t_file *file)
{
	write(file->fd, file->content, mstrlen(file->content));
}

void	mfiledestroy(t_file *file)
{
	close(file->fd);
	mstrdestroy(file->content);
	if (!file->is_arena)
		free(file);
}
