#include "checker.h"

void    firstPosition(t_ch *t)
{
    do_ra(t);
    ft_putstr("ra\n");
    if (!isStackSorted(t))
    {
        do_sa(t);
        ft_putstr("sa\n");
    }
}

void    secondPosition(t_ch *t)
{
    do_rra(t);
    ft_putstr("rra\n");
    if (!isStackSorted(t))
    {
        do_sa(t);
        ft_putstr("sa\n");
    }
}

void    thirdPosition(t_ch *t)
{
    do_sa(t);
    ft_putstr("sa\n");
}

void    sortThreeNums(t_ch *t)
{
    int     position;
    
    position = positionOfLargest(t);
    if (position == 0)
        firstPosition(t);
    else if (position == 1)
        secondPosition(t);
    else if (position == 2)
        thirdPosition(t);
}

void    sortTwoNums(t_ch *t)
{
    if (!isStackSorted(t))
    {
        do_sa(t);
        ft_putstr("sa\n");
    }
}
