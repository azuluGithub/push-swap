#include "checker.h"

int     main(int argc, char **argv)
{
    t_ch    t;
    
    initStruct(&t);
    initProgram(argc, argv, &t);
    if (isStackSorted(&t) && t.bSize == 0)
        return (0);
    sort(&t);
    freeAB(&t);
    return (0);
}