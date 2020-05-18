#include "checker.h"

int		chooseInstr(t_ch *t, int position)
{
    int     median;

    median = t->aSize / 2;
	if (position > median)
	{
		t->rotationType = ft_strcpy(t->rotationType, "rra");
		if (t->aSize > 2)
        {
			position = t->aSize - position;
        }
	}
	else if (position <= median)
    {
		t->rotationType = ft_strcpy(t->rotationType, "ra");
    }
	return (position);
}

int     findPosBtwnElementsA(t_ch *t)
{
    int     i;
    int     position;

    i = 0;
    position = 0;
    while (i < t->aSize)
    {
        if (t->stackB[0] > t->stackA[i] && 
            ((t->stackB[0] < t->stackA[i + 1] && i + 1 < t->aSize) || 
            (t->stackB[0] < t->stackA[0] && i + 1 == t->aSize)))
        {
            position = i + 1;
            break ;
        }
        i++;
    }
    return (position);
}

int     findPositionInA(t_ch *t)
{
    int     position;

    position = 0;
    if ((t->stackB[0] < t->stackA[0]) &&
        (t->stackB[0] > t->stackA[1]) && t->aSize == 2)
        position = 0;
    else if ((t->stackB[0] > t->stackA[0]) && 
            (t->stackB[0] < t->stackA[1]) && t->aSize == 2)
        position = 1;
    else if (t->stackB[0] < t->stackA[positionOfSmallest(t)] ||
            t->stackB[0] > t->stackA[positionOfLargest(t)])
		position = positionOfSmallest(t);
    else
        position = findPosBtwnElementsA(t);
    return (position);
}

void	pushSmallestToTop(t_ch *t)
{
	int     smallest;
    int     median;

    median = t->aSize / 2;
	smallest = positionOfSmallest(t);
	if (smallest <= median)
    {
		while (smallest--)
        {
			do_ra(t);
            ft_putstr("ra\n");
        }
    }
	else
    {
		while ((t->aSize - smallest) > 0)
		{
			do_rra(t);
            ft_putstr("rra\n");
			smallest++;
		}
    }
}

void    performInstr(int position, t_ch *t)
{
    int     numOfInstr;

    numOfInstr = chooseInstr(t, position);
    while (numOfInstr > 0)
	{
		if (ft_strequ(t->rotationType, "rra"))
        {
			do_rra(t);
            ft_putstr("rra\n");
        }
		else
        {
			do_ra(t);
            ft_putstr("ra\n");
        }
		numOfInstr--;
	}
}

void    pushBackToStackA(t_ch *t)
{
    int     position;

    position = 0;
    while (t->bSize > 0)
    {
        position = findPositionInA(t);
        performInstr(position, t);
		do_pa(t);
        ft_putstr("pa\n");
    }
    pushSmallestToTop(t);
}