#include "push_swap.h"

void	rra_ps_rrr(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*now_under;
	t_node	*new_under;

	if (stacks->A.size <= 1)
		return ;
	now_top = stacks->A.top;
	now_under = stacks->A.under;
	new_under = stacks->A.under->before;
	stacks->A.under = new_under;
	stacks->A.under->next = NULL;
	now_under->next = now_top;
	now_under->before = NULL;
	now_top->before = now_under;
	stacks->A.top = now_under;
	stacks->A.under = new_under;
}

void	rrb_ps_rrr(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*now_under;
	t_node	*new_under;

	if (stacks->B.size <= 1)
		return ;
	now_top = stacks->B.top;
	now_under = stacks->B.under;
	new_under = stacks->B.under->before;
	stacks->B.under = new_under;
	stacks->B.under->next = NULL;
	now_under->next = now_top;
	now_under->before = NULL;
	now_top->before = now_under;
	stacks->B.top = now_under;
	stacks->B.under = new_under;
}

void	rrr_ps(t_stacks *stacks)
{
	rra_ps_rrr(stacks);
	rrb_ps_rrr(stacks);
	write(1, "rrr\n", 4);
}