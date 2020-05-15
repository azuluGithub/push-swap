#include "checker.h"

void	shiftABy1down(t_ch *t)
{
	int		i;
	int		temp;
	
	i = t->aSize - 2;
	temp = t->stackA[t->aSize - 1];
	while (i >= 0)
	{
		t->stackA[i + 1] = t->stackA[i];
		i--;
	}
	t->stackA[0] = temp;
}

void	do_rra(t_ch *t)
{
	if (t->aSize == 0)
		return ;
	else
	{
		shiftABy1down(t);
		t->numOfInstr++;
	}
}

void	shiftBBy1down(t_ch *t)
{
	int		i;
	int		temp;
	
	i = t->bSize - 2;
	temp = t->stackB[t->bSize - 1];
	while (i >= 0)
	{
		t->stackB[i + 1] = t->stackB[i];
		i--;
	}
	t->stackB[0] = temp;
}

void	do_rrb(t_ch *t)
{
	if (t->bSize == 0)
		return ;
	else
	{
		shiftBBy1down(t);
		t->numOfInstr++;
	}
}

void	do_rrr(t_ch *t)
{
	do_rra(t);
	do_rrb(t);
	t->numOfInstr++;
}
