#include "checker.h"

int 	positionOfSmallest(t_ch *t)
{
	int     i;
    int     position;
    int     smallest;

    i = 0;
    position = 0;
	smallest = t->stackA[0];
    while (i < t->aSize) 
    {
        if (t->stackA[i] < smallest) {
            smallest = t->stackA[i];
            position = i;
        }
        i++;
    }
    return (position);
}

int 	positionOfLargest(t_ch *t)
{
    int     i;
    int     position;
    int     largest;

    i = 0;
    position = 0;
	largest = t->stackA[0];
    while (i < t->aSize) 
    {
        if (t->stackA[i] > largest) {
            largest = t->stackA[i];
            position = i;
        }
        i++;
    }
    return (position);
}