#include "checker.h"

void	pushTwoElementsToB(t_ch *t)
{
	while (t->bSize < 2)
    {
		do_pb(t);
        ft_putstr("pb\n");
    }
}