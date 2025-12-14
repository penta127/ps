#include "push_swap.h"

void	sa_ps_ss(t_stacks *stacks)
{
	if (stacks->A.size <= 1)
		return ;
	else if (stacks->A.size == 2)
	{
		sa_ps_size_two(&stacks->A);
	}
	else if (stacks->A.size >= 3)
	{
		sa_ps_size_over_two(&stacks->A);
	}
}

void	sb_ps_ss(t_stacks *stacks)
{
	if (stacks->B.size <= 1)
		return ;
	else if (stacks->B.size == 2)
	{
		sb_ps_size_two(&stacks->B);
	}
	else if (stacks->B.size >= 3)
	{
		sb_ps_size_over_two(&stacks->B);
	}
}

void	ss_ps(t_stacks *stacks)
{
	sa_ps_ss(stacks);
	sb_ps_ss(stacks);
	write(1, "ss\n", 3);
}
