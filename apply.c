#include "checker.h"

void	apply(t_ch *t, char *line)
{
	if (ft_strequ(line, "sa"))
		do_sa(t);
	else if (ft_strequ(line, "sb"))
		do_sb(t);
	else if (ft_strequ(line, "ss"))
		do_ss(t);
	else if (ft_strequ(line, "pa"))
		do_pa(t);
	else if (ft_strequ(line, "pb"))
		do_pb(t);
	else if (ft_strequ(line, "ra"))
		do_ra(t);
	else if (ft_strequ(line, "rb"))
		do_rb(t);
	else if (ft_strequ(line, "rr"))
		do_rr(t);
	else if (ft_strequ(line, "rra"))
		do_rra(t);
	else if (ft_strequ(line, "rrb"))
		do_rrb(t);
	else if (ft_strequ(line, "rrr"))
		do_rrr(t);
	else
		error(t);
}