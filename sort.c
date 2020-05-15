#include "checker.h"

void	sort(t_ch *t)
{
	if (t->aSize == 2)
		sortTwoNums(t);
	else if (t->aSize == 3)
		sortThreeNums(t);
	else
		sortAll(t);
}