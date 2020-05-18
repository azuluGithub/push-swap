#include "checker.h"

void    sortAll(t_ch *t)
{
	int		    size_;
    
	size_ = checkSizeOfA(t);
    pushTwoElementsToB(t);
	pushToStackB(t, size_);
    pushRemainingToStackB(t);
    pushBackToStackA(t);
}
