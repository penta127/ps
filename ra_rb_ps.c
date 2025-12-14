#include "push_swap.h"

void	ra_ps(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*new_top;
	t_node	*now_under;

	if (stacks->A.size <= 1)
		return ;
	now_top = stacks->A.top;
	new_top = now_top->next;
	now_under = stacks->A.under;
	stacks->A.top = new_top;
	stacks->A.top->before = NULL;
	now_top->next = NULL;
	now_top->before = now_under;
	now_under->next = now_top;
	stacks->A.under = now_top;
	write(1, "ra\n", 3);
}

void	rb_ps(t_stacks *stacks)
{
	t_node	*now_top;
	t_node	*new_top;
	t_node	*now_under;

	if (stacks->B.size <= 1)
		return ;
	now_top = stacks->B.top;
	new_top = now_top->next;
	now_under = stacks->B.under;
	stacks->B.top = new_top;
	stacks->B.top->before = NULL;
	now_top->next = NULL;
	now_top->before = now_under;
	now_under->next = now_top;
	stacks->B.under = now_top;
	write(1, "rb\n", 3);
}