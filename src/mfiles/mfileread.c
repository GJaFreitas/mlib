#include "mfiles.h"
#include "mstr.h"
#include "mutils.h"
#include <stdint.h>
#include <unistd.h>

char	*mfilereadwholefile(int fd)
{
	char	buf[READ_SIZE];
	int32_t	bytes;
	char	*content;

	bytes = read(fd, buf, READ_SIZE);
	content = NULL;
	while (bytes == READ_SIZE)
	{
		content = mstrconstcat(content, buf);
		bytes = read(fd, buf, bytes);
	}
	content = mstrconstcat(content, buf);
	return (content);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Used when the file it points to is being written to and you want to get
   that text, the example is stdin

 * * * * * * * * * * * * * * * * * * * * * * * * */
void	mfileread(t_file *mf)
{
	char	buf[READ_SIZE];
	int64_t	bytes;

	bytes = read(mf->fd, buf, READ_SIZE);
	if (bytes >= (int64_t)mstrallocsize(mf->content))
	{
		if (mf->content)
			mstrdestroy(mf->content);
		mf->content = mstrcat(mstrnew(buf), mfilereadwholefile(mf->fd));
		mf->alloc = mstrallocsize(mf->content);
	}
	else
		mutils_memcpy(mf->content, buf, bytes);
}
