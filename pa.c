#include "checker.h"

void	expandStackA(t_ch *t)
{
	int	i;
	
	i = t->aSize - 1;
	while (i >= 0)
	{
		t->stackA[i + 1] = t->stackA[i];
		i--;
	}
	t->stackA[0] = t->stackB[0];
	t->aSize++;
}

void	shrinkStackB(t_ch *t)
{
	int	i;
	
	i =  1;
	while (i <= t->bSize)
	{
		t->stackB[i - 1] = t->stackB[i];
		i++;
	}
	t->bSize--;
}

void	do_pa(t_ch *t)
{
	if (t->bSize == 0)
	{
		return ;
	}
	else
	{
		expandStackA(t);
		shrinkStackB(t);
		t->numOfInstr++;
	}
}