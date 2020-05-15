#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		y;

	i = ft_strlen(s1);
	y = 0;
	while (s2[y] != '\0')
	{
		s1[i + y] = s2[y];
		y++;
	}
	s1[i + y] = '\0';
	return (s1);
}