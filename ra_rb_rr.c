#include "checker.h"

void	shiftABy1up(t_ch *t)
{
	int		i;
	int		temp;
	
	i =  1;
	temp = t->stackA[0];
	while (i <= t->aSize - 1)
	{
		t->stackA[i - 1] = t->stackA[i];
		i++;
	}
	t->stackA[i - 1] = temp;
}

void	do_ra(t_ch *t)
{
	if (t->aSize == 0)
		return ;
	else
	{
		shiftABy1up(t);
		t->numOfInstr++;
	}
}

void	shiftBBy1up(t_ch *t)
{
	int		i;
	int		temp;
	
	i =  1;
	temp = t->stackB[0];
	while (i <= t->bSize - 1)
	{
		t->stackB[i - 1] = t->stackB[i];
		i++;
	}
	t->stackB[i - 1] = temp;
}

void	do_rb(t_ch *t)
{
	if (t->bSize == 0)
		return ;
	else
	{
		shiftBBy1up(t);
		t->numOfInstr++;
	}
}

void	do_rr(t_ch *t)
{
	do_ra(t);
	do_rb(t);
	t->numOfInstr++;
}
