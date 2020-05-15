#ifndef CHECKER_H
# define CHECKER_H
# include "libft/libft.h"

typedef struct s_ch
{
	int			aSize;
	int			bSize;
	char		*line;
	char		**input;
	int			*stackA;
    int 		*stackB;
	int			inputSize;
	int			numOfInstr;
}               t_ch;

void    sort(t_ch *t);
void	error(t_ch *t);
void 	do_sa(t_ch *t);
void 	do_sb(t_ch *t);
void 	do_ss(t_ch *t);
void 	do_pa(t_ch *t);
void 	do_pb(t_ch *t);
void 	do_ra(t_ch *t);
void 	do_rb(t_ch *t);
void 	do_rr(t_ch *t);
void 	do_rra(t_ch *t);
void 	do_rrb(t_ch *t);
void 	do_rrr(t_ch *t);
void	freeAB(t_ch *t);
void	sortAll(t_ch *t);
void	initStruct(t_ch *t);
void	sortTwoNums(t_ch *t);
void	initStackAB(t_ch *t);
void	pushToStackA(t_ch *t);
int		isStackSorted(t_ch *t);
void	sortThreeNums(t_ch *t);
void	apply(t_ch *t, char *line);
int 	positionOfLargest(t_ch *t);
int 	positionOfSmallest(t_ch *t);
void	countArguments(t_ch *t, char *s);
void	getArguments(char **argv, t_ch *t);
void    initProgram(int argc, char **argv, t_ch *t);

#endif