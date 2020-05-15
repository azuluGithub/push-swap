#include "checker.h"

void	countArguments(t_ch *t, char *s)
{
	int		count;
	
	count = 0;
	t->input = ft_strsplit(s, ' ');
	while (t->input[count])
		count++;
	t->inputSize = count;
}

char	*putSpace(char const *s1, char const *s2)
{
	char	*new_str;
	char	*str_j;

	str_j = ft_strjoin(s1, s2);
	new_str = ft_strjoin(str_j, " ");
	return (new_str);
}

void	getArguments(char **argv, t_ch *t)
{
	char	*buff;
	int		i;
	
	i = 1;
	buff = "\0";
	while (argv && argv[i])
	{
		buff = putSpace(buff, argv[i]);
		i++;
	}
	t->input = ft_strsplit(buff, ' ');
	t->inputSize = i - 1;
}