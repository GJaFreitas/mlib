#include "marg.h"
#include "mstr.h"

static char	*argument_options(int argc, char *argv[])
{
	static char	**av;
	static int32_t	ac;
	static int32_t	cur;

	if (av == NULL && argv != NULL)
	{
		av = argv;
		ac = argc;
	}
	if (!argv && !av)
		return (NULL);
	if (argc == 0 && argv == NULL && cur < ac)
	{
		while (cur < ac && av[cur][0] != '-')
			cur++;
		if (cur == ac)
		{
			av = NULL;
			return (NULL);
		}
		return (av[cur++]);
	}
	return (NULL);
}

/* * * * * * * * * * * * * * * * * * * * * * * * *

   - Parses argv and return every character in 'options' that appears, if a
   character that isn't in the 'options' string it returns that character but
   negative. When the arguments have all been processed it return 0;

 * * * * * * * * * * * * * * * * * * * * * * * * */
char	mgetarg(int argc, char *argv[], const char *options)
{
	static int32_t	init = 0;
	char		*cur;

	if (!init)
	{
		init = 1;
		argument_options(argc, argv);
	}
	cur = argument_options(0, NULL);
	if (cur == NULL)
		return (0);
	cur = mstrskipch(cur, "-");
	if (mstrch(options, *cur))
		return (*cur);
	else
		return (-(*cur));
}
