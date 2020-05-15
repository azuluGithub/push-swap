#include "checker.h"

void	expandStackB(t_ch *t)
{
	int	i;
	
	i = t->bSize - 1;
	while (i >= 0)
	{
		t->stackB[i + 1] = t->stackB[i];
		i--;
	}
	t->stackB[0] = t->stackA[0];
	t->bSize++;
}

void	shrinkStackA(t_ch *t)
{
	int	i;
	
	i =  1;
	while (i <= t->aSize)
	{
		t->stackA[i - 1] = t->stackA[i];
		i++;
	}
	t->aSize--;
}

void	do_pb(t_ch *t)
{
	if (t->aSize == 0)
	{
		return ;
	}
	else
	{
		expandStackB(t);
		shrinkStackA(t);
		t->numOfInstr++;
	}
}