#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c2;

	c2 = (char)c;
	i = 0;
	while (s[i] != '\0' && c2 != s[i])
		i++;
	if (s[i] != c2)
		return (0);
	else
		return ((char *)s + i);
}