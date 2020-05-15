#include "checker.h"

int		isDuplicate(t_ch *t)
{
	int		flag;
	int		i;
	int		j;
	
	i = 0;
	flag = 0;
	while (i < t->inputSize)
	{
		j = i + 1;
		while (j < t->inputSize)
		{
			if (ft_atoi(t->input[i]) == ft_atoi(t->input[j]))
				flag += 1;
			j++;
		}
		i++;
    }
	if (flag > 0)
		return (0);
	else
		return (1);
}

int		isNonNumeric(char *s)
{
	int		i;
	
	i = 0;
	while (*s && s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && s[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int		isNumberValid(char *s)
{
	long long		number;
	
	number = ft_atoi(s);
	if (number < INT_MIN || number > INT_MAX)
	{
		return (0);
	}
	return (1);
}

void	pushToStackA(t_ch *t)
{
	int		i;
	
	i = 0;
	while (i < t->inputSize)
	{
		if (isNumberValid(t->input[i]) && isNonNumeric(t->input[i])
		 && isDuplicate(t))
		{
			t->stackA[i] = ft_atoi(t->input[i]);
		}
		else
		{
			error(t);
		}
		i++;
	}
}