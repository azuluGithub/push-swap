#include "checker.h"

int		checkSizeOfA(t_ch *t)
{
	int		left_over;

	if (t->aSize > 200)
		left_over = 50;
	else
		left_over = 2;
	return (left_over);
}