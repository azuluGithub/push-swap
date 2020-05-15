#include "checker.h"

void	swapTop2(int *stack)
{
	int		temp;
	
	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	stackLessEqual1(int values)
{
	if (values <= 1)
		return ;
}

void	do_sa(t_ch *t)
{
	stackLessEqual1(t->aSize);
	swapTop2(t->stackA);
	t->numOfInstr++;
}

void 	do_sb(t_ch *t)
{
	stackLessEqual1(t->bSize);
	swapTop2(t->stackB);
	t->numOfInstr++;
}

void	do_ss(t_ch *t)
{
	do_sa(t);
	do_sb(t);
	t->numOfInstr++;
}
