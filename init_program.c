#include "checker.h"

void	initProgram(int argc, char **argv, t_ch *t)
{
	if (argc == 1)
		exit (0);
	else if (argc == 2)
		countArguments(t, argv[1]);
	else if (argc > 1)
		getArguments(argv, t);
	if (t->inputSize == 0)
	{
		ft_putstr("Error\n");
		exit (0);
	}
	initStackAB(t);
	pushToStackA(t);
}