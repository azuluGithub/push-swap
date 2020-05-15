#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b2;

	b2 = (unsigned char *)b;
	while (len > 0)
	{
		b2[len - 1] = c;
		len--;
	}
	return (b2);
}
