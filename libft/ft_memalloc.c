#include "libft.h"

void	*ft_memalloc(size_t x)
{
	char	*s;

	s = (char *)malloc(x);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, (int)x);
	return ((void *)s);
}
