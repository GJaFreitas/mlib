#include "marg.h"
#include "mfiles.h"
#include "mstr.h"
#include <fcntl.h>

static int32_t capitalize = 0;

int main(int argc, char *argv[])
{
	char	this;
	while ((this = mgetarg(argc, argv, "c")) != 0)
	{
		switch (this)
		{
			case 'c': capitalize = 1;
		}
	}

	printf("Args parsed\n");

	t_file	*stdin_file = mfilestdin();
	t_file	*file = mfilecreate("test_file.txt");

	if (!file)
		return (printf("NULL\n"));

	while (1)
	{
		mfileread(stdin_file);
		if (!mstrncmp(stdin_file->content, "exit", 4))
			break ;
		if (capitalize)
			mstrtoupper(stdin_file->content);
		file->content = mstrconstcat(file->content, stdin_file->content);
	}
	mfilewrite(file);

	mfiledestroy(stdin_file);
	mfiledestroy(file);

	return (0);
}
