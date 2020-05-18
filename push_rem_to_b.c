#include "checker.h"

void    positionFromMedian(t_ch *t, int position, int median)
{
    if (position == 0)
    {
        do_pb(t);
        ft_putstr("pb\n");
    }
    else if (position <= median)
    {
        do_ra(t);
        ft_putstr("ra\n");
    }
    else if (position > median)
    {
        do_rra(t);
        ft_putstr("rra\n");
    }
}

void	pushRemainingToStackB(t_ch *t)
{
    int         median;
    int         position;

	position = 0;
	median = t->aSize / 2;
	while (t->aSize > 2)
    {
        median = t->aSize / 2;
        position = positionOfSmallest(t);
        positionFromMedian(t, position, median);
    }
}