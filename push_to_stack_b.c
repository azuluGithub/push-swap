#include "checker.h"

int		chooseInstrA(t_ch *t, int position, char **aInstruction)
{	
	int     median;

    median = t->aSize / 2;
	if (position > median)
	{
		*aInstruction = ft_strcpy(*aInstruction, "rra");
		if (t->aSize > 2)
        {
			position = t->aSize - position;
        }
	}
	else if (position <= median)
    {
		*aInstruction = ft_strcpy(*aInstruction, "ra");
    }
	return (position);
}

int		chooseInstrB(t_ch *t, int position, char **bInstruction)
{
    int     median;

    median = t->bSize / 2;
	if (position > median)
	{
		*bInstruction = ft_strcpy(*bInstruction, "rrb");
		if (t->bSize > 2)
        {
			position = t->bSize - position;
        }
	}
	else if (position <= median)
    {
		*bInstruction = ft_strcpy(*bInstruction, "rb");
    }
	return (position);
}

int     findPosBtwnElementsB(t_ch *t, int num)
{
    int     i;
    int     position;

    i = 0;
    position = 0;
    while (i < t->bSize)
	{
		if (num < t->stackB[i] &&
			((i + 1 < t->bSize && num > t->stackB[i + 1]) || 
			(i + 1 == t->bSize && num > t->stackB[0])))
		{
			position = i + 1;
			break ;
		}
		i++;
	}
    return (position);
}

int		findPositionInB(t_ch *t, int i)
{
	int		position;

	position = 0;
	if ((t->stackA[i] < t->stackB[1]) &&
		(t->stackA[i] > t->stackB[0]) && t->bSize == 2)
		position = 0;
	else if (t->stackA[i] > t->stackB[1] && 
			(t->stackA[i] < t->stackB[0]) && t->bSize == 2)
		position = 1;
	else if (t->stackA[i] < t->stackB[positionOfSmallestB(t)] || 
			t->stackA[i] > t->stackB[positionOfLargestB(t)])
		position = positionOfLargestB(t);
	else
		position = findPosBtwnElementsB(t, t->stackA[i]);
	return (position);
}


int		findCommonRotations(t_instr *s)
{
	int		rot;

	rot = 0;
	if ((ft_strequ(s->aInstruction, "rra") &&
		(ft_strequ(s->bInstruction , "rrb"))) ||
		(ft_strequ(s->aInstruction, "ra") &&
		(ft_strequ(s->bInstruction , "rb"))))
	{
		if (s->numInstrA > s->numInstrB)
			rot = s->numInstrB;
		else
			rot = s->numInstrA;
		if (rot)
		{
			s->commonRotations = ft_strcpy(s->commonRotations, s->aInstruction);
			s->commonRotations[ft_strlen(s->commonRotations) - 1] = 'r';
			s->numInstrB = s->numInstrB - rot;
			s->numInstrA = s->numInstrA - rot;
		}
	}
	return (rot);
}

t_instr		*initStructInstr(t_ch *t, int i, t_instr *s)
{
	int		position;

	s->aInstruction = ft_strnew(3);
	s->numInstrA = chooseInstrA(t, i, &(s->aInstruction));
	s->bInstruction = ft_strnew(3);
	position = findPositionInB(t, i);
	s->numInstrB = chooseInstrB(t, position, &(s->bInstruction));
	s->commonRotations = ft_strnew(3);
	s->numOfCommonRotations = findCommonRotations(s);
	s->totalInstructions = s->numInstrA + s->numInstrB + s->numOfCommonRotations + 1;
	return (s);
}

t_instr			*findSmallestNumOfInstr(t_ch *t)
{
	int	            i;
	t_instr			*s;
	t_instr			*temp_struct;

	i = 0;
	while (i < t->aSize)
	{
		s = (t_instr *)malloc(sizeof(t_instr));
		s = initStructInstr(t, i, s);
		if (i == 0)
			temp_struct = s;
		else if (temp_struct->totalInstructions > s->totalInstructions)
		{
			free_instr(temp_struct);
			temp_struct = s;
		}
		else
			free_instr(s);
		i++;
	}
	return (temp_struct);
}

void		perfomCommonRotations(t_instr *s, t_ch *t)
{
	while (s->numOfCommonRotations)
	{
		if (ft_strequ(s->commonRotations, "rr"))
        {
			do_rr(t);
            ft_putstr("rr\n");
        }
		else if (ft_strequ(s->commonRotations, "rrr"))
        {
			do_rrr(t);
            ft_putstr("rrr\n");
        }
		s->numOfCommonRotations--;
	}
}

void	performRotationsA(t_instr *s, t_ch *t)
{
	while (s->numInstrA > 0)
	{
		if (ft_strequ(s->aInstruction, "ra"))
        {
			do_ra(t);
            ft_putstr("ra\n");
        }
		else if (ft_strequ(s->aInstruction, "rra"))
        {
			do_rra(t);
            ft_putstr("rra\n");
        }
		s->numInstrA--;
	}
}

void	performRotationsB(t_instr *s, t_ch *t)
{
	while (s->numInstrB > 0)
	{
		if (ft_strequ(s->bInstruction, "rb"))
        {
			do_rb(t);
            ft_putstr("rb\n");
        }
		else if (ft_strequ(s->bInstruction, "rrb"))
        {
			do_rrb(t);
            ft_putstr("rrb\n");
        }
		s->numInstrB--;
	}
}

void	pushToStackB(t_ch *t, int left_over)
{
    t_instr     *s;

	while (t->aSize > left_over)
	{
		s = findSmallestNumOfInstr(t);
		perfomCommonRotations(s, t);
		performRotationsA(s, t);
		performRotationsB(s, t);
		do_pb(t);
        ft_putstr("pb\n");
		free_instr(s);
	}
}