#include "checker.h"

int     isStackSorted(t_ch *t)
{
    int     flag;
    int     i;
    
    i = 0;
    flag = 0;
    while (i < t->aSize - 1)
    {
        if (t->stackA[i] > t->stackA[i + 1])
            flag++;
        i++;
    }
    if (flag > 0)
        return (0);
    else
        return (1);
}