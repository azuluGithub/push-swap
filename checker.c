#include "checker.h"

int		main(int argc, char **argv)
{
	t_ch  t;
	
	initStruct(&t);
	initProgram(argc, argv, &t);
	if (!isStackSorted(&t))
	{
		while (get_next_line(0, &(t.line)))
		{
			if (!t.line)
				break ;
			apply(&t, t.line);
		}
	}
	if (isStackSorted(&t) && t.bSize == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	freeAB(&t);
	return (0);
}