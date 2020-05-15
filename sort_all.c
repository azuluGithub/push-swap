#include "checker.h"

void    pushBackToStackA(t_ch *t)
{
    while (t->bSize > 0)
    {
        do_pa(t);
        ft_putstr("pa\n");
    }
}

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

void    sortAll(t_ch *t)
{
    int     position;
    int     median;
    
    position = 0;
    median = t->aSize / 2;
    while (t->aSize > 3)
    {
        median = t->aSize / 2;
        position = positionOfSmallest(t);
        positionFromMedian(t, position, median);
    }
    sortThreeNums(t);
    pushBackToStackA(t);
}
