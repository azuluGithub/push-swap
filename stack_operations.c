#include "checker.h"

void	initStackAB(t_ch *t)
{
	t->bSize =  0;
	t->aSize =  t->inputSize;
	t->stackA = (int *)malloc(sizeof(int) * t->inputSize);
	t->stackB = (int *)malloc(sizeof(int) * t->inputSize);
	if (!t->stackA || !t->stackB)
	{
		ft_putstr("ERROR INITIALIZIING STACKS!\n");
		freeAB(t);
		exit(1);
	}
}

void	freeAB(t_ch *t)
{
	free(t->stackA);
	free(t->stackB);
}

void	error(t_ch *t)
{
	ft_putstr("Error\n");
	freeAB(t);
	exit (1);
}